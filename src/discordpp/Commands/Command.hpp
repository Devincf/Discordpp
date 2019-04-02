/**
 * @file Command.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-02 01:04
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "nlohmann/json.hpp"

namespace discordpp
{
    class Discordpp;

    class Command
    {
    public:
    Command(Discordpp*);
    virtual bool proc(const nlohmann::json&) = 0;
    virtual ~Command();


    protected:
    Discordpp* m_dscpp;
    };
}

#endif