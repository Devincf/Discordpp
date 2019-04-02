/**
 * @file CommandManager.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-02 01:02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef COMMANDMANAGER_HPP
#define COMMANDMANAGER_HPP


#include <map>
#include <memory>

#include "Objects/Snowflake.hpp"

#include "Commands/Command.hpp"

namespace discordpp{
    class CommandManager
    {
        public:
        bool addCommand(const std::string&, Command*);
        bool addCommand(Snowflake, const std::string&, Command*);

        std::shared_ptr<Command> findCommand(const Snowflake&, const std::string&);

        private:
        typedef std::map<std::string,std::shared_ptr<Command>> CommandMap;
        std::map<Snowflake,CommandMap> m_commandMap;// global commands saved in snowflake 0, if problems occur try using a secondary map for global commands
    };
}
#endif