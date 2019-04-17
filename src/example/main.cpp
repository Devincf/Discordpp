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
#include "PicartoCommand.hpp"
#include "PicartoNotifier.hpp"
#include "Util/Singleton.hpp"
#include "Core/Rest/DiscordAPI.hpp"

class FunCommand : public discordpp::Command
{
    using discordpp::Command::Command;

  public:
    bool proc(const nlohmann::json &packet)
    {
        discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage(packet["d"]["channel_id"].get<std::string>(), "stop it u baka");
        return true;
    }
};

class Example : public discordpp::Discordpp
{
    using Discordpp::Discordpp;

    std::vector<Channel> m_picartoChannels;
    
  public:
    void setup()
    {
        this->addCommand("!picarto", new PicartoCommand(this, &m_picartoChannels));
        this->addCommand("!baka", new FunCommand(this));

        this->addTask(new PicartoNotifier(this, &m_picartoChannels));
        run();
    }
    ~Example()
    {
    }
};

int main()
{

    const std::string token1 = "NTM5ODIwNDYyMjg1Mzg5ODI0.DzH9tw.AYjoVQwUZJywz28L_nZP716FeEI"; //Lumi Test 3
    const std::string token2 = "NDQ0NjQ4Mzc4MTk5MDQ4MjE0.XKJSAg.GxJtz6y-7fRABPG-HZYN7ZnM1UQ"; // Lumi Bot
    //discordpp::Bot b{token};
    //discordpp::Discordpp dsc{token2};
    Example ex(token2);
    ex.setup();

    return 1;
}