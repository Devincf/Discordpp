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
    void sendMessage(const std::string&, const std::string&);
    const std::string getGatewayURI();

    void setToken(const std::string&);
    private:
    std::string m_token;
};
}
#endif