#ifndef CURL_HANDLE_H
#define CURL_HANDLE_H

#include <memory>
#include <functional>
#include <string>

#include <curl/curl.h>

// type of unique_ptr which holds CURL object and deleter function
typedef std::unique_ptr<CURL, std::function<void(CURL *)>> CURL_ptr;

class CurlHandle
{
public:
    // constructor
    CurlHandle();

    // getters / setters
    void url(std::string url);
    CURLcode fetch();
    std::string fetchedData();
    void clearFetchedData();

private:
    // instance to use curl library functions
    CURL_ptr curlptr_;
    std::string data_;

    // for CURL pointer deletion
    constexpr static auto deleter_ = [](CURL *c) {
        curl_easy_cleanup(c);
        curl_global_cleanup();
    };
};

#endif

