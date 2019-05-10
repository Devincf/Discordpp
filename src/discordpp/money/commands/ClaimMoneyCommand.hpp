/**
 * @file ClaimMoneyCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 01:31
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef CLAIMMONEYCOMMAND_HPP
#define CLAIMMONEYCOMMAND_HPP

#include "commands/Command.hpp"
namespace discordpp
{
class ClaimMoneyCommand : public Command
{
    using Command::Command;

  public:
    bool proc(const nlohmann::json&);
};
} // namespace discordpp

#endif