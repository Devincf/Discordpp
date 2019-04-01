/**
 * @file HelloEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 03:28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "HelloEvent.hpp"

#include "Core/Discordpp.hpp"

namespace discordpp{

    bool HelloEvent::proc(const nlohmann::json& packet)
    {
        int heartbeat_interval = packet["d"]["heartbeat_interval"].get<int>();
        if(heartbeat_interval==0)return false;

        return m_dscpp->startHeartbeat(heartbeat_interval);
    }
}