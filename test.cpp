#include <iostream>
#include <string>

#include <boost/date_time/posix_time/posix_time.hpp>

#include <chrono>

using namespace boost::gregorian;
using namespace boost::posix_time;
int main()
{
    std::string a = "2019-04-17 14:17:06";


    ptime pt = boost::posix_time::time_from_string(a);

    //get time until
    auto t2 = pt - second_clock::local_time();

    std::cout << boost::posix_time::to_simple_string(t2) << std::endl;
    //add time
    auto t = pt + minutes(10);

    //get time until
    t2 = t - second_clock::local_time();

    std::cout << boost::posix_time::to_simple_string(t2) << std::endl;

    std::cout << boost::posix_time::to_simple_string(t);

    return 0;
}