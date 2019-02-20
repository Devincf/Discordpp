cmake_minimum_required(VERSION 2.8.10)
project (Discordpp)

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
                            "src/discordpp/Objects/User.cpp"
                            "src/discordpp/Objects/Emoji.cpp"
                            "src/discordpp/Objects/Role.cpp"
                            "src/discordpp/Objects/Channel.cpp"
                            "src/discordpp/Objects/Guild.cpp"
                            
                            "src/discordpp/Gateway.cpp"
                            "src/discordpp/Bot.cpp"
                            "src/example/main.cpp")

target_include_directories(Discordpp PRIVATE "src/submodules/nlohmannjson/single_include/" "src/submodules/websocketpp/websocketpp/" "src/discordpp")

target_link_libraries(Discordpp Threads::Threads crypto ssl Boost::thread)
