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

#include "commands/Command.hpp"
namespace discordpp
{
class LeaderboardCommand : public Command
{
  const std::map<int, std::string> m_rankingEmojis = {{1,":one:"},{2,":two:"},{3,":three:"},{4,":four:"},{5,":five:"},{6,":six:"},{7,":seven:"},{8,":eight:"},{9,":nine:"}, {10,":keycap_ten:"}};
  using Command::Command;

  public:
    bool proc(const nlohmann::json&);
};
} // namespace discordpp

#endif