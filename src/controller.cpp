#include "controller.h"

#include <vector>
#include <string>
#include "nlohmann/json.hpp"

using std::vector;
using std::string;
using json = nlohmann::json;

Controller::Controller()
{
    curlHandle_.url(CryptoCoin::API_URL);
}

vector<CryptoCoin> Controller::cryptoCoins()
{
    curlHandle_.clearFetchedData();
    curlHandle_.fetch();
    json cryptoData = json::parse(curlHandle_.fetchedData());
    json coinsArray = std::move(cryptoData["data"]["coins"]);

    cryptoCoins_.clear();
    for (json::iterator it = coinsArray.begin(); it != coinsArray.end(); ++it)
        cryptoCoins_.emplace_back(
            it.value()["rank"].get<int>(),
            it.value()["symbol"].get<string>(),
            it.value()["name"].get<string>(),
            it.value()["price"].get<string>().substr(0, it.value()["price"].get<string>().find_first_of(".") + 3),
            it.value()["change"].get<float>());
    
    return cryptoCoins_;
}