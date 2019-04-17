/**
 * @file Task.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-17 12:14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Task.hpp"


#include "Util/constants.hpp"

namespace discordpp
{
Task::Task(){}
Task::~Task() 
{
    delete m_taskTimer;
    m_taskTimer = nullptr;
}

Task::Task(const int interval) : m_interval{interval}
{
    m_taskTimer = nullptr;
}

void Task::start(boost::asio::io_service& pIo)
{
    if(m_instantProc)
        m_taskTimer = new boost::asio::steady_timer(pIo,std::chrono::milliseconds{0});
    else
        m_taskTimer = new boost::asio::steady_timer(pIo,m_interval);
    m_taskTimer->async_wait(boost::bind(&Task::proc, this));
    DEBUG("Starting Task timer with an interval of " << m_interval.count() << " millisecconds");
    m_taskThread = boost::thread(boost::bind(&boost::asio::io_service::run, &pIo));
}

void Task::resetTimer()
{
    m_taskTimer->expires_at(m_taskTimer->expires_at() + m_interval);
    m_taskTimer->async_wait(boost::bind(&Task::proc, this));
}

boost::thread* Task::getThread()
{
    return &m_taskThread;
}
} // namespace discordpp
