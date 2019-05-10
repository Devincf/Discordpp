/**
 * @file MessageCreateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-31 01:37
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MESSAGECREATEEVENT_HPP
#define MESSAGECREATEEVENT_HPP

#include "events/Event.hpp"

namespace discordpp
{
class MessageCreateEvent : public Event
{
    using Event::Event;

  public:
    bool proc(const nlohmann::json &);
};
} // namespace discordpp

#endif