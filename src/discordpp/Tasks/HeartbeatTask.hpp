/**
 * @file TestTask.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-17 12:36
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef HEARTBEATTASK_HPP
#define HEARTBEATTASK_HPP

#include <iostream>

#include "Task.hpp"

#include "nlohmann/json.hpp"
#include "Util/constants.hpp"

namespace discordpp
{

class Discordpp;

class HeartbeatTask : public Task
{
    public:
    HeartbeatTask(Discordpp* pDscpp, const int interval);

  private:
    Discordpp* m_dscpp;
    void proc();
};
} // namespace discordpp

#endif