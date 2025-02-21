#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>
#include <map>
#include <ctime>

struct Transaction {
    std::string sender;
    std::string recipient;
    double amount;
};

class Block {
public:
    int index;
    time_t timestamp;
    std::vector<Transaction> transactions;
    std::string previous_hash;
    std::string hash;
    int nonce;

    Block(int idx, const std::vector<Transaction>& txs, const std::string& prev_hash);
    std::string calculate_hash() const;
};

class Blockchain {
public:
    std::vector<Block> chain;
    std::vector<Transaction> current_transactions;
    std::map<std::string, double> balances;
    std::map<std::string, int> stakes;
    std::string validator;

    Blockchain();
    void create_genesis_block();
    Block create_block(const std::string& prev_hash);
    void add_transaction(const std::string& sender, const std::string& recipient, double amount);
    bool is_transaction_valid(const Transaction& tx);
    std::string get_last_block_hash() const;
    void mine_block(const std::string& miner_address);
    bool is_chain_valid() const;
    void select_validator();
};

#endif