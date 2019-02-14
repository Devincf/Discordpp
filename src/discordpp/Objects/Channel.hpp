/**
 * @file Channel.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief Contains a wrapper class for Discord Channels
 * @version 0.1
 * @date 2019-02-14 06:11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Snowflake.hpp"

namespace discordpp
{
enum ChannelType
{
    GUILD_TEXT = 0,
    DM = 1,
    GUILD_VOICE = 2,
    GROUP_DM = 3,
    GUILD_CATEGORY = 4
};

class Channel
{
  public:
    /**
    * @brief Construct a new Channel object
    */
    Channel();
    /**
    * @brief Destroy the Channel object
    */
    ~Channel();
    /**
    * @brief Construct a new Channel object with a given payload
    * @param payload to use for constructing the channel
    */
    Channel(const Json::Value &payload);

    /**
     * @brief The channel id
     */
    Snowflake id;
    /**
     * @brief the type of channel
     */
    ChannelType type;
    /**
     * @brief guild id of the parent guild
     */
    Snowflake guildId; //Todo: change to guild ptr?
    /**
     * @brief sorting position of the channel
     */
    int position;
    /**
     * @brief channel name
     */
    std::string name;
    /**
     * @brief channel topic
     */
    std::string topic;
    /**
     * @brief whether the channel is nsfw or not
     */
    bool nsfw;
    /**
     * @brief id of the last message in the channel
     */
    Snowflake lastMessageId; //Todo: change to msg ptr?
    /**
     * @brief bitrate of the voice channel
     */
    int bitrate;
    /**
     * @brief userlimit of the voice channel
     */
    int userLimit;
    /**
     * @brief delay between messages in seconds (slowchat)
     */
    int rateLimitPerUser;
    /**
     * @brief icon hash of the server
     */
    std::string icon;
    /**
     * @brief id of the dm owner
     */
    Snowflake ownerId; //Todo: change to user ptr?
    /**
     * @brief appid of the dm owner if botcreated
     */
    Snowflake appId; //Todo: change to user ptr?
    /**
     * @brief if of the parent category for this channel
     */
    Snowflake parentId; //Todo: change to channel ptr?

    //Todo: add permiussion_overwrites, recipients

    //Todo: add timestamp
  private:
};
} // namespace discordpp

#endif