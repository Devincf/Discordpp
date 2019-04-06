/**
 * @file PicartoAPI.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-03 01:56
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PICARTOAPI_HPP
#define PICARTOAPI_HPP

#include "RestAPI.hpp"
#include "nlohmann/json.hpp"

namespace discordpp
{
class PicartoAPI : public RestAPI
{
    using RestAPI::RestAPI;
    public:
    
    bool isUserOnline(const std::string& channelname);
    bool isUserOnline(uint64_t channelname);
    nlohmann::json getChannelInfo(const std::string& channelname);
    nlohmann::json getChannelInfo(uint64_t channelid);
    void setToken(const std::string& token);
    private:
    std::string m_token;
};
} // namespace discordpp

#endif