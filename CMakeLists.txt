cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 17)
set(CURL_LIBRARY "-lcurl")

project(CryptoPriceViewer)

find_package(CURL REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(CryptoPriceViewer ${SOURCES})

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(CryptoPriceViewer ${CURL_LIBRARIES})
target_link_libraries(CryptoPriceViewer nlohmann_json::nlohmann_json)
