/**
 * @file StreamNotifier.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-01 07:06
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "StreamNotifier.hpp"
#include "Discordpp.hpp"

#include "Util/Singleton.hpp"
#include "Core/Databases/SQLiteDatabase.hpp"
#include "Core/Rest/DiscordAPI.hpp"
#include "Core/Rest/PicartoAPI.hpp"
#include "Core/Rest/TwitchAPI.hpp"

StreamNotifier::StreamNotifier(discordpp::Discordpp *pDsc, std::map<std::string, std::vector<Channel>> *pChannels) : Task(4000)
{
    m_dscpp = pDsc;
    m_channels = pChannels;

    (*m_channels)["picarto"] = std::vector<Channel>();
    (*m_channels)["twitch"] = std::vector<Channel>();

    auto picartoChannels = discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("SELECT (channel_name) FROM picarto_streams");
    auto twitchChannels = discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("SELECT (channel_name) FROM twitch_streams");
    for (auto i : picartoChannels)
    {
        m_channels->at("picarto").push_back(Channel(i["channel_name"]));
    }
    for (auto i : twitchChannels)
    {
        m_channels->at("twitch").push_back(Channel(i["channel_name"]));
    }
}
void StreamNotifier::proc()
{
    DEBUG("StreamNotifier proc");
    for (Channel &channel : m_channels->at("picarto"))
    {
        //std::cout << "checking " << channel.name << std::endl;
        if (channel.online != discordpp::Singleton<discordpp::PicartoAPI>::get()->isUserOnline(channel.name))
        {
            //Online Status Changed
            std::cout << channel.name << " online status changed" << std::endl;

            if (channel.online)
            {
                //was online now offline
            }
            else
            {
                discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(streamChannel, channel.name + " is online!\nWatch live at : https://picarto.tv/" + channel.name);
            }
            channel.online = !channel.online;
        }
        //std::cout << "Channel " + channel.name << " is " << channel.online << std::boolalpha << " checking next Person" << std::endl;
    }

    for (Channel &channel : m_channels->at("twitch"))
    {
        //std::cout << "checking " << channel.name << std::endl;
        if (channel.online != discordpp::Singleton<discordpp::TwitchAPI>::get()->isUserOnline(channel.name))
        {
            //Online Status Changed
            std::cout << channel.name << " online status changed" << std::endl;

            if (channel.online)
            {
                //was online now offline
            }
            else
            {
                discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(streamChannel, channel.name + " is online!\nWatch live at : https://twitch.tv/" + channel.name);
            }
            channel.online = !channel.online;
        }
        //std::cout << "Channel " + channel.name << " is " << channel.online << std::boolalpha << " checking next Person" << std::endl;
    }

    resetTimer();
}