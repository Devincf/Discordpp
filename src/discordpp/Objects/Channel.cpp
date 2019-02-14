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

namespace discordpp
{
Channel::Channel()
{
}
Channel::~Channel()
{
}
Channel::Channel(const Json::Value& payload)
{
    id = payload["id"];
    type = static_cast<ChannelType>(payload["type"].asInt());
    guildId = payload["guild_id"];
    position = payload["position"].asInt();
    name = payload["name"].asString();
    topic = payload["topic"].asString();
    nsfw = payload["nsfw"].asBool();
    lastMessageId = payload["last_message_id"];
    bitrate = payload["bitrate"].asInt();
    userLimit = payload["user_limit"].asInt();
    rateLimitPerUser = payload["rate_limit_per_user"].asInt();
    icon = payload["icon"].asString();
    ownerId = payload["owner_id"];
    appId = payload["application_id"];
    parentId = payload["parent_id"];
}

} // namespace discordpp