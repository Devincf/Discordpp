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

using namespace curlpp::options;

namespace discordpp
{


RestAPI::RestAPI()
{

}
RestAPI::~RestAPI()
{

}
void RestAPI::sendPOST(const std::string& url, const std::list<std::string>& headers, const curlpp::Forms& formdata)
{
try
    {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;

		myRequest.setOpt<Url>(url);
		myRequest.setOpt<HttpHeader>(headers);
		myRequest.setOpt<HttpPost>(formdata);
        myRequest.setOpt<WriteFunction>(std::bind([](curlpp::Easy * h,char* ptr, size_t size, size_t nmemb){ return size * nmemb; }, &myRequest, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

        // Send request and get a result.
        // By default the result goes to standard output.
        myRequest.perform();
    }

    catch (curlpp::RuntimeError &e)
    {
        std::cout << e.what() << std::endl;
    }

    catch (curlpp::LogicError &e)
    {
        std::cout << e.what() << std::endl;
    }
}
} // namespace discordpp