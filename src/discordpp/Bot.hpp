/**
 * @file Bot.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief Contains the main Bot class
 * @version 0.1
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BOT_HPP
#define BOT_HPP

#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include <map>

#include "Gateway.hpp"
#include "objects/Guild.hpp"
#include "util/constants.hpp"

#include "util/Singleton.hpp"
#include "Managers/UserManager.hpp"

using boost::asio::io_service;
using boost::asio::steady_timer;

namespace discordpp
{

/**
 * @brief Bot class with which one is able to create 
 *        own discord bots.
 */
class Bot
{
public:
  /**
   * @brief Construct a new Bot object
   * @param token of the bot
   */
  Bot(const std::string &token);
  /**
   * @brief Destroy the Bot object
   */
  ~Bot();
  /**
   * @brief Triggered after the gateway recieves an event through the websocket
   * @param payload the content of the event
   */
  void eventProc(const nlohmann::json &payload);

private:
  /**
   * @brief Sends a heartbeat event to the gateway
   */
  void heartbeat();
  /**
   * @brief Triggered when recieving the HELLO event from the gateway
   * @param payload containing the heartbeat interval
   */
  void onHello(const nlohmann::json &payload);
  /**
   * @brief Triggered when the Bot recieves a Heartbeat ACK event
   */
  void onHeartbeatACK();

  void processMessage();//todo: add docs
  /**
   * @brief Used to process different dispatch events
   * @param payload containing all the event data
   */    
  void processDispatchEvent(const nlohmann::json &payload);
  /**
   * @brief Function that sends the VERIFY payload to the gateway to verify the connection
   */
  void verifyBot();

  /**
   * @brief The last s value for heartbeats
   */
  int m_lastS;
  /**
   * @brief Whether the Bot recieved a heartbeat ACK event for the last heartbeat sent
   */
  bool m_lastHeartbeatACK;
  /**
   * @brief Bot token
   */
  std::string m_token;
  /**
   * @brief Current session id used to reconnect to the gateway
   */
  std::string m_currentSessionId;
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
  /**
   * @brief The current status of the bot. See Util/constants.hpp for more
   */
  constants::BotState m_currentState;
  /**
   * @brief The bot user object
   * Todo: integrate into globalUsers maybe by only saving the bot snowflake
   */
  User m_botUser;
  /**
   * @brief Map containing all players on all guilds the bot is connected to.
   *        So the Bot doesnt have to save the same user in different guilds twice
   */
  //std::map<Snowflake, std::shared_ptr<User>> m_globalUsers;
  /**
   * @brief Map of all the guilds the bot is in
   */
  std::map<Snowflake,Guild> m_guilds;
  /**
   * @brief Gateway object used for communicating with the discord gateway
   */
  /**
   * @brief Map of all the private Channels the bot is in
   */
  std::map<Snowflake,Channel> m_dmChannels;


  //Singleton<UserManager> m_userManager;

  Gateway m_gateway;
};
} // namespace discordpp

#endif