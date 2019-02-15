/**
 * @file Channel.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-14 06:11pm
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Channel.hpp"
#include "../constants.hpp"
#include "../jsonutils.hpp"

namespace discordpp
{
Channel::Channel()
{
}
Channel::~Channel()
{
}
Channel::Channel(const nlohmann::json &payload)
{
    DEBUG(payload.dump(2));
    id = payload["id"];
    type = static_cast<ChannelType>(payload["type"].get<int>());
    
    guildId = util::tryGetSnowflake("guild_id", payload);
    position = util::tryGetJson<int>("position",payload);
    name = util::tryGetJson<std::string>("name",payload);
    topic = util::tryGetJson<std::string>("topic", payload);
    nsfw = util::tryGetJson<bool>("nsfw", payload);
    lastMessageId = util::tryGetSnowflake("last_message_id", payload);
    bitrate = util::tryGetJson<int>("bitrate", payload);
    userLimit = util::tryGetJson<int>("user_limit", payload);
    rateLimitPerUser = util::tryGetJson<int>("rate_limit_per_user", payload);
    icon = util::tryGetJson<std::string>("icon", payload);
    ownerId = util::tryGetSnowflake("owner_id", payload);
    appId = util::tryGetSnowflake("application_id", payload);
    parentId = util::tryGetSnowflake("parent_id", payload);
    DEBUG("loaded Channel");
}

} // namespace discordpp