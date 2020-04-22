cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 17)

project(StockPriceViewer)

add_executable(StockPriceViewer src/main.cpp include/json.hpp)