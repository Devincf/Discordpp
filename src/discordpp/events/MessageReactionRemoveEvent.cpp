/**
 * @file MessageReactionRemoveEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 08:08
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "MessageReactionRemoveEvent.hpp"


namespace discordpp
{
bool MessageReactionRemoveEvent::proc(const nlohmann::json &packet)
{
    //DEBUG("MessageCreateProc");
    return true;
}
} // namespace discordpp