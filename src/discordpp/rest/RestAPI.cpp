/**
 * @file RestAPI.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-01 08:32
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "RestAPI.hpp"
#include "util/constants.hpp"

#include <sstream>

#include "curlpp/Infos.hpp"

using namespace curlpp::options;

namespace discordpp
{

RestAPI::RestAPI()
{
}
RestAPI::~RestAPI()
{
}

const std::string RestAPI::sendPOST(const std::string &url, const std::list<std::string> &headers, const curlpp::Forms &formdata)
{
    auto promise = std::shared_ptr<std::promise<std::string>>(new std::promise<std::string>());
    try
    {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;
        std::stringstream string;

        // Our request to be sent.
        curlpp::Easy myRequest;
        myRequest.setOpt<Url>(url);
        myRequest.setOpt<HttpHeader>(headers);
        myRequest.setOpt<HttpPost>(formdata);
        myRequest.setOpt<WriteStream>(&string);
        /*myRequest.setOpt<WriteFunction>(std::bind([promise](curlpp::Easy *h, char *ptr, size_t size, size_t nmemb) {
            //promise->set_value({ptr});
            return size * nmemb;
        },
                                                  &myRequest, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));*/
        // Send request and get a result.
        // By default the result goes to standard output.
        myRequest.perform();
        return string.str();
    }

    catch (curlpp::RuntimeError &e)
    {
        std::cout << e.what() << std::endl;
    }

    catch (curlpp::LogicError &e)
    {
        std::cout << e.what() << std::endl;
    }
    /*auto future = promise->get_future();
    future.wait();
    return future.get();*/
    return "";
}

const std::string RestAPI::sendGET(const std::string &url)
{
    return sendGET(url, std::list<std::string>());
}
const std::string RestAPI::sendGET(const std::string &url, const std::list<std::string> &headers)
{
    //auto promise = std::shared_ptr<std::promise<std::string>>(new std::promise<std::string>());
    try
    {
        curlpp::Cleanup myCleanup;
        std::stringstream string;

        curlpp::Easy myRequest;
        myRequest.setOpt<Url>(url);
        myRequest.setOpt<HttpHeader>(headers);
        myRequest.setOpt<WriteStream>(&string);
        /*myRequest.setOpt<WriteFunction>(std::bind([&string,promise](curlpp::Easy *h, char *ptr, size_t size, size_t nmemb) {
            string.append(ptr);
            DEBUG(string << ".");
            if(string.back() == '\n')//this might be a bug, if some json responses dont end with a newline or have newlines at the end of a response thats not the last
            {
                promise->set_value(string);
            }
            return size * nmemb;
        },
                                                  &myRequest, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));*/
        
        myRequest.perform();
        return string.str();
    }

    catch (curlpp::RuntimeError &e)
    {
        std::cout << e.what() << std::endl;
    }

    catch (curlpp::LogicError &e)
    {
        std::cout << e.what() << std::endl;
    }
    return "";
    /*auto future = promise->get_future();
    future.wait();
    return future.get();*/
}

} // namespace discordpp