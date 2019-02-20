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
    DEBUG("message.cpp");
    //if timestamp is unix
    std::string timestampstr = payload["timestamp"].get<std::string>();
    if (std::all_of(timestampstr.begin(), timestampstr.end(), ::isdigit))
    {
        _timestamp = util::fromUnixTimestamp(timestampstr);
    }
    else
    {
        _timestamp = util::fromISO8601Timestamp(timestampstr);
    }
}

util::Timestamp Message::getTime() { return _timestamp; }
} // namespace discordpp