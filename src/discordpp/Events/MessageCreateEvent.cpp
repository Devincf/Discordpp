/**
 * @file MessageCreateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-31 01:38
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "MessageCreateEvent.hpp"

#include "Util/Singleton.hpp"
#include "Core/Rest/DiscordAPI.hpp"

namespace discordpp
{
    bool MessageCreateEvent::proc(const nlohmann::json& packet)
    {
        DEBUG("MessageCreateProc");
        if(packet["d"]["content"] == "!ping" &&packet["d"]["author"]["id"] != "444648378199048214")
        {
            DEBUG("Message received");
            Singleton<DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),"pong!");
        }
        return true;
    }
}