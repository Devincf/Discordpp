/**
 * @file User.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.9
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <cstdint>
#include "objects/Snowflake.hpp"
#include "money/Money.hpp"

namespace discordpp
{

/**
 * @brief Class that holds user objects
 */
class User
{
public:
  /**
   * @brief Construct a new User object
   */
  User();
  /**
   * @brief Destroy the User object
   */
  ~User();
  /**
   * @brief Construct a new User object using a given json payload
   * @param payload json payload containing user information
   * @param if user is being created from the onHello event
   */
  User(const nlohmann::json &payload, bool hello=false);

  //Todo: Implement more User stuff
  /**
   * @brief User id
   */
  Snowflake userId;
  /**
   * @brief User name
   */
  std::string userName;
  /**
   * @brief User discriminator 
   */
  std::string discriminator;
  /**
   * @brief Whether the User is a bot or not
   */
  bool isBot;

  Money money;


  //Todo: implement other members
};
} // namespace discordpp

#endif