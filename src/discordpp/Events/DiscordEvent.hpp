#ifndef DISCORD_EVENT_HPP
#define DISCORD_EVENT_HPP

#include <functional>
#include <iostream>

#include "../constants.hpp"
#include "../libs/nlohmann/json.hpp"
#include "EventData.hpp"

namespace discordpp::event
{

class DiscordEvent
{
    public:
    DiscordEvent(){}

    virtual void eventProc()
    {
        DEBUG("Unknown Discord EventCall");
    }
};
}

#endif