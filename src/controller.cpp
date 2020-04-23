#include "controller.h"

#include <vector>
#include "nlohmann/json.hpp"

using std::vector;
using json = nlohmann::json;

Controller::Controller()
{
    curlHandle_.url(CryptoCoin::API_URL);
}

vector<CryptoCoin> Controller::cryptoCoins() 
{
    // TODO:: implement cryptoCoins
}