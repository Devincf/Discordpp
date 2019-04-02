/**
 * @file PingCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-02 03:08
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PINGCOMMAND_HPP
#define PINGCOMMAND_HPP

#include "Command.hpp"
namespace discordpp
{
class PingCommand : public Command
{
    using Command::Command;

  public:
    bool proc(const nlohmann::json&);
};
} // namespace discordpp

#endif