#include "blockchain.hpp"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

Block::Block(int idx, const std::vector<Transaction>& txs, const std::string& prev_hash)
    : index(idx), timestamp(time(0)), transactions(txs), previous_hash(prev_hash), nonce(0) {
    hash = calculate_hash();
}

std::string Block::calculate_hash() const {
    std::stringstream ss;
    ss << index << timestamp << previous_hash << nonce;
    for (const auto& tx : transactions) {
        ss << tx.sender << tx.recipient << tx.amount;
    }
    return sha256(ss.str());
}

Blockchain::Blockchain() {
    create_genesis_block();
}

void Blockchain::create_genesis_block() {
    std::vector<Transaction> txs;
    Block genesis(0, txs, "0");
    chain.push_back(genesis);
}

Block Blockchain::create_block(const std::string& prev_hash) {
    Block new_block(chain.size(), current_transactions, prev_hash);
    current_transactions.clear();
    chain.push_back(new_block);
    return new_block;
}

void Blockchain::add_transaction(const std::string& sender, const std::string& recipient, double amount) {
    Transaction tx{sender, recipient, amount};
    if (is_transaction_valid(tx)) {
        current_transactions.push_back(tx);
        balances[sender] -= amount;
        balances[recipient] += amount;
    }
}

bool Blockchain::is_transaction_valid(const Transaction& tx) {
    if (balances.find(tx.sender) == balances.end() || balances[tx.sender] < tx.amount) {
        return false;  // Insufficient balance
    }
    return true;
}

std::string Blockchain::get_last_block_hash() const {
    return chain.back().hash;
}

void Blockchain::mine_block(const std::string& miner_address) {
    select_validator();
    if (miner_address == validator) {
        std::string prev_hash = get_last_block_hash();
        Block new_block = create_block(prev_hash);
        std::cout << "Block mined by: " << validator << std::endl;
        // Reward validator
        add_transaction("network", validator, 50);
    }
}

bool Blockchain::is_chain_valid() const {
    for (size_t i = 1; i < chain.size(); i++) {
        const Block& current = chain[i];
        const Block& previous = chain[i - 1];
        if (current.hash != current.calculate_hash() || current.previous_hash != previous.hash) {
            return false;
        }
    }
    return true;
}

void Blockchain::select_validator() {
    int total_stake = 0;
    for (const auto& stake : stakes) {
        total_stake += stake.second;
    }
    int random = rand() % total_stake;
    for (const auto& stake : stakes) {
        random -= stake.second;
        if (random <= 0) {
            validator = stake.first;
            break;
        }
    }
}