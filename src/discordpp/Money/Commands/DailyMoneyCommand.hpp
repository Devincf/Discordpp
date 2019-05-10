/**
 * @file DailyMoneyCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 03:02
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef DAILYMONEYCOMMAND_HPP
#define DAILYMONEYCOMMAND_HPP

#include "Commands/Command.hpp"
namespace discordpp
{
class DailyMoneyCommand : public Command
{
    using Command::Command;

  public:
    bool proc(const nlohmann::json&);
};
} // namespace discordpp

#endif