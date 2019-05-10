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
        Role::Role(const nlohmann::json& role)
        {
            id = role["id"];
            color = role["color"].get<int>();
            hoist = role["hoist"].get<bool>();
            managed = role["managed"].get<bool>();
            mentionable = role["mentionable"].get<bool>();
            name = role["name"].get<std::string>();
            permissions = role["permissions"].get<int>();
            position = role["position"].get<int>();
        }
}