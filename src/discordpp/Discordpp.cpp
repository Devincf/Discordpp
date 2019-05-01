/**
 * @file Discordpp.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 03:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Discordpp.hpp"

#include "Util/constants.hpp"
#include "Events/EventIncludes.hpp"
#include "Commands/CommandIncludes.hpp"
#include "Util/Singleton.hpp"

#include "Core/Rest/DiscordAPI.hpp"
#include "Core/Rest/PicartoAPI.hpp"
#include "Core/Rest/TwitchAPI.hpp"

#include "Core/Databases/SQLiteDatabase.hpp"

#include "Managers/UserManager.hpp"
#include "Managers/GuildManager.hpp"
#include "Managers/CommandManager.hpp"

#include "Tasks/HeartbeatTask.hpp"

namespace discordpp
{
Discordpp::Discordpp(const std::string &token) : m_botToken(token), m_running(false), m_currentState(constants::Starting), m_heartbeat_timer(m_ioservice, m_heartbeatInterval), m_gateway()
{
    Singleton<UserManager>::create();
    Singleton<GuildManager>::create();
    Singleton<CommandManager>::create();

    Singleton<DiscordAPI>::create();
    Singleton<DiscordAPI>::get()->setToken(token);

    Singleton<PicartoAPI>::create();
    Singleton<PicartoAPI>::get()->setToken("CGoghj4k1RXZlWaaJrQdKIMe");

    Singleton<TwitchAPI>::create();
    Singleton<TwitchAPI>::get()->setToken("6mi2i543yic56qlee3fgdwor0l1bx7");

    Singleton<SQLiteDatabase>::create();
    //DEBUG(Singleton<PicartoAPI>::get()->getChannelInfo("Kiraki").dump(2));

    registerEvents();
    registerGlobalCommands();
    try
    {
        m_gatewayThread = boost::thread(boost::bind(&Gateway::connect, &m_gateway));
        m_canStart = true;
    }
    catch (websocketpp::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "other exception" << std::endl;
    }
}
Discordpp::Discordpp() : m_heartbeat_timer(m_ioservice, m_heartbeatInterval)
{
    std::cerr << "Please enter a valid botToken" << std::endl;
    m_canStart = false;
}
Discordpp::~Discordpp()
{
    Singleton<SQLiteDatabase>::destroy();
    Singleton<TwitchAPI>::destroy();
    Singleton<PicartoAPI>::destroy();
    Singleton<DiscordAPI>::destroy();
    Singleton<CommandManager>::destroy();
    Singleton<GuildManager>::destroy();
    Singleton<UserManager>::destroy();
}

void Discordpp::registerEvents()
{

    m_gatewayEvents[0] = std::unique_ptr<Event>(new DispatchEvent(this));
    m_gatewayEvents[10] = std::unique_ptr<Event>(new HelloEvent(this));
    m_gatewayEvents[11] = std::unique_ptr<Event>(new HeartbeatACKEvent(this));
}
void Discordpp::registerGlobalCommands()
{
    Singleton<CommandManager>::get()->addCommand("!ping", new PingCommand(this));
}

void Discordpp::addCommand(const std::string &cmdStr, Command *cmd)
{
    Singleton<CommandManager>::get()->addCommand(cmdStr, cmd);
}

void Discordpp::addTask(Task *pTask)
{
    pTask->start(m_ioservice);
    m_tasks.push_back(std::unique_ptr<Task>(pTask));
}

bool Discordpp::startHeartbeat(const int interval)
{
    DEBUG("Starting Heartbeat Timer with an interval of " << interval << " seconds");
    addTask(new HeartbeatTask(this,interval));
    return true;
}

void Discordpp::run()
{
    if (!m_canStart)
        return;

    DEBUG("Starting Discordpp");

    m_running = true;
    while (m_running)
    {
        std::unique_lock<std::mutex> lk(*m_gateway.getEventMutex());
        m_gateway.getEventCV()->wait(lk);
        nlohmann::json event = m_gateway.getNextEvent();
        auto eventit = m_gatewayEvents.find(event["op"].get<int>());
        if (eventit != m_gatewayEvents.end())
        {
            if (!eventit->second->proc(event))
            {
                DEBUG("Error occured during Event printing json data");
                DEBUG(event.dump(4));
            }
        }
        else
        {
            DEBUG("Event recieved with opcode " << event["op"].get<int>() << " but no suitable eventhandler found");
            DEBUG(event.dump(2));
        }
    }
}

constants::BotState Discordpp::getCurrentBotState() { return m_currentState; }
const std::string Discordpp::getToken() { return m_botToken; }
Gateway *Discordpp::getGateway() { return &m_gateway; }
bool Discordpp::getLastHeartbeatACK() { return m_lastHeartbeatACK; }
bool Discordpp::isInitialized() { return m_initialized; }
void Discordpp::setCurrentBotState(constants::BotState newState) { m_currentState = newState; }
void Discordpp::setLastHeartbeatACK(bool val) { m_lastHeartbeatACK = val; }
int Discordpp::getLastS(){return m_lastS;}

} // namespace discordpp