#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "curl_handle.h"
#include "crypto_coin.h"

class Controller
{
public:
    Controller();
    std::vector<CryptoCoin> cryptoCoins();

private:
    CurlHandle curlHandle_ = {};
    std::vector<CryptoCoin> cryptoCoins_ = {};
};

#endif
