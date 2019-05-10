/**
 * @file PicartoNotifier.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-17 01:18
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "DisboardBumper.hpp"
#include "Discordpp.hpp"

#include "util/Singleton.hpp"
#include "databases/SQLiteDatabase.hpp"

#include <boost/date_time/posix_time/posix_time.hpp>

DisboardBumper::DisboardBumper(discordpp::Discordpp *pDsc) : Task(4000)
{
    m_dscpp = pDsc;

    auto uhm = discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("SELECT (next_bump) FROM disboard WHERE id=0").at(0);
    boost::posix_time::ptime pt = boost::posix_time::time_from_string(uhm["next_bump"]);

    

}
void DisboardBumper::proc()
{
    DEBUG("DisboardBumper proc");



    resetTimer();
}