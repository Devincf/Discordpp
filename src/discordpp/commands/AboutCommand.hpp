/**
 * @file AboutCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-11 12:42
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef ABOUTCOMMAND_HPP
#define ABOUTCOMMAND_HPP

#include "Command.hpp"

namespace discordpp
{
    class AboutCommand : public Command
{
    using Command::Command;

  public:
    bool proc(const nlohmann::json&);
};
}

#endif