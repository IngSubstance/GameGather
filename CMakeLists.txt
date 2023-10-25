cmake_minimum_required(VERSION 3.11)
project(SteamWebCpp VERSION 0.1.0 LANGUAGES C CXX)

# standard C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(SteamWebCpp main.cpp)