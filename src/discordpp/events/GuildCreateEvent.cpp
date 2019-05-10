/**
 * @file GuildCreateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 05:54
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "GuildCreateEvent.hpp"

#include "util/Singleton.hpp"
#include "guilds/GuildManager.hpp"

namespace discordpp{
    bool GuildCreateEvent::proc(const nlohmann::json& packet)
    {
        //DEBUG("Guild Create Event proc");
        Snowflake id = packet["d"]["id"];
        if(Singleton<GuildManager>::get()->findGuild(id) != nullptr)
        {
            DEBUG("Received GUILD_CREATE Event but the guild already exists");
            return false;
        }else
        {
            Guild* g = new Guild(packet["d"],true);
            return Singleton<GuildManager>::get()->addGuild(id,std::shared_ptr<Guild>(g));
        }

        return true;
    }
}