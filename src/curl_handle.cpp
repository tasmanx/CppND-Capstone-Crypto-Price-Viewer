#include "curl_handle.h"

#include "assert.h"
#include <string>

using std::string;

// callback function to receive incoming data chunks using curl write function
extern "C" size_t dataHandler(const char *buffer, size_t size, size_t nmemb, string *userData)
{
    if (userData == nullptr)
        return 0;
    // write data to userData string
    userData->append(buffer, (size * nmemb));
    // return number of bytes written
    return size * nmemb;
}

// init curlptr_ by calling CURL lib function curl_easy_init()
// custom deleter will take care of curlptr_ when it goes out of scope
CurlHandle::CurlHandle() : curlptr_(curl_easy_init(), deleter_)
{
    // init to use curl library
    curl_global_init(CURL_GLOBAL_ALL);
    // attach curl library writer function
    curl_easy_setopt(curlptr_.get(), CURLOPT_WRITEFUNCTION, dataHandler);
    curl_easy_setopt(curlptr_.get(), CURLOPT_WRITEDATA, &data_);
}

void CurlHandle::url(string url)
{
    curl_easy_setopt(curlptr_.get(), CURLOPT_URL, url.c_str());
}

CURLcode CurlHandle::fetch()
{
    return curl_easy_perform(curlptr_.get());
}

string CurlHandle::fetchedData()
{
    return data_;
}

void CurlHandle::clearFetchedData()
{
    data_.clear();
}
