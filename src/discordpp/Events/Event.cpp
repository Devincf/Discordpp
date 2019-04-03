/**
 * @file Event.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 03:28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Event.hpp"

#include "Discordpp.hpp"

namespace discordpp{
    Event::~Event(){}

    Event::Event(Discordpp* dscpp): m_dscpp(dscpp){}
}