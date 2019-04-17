/**
 * @file PicartoCommand.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-03 04:24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "PicartoCommand.hpp"
#include "Util/constants.hpp"

#include "boost/algorithm/string.hpp"

#include "Util/Singleton.hpp"
#include "Core/Rest/DiscordAPI.hpp"
#include "Core/Rest/PicartoAPI.hpp"
#include "Core/Databases/SQLiteDatabase.hpp"

#include "Discordpp.hpp"

PicartoCommand::PicartoCommand(discordpp::Discordpp *dscpp, std::vector<Channel>* channels):discordpp::Command(dscpp),m_picartoChannel(channels)
{
}
PicartoCommand::~PicartoCommand() {}

bool PicartoCommand::proc(const nlohmann::json &packet)
{
    DEBUG("picartocommand proc");
    std::string content = packet["d"]["content"].get<std::string>();
    std::vector<std::string> splitcontent;
    boost::split(splitcontent, content, boost::is_any_of(" "));
    if (splitcontent.size() < 3)
    {
        DEBUG("wrong parameters");
        return false;
    }
    std::string username = splitcontent[2];
    if (splitcontent[1] == "get")
    {
        nlohmann::json channel_data = discordpp::Singleton<discordpp::PicartoAPI>::get()->getChannelInfo(username);
        if (channel_data.is_null())
        {
            discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                            "User " + username + " doesnt exist");
        }
        else
        {
            discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                            "User " + username + " is currently " + (channel_data["online"].get<bool>() ? ("online with " + std::to_string(channel_data["viewers"].get<int>()) + " viewers") : "offline"));
        }
    }
    else if (splitcontent[1] == "add")
    {
        m_picartoChannel->push_back(Channel(username));
        discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("INSERT INTO picarto_streams (channel_name,live) values(\""+username+"\",0)");
        discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                            "Added picarto channel " + username + " to the database");
    }
    return true;
}