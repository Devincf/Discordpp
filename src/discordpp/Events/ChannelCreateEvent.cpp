/**
 * @file ChannelCreateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-31 01:41
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "ChannelCreateEvent.hpp"
namespace discordpp
{
    bool ChannelCreateEvent::proc(const nlohmann::json& packet)
    {
        //DEBUG("ChannelCreateProc");
        return true;
    }
}