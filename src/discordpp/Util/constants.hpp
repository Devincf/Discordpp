/**
 * @file Util/constants.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief Defines various constants to be used throughout the library
 * @version 1.0
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#define DEBUG_ENABLED

#include <string>
#include <iostream>


#ifdef DEBUG_ENABLED
#define DEBUG(x) std::cout << x << std::endl
#else
#define DEBUG(x)
#endif

namespace discordpp::constants
{
/**
 * @brief Defines various Bot states that the Bot can be in
 */
enum BotState
{
    Starting = 0,
    FirstHeartbeat = 1,
    VerificationSent = 2,
    VerificationAccepted = 3,
    Running = 4
};

/**
 * @brief Defines the various OpCodes of Discord Events
 */
enum OpCodes
{
    Dispatch = 0,
    Heartbeat = 1,
    Identify = 2,
    StatusUpdate = 3,
    VoiceStateUpdate = 4,
    Resume = 6,
    Reconnect = 7,
    RequestGuildMembers = 8,
    InvalidSession = 9,
    Hello = 10,
    HeartbeatACK = 11
};

/**
 * @brief websocket uri             Todo: Pull it from the RESTAPI
 */
static const std::string websocketuri = "wss://gateway.discord.gg/?v=6&encoding=json";
}

#endif