/**
 * @file MoneyManager.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-09 01:33
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MONEYMANAGER_HPP
#define MONEYMANAGER_HPP

#include "Money.hpp"
#include "util/Snowflake.hpp"
#include <vector>

namespace discordpp{
    class MoneyManager{
        public:
        MoneyManager();
        ~MoneyManager();

        bool canClaim(const Snowflake& id);

        void updateMoney(const Snowflake& id, const long long amt);
        void addMoney(const Snowflake& id,const long long amt);
        void subMoney(const Snowflake& id,const long long amt);
        std::vector<std::pair<Snowflake,long long>> getLeaderboard(const int limit);
        const long long fetchMoney(const Snowflake& id);
    };
}

#endif