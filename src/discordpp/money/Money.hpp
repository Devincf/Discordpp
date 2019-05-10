/**
 * @file Money.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-09 07:49
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MONEY_HPP
#define MONEY_HPP

namespace discordpp
{
    class Money
    {
        public:
        Money();
        Money(unsigned long long val);
        ~Money();

        unsigned long long get() const;

        private:
        unsigned long long m_value;
    };
}

#endif