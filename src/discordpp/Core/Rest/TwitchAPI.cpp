/**
 * @file TwitchAPI.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-01 06:57
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "TwitchAPI.hpp"
#include "nlohmann/json.hpp"
#include "Util/constants.hpp"
namespace discordpp
{

bool TwitchAPI::isOnline(const std::string& channelName)
{
    auto get_result = this->sendGET("https://api.twitch.tv/kraken/streams?client_id=" + m_token + "&channel=" + channelName);
    nlohmann::json json = nlohmann::json::parse(get_result);
    return json["_total"].get<int>() > 0;
}

void TwitchAPI::setToken(const std::string &token) { m_token = token; }
}