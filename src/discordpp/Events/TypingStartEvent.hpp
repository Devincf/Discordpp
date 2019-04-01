/**
 * @file TypingStartEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-31 01:39
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TYPINGSTARTEVENT_HPP
#define TYPINGSTARTEVENT_HPP

#include "Event.hpp"

namespace discordpp
{
class TypingStartEvent : public Event
{
    using Event::Event;

  public:
    bool proc(const nlohmann::json &);
};
} // namespace discordpp

#endif