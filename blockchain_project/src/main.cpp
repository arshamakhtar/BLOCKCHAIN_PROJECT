#include "blockchain.hpp"
#include "p2p.hpp"
#include "wallet.hpp"
#include "api.hpp"
#include <iostream>

int main() {
    Blockchain blockchain;
    P2PNetwork p2p(5000);
    Wallet wallet;

    // Start P2P network
    std::thread p2p_thread([&p2p]() {
        p2p.start();
    });

    // Start API server
    BlockchainAPI api(blockchain);
    std::thread api_thread([&api]() {
        api.start(8080);  // Start API on port 8080
    });

    // Add some nodes
    p2p.add_node("127.0.0.1:5001");

    // Add transactions
    blockchain.add_transaction("Alice", "Bob", 10);
    blockchain.add_transaction("Bob", "Charlie", 5);

    // Mine a block
    blockchain.mine_block(wallet.get_address());

    // Check if the chain is valid
    if (blockchain.is_chain_valid()) {
        std::cout << "Blockchain is valid!" << std::endl;
    } else {
        std::cout << "Blockchain is invalid!" << std::endl;
    }

    p2p_thread.join();
    api_thread.join();
    return 0;
}