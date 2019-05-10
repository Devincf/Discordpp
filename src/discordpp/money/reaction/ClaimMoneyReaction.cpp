/**
 * @file ClaimMoneyReaction.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 05:32
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "ClaimMoneyReaction.hpp"
#include "util/constants.hpp"
#include "util/Singleton.hpp"
#include "rest/DiscordAPI.hpp"
#include "money/MoneyManager.hpp"
#include "users/UserManager.hpp"
#include "reactions/ReactionManager.hpp"

namespace discordpp
{
ClaimMoneyReaction::ClaimMoneyReaction() {}
ClaimMoneyReaction::~ClaimMoneyReaction() {}

bool ClaimMoneyReaction::proc(const nlohmann::json &packet)
{
    
    DEBUG("Claim money reaction proc");
    //DEBUG(packet.dump(2));
    nlohmann::json data = packet["d"];

    if(data["user_id"].get<std::string>() == "444648378199048214")
        return false;
    
    std::string emojiname = data["emoji"]["name"].get<std::string>();
        if (emojiname == constants::emoji::coffee)
        {
            //Singleton<DiscordAPI>::get()->sendMessage(data["channel_id"].get<std::string>(), "Reacted to message with emoji : " + emojiname);
            Snowflake userId = data["user_id"];
            Singleton<MoneyManager>::get()->addMoney(userId, 100);
            Singleton<DiscordAPI>::get()->sendMessage(data["channel_id"].get<std::string>(),
                                                      Singleton<UserManager>::get()->findUser(userId)->userName + " has claimed 100 coins");
            std::string msgId = data["message_id"].get<std::string>();
            Singleton<ReactionManager>::get()->removeReactableMessage(msgId);
            Singleton<DiscordAPI>::get()->deleteMessage(data["channel_id"].get<std::string>(), msgId);
                                                      

        }else if(emojiname == constants::emoji::pizza)
        {
            DEBUG("webhook test" << emojiname);
            //Singleton<DiscordAPI>::get()->webhookTest();
            //Singleton<DiscordAPI>::get()->embedTest();
        }
    return true;
}
} // namespace discordpp