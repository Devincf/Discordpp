/**
 * @file HeartbeatACKEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 03:43
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "HeartbeatACKEvent.hpp"
#include "Discordpp.hpp"

namespace discordpp
{
bool HeartbeatACKEvent::proc(const nlohmann::json &packet)
{
    DEBUG("ACK");
    if (m_dscpp->getCurrentBotState() == constants::Starting)
    {
        if (m_dscpp->getSessionId() == "")
        {
            //Send Verify
            m_dscpp->setCurrentBotState(constants::FirstHeartbeat);

            DEBUG("sending verify information");
            nlohmann::json payload;

            payload["op"] = constants::Identify;
            payload["d"]["token"] = m_dscpp->getToken();
            payload["d"]["properties"]["$os"] = "linux";
            payload["d"]["properties"]["$browser"] = "disco";
            payload["d"]["properties"]["$device"] = "disco";
            payload["d"]["compress"] = false;
            payload["d"]["large_threshold"] = 250;
            payload["d"]["shard"] = {0, 1};
            payload["d"]["presence"]["game"] = nullptr;
            payload["d"]["presence"]["status"] = "online";
            payload["d"]["presence"]["since"] = nullptr;
            payload["d"]["presence"]["afk"] = false;

            DEBUG("Sending Verify Payload");
            //DEBUG(payload.dump());
            m_dscpp->getGateway()->sendPayload(payload);
            m_dscpp->setCurrentBotState(constants::VerificationSent);
            m_dscpp->setLastHeartbeatACK(true);
            DEBUG("verify sent");
            return true;
        }else
        {
            //Reconnect
            m_dscpp->setCurrentBotState(constants::Starting);
            DEBUG("Sending Resume information");
            nlohmann::json payload;

            payload["op"] = constants::Resume;
            payload["d"]["token"] = m_dscpp->getToken();
            payload["d"]["session_id"] = m_dscpp->getSessionId();
            payload["d"]["seq"] = m_dscpp->getLastS();
            m_dscpp->getGateway()->sendPayload(payload);
            m_dscpp->setCurrentBotState(constants::VerificationSent);
            m_dscpp->setLastHeartbeatACK(true);
        }
    }
    else
    {
        if (!m_dscpp->getLastHeartbeatACK())
        {
            m_dscpp->setLastHeartbeatACK(true);
        }
        else
        {
            DEBUG("[ERROR] HEARTBEAT ACK RECIEVED BUT NOT WAITING FOR ONE");
            return false;
        }
    }
    return true;
}
} // namespace discordpp