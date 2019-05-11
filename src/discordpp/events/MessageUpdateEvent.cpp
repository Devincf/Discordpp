/**
 * @file MessageUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-11 01:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "MessageUpdateEvent.hpp"

#include "util/Singleton.hpp"
#include "util/jsonutils.hpp"
#include "util/constants.hpp"
#include "commands/CommandManager.hpp"
#include "guilds/GuildManager.hpp"
#include "users/UserManager.hpp"
#include "objects/Message.hpp"

namespace discordpp
{
bool MessageUpdateEvent::proc(const nlohmann::json &packet)
{
    //DEBUG("MessageUpdateEvent");
    nlohmann::json data = packet["d"];
    if (data.find("author") == data.end())
    {
        DEBUG("No author for MessageUpdateEvent found error");
        return false;
    }
    if(data["author"]["id"] == "444648378199048214")
    {
        return true;
    }
    std::string content = data["content"].get<std::string>();
    Message m(data);
    auto cmdit = Singleton<CommandManager>::get()->findCommand(util::tryGetSnowflake("guild_id", data), content);

    if (cmdit != nullptr)
    {
        return cmdit->proc(packet);
    }

    return true;
}
}