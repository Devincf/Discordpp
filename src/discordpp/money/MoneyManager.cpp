/**
 * @file MoneyManager.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-09 01:33
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "MoneyManager.hpp"

#include <ctime>

#include "util/Singleton.hpp"
#include "util/constants.hpp"
#include "databases/SQLiteDatabase.hpp"

namespace discordpp
{
MoneyManager::MoneyManager()
{
    //read from database
}

MoneyManager::~MoneyManager()
{
    //write to database
}

bool MoneyManager::canClaim(const Snowflake &id)
{
    int count = discordpp::Singleton<discordpp::SQLiteDatabase>::get()->count("users WHERE id = " + std::to_string(id) + " and last_claimed+86400<=" + std::to_string(std::time(0)));
    if (count == 0)
    {
        DEBUG("Sorry cant claim it :(");
        return false;
    }
    else
    {
        return true;
    }
}

void MoneyManager::subMoney(const Snowflake &id, const long long amt)
{
    addMoney(id, -1 * amt);
}

void MoneyManager::addMoney(const Snowflake &id, const long long amt)
{
    auto current = fetchMoney(id);
    updateMoney(id, current + amt);
}

void MoneyManager::updateMoney(const Snowflake &id, const long long amt)
{
    discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("UPDATE users SET money=" + std::to_string(amt) + " where id=" + std::to_string(id));
}

const long long MoneyManager::fetchMoney(const Snowflake &id)
{
    auto result = discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query(
        "SELECT money FROM users WHERE id=" + std::to_string(id) + " limit 1");
    return std::stol(result.at(0)["money"]);
}
std::vector<std::pair<Snowflake,long long>> MoneyManager::getLeaderboard(const int limit)
{
    auto result = discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("SELECT id,money FROM users ORDER BY money DESC LIMIT " + std::to_string(limit));
    std::vector<std::pair<Snowflake,long long>> returnvec;
    for(auto i : result)
    {
        returnvec.push_back({Snowflake(i["id"]), std::stol(i["money"])});
    }

    return returnvec;
}

} // namespace discordpp