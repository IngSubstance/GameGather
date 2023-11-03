#include <iostream>
#include "SteamWeb.hpp"


int main(int, char**){
    auto steamid = std::to_string(76561197975966352); //mio id
    const auto playerSummaries = SteamWebApi::SteamWebRequest("GetPlayerSummaries", 2, { { "steamids", steamid } });

    std::cout << playerSummaries;
}
