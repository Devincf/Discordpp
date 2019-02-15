/**
 * @file User.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "User.hpp"

#include "../constants.hpp"
#include "../jsonutils.hpp"

namespace discordpp
{

User::User() {}
User::~User() {}
User::User(const nlohmann::json &user, bool hello)
{
  DEBUG(user.dump(2));
  if (hello)
  {
    discriminator = user["discriminator"].get<std::string>();
    isBot = user["bot"].get<bool>();
    userId = user["id"];
    userName = user["username"].get<std::string>();
  }
  else
  {
    userId = user["user"]["id"];
    userName = user["user"]["username"].get<std::string>();
    discriminator = user["user"]["discriminator"].get<std::string>();
    isBot = util::tryGetJson<bool>("bot", user["user"]);
  }
}

} // namespace discordpp