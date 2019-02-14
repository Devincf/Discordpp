#ifndef EVENTDATA_HPP
#define EVENTDATA_HPP

#include <websocketpp/config/asio_client.hpp>


#include "../constants.hpp"
#include "../json/json.h"

namespace discordpp::event
{

struct EventData
{
    Json::Value json;
    constants::BotState botState;
    websocketpp::connection_hdl &hdl;
};
} // namespace discordpp::event

#endif