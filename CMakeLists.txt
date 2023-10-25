cmake_minimum_required(VERSION 3.11)
project(SteamWebCpp VERSION 0.1.0 LANGUAGES C CXX)

# standard C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#add nlohmann/json library
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(SteamWebCpp src/main.cpp)

target_link_libraries(SteamWebCpp PRIVATE nlohmann_json::nlohmann_json)