/**
 * @file Gateway.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief Implementation of a websocket connection to the discord gateway
 * @version 1.0
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef GATEWAY_HPP
#define GATEWAY_HPP

#include <queue>
#include <mutex>
#include <condition_variable>

#include <boost/bind.hpp>

#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>

#include "nlohmann/json.hpp"

typedef websocketpp::client<websocketpp::config::asio_tls_client> client;

using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

using boost::asio::io_service;
using boost::asio::steady_timer;

// pull out the type of messages sent by our config
typedef websocketpp::config::asio_tls_client::message_type::ptr message_ptr;
typedef websocketpp::lib::shared_ptr<boost::asio::ssl::context> context_ptr;
typedef client::connection_ptr connection_ptr;

namespace discordpp
{

enum ConnectionStatus
{
  WEBSOCKET_DISCONNECTED = 0,
  WEBSOCKET_CONNECTING = 1,
  WEBSOCKET_CONNECTED = 2,
  WEBSOCKET_RECONNECTING = 4
};

/**
 * 
 * @brief Class used for communicating with the discord gateway
 */
class Gateway
{
public:
  typedef Gateway type;
  typedef std::chrono::duration<int, std::micro> dur_type;

  /**
   * @brief Construct a new Gateway object
   * @param botptr a pointer to the bot object
   */
  Gateway();
  /**
   * @brief Destroy the Gateway object
   */
  ~Gateway();
  /**
   * @brief connects to the websocket
   */
  void connect();  
  
  /**
   * @brief connects to the websocket
   */
  void reconnect(const std::string& sessionid, int sequence);
  /**
   * @brief called when the socket connection is initialized
   * @param handle to the connection
   */
  void on_socket_init(const websocketpp::connection_hdl &handle);
  /**
   * @brief called when the tls gateway connection is initialized
   * @param handle to the connection
   * @return context_ptr for the tls connection
   */
  context_ptr on_tls_init(const websocketpp::connection_hdl &handle);
  /**
   * @brief called when the websocket connection failed
   * @param handle to the connection
   */
  void on_fail(const websocketpp::connection_hdl &handle);
  /**
   * @brief called when the websocket connection successfully opens up
   * @param handle to the connection
   */
  void on_open(const websocketpp::connection_hdl &handle);
  /**
   * @brief called when the gateway connection recieves a message from the server
   * @param handle to the connection
   * @param msgptr containing the message
   */
  void on_message(const websocketpp::connection_hdl &handle, const message_ptr &msgptr);
  /**
   * @brief called when the gateway connection gets closed
   * @param handle to the connection
   */
  void on_close(const websocketpp::connection_hdl &handle);
  /**
   * @brief Used to send json payloads to the gateway connection
   * @param payload 
   */
  void sendPayload(const nlohmann::json &payload);
  /**
   * @brief Get the gateway connection handle
   * @return websocketpp::connection_hdl& 
   */
  websocketpp::connection_hdl &getHandle();
  /**
   * @brief Get the endpoint connection
   * @return client& 
   */
  client &getEndpoint();

  /**
   * @brief checks whether the eventqueue is empty or not
   * @return true if eventqueue empty
   */
  bool hasEvent();
  /**
   * @brief Get the Next Event object
   * @return nlohmann::json 
   */
  nlohmann::json getNextEvent();


  std::mutex* getEventMutex();

  std::condition_variable* getEventCV();

  std::mutex* getConnectionMutex();

  std::condition_variable* getConnectionCV();


  ConnectionStatus getConnectionStatus();

private:
  /**
   * @brief client endpoint for the gateway connection
   */
  client m_endpoint;
  /**
   * @brief connection handle to the gateway
   */
  websocketpp::connection_hdl m_hdl;

  /**
   * @brief event queue
   */
  std::queue<nlohmann::json> m_eventQueue;

  std::mutex* m_eventQueueMutex;

  std::condition_variable* m_eventCV;

  std::mutex* m_connectionMutex;

  std::condition_variable* m_connectionCV;

  ConnectionStatus m_connectionStatus;
};
} // namespace discordpp

#endif