/**
 * @file Command.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-02 02:59
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Command.hpp"

namespace discordpp
{
    Command::~Command(){}
    Command::Command(Discordpp* dscpp): m_dscpp(dscpp){}
} // namespace discordpp