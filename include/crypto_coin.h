#ifndef CRYPTO_COIN_H
#define CRYPTO_COIN_H

#include <string>

class CryptoCoin
{
public:
    // constructor
    CryptoCoin(int rank, std::string symbol, std::string name, int price, float change) : 
        rank_(rank), symbol_(symbol), name_(name), price_(price), change_(change) {}

    // getters
    int rank() { return rank_; }
    std::string symbol() { return symbol_; }
    std::string name() { return name_; }
    int price() { return price_; }
    float change() { return change_; }

    static constexpr const char *API_URL = "https://api.coinranking.com/v1/public/coins?limit=10";

private:
    // variables to store coin info
    int rank_ = {};
    std::string symbol_ = {};
    std::string name_ = {};
    int price_ = {};
    float change_ = {};
};

#endif
