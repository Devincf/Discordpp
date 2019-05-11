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

#include <future>
#include "util/constants.hpp"
#include "nlohmann/json.hpp"

namespace discordpp
{

void DiscordAPI::setToken(const std::string &token) { m_token = token; }

std::string DiscordAPI::sendMessage(const std::string &channel, const std::string &message)
{

    std::list<std::string> headers;
    headers.push_back("Authorization: Bot " + m_token);
    headers.push_back("Content-Type: multipart/form-data");

    nlohmann::json json;
    json["content"] = message;

    return this->sendPOST("https://discordapp.com/api/v6/channels/" + channel + "/messages", headers, json);
}

std::string DiscordAPI::sendMessageExtended(const std::string &channel, const nlohmann::json& json)
{

    std::list<std::string> headers;
    headers.push_back("Authorization: Bot " + m_token);
    headers.push_back("Content-Type: multipart/form-data");

    return this->sendPOST("https://discordapp.com/api/v6/channels/" + channel + "/messages", headers, json);
}

std::string DiscordAPI::deleteMessage(const std::string &channel, const std::string &id)
{
    std::list<std::string> headers;
    headers.push_back("Authorization: Bot " + m_token);
    headers.push_back("Content-Type: multipart/form-data");

    return this->sendDELETE("https://discordapp.com/api/v6/channels/" + channel + "/messages/" + id, headers);
}

std::string DiscordAPI::reactToMessage(const std::string& channelid, const std::string &msgid, const std::string &reaction)
{

    std::list<std::string> headers;
    headers.push_back("Authorization: Bot " + m_token);
    headers.push_back("Content-Type: multipart/form-data");
    headers.push_back("Content-Length:0");

    return this->sendPUT("https://discordapp.com/api/v6/channels/"+channelid+"/messages/"+msgid+"/reactions/"+reaction+"/@me", headers);
}

void DiscordAPI::webhookTest()
{
    //https://discordapp.com/api/webhooks/576458939202273291/COdDKrRI6j1c6t2mVPWRO9ortC60uLn0FXjR9OcFhHldTJLZYmUkoDa2g5rGN0kTUxfR

    std::list<std::string> headers;
    headers.push_back("Content-Type: multipart/form-data");

    nlohmann::json json;
    json["content"] = "Test Content";
    json["tts"] = false;
    json["embed"]["title"] = "Embed Title";
    json["embed"]["description"] = "Embed Description";

    this->sendPOST("https://discordapp.com/api/webhooks/576458939202273291/COdDKrRI6j1c6t2mVPWRO9ortC60uLn0FXjR9OcFhHldTJLZYmUkoDa2g5rGN0kTUxfR", headers, json);
}

void DiscordAPI::embedTest()
{

    std::list<std::string> headers;
    headers.push_back("Authorization: Bot " + m_token);
    headers.push_back("Content-Type: multipart/form-data");

    nlohmann::json json;
    nlohmann::json embed;
    embed["url"] = "https://www.google.com/";
    embed["title"] = "Coin drop";
    embed["color"] = 10824234;
    embed["description"] = "w-would u like a drink master?";
    embed["image"]["url"] = "https://cdn.discordapp.com/attachments/439065048628068365/576535445123629064/20190510_172533.jpg";
    json["embed"] = embed;

    this->sendPOST("https://discordapp.com/api/v6/channels/445942826534961153/messages", headers, json);
}

const std::string DiscordAPI::getGatewayURI()
{
    auto get_result = this->sendGET("https://discordapp.com/api/v6/gateway");
    nlohmann::json json = nlohmann::json::parse(get_result);
    return json["url"].get<std::string>();
}

} // namespace discordpp