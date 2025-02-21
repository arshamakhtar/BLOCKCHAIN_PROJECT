#include "p2p.hpp"
#include <iostream>

P2PNetwork::P2PNetwork(short port)
    : acceptor(io_context, tcp::endpoint(tcp::v4(), port)) {}

void P2PNetwork::start() {
    do_accept();
    io_context.run();
}

void P2PNetwork::do_accept() {
    acceptor.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
        if (!ec) {
            std::thread(&P2PNetwork::handle_connection, this, std::move(socket)).detach();
        }
        do_accept();
    });
}

void P2PNetwork::handle_connection(tcp::socket socket) {
    do_read(socket);
}

void P2PNetwork::do_read(tcp::socket& socket) {
    char data[1024];
    socket.async_read_some(boost::asio::buffer(data), [this, &socket](boost::system::error_code ec, std::size_t length) {
        if (!ec) {
            std::string message(data, length);
            std::cout << "Received: " << message << std::endl;
            broadcast(message);  // Broadcast to other nodes
        }
    });
}

void P2PNetwork::broadcast(const std::string& message) {
    for (const auto& node : nodes) {
        tcp::socket socket(io_context);
        boost::asio::connect(socket, tcp::resolver(io_context).resolve(node));
        boost::asio::write(socket, boost::asio::buffer(message));
    }
}

void P2PNetwork::add_node(const std::string& address) {
    nodes.push_back(address);
}