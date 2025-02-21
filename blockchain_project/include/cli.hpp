#ifndef CLI_H
#define CLI_H

#include <string>
#include <cxxopts.hpp>

class CLI {
public:
    void parse(int argc, char* argv[]);

private:
    std::string port;
    std::string from;
    std::string to;
    double amount;
};

#endif