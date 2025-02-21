#include "api.hpp"
#include <iostream>

BlockchainAPI::BlockchainAPI(Blockchain& blockchain) : blockchain(blockchain) {
    setup_routes();
}

void BlockchainAPI::start(int port) {
    std::cout << "Starting API server on port " << port << "..." << std::endl;
    server.listen("0.0.0.0", port);
}

void BlockchainAPI::setup_routes() {
    // Get the entire blockchain
    server.Get("/blocks", [this](const httplib::Request& req, httplib::Response& res) {
        res.set_content(serialize_blockchain(), "application/json");
    });

    // Add a new transaction
    server.Post("/transactions", [this](const httplib::Request& req, httplib::Response& res) {
        json body = json::parse(req.body);
        std::string sender = body["sender"];
        std::string recipient = body["recipient"];
        double amount = body["amount"];

        blockchain.add_transaction(sender, recipient, amount);
        res.set_content("Transaction added", "text/plain");
    });

    // Mine a new block
    server.Post("/mine", [this](const httplib::Request& req, httplib::Response& res) {
        json body = json::parse(req.body);
        std::string miner_address = body["miner_address"];

        blockchain.mine_block(miner_address);
        res.set_content("Block mined", "text/plain");
    });

    // Get the balance of an address
    server.Get("/balance", [this](const httplib::Request& req, httplib::Response& res) {
        std::string address = req.get_param_value("address");
        double balance = blockchain.balances[address];
        res.set_content(json{{"address", address}, {"balance", balance}}.dump(), "application/json");
    });
}

std::string BlockchainAPI::serialize_blockchain() const {
    json j;
    for (const auto& block : blockchain.chain) {
        j["blocks"].push_back({
            {"index", block.index},
            {"timestamp", block.timestamp},
            {"transactions", block.transactions},
            {"previous_hash", block.previous_hash},
            {"hash", block.hash},
            {"nonce", block.nonce}
        });
    }
    return j.dump(4);
}