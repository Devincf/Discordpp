/**
 * @file ReadyEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 05:47
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "ReadyEvent.hpp"
#include "Discordpp.hpp"

namespace discordpp
{
bool ReadyEvent::proc(const nlohmann::json &packet)
{
    //DEBUG("Ready Event proc!");
    DEBUG(packet.dump(2));
    m_dscpp->setSessionId(packet["d"]["session_id"].get<std::string>());
    return true;
}
} // namespace discordpp