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
                            "src/discordpp/Objects/Snowflake.cpp"
                            "src/discordpp/Objects/Message.cpp"
                            "src/discordpp/Objects/Emoji.cpp"
                            "src/discordpp/Objects/Role.cpp"
                            "src/discordpp/Objects/Channel.cpp"

                            "src/discordpp/Events/Event.cpp"
                            "src/discordpp/Events/HelloEvent.cpp"
                            "src/discordpp/Events/HeartbeatACKEvent.cpp"
                            "src/discordpp/Events/DispatchEvent.cpp"
                            "src/discordpp/Events/ReadyEvent.cpp"
                            "src/discordpp/Events/GuildCreateEvent.cpp"
                            "src/discordpp/Events/ChannelCreateEvent.cpp"
                            "src/discordpp/Events/TypingStartEvent.cpp"
                            "src/discordpp/Events/MessageCreateEvent.cpp"
                            "src/discordpp/Events/PresenceUpdateEvent.cpp"
                            "src/discordpp/Events/MessageReactionAddEvent.cpp"


                            "src/discordpp/Money/MoneyManager.cpp"
                            "src/discordpp/Money/Money.cpp"
                            "src/discordpp/Money/Commands/ClaimMoneyCommand.cpp"
                            "src/discordpp/Money/Commands/LeaderboardCommand.cpp"
                            "src/discordpp/Money/Commands/DailyMoneyCommand.cpp"
                            
                            "src/discordpp/Users/User.cpp"
                            "src/discordpp/Users/UserManager.cpp"

                            "src/discordpp/Guilds/Guild.cpp"
                            "src/discordpp/Guilds/GuildManager.cpp"

                            "src/discordpp/Commands/Command.cpp"
                            "src/discordpp/Commands/PingCommand.cpp"
                            "src/discordpp/Commands/CommandManager.cpp"


                            "src/discordpp/Tasks/Task.cpp"
                            "src/discordpp/Tasks/HeartbeatTask.cpp"
                            
                            "src/discordpp/Core/WebSocket/Gateway.cpp"

                            "src/discordpp/Core/Rest/RestAPI.cpp"
                            "src/discordpp/Core/Rest/DiscordAPI.cpp"
                            "src/discordpp/Core/Rest/PicartoAPI.cpp"
                            "src/discordpp/Core/Rest/TwitchAPI.cpp"

                            "src/discordpp/Core/Databases/SQLiteDatabase.cpp"

                            "src/discordpp/Discordpp.cpp"


                            "example/StreamNotifier.cpp"
                            "example/AddStreamCommand.cpp"
                            "example/main.cpp")

target_include_directories(Discordpp PRIVATE "src/submodules/nlohmannjson/single_include/" "src/submodules/websocketpp/websocketpp/" "src/submodules/curlpp/include/" "src/discordpp")

target_link_libraries(Discordpp Threads::Threads crypto ssl curl curlpp sqlite3  Boost::thread)
