/**
 * @file Guild.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief Contains a wrapper class for Guild objects
 * @version 0.9
 * @date 2019-02-01 02:24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILD_HPP
#define GUILD_HPP

#include <vector>
#include <memory>

#include "Emoji.hpp"
#include "Role.hpp"
#include "User.hpp"
#include "Channel.hpp"

namespace discordpp
{
/**
 * @brief Wrapper class for guilds
 * See https://discordapp.com/developers/docs/resources/guild#guild-object
 */
class Guild
{
public:
  /**
   * @brief Construct a new Guild object
   */
  Guild();
  /**
   * @brief Destroy the Guild object
   */
  ~Guild();

  /**
   * @brief Construct a new Guild object
   * @param payload the payload to use to construct the Guild object
   * @param is this Guild being constructed from a GUILD_CREATE event
   */
  Guild(const nlohmann::json &payload, bool guildCreate = true);

  /**
   * @brief Manually adds a User to the Guild. This should always be called after first checking the global user map.
   * @param user The shared_ptr of the User that should be added to the Guild
   */
  void addUser(std::shared_ptr<User> user);

  /**
   * @brief The Guild id
   */
  Snowflake id;
  /**
   * @brief The Guild name
   */
  std::string name;
  /**
   * @brief The Guild icon-hash           Todo: Implement?
   */
  std::string icon;
  /**
   * @brief The Guild splash-hash         Todo: Implement?
   */
  std::string splash;
  /**
   * @brief Whether or not the user is the owner of the guild
   */
  bool owner;
  /**
   * @brief The id of the Guild owner
   */
  Snowflake ownerId;
  /**
   * @brief The users permission within the Guild
   */
  int permissions;
  /**
   * @brief Voice region of the Guild
   */
  std::string region;
  /**
   * @brief Id of afk channel
   */
  Snowflake afkChannelId;
  /**
   * @brief Afk timeout in seconds
   */
  int afkTimeout;
  /**
   * @brief Guild embeddable?
   */
  bool embedEnabled;
  /**
   * @brief Embed invite channel id
   */
  Snowflake embedChannelId;
  /**
   * @brief Required verification level
   */
  int verificationLevel;
  /**
   * @brief Default message notification level
   */
  int defaultMessageNotifications;
  /**
   * @brief Explicit content filter level
   */
  int explicitContentFilter;
  /**
   * @brief Vector of all available roles within the Guild
   */
  std::vector<Role> roles;
  /**
   * @brief Vector of all the available emojis within the Guild
   */
  std::vector<Emoji> emojis;
  /**
   * @brief Vector of all the available features within the Guild
   */
  std::vector<std::string> features;
  /**
   * @brief Required MFA level for the guild
   * See https://discordapp.com/developers/docs/resources/guild#guild-object-mfa-level
   */
  int mfaLevel;
  /**
   * @brief Application id of the guild creator if it is bot-created
   */
  Snowflake applicationId;
  /**
   * @brief Server widget enabled?
   */
  bool widgetEnabled;
  /**
   * @brief Server widget channel id
   */
  Snowflake widgetChannelId;
  /**
   * @brief System message channel id
   */
  Snowflake systemChannelId;
  /**
   * @brief When the guild was joined at
   */
  std::string joinedAt; //ISO8601 timestamp
  /**
   * @brief Large guild?
   */
  bool large;
  /**
   * @brief Unavailable?
   */
  bool unavailable;
  /**
   * @brief Total amount of members in the Guild
   */
  int memberCount;
  /**
   * @brief Vector of shared_ptr of all the users in the Guild
   */
  std::vector<std::shared_ptr<User>> members;

  /**
     * @brief vector of all the channels within the guild
     */
  std::vector<Channel> channels;

  //Todo: add voice states,channels,presences
  //Todo: Create own timestamp format
};
} // namespace discordpp

#endif