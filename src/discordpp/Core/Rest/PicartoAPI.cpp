/**
 * @file PicartoAPI.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-03 01:58
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "PicartoAPI.hpp"

#include "Util/constants.hpp"

namespace discordpp
{
    void PicartoAPI::setToken(const std::string& token)
    {
        m_token = token;
    }


    nlohmann::json PicartoAPI::getChannelInfo(const std::string& channelname)
    {
        auto get_result = this->sendGET("https://api.picarto.tv/v1/channel/name/" + channelname);
        return nlohmann::json::parse(get_result);
    }
    nlohmann::json PicartoAPI::getChannelInfo(uint64_t channelid)
    {
        auto get_result = this->sendGET("https://api.picarto.tv/v1/channel/id/" + channelid);
        return nlohmann::json::parse(get_result);
    }
}