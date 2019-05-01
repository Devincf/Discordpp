/**
 * @file TwitchAPI.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-01 06:57
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "RestAPI.hpp"

namespace discordpp
{
class TwitchAPI : public RestAPI
{
  public:
    bool isOnline(const std::string& channelName);
    void setToken(const std::string &);

  private:
    std::string m_token;
};
} // namespace discordpp