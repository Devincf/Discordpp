/**
 * @file PicartoNotifier.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-17 01:18
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "PicartoNotifier.hpp"
#include "Discordpp.hpp"

#include "Util/Singleton.hpp"
#include "Core/Databases/SQLiteDatabase.hpp"
#include "Core/Rest/DiscordAPI.hpp"
#include "Core/Rest/PicartoAPI.hpp"

PicartoNotifier::PicartoNotifier(discordpp::Discordpp *pDsc, std::vector<Channel> *pChannels) : Task(4000)
{
    m_dscpp = pDsc;
    m_channels = pChannels;

    auto picartoChannels = discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("SELECT (channel_name) FROM picarto_streams");
    for (auto i : picartoChannels)
    {
        m_channels->push_back(Channel(i["channel_name"]));
    }
}
void PicartoNotifier::proc()
{
    DEBUG("PicartoNotifier proc");
    for (Channel &channel : *m_channels)
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
                discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage("439065048628068365", channel.name + " is online!\nWatch live at : https://picarto.tv/" + channel.name);
            }
            channel.online = !channel.online;
        }
        //std::cout << "Channel " + channel.name << " is " << channel.online << std::boolalpha << " checking next Person" << std::endl;
    }
    resetTimer();
}