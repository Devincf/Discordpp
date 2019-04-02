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

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

namespace discordpp{
class RestAPI
{
public:
RestAPI();
virtual ~RestAPI();
protected:
void sendPOST(const std::string&, const std::list<std::string>& headers, const curlpp::Forms& formdata);

};
}


#endif