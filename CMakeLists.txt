cmake_minimum_required(VERSION 3.10)
project (Discordpp)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  MESSAGE("Clang")
  MESSAGE("${CMAKE_CXX_COMPILER_VERSION}")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  MESSAGE("GNU")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  MESSAGE("Intel")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  MESSAGE("MSVC")
endif()

# The version number.
set (Discordpp_VERSION_MAJOR 0)
set (Discordpp_VERSION_MINOR 1)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(CMAKE_BUILD_TYPE Debug)

find_package(Boost 1.55.0 REQUIRED COMPONENTS thread system filesystem)
include_directories(... ${Boost_INCLUDE_DIRS})
link_directories(... ${Boost_LIBRARY_DIRS})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/DiscordppConfig.h.in"
  "${PROJECT_BINARY_DIR}/DiscordppConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find DiscordppConfig.h
include_directories("${PROJECT_BINARY_DIR}")
 
# add the executable

add_executable(Discordpp    
                            "src/discordpp/objects/Message.cpp"
                            "src/discordpp/objects/Emoji.cpp"
                            "src/discordpp/objects/Role.cpp"
                            "src/discordpp/objects/Channel.cpp"

                            "src/discordpp/events/Event.cpp"
                            "src/discordpp/events/HelloEvent.cpp"
                            "src/discordpp/events/HeartbeatACKEvent.cpp"
                            "src/discordpp/events/DispatchEvent.cpp"
                            "src/discordpp/events/ReadyEvent.cpp"
                            "src/discordpp/events/GuildCreateEvent.cpp"
                            "src/discordpp/events/ChannelCreateEvent.cpp"
                            "src/discordpp/events/TypingStartEvent.cpp"
                            "src/discordpp/events/MessageCreateEvent.cpp"
                            "src/discordpp/events/MessageUpdateEvent.cpp"
                            "src/discordpp/events/PresenceUpdateEvent.cpp"
                            "src/discordpp/events/MessageReactionAddEvent.cpp"
                            "src/discordpp/events/MessageReactionRemoveEvent.cpp"


                            "src/discordpp/money/MoneyManager.cpp"
                            "src/discordpp/money/Money.cpp"
                            "src/discordpp/money/commands/ClaimMoneyCommand.cpp"
                            "src/discordpp/money/commands/LeaderboardCommand.cpp"
                            "src/discordpp/money/commands/DailyMoneyCommand.cpp"
                            
                            "src/discordpp/users/User.cpp"
                            "src/discordpp/users/UserManager.cpp"

                            "src/discordpp/guilds/Guild.cpp"
                            "src/discordpp/guilds/GuildManager.cpp"

                            "src/discordpp/commands/Command.cpp"
                            "src/discordpp/commands/PingCommand.cpp"
                            "src/discordpp/commands/AboutCommand.cpp"
                            "src/discordpp/commands/CommandManager.cpp"

                            "src/discordpp/reactions/ReactableMessage.cpp"
                            "src/discordpp/reactions/ReactionManager.cpp"
                            "src/discordpp/money/reaction/ClaimMoneyReaction.cpp"

                            "src/discordpp/tasks/Task.cpp"
                            "src/discordpp/tasks/HeartbeatTask.cpp"
                            "src/discordpp/tasks/DistributeMoneyTask.cpp"
                            
                            "src/discordpp/websocket/Gateway.cpp"

                            "src/discordpp/rest/RestAPI.cpp"
                            "src/discordpp/rest/DiscordAPI.cpp"
                            "src/discordpp/rest/PicartoAPI.cpp"
                            "src/discordpp/rest/TwitchAPI.cpp"

                            "src/discordpp/databases/SQLiteDatabase.cpp"

                            "src/discordpp/Discordpp.cpp"


                            "example/StreamNotifier.cpp"
                            "example/AddStreamCommand.cpp"
                            "example/main.cpp")

target_include_directories(Discordpp PRIVATE "src/submodules/nlohmannjson/single_include/" "src/submodules/websocketpp/websocketpp/" "src/submodules/curlpp/include/" "src/discordpp")

target_link_libraries(Discordpp Threads::Threads crypto ssl curl curlpp sqlite3  Boost::thread)
