/**
 * @file Emoji.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief Contains a wrapper class for Emoji objects
 * @version 0.9
 * @date 2019-02-01 08:18
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef EMOJI_HPP
#define EMOJI_HPP

#include "Snowflake.hpp"
#include "Users/User.hpp"

namespace discordpp
{
/**
* @brief Wrapper class for emojis
* See https://discordapp.com/developers/docs/resources/emoji
*/
class Emoji
{
  public:
    /**
    * @brief Construct a new Emoji object
    */
    Emoji();
    /**
    * @brief Destroy the Emoji object
    */
    ~Emoji();
    /**
    * @brief Construct a new Emoji object
    * @param payload The json payload to use when constructing the Emoji
    */
    Emoji(const nlohmann::json &payload);
    /**
    * @brief Id of the Emoji
    */
    Snowflake id;
    /**
    * @brief Name of the Emoji
    */
    std::string name;
    /**
    * @brief A container for all the role id's that can access this Emoji
    */
    std::vector<Snowflake> roles;
    /**
    * @brief User that created this Emoji
    */
    std::weak_ptr<User> creator; //Todo: Add real Userptr
    /**
    * @brief Whether this emoji must be wrapped in colons
    */
    bool requireColons;
    /**
    * @brief Whether this emoji is managed
    */
    bool managed;
    /**
    * @brief Whether this emoji is animated
    */
    bool animated;
};
} // namespace discordpp

#endif