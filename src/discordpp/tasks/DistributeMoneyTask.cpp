/**
 * @file DistributeMoneyTask.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 08:51
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "DistributeMoneyTask.hpp"

#include "Discordpp.hpp"

#include "util/randomizer.hpp"
#include "util/Singleton.hpp"
#include "guilds/GuildManager.hpp"
#include "rest/DiscordAPI.hpp"
#include "reactions/ReactionManager.hpp"

namespace discordpp
{
DistributeMoneyTask::DistributeMoneyTask(Discordpp *pDscpp, const int interval) : Task(interval)
{
    m_instantProc = false;
    m_dscpp = pDscpp;
}

void DistributeMoneyTask::proc()
{
    /*
            get random channel in guild
            create message
            add message to reactables
        */
    if(m_dscpp->getCurrentBotState() != constants::Running)
    {
        this->resetTimer();
        return;
    }

    /* TO SELECT RANDOM CHANNEL: (item->second is random channel)
    auto channelmap = Singleton<GuildManager>::get()->findGuild(guildID)->channels;

    auto item = channelmap.begin();
    int r = randomizer::getRandom(channelmap.size());
    std::advance(item, r);

    */ 

    //DEBUG("Random number: " << r);
    //DEBUG("Random Channel: " << item->second.id << " - " << item->second.name);

    //auto channel = Singleton<GuildManager>::get()->findGuild(guildID)->getChannel(channelID);

    auto a = nlohmann::json::parse(Singleton<DiscordAPI>::get()->sendMessage(std::to_string(channelID), "React to this message to receive 100 coins!"));
    //DEBUG(a.dump(2));
    std::string messageId = a["id"].get<std::string>();
    Singleton<ReactionManager>::get()->addReactableMessage(messageId, 0);
    DEBUG(Singleton<DiscordAPI>::get()->reactToMessage(a["channel_id"].get<std::string>(), messageId, constants::emoji::coffee));

    this->resetTimer();
}
} // namespace discordpp
