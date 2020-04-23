cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 17)
set(CURL_LIBRARY "-lcurl")

project(CryptoPriceViewer)

find_package(CURL REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(Curses REQUIRED)

include_directories(${CURL_INCLUDE_DIR})
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(CryptoPriceViewer ${SOURCES})

target_link_libraries(CryptoPriceViewer ${CURL_LIBRARIES})
target_link_libraries(CryptoPriceViewer nlohmann_json::nlohmann_json)
target_link_libraries(CryptoPriceViewer ${CURSES_LIBRARIES})
