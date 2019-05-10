/**
 * @file HelloEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 03:28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef HELLOEVENT_HPP
#define HELLOEVENT_HPP



#include "events/Event.hpp"


namespace discordpp{
    class HelloEvent : public Event{
        using Event::Event;
        public:

        bool proc(const nlohmann::json&);
    };
}

#endif