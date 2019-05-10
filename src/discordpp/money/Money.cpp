/**
 * @file Money.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-09 07:49
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Money.hpp"

namespace discordpp
{

        Money::Money():Money(0)
        {
        }

        Money::Money(unsigned long long val):m_value(val)
        {
        }

        Money::~Money()
        {

        }

        unsigned long long Money::get() const{return m_value;}
}