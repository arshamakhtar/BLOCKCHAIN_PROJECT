#include "storage.hpp"

Storage::Storage(const std::string& db_name) {
    sqlite3_open(db_name.c_str(), &db);
}

Storage::~Storage() {
    sqlite3_close(db);
}

void Storage::save_block(const Block& block) {
    std::string sql = "INSERT INTO blocks (index, hash, previous_hash) VALUES (" +
                      std::to_string(block.index) + ", '" + block.hash + "', '" + block.previous_hash + "');";
    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}

void Storage::load_blocks(Blockchain& blockchain) {
    std::string sql = "SELECT * FROM blocks;";
    sqlite3_exec(db, sql.c_str(), [](void* data, int argc, char** argv, char** colNames) -> int {
        Blockchain* blockchain = static_cast<Blockchain*>(data);
        Block block(std::stoi(argv[0]), {}, argv[2]);
        blockchain->chain.push_back(block);
        return 0;
    }, &blockchain, nullptr);
}