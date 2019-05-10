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
#include "Util/constants.hpp"
#include "Commands/CommandManager.hpp"
#include "Guilds/GuildManager.hpp"
#include "Users/UserManager.hpp"
#include "Objects/Message.hpp"

namespace discordpp
{
bool MessageCreateEvent::proc(const nlohmann::json &packet)
{
    //DEBUG("MessageCreateProc");
    std::string content = packet["d"]["content"].get<std::string>();
    Message m(packet["d"]);
    if (packet["d"]["author"]["id"] == "444648378199048214")
    {
        //bot message
        return true;
    }

    auto cmdit = Singleton<CommandManager>::get()->findCommand(util::tryGetSnowflake("guild_id", packet["d"]), content);
    if (cmdit != nullptr)
    {
        return cmdit->proc(packet);
    }


    auto user = Singleton<UserManager>::get()->findUser(packet["d"]["author"]["id"]);
        if (user == nullptr)
        {
            DEBUG("Unknown user in MESSAGE_CREATE event");
            return false;
        }

    auto guildit = Singleton<GuildManager>::get()->findGuild(packet["d"]["guild_id"]);
    if (guildit != nullptr)
    {
        //guild message
        DEBUG(m.getTime().getISOTime() << "  " << guildit->name << "[" << guildit->getChannel(m.getChannelId()).name << "] " << user->userName << " : " << m.getContent());
    }
    else
    {
        //pm
        DEBUG(m.getTime().getISOTime() << "  "
                                       << "[" << guildit->getChannel(m.getChannelId()).name << "] " << user->userName << " : " << m.getContent());
    }

    return true;
}
} // namespace discordpp