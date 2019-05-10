/**
 * @file DispatchEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 05:37
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DISPATCHEVENT_HPP
#define DISPATCHEVENT_HPP

#include <map>
#include <memory>

#include "events/Event.hpp"

namespace discordpp{
    class DispatchEvent: public Event{
        using Event::Event;
        public:
        DispatchEvent(Discordpp*);
        bool proc(const nlohmann::json&);
        private:
        std::map<std::string,std::unique_ptr<Event>> m_dispatchEvents;
    };
}


#endif