/**
 * @file RestAPI.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-01 08:30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef RESTAPI_HPP
#define RESTAPI_HPP

#include <string>

namespace discordpp{
class RestApi
{
public:
void sendMessage(const std::string&);
private:
void sendPOST();
};
}


#endif