/**
 * @file DiscordAPI.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-02 04:04
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DISCORDAPI_HPP
#define DISCORDAPI_HPP

#include "RestAPI.hpp"
namespace discordpp{

class DiscordAPI : public RestAPI
{
    public:
    std::string sendMessage(const std::string& channel, const std::string& message);
    std::string deleteMessage(const std::string& channel,const std::string& id);
    std::string reactToMessage(const std::string& channelid, const std::string& msgid, const std::string& reaction);
    const std::string getGatewayURI();

    void webhookTest();
    void embedTest();

    void setToken(const std::string&);
    private:
    std::string m_token;
};
}
#endif