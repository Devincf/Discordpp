/**
 * @file ReactableMessage.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-10 05:26
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef REACTABLEMESSAGE_HPP
#define REACTABLEMESSAGE_HPP

#include "nlohmann/json.hpp"
namespace discordpp
{
class ReactableMessage
{
public:
    ReactableMessage();
    virtual ~ReactableMessage();

    virtual bool proc(const nlohmann::json &packet) = 0;
};

} // namespace discordpp

#endif