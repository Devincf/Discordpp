/**
 * @file main.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-01 02:24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Bot.hpp"

#include "Util/Timestamp.hpp"


int main()
{

    /*discordpp::util::Timestamp t1 = discordpp::util::fromUnixTimestamp("1550622594");
    discordpp::util::Timestamp t2 = discordpp::util::fromISO8601Timestamp("2019-02-20T00:29:56.162000+00:00");
    std::cout << t1.getUnixTime() << std::endl;
    std::cout << t2.getUnixTime() << std::endl;*/
    

    const std::string token = "NTM5ODIwNDYyMjg1Mzg5ODI0.DzH9tw.AYjoVQwUZJywz28L_nZP716FeEI";
    discordpp::Bot b{token};

    return 1;
}