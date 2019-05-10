/**
 * @file ReactionManager.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 05:43
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "ReactionManager.hpp"
#include "util/constants.hpp"

#include "money/reaction/ClaimMoneyReaction.hpp"

namespace discordpp
{
ReactionManager::ReactionManager() 
{
    addReaction(new ClaimMoneyReaction());
}
ReactionManager::~ReactionManager() {}

int ReactionManager::addReaction(ReactableMessage *msg)
{
    m_reactions.push_back(std::shared_ptr<ReactableMessage>(msg));
    return m_reactions.size() - 1;
}

bool ReactionManager::isReaction(const int id)
{
    return id >= 0 && id < m_reactions.size();
}

bool ReactionManager::addReactableMessage(const Snowflake &id, const int reaction)
{
    if (isReaction(reaction))
    {
        auto ret = m_reactableMessages.insert({id, reaction});
        return ret.second;
    }
    return false;
}


bool ReactionManager::removeReactableMessage(const Snowflake& id)
{
    auto reaction = m_reactableMessages.find(id);
    if(reaction == m_reactableMessages.end())
        return false;

    m_reactableMessages.erase(reaction);
    return true;
}

bool ReactionManager::isReactableMessage(const Snowflake &id)
{
    return m_reactableMessages.find(id) != m_reactableMessages.end();
}

std::shared_ptr<ReactableMessage> ReactionManager::getReaction(const int id)
{
    return m_reactions.at(id);
}

std::shared_ptr<ReactableMessage> ReactionManager::getReaction(const Snowflake &id)
{
    return m_reactions.at(m_reactableMessages[id]);
}

} // namespace discordpp