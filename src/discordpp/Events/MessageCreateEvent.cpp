/**
 * @file MessageCreateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-31 01:38
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "MessageCreateEvent.hpp"

namespace discordpp
{
    bool MessageCreateEvent::proc(const nlohmann::json& packet)
    {
        DEBUG("MessageCreateProc");
        return true;
    }
}