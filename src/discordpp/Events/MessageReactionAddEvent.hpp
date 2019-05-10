/**
 * @file MessageReactionAddEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 03:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MESSAGEREACTIONADDEVENT_HPP
#define MESSAGEREACTIONADDEVENT_HPP

#include "Event.hpp"

namespace discordpp
{
class MessageReactionAddEvent : public Event
{
    using Event::Event;

  public:
    bool proc(const nlohmann::json &);
};
} // namespace discordpp

#endif