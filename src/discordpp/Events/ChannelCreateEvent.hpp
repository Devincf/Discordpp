/**
 * @file ChannelCreateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-31 01:40
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CHANNELCREATEEVENT_HPP
#define CHANNELCREATEEVENT_HPP

#include "Event.hpp"

namespace discordpp
{
class ChannelCreateEvent : public Event
{
    using Event::Event;

  public:
    bool proc(const nlohmann::json &);
};
} // namespace discordpp

#endif