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

#include <string>
#include "util/Snowflake.hpp"
#include "util/Singleton.hpp"
#include "reactions/ReactionManager.hpp"

namespace discordpp
{
bool MessageReactionAddEvent::proc(const nlohmann::json &packet)
{
    //DEBUG(packet.dump(2));
    Snowflake id = packet["d"]["message_id"];
    if(Singleton<ReactionManager>::get()->isReactableMessage(id))
    {
        Singleton<ReactionManager>::get()->getReaction(id)->proc(packet);
    }
    return true;
}
} // namespace discordpp