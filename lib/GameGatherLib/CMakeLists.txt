cmake_minimum_required(VERSION 3.11)
project(GameGatherLib VERSION 0.1.0 LANGUAGES C CXX)

# standard C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set library file
add_library(GameGatherLib src/SteamWeb.cpp)

# Specifica le directory in cui cercare gli header della tua libreria
target_include_directories(GameGatherLib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#add library subdirectories
add_subdirectory(thirdparty/json)
add_subdirectory(thirdparty/curlpp)

#link libraries
target_link_libraries(GameGatherLib PUBLIC nlohmann_json::nlohmann_json)
target_link_libraries(GameGatherLib PRIVATE curlpp)