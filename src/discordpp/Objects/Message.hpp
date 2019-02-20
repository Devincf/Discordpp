/**
 * @file Message.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief wrapper class for message objects
 * @version 0.1
 * @date 2019-02-14 07:03pm
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "Snowflake.hpp"
#include "Util/Timestamp.hpp"

namespace discordpp
{
enum MessageType
{
    DEFAULT = 0,
    RECIPIENT_ADD = 1,
    RECIPIENT_REMOVE = 2,
    CALL = 3,
    CHANNEL_NAME_CHANGE = 4,
    CHANNEL_ICON_CHANGE = 5,
    CHANNEL_PINNED_MESSAGE = 6,
    GUILD_MEMBER_JOIN = 7,
};

class Message{
    private:
    bool _tts;
    Snowflake _id;
    util::Timestamp _timestamp;
    std::string _content;
    Snowflake _channelId;
    public:

    util::Timestamp getTime();
    std::string getContent();
    Snowflake getChannelId();
    Snowflake getId();
    bool hasTTSEnabled();
    Message();
    ~Message();
    Message(const nlohmann::json& payload);
};
}

#endif