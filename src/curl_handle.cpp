#include "curl_handle.h"

#include "assert.h"
#include <string>

using std::string;

// init curl_ptr_ by calling CURL lib function curl_easy_init()
// custom deleter will take care of curl_ptr_ when it goes out of scope 
CurlHandle::CurlHandle() : curl_ptr_(curl_easy_init(), deleter_)
{
    // init to use curl library
    curl_global_init(CURL_GLOBAL_ALL);
}

void CurlHandle::setUrl(string url) 
{
    curl_easy_setopt(curl_ptr_.get(), CURLOPT_URL, url.c_str());
}

CURLcode CurlHandle::getData()
{
    return curl_easy_perform(curl_ptr_.get());
}