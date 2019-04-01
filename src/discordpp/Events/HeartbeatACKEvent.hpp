/**
 * @file HeartbeatACKEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 03:42
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef HEARTBEATACKEVENT_HPP
#define HEARTBEATACKEVENT_HPP

#include "Event.hpp"

namespace discordpp{
    class HeartbeatACKEvent : public Event{
        using Event::Event;
        public:
        bool proc(const nlohmann::json&);
    };
}

#endif