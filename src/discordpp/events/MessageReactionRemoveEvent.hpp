/**
 * @file MessageReactionRemoveEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 08:07
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MESSAGEREACTIONREMOVEEVENT_HPP
#define MESSAGEREACTIONREMOVEEVENT_HPP


#include "events/Event.hpp"

namespace discordpp
{
class MessageReactionRemoveEvent : public Event
{
    using Event::Event;

  public:
    bool proc(const nlohmann::json &);
};
} // namespace discordpp

#endif