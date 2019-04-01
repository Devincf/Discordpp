/**
 * @file DispatchEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 05:40
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "DispatchEvent.hpp"
#include "Core/Discordpp.hpp"
#include "ReadyEvent.hpp"
#include "GuildCreateEvent.hpp"
#include "ChannelCreateEvent.hpp"
#include "TypingStartEvent.hpp"
#include "MessageCreateEvent.hpp"


namespace discordpp
{
DispatchEvent::DispatchEvent(Discordpp *dscpp) : Event(dscpp)
{
    m_dispatchEvents["READY"] = std::unique_ptr<Event>(new ReadyEvent(dscpp));
    m_dispatchEvents["GUILD_CREATE"] = std::unique_ptr<Event>(new GuildCreateEvent(dscpp));
    m_dispatchEvents["CHANNEL_CREATE"] = std::unique_ptr<Event>(new ChannelCreateEvent(dscpp));
    m_dispatchEvents["TYPING_START"] = std::unique_ptr<Event>(new TypingStartEvent(dscpp));
    m_dispatchEvents["MESSAGE_CREATE"] = std::unique_ptr<Event>(new MessageCreateEvent(dscpp));
}

bool DispatchEvent::proc(const nlohmann::json &packet)
{
    //DEBUG("Dispatch Event recieved, distributing");
    auto it = m_dispatchEvents.find(packet["t"].get<std::string>());
    if (it != m_dispatchEvents.end())
    {
        return it->second->proc(packet);
    }else
    {
        DEBUG("Dispatch Event not found");
        return false;
    }
}
} // namespace discordpp