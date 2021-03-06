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
#include "util/constants.hpp"

#include "util/jsonutils.hpp"

#include "util/Singleton.hpp"
#include "users/UserManager.hpp"

namespace discordpp
{
Guild::Guild() {}
Guild::~Guild() {}
Guild::Guild(const nlohmann::json &guild, bool guild_create)
{
    /// muss nicht im payload sein
    //  immer im payload kann aber null sein
    ///- muss nicht im payload sein, nur in GUILD_CREATE
    id = guild["id"];
    name = guild["name"].get<std::string>();
    DEBUG("Loading Guild " << name << "( " << id << " )");
    afkChannelId = guild["afk_channel_id"];
    afkTimeout = guild["afk_timeout"].get<int>();
    applicationId = guild["application_id"]; //done
    defaultMessageNotifications = guild["default_message_notifications"].get<int>();
    embedChannelId = util::tryGetSnowflake("embed_channel_id", guild); ///done
    embedEnabled = util::tryGetJson<bool>("embed_enabled", guild);
    ; ///done

    //load users
    for (unsigned int i = 0; i < guild["members"].size(); i++)
    {
        nlohmann::json currentMember = guild["members"][i];
        Snowflake snowflake = util::tryGetSnowflake("id", currentMember["user"]);
        auto user = Singleton<UserManager>::get()->findUser(snowflake);
        if (user == nullptr)
        {
            user = std::unique_ptr<User>(new User(currentMember));
            Singleton<UserManager>::get()->addUser(snowflake, user);
        }
        addUser(snowflake, user);
    }

    //load emojis
    for (unsigned int i = 0; i < guild["emojis"].size(); i++)
    {
        emojis.push_back(Emoji(guild["emojis"][i]));
    }
    explicitContentFilter = guild["explicit_content_filter"].get<int>();

    //load features
    for (unsigned int i = 0; i < guild["features"].size(); i++)
    {
        features.push_back(guild["features"][i].get<std::string>());
    }
    icon = util::tryGetJson<std::string>("icon", guild); //
    joinedAt = guild["joined_at"].get<std::string>();    ///-
    large = guild["large"].get<bool>();                  ///-
    memberCount = guild["member_count"].get<int>();      ///-
    members = std::map<Snowflake,std::shared_ptr<User>>();      ///-
    mfaLevel = guild["mfa_level"].get<int>();
    ownerId = guild["owner_id"];
    permissions = util::tryGetJson<int>("permissions", guild);
    region = guild["region"].get<std::string>();

    //load roles
    for (unsigned int i = 0; i < guild["roles"].size(); i++)
    {
        roles.push_back(Role(guild["roles"][i]));
    }
    splash = util::tryGetJson<std::string>("splash", guild);
    systemChannelId = guild["system_channel_id"];   //
    unavailable = guild["unavailable"].get<bool>(); ///-
    verificationLevel = guild["verification_level"].get<int>();
    widgetChannelId = util::tryGetSnowflake("widget_channel_id", guild);
    widgetEnabled = util::tryGetJson<bool>("widget_enabled", guild);

    //load channels
    for (unsigned int i = 0; i < guild["channels"].size(); i++)
    {
        //DEBUG(guild["channels"][i].dump(2));
        auto ret = channels.insert({util::tryGetSnowflake("id", guild["channels"][i]), Channel(guild["channels"][i])});
        if (!ret.second)
        {
            DEBUG("Channel already existed!");
        }
    }
}

void Guild::addUser(const Snowflake& id, std::shared_ptr<User> user)
{
    DEBUG("Added User with snowflake " << user->userId);
    auto ret = members.insert({id,user});
    if(!ret.second)
    {
        DEBUG("User already in memberlist");
    }
}

Channel Guild::getChannel(const Snowflake &id)
{
    auto channelit = channels.find(id);
    if (channelit != channels.end())
    {
        return channelit->second;
    }
    else
    {
        return Channel();
    }
}

std::shared_ptr<User> Guild::getUser(const Snowflake &id)
{
    auto userit = members.find(id);
    if (userit != members.end())
    {
        return userit->second;
    }
    else
    {
        return nullptr;
    }
}
} // namespace discordpp