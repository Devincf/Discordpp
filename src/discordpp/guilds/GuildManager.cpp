/**
 * @file GuildManager.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 11:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "GuildManager.hpp"

namespace discordpp
{
GuildManager::GuildManager() {}
GuildManager::~GuildManager() {}

bool GuildManager::addGuild(std::pair<const Snowflake &, std::shared_ptr<Guild>>guild)
{
    auto ret = m_guildMap.insert(guild);
    if (!ret.second)
    {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
        return false;
    }
    return true;
}
bool GuildManager::addGuild(const Snowflake & id, std::shared_ptr<Guild>guildptr)
{
    auto ret = m_guildMap.insert({id, guildptr});
    if (!ret.second)
    {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
        return false;
    }
    return true;
}

int GuildManager::amount() const
{
    return m_guildMap.size();
}

std::shared_ptr<Guild> GuildManager::findGuild(const Snowflake &id)
{
    auto it = m_guildMap.find(id);
    if (it != m_guildMap.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}
} // namespace discordpp