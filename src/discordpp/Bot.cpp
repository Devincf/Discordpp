/**
 * @file Bot.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Bot.hpp"

namespace discordpp
{
Bot::Bot(const std::string &token) : m_lastS(0), m_token(token), m_heartbeat_timer(m_ioservice, m_heartbeatInterval), m_currentState(constants::Starting), m_gateway(this)
{
    try
    {
        m_gateway.connect();
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

Bot::~Bot()
{
    //disconnect Gateway and cleanup
}

void Bot::eventProc(const Json::Value &payload)
{
    if (payload["s"] != Json::Value::null)
    {
        m_lastS = payload["s"].asInt();
    }

    switch (payload["op"].asInt())
    {
    case constants::Dispatch:
        processDispatchEvent(payload);
        break;
    case constants::Hello:
        onHello(payload);
        break;
    case constants::HeartbeatACK:
        onHeartbeatACK();
        break;
    }
}

void Bot::heartbeat()
{
    if (!m_lastHeartbeatACK && m_currentState != constants::Starting)
    { //Todo: Add ACK Check
        DEBUG("[ERROR] NO HEARTBEAT ACK RECIEVED ERROR");
    }
    DEBUG("Heartbeat");
    Json::Value payload;
    payload["op"] = constants::Heartbeat;
    payload["d"] = m_lastS;
    m_gateway.getEndpoint().send(m_gateway.getHandle(), payload.toStyledString(), websocketpp::frame::opcode::text);
    m_heartbeat_timer.expires_at(m_heartbeat_timer.expires_at() + m_heartbeatInterval);
    m_heartbeat_timer.async_wait(boost::bind(&Bot::heartbeat, this));
    m_lastHeartbeatACK = false;
}

void Bot::onHeartbeatACK()
{
    if (m_currentState == constants::Starting)
    {
        m_currentState = constants::FirstHeartbeat;
        verifyBot();
    }
    else
    {
        if (!m_lastHeartbeatACK)
            m_lastHeartbeatACK = true;
        else
            DEBUG("[ERROR] HEARTBEAT ACK RECIEVED BUT NOT WAITING FOR ONE");
    }
}

void Bot::onHello(const Json::Value &payload)
{
    m_heartbeatInterval = std::chrono::milliseconds{payload["d"]["heartbeat_interval"].asInt()};
    m_heartbeat_timer.async_wait(boost::bind(&Bot::heartbeat, this));
    DEBUG("Starting Heartbeat Timer with an interval of " << payload["d"]["heartbeat_interval"].asInt() << " seconds");
    boost::thread t(boost::bind(&boost::asio::io_service::run, &m_ioservice));
    t.detach();
    DEBUG("Detaching Heartbeat Thread");
}

void Bot::processDispatchEvent(const Json::Value &msg)
{
    std::string dispatchEvent = msg["t"].asString();
    Json::Value payload = msg["d"];
    if (dispatchEvent == "READY")
    {
        m_currentSessionId = payload["session_id"].asString();
        m_botUser = User(payload["user"]);
        m_currentState = constants::VerificationAccepted;
    }
    else if (dispatchEvent == "GUILD_CREATE")
    {
        Guild g(payload);
        for (unsigned int i = 0; i < payload["members"].size(); i++)
        {
            Json::Value currentMember = payload["members"][i];
            Snowflake snowflake = currentMember["user"]["id"];
            std::map<Snowflake, std::shared_ptr<User>>::iterator it = m_globalUsers.find(snowflake);
            if (it != m_globalUsers.end())
            {
                g.addUser(it->second);
            }
            else
            {
                std::shared_ptr<User> u = std::make_shared<User>(currentMember);
                m_globalUsers.insert(std::make_pair(snowflake, u));
                g.addUser(u);
            }
        }
        m_guilds.insert(std::make_pair(Snowflake(payload["id"]), g));
        DEBUG(g.name << " loaded with " << g.memberCount << " Members " << g.roles.size() << " roles and " << g.emojis.size() << " emojis");
    }
    else if (dispatchEvent == "TYPING_START")
    {
        Snowflake channel_id = payload["channel_id"];
        std::map<Snowflake, Guild>::iterator guild_it = m_guilds.find(Snowflake(payload["guild_id"]));
        if (guild_it == m_guilds.end())
        {
            DEBUG("Unknown guild in MESSAGE_CREATE event");
            DEBUG(payload.toStyledString());
            return;
        }
        std::map<Snowflake, std::shared_ptr<User>>::iterator it = m_globalUsers.find(Snowflake(payload["user_id"]));
        if (it == m_globalUsers.end())
        {
            DEBUG("Unknown user started typing!");
            DEBUG(payload.toStyledString());
        }
        else
        {
            DEBUG(payload["timestamp"] << "  " << guild_it->second.name << "[" << channel_id << "] : " << it->second->userName << " started typing");
        }
    }
    else if (dispatchEvent == "MESSAGE_CREATE")
    {
        Snowflake channel_id = payload["channel_id"];
        std::map<Snowflake, Guild>::iterator guild_it = m_guilds.find(Snowflake(payload["guild_id"]));
        if (guild_it == m_guilds.end())
        {
            DEBUG("Unknown guild in MESSAGE_CREATE event");
            DEBUG(payload.toStyledString());
            return;
        }
        std::map<Snowflake, std::shared_ptr<User>>::iterator it = m_globalUsers.find(Snowflake(payload["author"]["id"]));
        if (it == m_globalUsers.end())
        {
            DEBUG("Unknown user in MESSAGE_CREATE event");
            DEBUG(payload.toStyledString());
            return;
        }
        else
        {
            DEBUG(payload["timestamp"] << "  " << guild_it->second.name << "[" << channel_id << "] " << it->second->userName << " : " << payload["content"].asString());
        }
    }
    else if (dispatchEvent == "CHANNEL_CREATE")
    {
        int type = payload["type"].asInt();
        if (type == ChannelType::DM || type == ChannelType::GROUP_DM)
        {
            
        }
    }
    else
    {
        DEBUG("Unknown Dispatch Event [ " << msg["t"].asString() << " ] encountered");
        DEBUG(msg["d"].toStyledString());
    }
}

void Bot::verifyBot()
{
    Json::Value payload, shard;
    payload["op"] = constants::Identify;
    payload["d"]["token"] = m_token;
    payload["d"]["properties"]["$os"] = "linux";
    payload["d"]["properties"]["$browser"] = "disco";
    payload["d"]["properties"]["$device"] = "disco";
    payload["d"]["compress"] = false;
    payload["d"]["large_threshold"] = 250;
    shard.append(0);
    shard.append(1);
    payload["d"]["shard"] = shard;
    payload["d"]["presence"]["game"] = Json::Value::null;
    payload["d"]["presence"]["status"] = "online";
    payload["d"]["presence"]["since"] = Json::Value::null;
    payload["d"]["presence"]["afk"] = false;

    DEBUG("Sending Verify Payload");
    m_gateway.sendPayload(payload);
    m_currentState = constants::VerificationSent;
}

} // namespace discordpp