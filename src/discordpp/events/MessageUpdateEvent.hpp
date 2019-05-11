/**
 * @file MessageUpdateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-11 01:12
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef MESSAGEUPDATEEVENT_HPP
#define MESSAGEUPDATEEVENT_HPP

#include "events/Event.hpp"

namespace discordpp
{
class MessageUpdateEvent : public Event
{
    using Event::Event;

  public:
    bool proc(const nlohmann::json &);
};
} // namespace discordpp


#endif