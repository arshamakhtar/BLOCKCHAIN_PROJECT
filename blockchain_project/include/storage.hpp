#ifndef STORAGE_H
#define STORAGE_H

#include <sqlite3.h>
#include <string>

class Storage {
public:
    Storage(const std::string& db_name);
    ~Storage();
    void save_block(const Block& block);
    void load_blocks(Blockchain& blockchain);

private:
    sqlite3* db;
};

#endif