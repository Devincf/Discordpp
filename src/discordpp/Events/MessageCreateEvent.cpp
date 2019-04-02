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
#include "Util/jsonutils.hpp"
#include "Managers/CommandManager.hpp"

namespace discordpp
{
    bool MessageCreateEvent::proc(const nlohmann::json& packet)
    {
        DEBUG("MessageCreateProc");
        if(packet["d"]["author"]["id"] == "444648378199048214")
        { 
            //bot message
            return true;
        }

        auto cmdit = Singleton<CommandManager>::get()->findCommand(util::tryGetSnowflake("guild_id", packet["d"]),packet["d"]["content"].get<std::string>());
        if(cmdit != nullptr)
        {
            return cmdit->proc(packet);
        }

        return true;
    }
}