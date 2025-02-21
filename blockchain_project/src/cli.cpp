#include "cli.hpp"

void CLI::parse(int argc, char* argv[]) {
    cxxopts::Options options("blockchain_cpp", "A blockchain implementation in C++");
    options.add_options()
        ("p,port", "Port to listen on", cxxopts::value<std::string>(port))
        ("s,send", "Send a transaction", cxxopts::value<std::string>(from))
        ("t,to", "Recipient address", cxxopts::value<std::string>(to))
        ("a,amount", "Amount to send", cxxopts::value<double>(amount))
        ("h,help", "Print usage");

    auto result = options.parse(argc, argv);
    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }
}