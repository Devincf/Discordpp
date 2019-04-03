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
#include "Discordpp.hpp"


int main()
{

    const std::string token1 = "NTM5ODIwNDYyMjg1Mzg5ODI0.DzH9tw.AYjoVQwUZJywz28L_nZP716FeEI"; //Lumi Test 3
    const std::string token2 = "NDQ0NjQ4Mzc4MTk5MDQ4MjE0.XKJSAg.GxJtz6y-7fRABPG-HZYN7ZnM1UQ"; // Lumi Bot
    //discordpp::Bot b{token};
    discordpp::Discordpp dsc{token2};
    dsc.run();

    return 1;
}