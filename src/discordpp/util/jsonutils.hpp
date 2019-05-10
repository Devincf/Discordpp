#ifndef JSONUTILS_HPP
#define JSONUTILS_HPP

#include "nlohmann/json.hpp"
#include <string>

#include "objects/Snowflake.hpp"


namespace discordpp::util{


inline Snowflake tryGetSnowflake(const std::string& key, const nlohmann::json& json){
    if(json.find(key) != json.end() && !json[key].is_null())
        return Snowflake(json[key].get<std::string>());
    return std::string{"0"};
}

template <typename T>
inline T tryGetJson(const std::string& key, const nlohmann::json& json){
    if(json.find(key) != json.end() && !json[key].is_null())
        return json[key].get<T>();
    
    return T();
}

}

#endif