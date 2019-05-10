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

#include <ctime>

#include "util/constants.hpp"
#include "util/jsonutils.hpp"
#include "util/Singleton.hpp"
#include "databases/SQLiteDatabase.hpp"

namespace discordpp
{

User::User() {}
User::~User() {}
User::User(const nlohmann::json &user, bool hello)
{
  std::string userIdString;
  if (hello)
  {
    discriminator = user["discriminator"].get<std::string>();
    isBot = user["bot"].get<bool>();
    userIdString = user["id"].get<std::string>();
    userId = userIdString;
    userName = user["username"].get<std::string>();
  }
  else
  {
    userIdString = user["user"]["id"].get<std::string>();
    userId = userIdString;
    userName = user["user"]["username"].get<std::string>();
    discriminator = user["user"]["discriminator"].get<std::string>();
    isBot = util::tryGetJson<bool>("bot", user["user"]);
  }
  
  if (Singleton<SQLiteDatabase>::get()->count("users where id = " + userIdString) == 0)
  {
    std::string temp = "INSERT INTO users (id,money,last_claimed) VALUES(" + userIdString + ",0," + std::to_string(std::time(0)) + ") ";
    Singleton<SQLiteDatabase>::get()->query(temp);
    DEBUG("Inserting " << userIdString << " into Database");
  }
}

} // namespace discordpp