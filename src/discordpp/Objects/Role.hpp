/**
 * @file Role.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief Contains a wrapper class for roles in discord
 * @version 1.0
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ROLE_HPP
#define ROLE_HPP

#include "Snowflake.hpp"

namespace discordpp
{
/**
 * @brief Wrapper class containing information about a certain role
 */
class Role
{
  public:
    /**
     * @brief Construct a new Role object
     */
    Role();
    /**
     * @brief Destroy the Role object
     */
    ~Role();
    /**
     * @brief Construct a new Role object using a json payload
     * @param payload the json data to construct the role
     */
    Role(const Json::Value &payload);
    /**
     * @brief The role id
     */
    Snowflake id;
    /**
     * @brief the role name
     */
    std::string name;
    /**
     * @brief The role color
     */
    int color;
    /**
     * @brief role pinned in userlist?
     */
    bool hoist;
    /**
     * @brief position of the role in the userlist
     */
    int position;
    /**
     * @brief permissions of the role
     */
    int permissions;
    /**
     * @brief managed by an integration?
     */
    bool managed;
    /**
     * @brief mentionable?
     */
    bool mentionable;
};
} // namespace discordpp

#endif