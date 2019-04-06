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

    bool PicartoAPI::isUserOnline(const std::string& channelname)
    {
        nlohmann::json t =  getChannelInfo(channelname);
        if(t.is_null()) return false;
        return t["online"].get<bool>();
    }

    bool PicartoAPI::isUserOnline(uint64_t channelid)
    {
        nlohmann::json t =  getChannelInfo(channelid);
        if(t.is_null()) return false;
        return t["online"].get<bool>();
    }

    nlohmann::json PicartoAPI::getChannelInfo(const std::string& channelname)
    {
        auto get_result = this->sendGET("https://api.picarto.tv/v1/channel/name/" + channelname);
        if(nlohmann::json::accept(get_result))
            return nlohmann::json::parse(get_result);
        return nlohmann::json();
    }
    nlohmann::json PicartoAPI::getChannelInfo(uint64_t channelid)
    {
        auto get_result = this->sendGET("https://api.picarto.tv/v1/channel/id/" + std::to_string(channelid));
        if(nlohmann::json::accept(get_result))
            return nlohmann::json::parse(get_result);
        return nlohmann::json();
    }
}