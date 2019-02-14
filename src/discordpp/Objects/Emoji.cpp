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

namespace discordpp
{
Emoji::Emoji() {}
Emoji::~Emoji() {}
Emoji::Emoji(const Json::Value &emoji)
{
    id = emoji["id"];
    name = emoji["name"].asString();
    roles = std::vector<Snowflake>();              //todo: init emoji roles
    username = emoji["user"]["username"].asString();
    requireColons = emoji["require_colons"].asBool();
    managed = emoji["managed"].asBool();
    animated = emoji["animated"].asBool();
}
} // namespace discordpp