#ifndef API_HPP
#define API_HPP

#include "blockchain.hpp"
#include "httplib.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class BlockchainAPI {
public:
    BlockchainAPI(Blockchain& blockchain);
    void start(int port);

private:
    Blockchain& blockchain;
    httplib::Server server;

    void setup_routes();
    std::string serialize_blockchain() const;
};

#endif