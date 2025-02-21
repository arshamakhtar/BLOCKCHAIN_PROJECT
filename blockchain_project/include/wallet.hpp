#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <openssl/ec.h>

class Wallet {
public:
    Wallet();
    ~Wallet();
    std::string get_address() const;
    std::string sign(const std::string& message) const;
    bool verify(const std::string& message, const std::string& signature, const std::string& address) const;

private:
    EC_KEY* key_pair;
    std::string address;
};

#endif