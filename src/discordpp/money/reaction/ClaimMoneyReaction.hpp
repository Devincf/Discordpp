/**
 * @file ClaimMoneyReaction.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 05:31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CLAIMMONEYREACTION_HPP
#define CLAIMMONEYREACTION_HPP

#include "reactions/ReactableMessage.hpp"

namespace discordpp
{
    class ClaimMoneyReaction : public ReactableMessage
    {
        public:
        ClaimMoneyReaction();
        ~ClaimMoneyReaction();

        bool proc(const nlohmann::json& packet);
    };
}

#endif