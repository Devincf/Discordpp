/**
 * @file Role.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Role.hpp"

namespace discordpp
{

        Role::Role(){}
        Role::~Role(){}
        Role::Role(const Json::Value& role)
        {
            id = role["id"];
            color = role["color"].asInt();
            hoist = role["hoist"].asBool();
            managed = role["managed"].asBool();
            mentionable = role["mentionable"].asBool();
            name = role["name"].asString();
            permissions = role["permissions"].asInt();
            position = role["position"].asInt();
        }
}