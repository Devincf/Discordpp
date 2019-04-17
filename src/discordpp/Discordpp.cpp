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

#include "Core/Databases/SQLiteDatabase.hpp"

#include "Managers/UserManager.hpp"
#include "Managers/GuildManager.hpp"
#include "Managers/CommandManager.hpp"


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


void Discordpp::addCommand(const std::string& cmdStr, Command* cmd)
{
    Singleton<CommandManager>::get()->addCommand(cmdStr,cmd);
}

void Discordpp::heartbeat()
{
    if (!m_lastHeartbeatACK && m_currentState != constants::Starting)
    { //Todo: Add ACK Check
        //terminate and reconnect/resume
        DEBUG("[ERROR] NO HEARTBEAT ACK RECIEVED ERROR");
    }
    nlohmann::json payload;
    payload["op"] = constants::Heartbeat;
    payload["d"] = m_lastS;
    m_gateway.sendPayload(payload);
    m_heartbeat_timer.expires_at(m_heartbeat_timer.expires_at() + m_heartbeatInterval);
    m_heartbeat_timer.async_wait(boost::bind(&Discordpp::heartbeat, this));
    m_lastHeartbeatACK = false;
    DEBUG("HEARTBEAT");
}

bool Discordpp::startHeartbeat(const int interval)
{
    m_heartbeatInterval = std::chrono::milliseconds{interval};
    m_heartbeat_timer.async_wait(boost::bind(&Discordpp::heartbeat, this));
    DEBUG("Starting Heartbeat Timer with an interval of " << interval << " seconds");
    m_heartbeatThread = boost::thread(boost::bind(&boost::asio::io_service::run, &m_ioservice));
    DEBUG("Executing heartbeat timer in new thread");
    //t.detach();
    //DEBUG("Detaching Heartbeat Thread");
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
bool Discordpp::isInitialized(){return m_initialized;}
void Discordpp::setCurrentBotState(constants::BotState newState) { m_currentState = newState; }
void Discordpp::setLastHeartbeatACK(bool val) { m_lastHeartbeatACK = val; }

} // namespace discordpp