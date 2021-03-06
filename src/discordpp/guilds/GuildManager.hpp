/**
 * @file GuildManager.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-30 11:23
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILDMANAGER_HPP
#define GUILDMANAGER_HPP

#include <map>
#include <memory>

#include "util/Snowflake.hpp"
#include "Guild.hpp"

namespace discordpp{
    class GuildManager{
        public:
        GuildManager();
        ~GuildManager();

        bool addGuild(std::pair<const Snowflake&,std::shared_ptr<Guild>>);
        bool addGuild(const Snowflake&,std::shared_ptr<Guild>);

        int amount() const;

        std::shared_ptr<Guild> findGuild(const Snowflake& id);

        
        private:
        std::map<Snowflake,std::shared_ptr<Guild>> m_guildMap;
    };
}

#endif