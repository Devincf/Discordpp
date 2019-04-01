/**
 * @file Event.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 03:28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef EVENT_HPP
#define EVENT_HPP

#include "nlohmann/json.hpp"
#include "Util/constants.hpp"

namespace discordpp{

class Discordpp;
class Event{
    public:
    Event(Discordpp*);
    virtual bool proc(const nlohmann::json&) = 0;
    virtual ~Event();



    protected:
    Discordpp* m_dscpp;
};
}

#endif