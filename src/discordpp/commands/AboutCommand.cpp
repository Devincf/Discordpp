/**
 * @file AboutCommand.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-11 12:43
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "AboutCommand.hpp"

#include "util/constants.hpp"

#include "util/Singleton.hpp"
#include "rest/DiscordAPI.hpp"
#include "guilds/GuildManager.hpp"
#include "users/UserManager.hpp"

namespace discordpp
{
bool AboutCommand::proc(const nlohmann::json &packet)
{
    
    nlohmann::json json;
    nlohmann::json embed;
    embed["color"] = 15794175;
    embed["title"] = ":gem:  About ";
    embed["description"] = "• Developer : <@!142733073262444545>「**Luminous#6996**」\n"
                           "• Invite Link : To be added \n"
                           "• Current Version : Beta 1.0.0\n"
                           "• Developed in **C++** using [**Discord++**](https://github.com/Devincf/Discordpp)\n"
                           "• Active in : **"+std::to_string(Singleton<GuildManager>::get()->amount()) + "** servers with a total of **"+std::to_string(Singleton<UserManager>::get()->amount())+"** users";

    /*embed["fields"] = nlohmann::json::array();

    nlohmann::json field1;
    field1["name"] = "test field 1";
    field1["value"] = "test value 1";

    nlohmann::json field2;
    field2["name"] = "test field 2";
    field2["value"] = "test value 2";
    field2["inline"] = true;

    embed["fields"].push_back(field1);
    embed["fields"].push_back(field2);*/

    json["embed"] = embed;


    Singleton<DiscordAPI>::get()->sendMessageExtended(packet["d"]["channel_id"].get<std::string>(), json);
    return true;
}
} // namespace discordpp