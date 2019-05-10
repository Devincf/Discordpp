/**
 * @file PresenceUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-03 03:02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "PresenceUpdateEvent.hpp"

namespace discordpp
{
    bool PresenceUpdateEvent::proc(const nlohmann::json& packet)
    {
        return true;
    }
}