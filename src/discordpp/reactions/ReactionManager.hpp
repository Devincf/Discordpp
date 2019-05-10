/**
 * @file ReactionManager.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 05:43
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef REACTIONMANAGER_HPP
#define REACTIONMANAGER_HPP

#include "util/Snowflake.hpp"
#include "ReactableMessage.hpp"

namespace discordpp
{
    class ReactionManager
    {
        public:
        ReactionManager();
        ~ReactionManager();

        int addReaction(ReactableMessage* msg);
        bool addReactableMessage(const Snowflake& id, const int reaction);
        bool removeReactableMessage(const Snowflake& id);
        bool isReactableMessage(const Snowflake& id);
        bool isReaction(const int id);
        std::shared_ptr<ReactableMessage> getReaction(const int id);
        std::shared_ptr<ReactableMessage> getReaction(const Snowflake& id);



        private:
        std::vector<std::shared_ptr<ReactableMessage>>  m_reactions;
        std::map<Snowflake, int> m_reactableMessages;
    };
}

#endif