#ifndef EVENTDATA_HPP
#define EVENTDATA_HPP

#include <websocketpp/config/asio_client.hpp>


#include "../constants.hpp"
#include "../libs/nlohmann/json.hpp"

namespace discordpp::event
{

struct EventData
{
    nlohmann::json json;
    constants::BotState botState;
    websocketpp::connection_hdl &hdl;
};
} // namespace discordpp::event

#endif