/**
 * @file Guild.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-01 02:24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Guild.hpp"
#include "../constants.hpp"

namespace discordpp
{
    Guild::Guild(){}
    Guild::~Guild(){}
    Guild::Guild(const Json::Value& guild)
    {
        DEBUG(guild["channels"].toStyledString());

        id = guild["id"];
        name = guild["name"].asString();
        DEBUG("Loading Guild " << name << "( " << id << " )");
        afkChannelId = guild["afk_channel_id"];
        afkTimeout = guild["afk_timeout"].asInt();
        applicationId = guild["application_id"];
        defaultMessageNotifications = guild["default_message_notifications"].asInt();
        embedChannelId = guild["embed_channel_id"];
        embedEnabled = guild["embed_enabled"].asBool();
        for(unsigned int i = 0; i< guild["emojis"].size();i++)
        {
            emojis.push_back(Emoji(guild["emojis"][i]));
        }
        explicitContentFilter = guild["explicit_content_filter"].asInt();
        for(unsigned int i = 0;i<guild["features"].size();i++)
        {
            features.push_back(guild["features"][i].asString());
        }
        icon = guild["icon"].asString();
        joinedAt = guild["joined_at"].asString();
        large = guild["large"].asBool();
        memberCount = guild["member_count"].asInt();
        members = std::vector<std::shared_ptr<User>>();
        mfaLevel = guild["mfa_level"].asInt();
        ownerId = guild["owner_id"];
        permissions = guild["permissions"].asInt();
        region = guild["region"].asString();
        for(unsigned int i=0;i<guild["roles"].size();i++)
        {
            roles.push_back(Role(guild["roles"][i]));
        }
        splash = guild["splash"].asString();
        systemChannelId = guild["system_channel_id"];
        unavailable = guild["unavailable"].asBool();
        verificationLevel = guild["verification_level"].asInt();
        widgetChannelId = guild["widget_channel_id"];
        widgetEnabled = guild["widget_enabled"].asBool();
    }


    void Guild::addUser(std::shared_ptr<User> user)
    {
        DEBUG("Added User with snowflake " << user->userId);
        members.push_back(user);
    }
}