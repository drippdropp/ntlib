#pragma once

#ifndef NTLIB_CRYPTO_H
#define NTLIB_CRYPTO_H

#include <algorithm>
#include <bitset>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <string>

class Crypto
{
protected:
    std::string plain_text_string;
    std::string bin_pt_string;
    std::string cipher_text_string;
    std::string bin_ct_string;
    std::string cipher_text_seed;
    std::string bin_ct_seed;
    unsigned int random_number;

public:
    Crypto();
    void set_plain_text_string(std::string &);
    void get_plain_text_string();
    static std::string string_to_binary(const std::string&);
    static unsigned int generate_random_number();
};

Crypto::Crypto() {
    this->random_number = Crypto::generate_random_number();

}

/**
 * @static
 * @return [uint64_t] Randomly generated number.
 */
unsigned int Crypto::generate_random_number()
{
    // todo: replace with MersenneTwister or similar for generator
    srand(time(0));
    return static_cast<int>( rand() % 255 );
}

std::string Crypto::string_to_binary(const std::string &str) {
    size_t word_length = str.size();
    std::string bin_str_output;

    for (size_t i = 0; i < word_length; i++) {
        std::bitset<8> b(str.c_str()[i]);
        bin_str_output += b.to_string();
    }
    return bin_str_output;
}

#endif
