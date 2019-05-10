/**
 * @file PresenceUpdateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-03 03:00
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PRESENCEUPDATEEVENT_HPP
#define PRESENCEUPDATEEVENT_HPP

#include "events/Event.hpp"

namespace discordpp{
    class PresenceUpdateEvent : public Event
    {
        using Event::Event;
        public:
        bool proc(const nlohmann::json& packet);
    };
}
#endif