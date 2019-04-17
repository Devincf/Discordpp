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

#ifndef PICARTONOTIFIER_HPP
#define PICARTONOTIFIER_HPP

#include "Tasks/Task.hpp"
#include "structs.hpp"
namespace discordpp{class Discordpp;}
class PicartoNotifier : public discordpp::Task
{
    public:
    PicartoNotifier(discordpp::Discordpp* pDsc, std::vector<Channel>* pChannels);
    void proc();

    private:
    discordpp::Discordpp* m_dscpp;
    std::vector<Channel>* m_channels;
};

#endif