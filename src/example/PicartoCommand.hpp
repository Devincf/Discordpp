/**
 * @file PicartoCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-03 04:24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Commands/Command.hpp"
#include "structs.hpp"


class Discordpp;
class PicartoCommand : public discordpp::Command
{
    using discordpp::Command::Command;
    public:
    PicartoCommand(discordpp::Discordpp* dscpp, std::vector<Channel>* channels);
    ~PicartoCommand();
    bool proc(const nlohmann::json& packet);
    private:
    std::vector<Channel>* m_picartoChannel;
};