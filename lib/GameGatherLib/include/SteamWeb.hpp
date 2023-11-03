#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace SteamWebApi
{
json SteamWebRequest(const std::string& name, uint16_t version,
                                                std::vector<std::pair<std::string, std::string>> data);
} // namespace SteamWebApi