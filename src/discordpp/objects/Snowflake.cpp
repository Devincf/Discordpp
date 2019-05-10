/**
 * @file Snowflake.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Snowflake.hpp"

#include "util/constants.hpp"

namespace discordpp
{
    Snowflake::Snowflake():m_snowflake(0){}
    Snowflake::~Snowflake(){}

    Snowflake::Snowflake(const uint64_t& snow): m_snowflake(snow)
    {
        
    }


    Snowflake::Snowflake(const nlohmann::json& snow)
    {
        m_snowflake = (snow == nullptr) ? 0 : std::stoul(snow.get<std::string>());
    }

    Snowflake::Snowflake(const std::string& snow)
    {
        m_snowflake = (snow == "") ? 0 : std::stoul(snow);
    }

    const uint64_t __always_inline Snowflake::getTimestamp()const
    {
        return (m_snowflake >> 22) + 1420070400000;
    }

    const uint8_t __always_inline Snowflake::getInternalWorkerID() const
    {
        return (m_snowflake & 0x3E0000) >> 17;
    }
    const uint8_t __always_inline Snowflake::getInternalProcessID() const
    {
        return (m_snowflake & 0x1F000) >> 12;
    }

    const uint16_t __always_inline Snowflake::getIncrement() const
    {
        return m_snowflake & 0xFFF;
    }
}