/**
 * @file DiscordAPI.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-02 04:06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "DiscordAPI.hpp"

namespace discordpp
{

    DiscordAPI::DiscordAPI(const std::string& token): m_token(token){}
    DiscordAPI::DiscordAPI(){}
    DiscordAPI::~DiscordAPI(){}

void DiscordAPI::sendMessage(const std::string &channel, const std::string &message)
{

    std::list<std::string> headers;
    headers.push_back("Authorization: Bot" + m_token);
    headers.push_back("Content-Type: multipart/form-data");

    curlpp::Forms formdata;
    formdata.push_back(new curlpp::FormParts::Content("content", message));

    this->sendPOST("https://discordapp.com/api/v6/channels/" + channel + "/messages", headers, formdata);
}
} // namespace discordpp