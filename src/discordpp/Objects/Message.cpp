/**
 * @file Message.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-14 07:29pm
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Message.hpp"

#include "Util/constants.hpp"

namespace discordpp
{
Message::Message()
{
}
Message::~Message()
{
}
Message::Message(const nlohmann::json &payload)
{
    //DEBUG(payload);
    /*{"attachments":[],
    "author":{
        "avatar":"8cc5e9b7b50ec12cee0f4179469545a8",
        "discriminator":"6996",
        "id":"142733073262444545",
        "username":"Luminous"},
    "channel_id":"439065048628068365",
    "content":"test",
    "edited_timestamp":null,
    "embeds":[],
    "guild_id":"439065048628068363",
    "id":"547804640683622401",
    "member":{
        "deaf":false,"joined_at":"2018-04-26T14:07:45.068000+00:00",
        "mute":false,
        "roles":["444778351375286272"]},
    "mention_everyone":false,
    "mention_roles":[],
    "mentions":[],
    "nonce":"547804640511524864",
    "pinned":false,
    "timestamp":"2019-02-20T15:40:04.057000+00:00",
    "tts":false,
    "type":0}
    */
    const std::string timestampstr = payload["timestamp"].get<std::string>();
    if (std::all_of(timestampstr.begin(), timestampstr.end(), ::isdigit))
    {
        _timestamp = util::fromUnixTimestamp(timestampstr);
    }
    else
    {
        _timestamp = util::fromISO8601Timestamp(timestampstr);
    }

    _tts = payload["tts"].get<bool>();
    _content = payload["content"].get<std::string>();
    _id = payload["id"];
    _channelId = payload["channel_id"];
}

void Message::printMessage()
{

}

util::Timestamp Message::getTime() { return _timestamp; }

std::string Message::getContent() { return _content; }
Snowflake Message::getChannelId() { return _channelId; }
Snowflake Message::getId() { return _id; }
bool Message::hasTTSEnabled() { return _tts; }

} // namespace discordpp