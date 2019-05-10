/**
 * @file TestTask.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-17 12:36
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "HeartbeatTask.hpp"

#include "Discordpp.hpp"

namespace discordpp
{
    HeartbeatTask::HeartbeatTask(Discordpp* pDscpp, const int interval) : Task(interval)
    {
        m_instantProc = true;
        m_dscpp = pDscpp;
    }

    void HeartbeatTask::proc()
    {
        if (!m_dscpp->getLastHeartbeatACK() && m_dscpp->getCurrentBotState() != constants::Starting)
        {   //Todo: Add ACK Check
            //terminate and reconnect/resume
            DEBUG("[ERROR] NO HEARTBEAT ACK RECIEVED ERROR");
        }
        nlohmann::json payload;
        payload["op"] = constants::Heartbeat;
        payload["d"] = m_dscpp->getLastS();
        m_dscpp->getGateway()->sendPayload(payload);
        m_dscpp->setLastHeartbeatACK(false);
        DEBUG("HEARTBEAT");
        this->resetTimer();
    }
}
