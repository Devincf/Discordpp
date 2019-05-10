/**
 * @file MessageReactionAddEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 03:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "MessageReactionAddEvent.hpp"
namespace discordpp
{
    bool MessageReactionAddEvent::proc(const nlohmann::json& packet)
    {
        
        DEBUG(packet.dump(2));
        return true;
    }
}