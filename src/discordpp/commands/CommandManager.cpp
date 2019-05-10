/**
 * @file CommandManager.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-02 01:06
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "CommandManager.hpp"

#include "util/constants.hpp"
#include "boost/algorithm/string.hpp"

namespace discordpp
{

bool CommandManager::addCommand(const std::string &cmdStr, Command *cmdPtr)
{
    return addCommand({0}, cmdStr, cmdPtr);
}
bool CommandManager::addCommand(Snowflake guildId, const std::string &cmdStr, Command *cmdPtr)
{

    auto guildit = m_commandMap.find(guildId);
    if (guildit == m_commandMap.end())
    {
        m_commandMap.insert({guildId, std::map<std::string,std::shared_ptr<Command>>()});
        m_commandMap[guildId].insert(std::make_pair(cmdStr, std::shared_ptr<Command>(cmdPtr)));
        return true;
    }
    else
    {
        auto ret = (*guildit).second.insert(std::make_pair(cmdStr, std::shared_ptr<Command>(cmdPtr)));
        if (!ret.second)
        {
            DEBUG("element already existed");
            return false;
        }
        return true;
    }
}

std::shared_ptr<Command> CommandManager::findCommand(const Snowflake & guild_id, const std::string & cmdStr)
{
    std::vector<std::string> split_cmdStr;
    boost::split(split_cmdStr, cmdStr, boost::is_any_of(" "));

    auto cmdit = m_commandMap[0].find(split_cmdStr[0]);
    if(cmdit != m_commandMap[0].end())
    {
        //return global command
        return cmdit->second;
    }else
    {
        auto guildit = m_commandMap.find(guild_id);
        if(guildit == m_commandMap.end())
        {
            //command not in global list and guild doesnt exist
            return nullptr;
        }else{
            cmdit = guildit->second.find(split_cmdStr[0]);
            if(cmdit != guildit->second.end())
            {
                //return guild local command
                return cmdit->second;
            }else{
                //command neither in global nor in guild list
                return nullptr;
            }
        }
    }
}

} // namespace discordpp