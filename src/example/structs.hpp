#ifndef structs_hpp
#define structs_hpp

#include <string>

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

#endif