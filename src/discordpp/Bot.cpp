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

#include "Util/jsonutils.hpp"

namespace discordpp
{
Bot::Bot(const std::string &token) : m_lastS(0), m_token(token), m_heartbeat_timer(m_ioservice, m_heartbeatInterval), m_currentState(constants::Starting), m_gateway()
{
    Singleton<UserManager>::create();
    m_guilds = std::map<Snowflake, Guild>();
    m_dmChannels = std::map<Snowflake, Channel>();
    //m_globalUsers = std::map<Snowflake, std::shared_ptr<User>>();

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
    Singleton<UserManager>::destroy();
    //disconnect Gateway and cleanup
}

void Bot::eventProc(const nlohmann::json &payload)
{
    if (!payload["s"].is_null())
    {
        m_lastS = payload["s"].get<int>();
    }
    switch (payload["op"].get<int>())
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
        //terminate and reconnect/resume
        DEBUG("[ERROR] NO HEARTBEAT ACK RECIEVED ERROR");
    }
    nlohmann::json payload;
    payload["op"] = constants::Heartbeat;
    payload["d"] = m_lastS;
    m_gateway.sendPayload(payload);
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

void Bot::onHello(const nlohmann::json &payload)
{
    m_heartbeatInterval = std::chrono::milliseconds{payload["d"]["heartbeat_interval"].get<int>()};
    m_heartbeat_timer.async_wait(boost::bind(&Bot::heartbeat, this));
    DEBUG("Starting Heartbeat Timer with an interval of " << payload["d"]["heartbeat_interval"].get<int>() << " seconds");
    boost::thread t(boost::bind(&boost::asio::io_service::run, &m_ioservice));
    t.detach();
    DEBUG("Detaching Heartbeat Thread");
}

void Bot::processDispatchEvent(const nlohmann::json &msg)
{
    std::string dispatchEvent = msg["t"].get<std::string>();
    nlohmann::json payload = msg["d"];
    if (dispatchEvent == "READY")
    {
        m_currentSessionId = payload["session_id"].get<std::string>();
        m_botUser = User(payload["user"], true);
        m_currentState = constants::VerificationAccepted;
    }
    else if (dispatchEvent == "GUILD_CREATE")
    {
        Guild g(payload);
        for (unsigned int i = 0; i < payload["members"].size(); i++)
        {
            nlohmann::json currentMember = payload["members"][i];
            Snowflake snowflake = util::tryGetSnowflake("id", currentMember["user"]);
            //std::map<Snowflake, std::shared_ptr<User>>::iterator it = m_globalUsers.find(snowflake);
            auto user = Singleton<UserManager>::get()->findUser(snowflake);
            if(user == nullptr){
                user = std::make_shared<User>(currentMember);
                Singleton<UserManager>::get()->addUser({snowflake,user});
            }
            g.addUser(user);
        }
        m_guilds.insert(std::make_pair(Snowflake(payload["id"]), g));
        DEBUG(g.name << " loaded with " << g.memberCount << " Members " << g.roles.size() << " roles and " << g.emojis.size() << " emojis");
    }
    else if (dispatchEvent == "TYPING_START")
    {
        bool dmMessage = false;
        Snowflake channel_id = payload["channel_id"];
        std::map<Snowflake, Guild>::iterator guild_it = m_guilds.find(payload["guild_id"]);
        if (guild_it == m_guilds.end())
        {
            std::map<Snowflake, Channel>::iterator dm_it = m_dmChannels.find(payload["channel_id"]);
            if (dm_it == m_dmChannels.end())
            {
                DEBUG("Unknown guild and Channel in TYPING_START event");
                DEBUG(payload.dump(4));
                return;
            }
            dmMessage = true;
        }
        auto user = Singleton<UserManager>::get()->findUser(payload["user_id"]);
        if(user == nullptr){

            DEBUG("Unknown user started typing!");
            DEBUG(payload.dump(4));
        }else{
            if (dmMessage)
                DEBUG(payload["timestamp"] << " [" << channel_id << "] : " << user->userName << " started typing in dm");
            else
                DEBUG(payload["timestamp"] << "  " << guild_it->second.name << "[" << channel_id << "] : " << user->userName << " started typing");
        }
    }
    else if (dispatchEvent == "MESSAGE_CREATE")
    {
        bool dmMessage = false;
        Snowflake channel_id = payload["channel_id"];
        std::map<Snowflake, Guild>::iterator guild_it = m_guilds.find(payload["guild_id"]);
        if (guild_it == m_guilds.end())
        {
            std::map<Snowflake, Channel>::iterator dm_it = m_dmChannels.find(payload["channel_id"]);
            if (dm_it == m_dmChannels.end())
            {

                DEBUG("Unknown guild and Channel in MESSAGE_CREATE event");
                DEBUG(payload.dump(4));
                return;
            }
            dmMessage = true;
        }
        auto user = Singleton<UserManager>::get()->findUser(payload["author"]["id"]);
        if (user == nullptr)
        {
            DEBUG("Unknown user in MESSAGE_CREATE event");
            DEBUG(payload.dump(4));
            return;
        }
        else
        {
            Message m(payload);

            if (dmMessage)
                DEBUG(m.getTime().getISOTime() << "  "
                                               << "[" << m.getChannelId() << "] " << user->userName << " : " << m.getContent());
            else
                DEBUG(m.getTime().getISOTime() << "  " << guild_it->second.name << "[" << m.getChannelId() << "] " << user->userName << " : " << m.getContent());
        }
    }
    else if (dispatchEvent == "CHANNEL_CREATE")
    {
        DEBUG("asd");
        int type = payload["type"].get<int>();
        if (type == ChannelType::DM || type == ChannelType::GROUP_DM)
        {
            std::map<Snowflake, Channel>::iterator dmit = m_dmChannels.find(payload["id"]);
            if (dmit == m_dmChannels.end())
            {
                Channel c(payload);
                m_dmChannels.insert(std::make_pair(payload["id"], c));
                DEBUG("Added channel " << c.id);
            }
        }
    }
    else
    {
        DEBUG("Unknown Dispatch Event [ " << msg["t"].get<std::string>() << " ] encountered");
        DEBUG(msg["d"].dump(4));
    }
} // namespace discordpp

void Bot::verifyBot()
{
    DEBUG("verify");
    nlohmann::json payload;

    payload["op"] = constants::Identify;
    payload["d"]["token"] = m_token;
    payload["d"]["properties"]["$os"] = "linux";
    payload["d"]["properties"]["$browser"] = "disco";
    payload["d"]["properties"]["$device"] = "disco";
    payload["d"]["compress"] = false;
    payload["d"]["large_threshold"] = 250;
    payload["d"]["shard"] = {0, 1};
    payload["d"]["presence"]["game"] = nullptr;
    payload["d"]["presence"]["status"] = "online";
    payload["d"]["presence"]["since"] = nullptr;
    payload["d"]["presence"]["afk"] = false;

    DEBUG("Sending Verify Payload");
    //DEBUG(payload.dump());
    nlohmann::json json;
    json["op"] = 2;
    m_gateway.sendPayload(payload);
    m_currentState = constants::VerificationSent;
    DEBUG("verify complete");
}

} // namespace discordpp