cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 17)
set(CURL_LIBRARY "-lcurl")

project(CryptoPriceViewer)

find_package(CURL REQUIRED)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(CryptoPriceViewer ${SOURCES})

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(CryptoPriceViewer ${CURL_LIBRARIES})
