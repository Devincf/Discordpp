/**
 * @file Task.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-17 12:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TASK_HPP
#define TASK_HPP

#include <thread>

#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/thread.hpp>

namespace discordpp
{
    class Task
    {
        public:
        Task(const int interval);
        virtual ~Task();

        void start(boost::asio::io_service& pIo);
        void stop();


        boost::thread* getThread();
        protected:
        virtual void proc() = 0;
        void resetTimer();

        bool m_instantProc;
        private:
        Task();

        boost::asio::steady_timer* m_taskTimer;
        std::chrono::milliseconds m_interval;
        boost::thread m_taskThread;

    };
}


#endif