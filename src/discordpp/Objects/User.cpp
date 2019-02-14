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

namespace discordpp
{


  User::User(){}
  User::~User(){}
  User::User(const Json::Value& user)
  {
        discriminator = user["user"]["discriminator"].asString();
        isBot = user["user"]["bot"].asBool();
        userId = user["user"]["id"];
        userName = user["user"]["username"].asString();
  }

}