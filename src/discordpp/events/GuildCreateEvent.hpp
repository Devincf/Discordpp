/**
 * @file GuildCreateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 05:52
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILDCREATEEVENT_HPP
#define GUILDCREATEEVENT_HPP

#include "events/Event.hpp"

namespace discordpp
{
class GuildCreateEvent : public Event
{
    using Event::Event;
    public:
    bool proc(const nlohmann::json&);
};
} // namespace discordpp

#endif