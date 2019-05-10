/**
 * @file LeaderboardCommand.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 02:22
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "LeaderboardCommand.hpp"

#include <sstream>

#include "util/constants.hpp"

#include "util/Singleton.hpp"
#include "money/MoneyManager.hpp"
#include "users/UserManager.hpp"
#include "rest/DiscordAPI.hpp"


namespace discordpp
{
    bool LeaderboardCommand::proc(const nlohmann::json& packet)
    {
        Snowflake userId = packet["d"]["author"]["id"];
        auto leaderboard = Singleton<MoneyManager>::get()->getLeaderboard(10);
        std::stringstream ss;
        for(auto i : leaderboard)
        {
            auto userptr = Singleton<UserManager>::get()->findUser(i.first);
            if(userptr != nullptr)
            {
                //DEBUG(userptr->userName << " : " << i.second);
                ss << userptr->userName << " : " << i.second << "\n";
            }
            else
            {
                DEBUG("Couldnt find user with userid " << i.first);
            }
            
        }
        Singleton<DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(), ss.str());
        return true;
    }
}

