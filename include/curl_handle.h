#ifndef CURL_HANDLE_H
#define CURL_HANDLE_H

#include <memory>
#include <functional>

#include <curl/curl.h>

// type of unique_ptr which holds CURL object and deleter function
typedef std::unique_ptr<CURL, std::function<void(CURL *)>> CURL_ptr;

class CurlHandle
{
public:
    // constructor
    CurlHandle();

    // getters / setters
    void setUrl(std::string url);
    void setHeader(std::string header);
    CURLcode getData();

private:
    // instance to use curl library functions
    CURL_ptr curl_ptr_;

    // for CURL pointer deletion
    constexpr static auto deleter_ = [](CURL *c) {
        curl_easy_cleanup(c);
        curl_global_cleanup();
    };
};

#endif













