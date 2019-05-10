/**
 * @file PicartoNotifier.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-17 01:15
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DISBOARDBUMPER_HPP
#define DISBOARDBUMPER_HPP

#include "Tasks/Task.hpp"
#include "structs.hpp"
namespace discordpp{class Discordpp;}
class DisboardBumper : public discordpp::Task
{
    public:
    DisboardBumper(discordpp::Discordpp* pDsc);
    void proc();

    private:
    discordpp::Discordpp* m_dscpp;
};

#endif