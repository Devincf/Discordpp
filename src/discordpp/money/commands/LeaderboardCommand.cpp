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
        for(int i = 0;i<leaderboard.size();i++)
        {
            auto current = leaderboard.at(i);
            auto userptr = Singleton<UserManager>::get()->findUser(current.first);
            if(userptr != nullptr)
            {
                ss << m_rankingEmojis.at(i+1) << " **" << userptr->userName << "**      ( " << current.second << " )\n\n";
            }
            else
            {
                DEBUG("Couldnt find user with userid " << current.first);
            }
            
        }
        nlohmann::json json;
        //https://news.bitcoin.com/wp-content/uploads/2018/07/ranking-300x237.jpg

        nlohmann::json embed;
        embed["title"] = ":trophy:  Rankings";
        embed["description"] = ss.str();
        embed["thumbnail"]["url"] = "https://news.bitcoin.com/wp-content/uploads/2018/07/ranking-300x237.jpg";
        embed["color"] = 8388352;

        json["embed"] = embed;

        Singleton<DiscordAPI>::get()->sendMessageExtended(packet["d"]["channel_id"].get<std::string>(), json);
        return true;
    }
}

