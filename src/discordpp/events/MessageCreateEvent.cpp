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

#include "util/Singleton.hpp"
#include "util/jsonutils.hpp"
#include "util/constants.hpp"
#include "commands/CommandManager.hpp"
#include "guilds/GuildManager.hpp"
#include "users/UserManager.hpp"
#include "objects/Message.hpp"

namespace discordpp
{
bool MessageCreateEvent::proc(const nlohmann::json &packet)
{
    //DEBUG("MessageCreateProc");
    nlohmann::json data = packet["d"];
    if (data.find("author") == data.end())
    {
        DEBUG("No author for MessageCreateEvent found error");
        return false;
    }
    std::string authorID = data["author"]["id"].get<std::string>();
    if (authorID== "444648378199048214")
    {
        //bot message
        return true;
    }
    std::string content = data["content"].get<std::string>();
    Message m(data);

    auto cmdit = Singleton<CommandManager>::get()->findCommand(util::tryGetSnowflake("guild_id", data), content);
    if (cmdit != nullptr)
    {
        return cmdit->proc(packet);
    }


    auto user = Singleton<UserManager>::get()->findUser(authorID);
        if (user == nullptr)
        {
            DEBUG("Unknown user in MESSAGE_CREATE event");
            return false;
        }

    auto guildit = Singleton<GuildManager>::get()->findGuild(data["guild_id"]);
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