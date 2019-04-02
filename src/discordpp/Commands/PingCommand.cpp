/**
 * @file PingCommand.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-02 03:10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "PingCommand.hpp"

#include "Util/constants.hpp"

#include "Util/Singleton.hpp"
#include "Core/Rest/DiscordAPI.hpp"

namespace discordpp
{
    bool PingCommand::proc(const nlohmann::json& packet)
    {
        Singleton<DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(), "pong!");
        return true;
    }
}