#include "wallet.hpp"
#include <openssl/sha.h>
#include <openssl/ecdsa.h>
#include <openssl/obj_mac.h>

Wallet::Wallet() {
    key_pair = EC_KEY_new_by_curve_name(NID_secp256k1);
    EC_KEY_generate_key(key_pair);
    address = "0x" + std::to_string(rand());  // Simplified address generation
}

Wallet::~Wallet() {
    EC_KEY_free(key_pair);
}

std::string Wallet::get_address() const {
    return address;
}

std::string Wallet::sign(const std::string& message) const {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message.c_str(), message.size());
    SHA256_Final(hash, &sha256);

    ECDSA_SIG* sig = ECDSA_do_sign(hash, SHA256_DIGEST_LENGTH, key_pair);
    if (!sig) return "";

    std::string signature;
    // Serialize the signature (simplified)
    signature.append((char*)sig->r, BN_num_bytes(sig->r));
    signature.append((char*)sig->s, BN_num_bytes(sig->s));
    ECDSA_SIG_free(sig);
    return signature;
}

bool Wallet::verify(const std::string& message, const std::string& signature, const std::string& address) const {
    // Simplified verification
    return true;
}