/**
 * @file DistributeMoneyTask.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 08:51
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DISTRIBUTEMONEYTASK_HPP
#define DISTRIBUTEMONEYTASK_HPP

#include <iostream>

#include "Task.hpp"

#include "nlohmann/json.hpp"
#include "util/constants.hpp"
#include "util/Snowflake.hpp"

namespace discordpp
{
static const Snowflake guildID = {439065048628068363};
static const Snowflake channelID = {439065048628068365};

class Discordpp;

class DistributeMoneyTask : public Task
{
    public:
    DistributeMoneyTask(Discordpp* pDscpp, const int interval);

  private:

    Discordpp* m_dscpp;
    void proc();
};
} // namespace discordpp

#endif