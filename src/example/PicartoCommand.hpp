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

enum ChannelType
{
    CHANNEL_PICARTO
};

struct Channel
{
  public:
    std::string name;
    bool online;
    ChannelType type;
    Channel(std::string n, ChannelType t = CHANNEL_PICARTO) : name(n), online(false), type(t)
    {
    }
};
static std::array<Channel, 15> channels = {
    Channel("Rays"),
    Channel("cynpai"),
    Channel("katsukaze"),
    Channel("winyumi"),
    Channel("BlazinFlizard"),
    Channel("Johnsonist"),
    Channel("kiroh"),
    Channel("LePetiteCafe"),
    Channel("yuukiame"),
    Channel("Lemyzest"),
    Channel("Redblaze27"),
    Channel("AsuraEterna"),
    Channel("ColdMittens"),
    Channel("scissorchan"),
    Channel("Chocpocalypse")};

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