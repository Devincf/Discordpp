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
#include "Util/Singleton.hpp"
#include "Core/Rest/PicartoAPI.hpp"
#include "Core/Rest/DiscordAPI.hpp"
#include "Core/Databases/SQLiteDatabase.hpp"

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
    boost::thread m_picartoThread;
    std::chrono::milliseconds m_picartoInterval;
    steady_timer *m_picartoTimer;

    std::vector<Channel> m_picartoChannels;

    void picartoNotifications()
    {

        for (Channel &channel : m_picartoChannels)
        {
            //std::cout << "checking " << channel.name << std::endl;
            if (channel.online != discordpp::Singleton<discordpp::PicartoAPI>::get()->isUserOnline(channel.name))
            {
                //Online Status Changed
                std::cout << channel.name << " online status changed" << std::endl;

                if (channel.online)
                {
                    //was online now offline
                }
                else
                {
                    discordpp::Singleton<discordpp::DiscordAPI>::get()->sendMessage("301933844876230657", channel.name + " is online!\nWatch live at : https://picarto.tv/" + channel.name);
                }
                channel.online = !channel.online;
            }
            //std::cout << "Channel " + channel.name << " is " << channel.online << std::boolalpha << " checking next Person" << std::endl;
        }

        m_picartoTimer->expires_at(m_picartoTimer->expires_at() + m_picartoInterval);
        m_picartoTimer->async_wait(boost::bind(&Example::picartoNotifications, this));
    }

  public:
    void setup()
    {
        auto picartoChannels = discordpp::Singleton<discordpp::SQLiteDatabase>::get()->query("SELECT (channel_name) FROM picarto_streams");
        for (auto i : picartoChannels)
        {
            m_picartoChannels.push_back(Channel(i["channel_name"]));
        }

        this->addCommand("!picarto", new PicartoCommand(this, &m_picartoChannels));
        this->addCommand("!baka", new FunCommand(this));

        

        io_service ioservice;
        m_picartoInterval = std::chrono::seconds{4};
        m_picartoTimer = new steady_timer(ioservice, m_picartoInterval);

        m_picartoTimer->expires_at(m_picartoTimer->expires_at() + m_picartoInterval);
        m_picartoTimer->async_wait(boost::bind(&Example::picartoNotifications, this));
        m_picartoThread = boost::thread(boost::bind(&boost::asio::io_service::run, &ioservice));
        run();
    }
    ~Example()
    {
        delete m_picartoTimer;
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