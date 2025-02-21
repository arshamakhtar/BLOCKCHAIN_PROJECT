#ifndef P2P_H
#define P2P_H

#include <boost/asio.hpp>
#include <string>
#include <vector>
#include <thread>

using boost::asio::ip::tcp;

class P2PNetwork {
public:
    P2PNetwork(short port);
    void start();
    void broadcast(const std::string& message);
    void add_node(const std::string& address);

private:
    void do_accept();
    void handle_connection(tcp::socket socket);
    void do_read(tcp::socket& socket);

    boost::asio::io_context io_context;
    tcp::acceptor acceptor;
    std::vector<std::string> nodes;
    std::vector<std::thread> threads;
};

#endif