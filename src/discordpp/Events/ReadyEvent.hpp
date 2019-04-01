/**
 * @file ReadyEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 05:45
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef READYEVENT_HPP
#define READYEVENT_HPP
#include "Event.hpp"

namespace discordpp{
    class ReadyEvent:public Event{
        using Event::Event;
        public:
        bool proc(const nlohmann::json&); 
    };
}

#endif