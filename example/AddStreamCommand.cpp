/**
 * @file AddStreamCommand.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-01 07:16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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

#include "AddStreamCommand.hpp"
#include "util/constants.hpp"

#include "boost/algorithm/string.hpp"

#include "util/Singleton.hpp"
#include "rest/DiscordAPI.hpp"
#include "rest/PicartoAPI.hpp"
#include "databases/SQLiteDatabase.hpp"

#include "Discordpp.hpp"

AddStreamCommand::AddStreamCommand(discordpp::Discordpp *dscpp, std::map<std::string, std::vector<Channel>> *channels) : discordpp::Command(dscpp), m_channels(channels)
{
}
AddStreamCommand::~AddStreamCommand() {}

bool AddStreamCommand::proc(const nlohmann::json &packet)
{
    DEBUG("AddStreamCommand proc");
    std::string content = packet["d"]["content"].get<std::string>();
    std::vector<std::string> splitcontent;
    boost::split(splitcontent, content, boost::is_any_of(" "));
    //!stream add link
    // 0       1   2

    if (splitcontent[1] == "get")
    {
        if (splitcontent.size() < 2)
        {
            discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                            "Please specify a channel");
            return false;
        }
        /*      Todo: implement
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
        }*/
    }
    else if (splitcontent[1] == "list")
    {
        std::stringstream iss;
        iss << "Picarto Channel:" << std::endl;
        for (Channel &channel : m_channels->at("picarto"))
        {
            iss << channel.name << " -- " << (channel.online ? "online" : "offline") << std::endl;
        }
        iss << "Twitch Channel:" << std::endl;
        for (Channel &channel : m_channels->at("twitch"))
        {
            iss << channel.name << " -- " << (channel.online ? "online" : "offline") << std::endl;
        }

        discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                        iss.str());
        return true;
    }
    else if (splitcontent[1] == "add")
    {
        if (splitcontent.size() < 3)
        {
            discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                            "Please specify a channel");
            return false;
        }
        const std::string channel = splitcontent[2];
        if (channel.find("twitch.tv/") != std::string::npos)
        {
            if (channel.find("picarto.tv/") != std::string::npos)
            {

                discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                                "Some kind of unknown error occured please contact the developer");
                return false;
            }

            const std::string channelName = channel.substr(channel.find("twitch.tv/") + 10);
            m_channels->at("twitch").push_back(Channel(channelName));
            discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("INSERT INTO twitch_streams (channel_name,live) values(\"" + channelName + "\",0)");
            discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                            "Added twitch channel " + channelName + " to the database");
            return true;
        }
        else if (channel.find("picarto.tv/") != std::string::npos)
        {
            const std::string channelName = channel.substr(channel.find("picarto.tv/") + 11);
            m_channels->at("picarto").push_back(Channel(channelName));
            discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("INSERT INTO picarto_streams (channel_name,live) values(\"" + channelName + "\",0)");
            discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                            "Added picarto channel " + channelName + " to the database");
            return true;
        }
        else
        {
            //not a twitch/picarto stream what are u doing
            discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
                                                                            "Some kind of error occured. Maybe your link is in a wrong format or you specified a streaming service that is not yet implemented. Currently Implemented Services are: Twitch, Picarto");
            return false;
        }
    }
    return true;
}