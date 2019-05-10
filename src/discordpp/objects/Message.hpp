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

#include "util/Snowflake.hpp"
#include "util/Timestamp.hpp"

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

class Guild;
class User;

class Message{
    private:
    bool m_tts;
    Snowflake m_id;
    util::Timestamp m_timestamp;
    std::string m_content;
    Snowflake m_channelId;
    std::shared_ptr<Guild> m_guild;
    std::shared_ptr<User> m_author;
    public:

    /**
     * @brief converts the message object into a string and prints it into the console
     */
    void printMessage();

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