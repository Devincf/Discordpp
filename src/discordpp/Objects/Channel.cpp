/**
 * @file Channel.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-14 06:11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Channel.hpp"
#include "../constants.hpp"

namespace discordpp
{
Channel::Channel()
{
}
Channel::~Channel()
{
}
Channel::Channel(const Json::Value& payload)
{
    DEBUG(payload.toStyledString());
    DEBUG("____________________________________________________________");
}

} // namespace discordpp