/**
 * @file TypingStartEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-31 01:40
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "TypingStartEvent.hpp"

namespace discordpp
{
    bool TypingStartEvent::proc(const nlohmann::json& packet)
    {
        //DEBUG("TypingStartProc");
        return true;
    }
}