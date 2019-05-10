/**
 * @file StreamNotifier.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-01 07:06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef STREAMNOTIFIER_HPP
#define STREAMNOTIFIER_HPP

#include "tasks/Task.hpp"
#include "structs.hpp"

const std::string streamChannel = "301933844876230657";

namespace discordpp{class Discordpp;}
class StreamNotifier : public discordpp::Task
{
    public:
    StreamNotifier(discordpp::Discordpp* pDsc, std::map<std::string,std::vector<Channel>>* pChannels);
    void proc();

    private:
    discordpp::Discordpp* m_dscpp;
    std::map<std::string,std::vector<Channel>>* m_channels;
};

#endif