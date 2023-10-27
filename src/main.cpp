#include <iostream>
#include <nlohmann/json.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Easy.hpp>
#include <sstream>

#define STEAM_API_URL "http://api.steampowered.com/"

using json = nlohmann::json;

std::string apikey = "91DA87FD070411756C502563F2429DFB";

json SteamWebRequest(const std::string& name, uint16_t version,
                                                std::vector<std::pair<std::string, std::string>> data)
{
    std::string url = STEAM_API_URL;
    url.append("ISteamUser/");
    url.append(name + "/v" + std::to_string(version));
    url.append("/?key=" + apikey);

    for (auto& tag : data)
        url.append("&" + tag.first + "=" + tag.second);

    std::cout << "url request: " << url << std::endl;

    curlpp::Easy req;
    std::ostringstream stream;

    req.setOpt<curlpp::options::Url>(url);
    req.setOpt<curlpp::options::WriteStream>(&stream);
    req.perform();

    std::cout << "req response: " << stream.str() << std::endl;

    return json::parse(stream.str()); //occorre una gestione di erroe sulla richiesta
}


int main(int, char**){
    auto steamid = std::to_string(76561197975966352); //mio id
    json request = SteamWebRequest("GetPlayerSummaries", 2, { { "steamids", steamid } });

    std::cout << "Hello, from SteamWebCpp!\n";
}
