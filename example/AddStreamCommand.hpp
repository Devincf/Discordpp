/**
 * @file AddStreamCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-01 07:16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "commands/Command.hpp"
#include "structs.hpp"


class Discordpp;
class AddStreamCommand : public discordpp::Command
{
    using discordpp::Command::Command;
    public:
    AddStreamCommand(discordpp::Discordpp* dscpp, std::map<std::string,std::vector<Channel>>* channels);
    ~AddStreamCommand();
    bool proc(const nlohmann::json& packet);
    private:
    std::map<std::string,std::vector<Channel>>* m_channels;
};