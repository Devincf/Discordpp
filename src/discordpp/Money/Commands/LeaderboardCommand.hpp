/**
 * @file LeaderboardCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 02:22
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef LEADERBOARDCOMMAND_HPP
#define LEADERBOARDCOMMAND_HPP

#include "Commands/Command.hpp"
namespace discordpp
{
class LeaderboardCommand : public Command
{
    using Command::Command;

  public:
    bool proc(const nlohmann::json&);
};
} // namespace discordpp

#endif