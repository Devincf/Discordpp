/**
 * @file ClaimMoneyCommand.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 01:31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "ClaimMoneyCommand.hpp"

#include "Util/constants.hpp"

#include "Util/Singleton.hpp"
#include "Money/MoneyManager.hpp"
#include "Users/UserManager.hpp"
#include "Core/Rest/DiscordAPI.hpp"

namespace discordpp
{
    bool ClaimMoneyCommand::proc(const nlohmann::json& packet)
    {
        Snowflake userId = packet["d"]["author"]["id"];
        if(Singleton<MoneyManager>::get()->canClaim(userId))
        {   
            //DEBUG(packet.dump(2));
            Singleton<MoneyManager>::get()->addMoney(userId, 100);
            Singleton<DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),

            Singleton<UserManager>::get()->findUser(userId)->userName + " has claimed 100 coins"
            );

        }else
        {
            Singleton<DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(),
            "Sorry but you can't claim coins again just yet"
            );
        }
        
        return true;
    }
}

