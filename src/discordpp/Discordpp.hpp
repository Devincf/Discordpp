/**
 * @file Discordpp.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 03:28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DISCORDPP_HPP
#define DISCORDPP_HPP

#include <map>
#include <memory>
#include <thread>

#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "websocket/Gateway.hpp"
#include "events/Event.hpp"
#include "tasks/Task.hpp"

namespace discordpp
{
class Command;
class Discordpp
{
  public:
    Discordpp(const std::string &token);
    Discordpp();
    virtual ~Discordpp();

    constants::BotState getCurrentBotState();
    const std::string getToken();
    Gateway* getGateway();
    bool getLastHeartbeatACK();
    void setCurrentBotState(constants::BotState newState);
    void setLastHeartbeatACK(bool ack);
    void setSessionId(const std::string& sessid);
    bool startHeartbeat(const int interval);
    bool isInitialized();
    int getLastS();
    std::string getSessionId();
    virtual void setup() = 0;
  protected:
    void run();

    void addCommand(const std::string& cmdStr, Command* pCmd);
    void addTask(Task* pTask);
  private:
    std::string m_botToken;
    bool m_running;
    bool m_canStart;
    bool m_initialized;

    /**
    * @brief Whether the Bot recieved a heartbeat ACK event for the last heartbeat sent
    */
    bool m_lastHeartbeatACK;
    /**
    * @brief The last s value for heartbeats
    */
    int m_lastS;

    std::string m_sessionId;

    /**
    * @brief The current status of the bot. See Util/constants.hpp for more
    */
    constants::BotState m_currentState;
    /**
    * @brief The heartbeat interval that gets set after recieving the HELLO payload
    */
    std::chrono::milliseconds m_heartbeatInterval;
    /**
    * @brief IOService for the heartbeat timer
    */
    io_service m_ioservice;
    /**
    * @brief Heartbeat timer
    */
    steady_timer m_heartbeat_timer;

    Gateway m_gateway;

    boost::thread m_gatewayThread;

    std::map<int, std::unique_ptr<Event>> m_gatewayEvents;

    std::vector<std::unique_ptr<Task>> m_tasks;


    void registerEvents();
    void registerGlobalCommands();
    void heartbeat();
};
} // namespace discordpp

#endif