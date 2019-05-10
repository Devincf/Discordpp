/**
 * @file Emoji.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-01 02:24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Emoji.hpp"
#include "util/constants.hpp"
#include "util/jsonutils.hpp"

#include "util/Singleton.hpp"
#include "users/UserManager.hpp"

namespace discordpp
{
Emoji::Emoji() {}
Emoji::~Emoji() {}
Emoji::Emoji(const nlohmann::json &emoji)
{
    //DEBUG(emoji.dump(2));
    id = emoji["id"];
    name = emoji["name"].get<std::string>();
    roles = std::vector<Snowflake>();
    if(emoji["roles"].size() > 0){
        for(auto role : emoji["roles"]){
            roles.push_back(emoji.get<std::string>());//Todo: test once I can create role specific emojis
        }
    }
    if(emoji.find("user") != emoji.end()){
        creator = Singleton<UserManager>::get()->findUser(util::tryGetSnowflake("username", emoji["user"]));
    }
    requireColons = util::tryGetJson<bool>("require_colons",emoji);
    managed = util::tryGetJson<bool>("managed",emoji);
    animated = util::tryGetJson<bool>("animated",emoji);
}
} // namespace discordpp