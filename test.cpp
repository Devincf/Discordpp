#include <iostream>
#include <string>

#include <boost/date_time/posix_time/posix_time.hpp>

#include <chrono>

const boost::posix_time::ptime UNIX_TIME = boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1));

class Timestamp
{
  public:
    Timestamp() : _timestamp(time(0)) {}
    Timestamp(time_t date) : _timestamp(date) {}
    Timestamp(const std::string &string)
    {
        if (std::all_of(string.begin(), string.end(), ::isdigit))
        {
            *this = Timestamp::fromUnixTimestamp(string);
        }
        else
        {
            *this = Timestamp::fromISO8601Timestamp(string);
        }
    }
    ~Timestamp() {}

    const time_t getTimestamp() const { return _timestamp; }
    const std::string getISOTime() const
    {
        char buff[20];
        strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&_timestamp));
        return std::string(buff);
    }
    const std::string getUnixTime() const { return std::to_string(_timestamp); }

    static Timestamp fromUnixTimestamp(const std::string &time)
    {
        return Timestamp(static_cast<time_t>(strtol(time.c_str(), NULL, 10)));
    }

    static Timestamp fromISO8601Timestamp(std::string time)
    {
        try
        {
            boost::posix_time::ptime pt = boost::posix_time::from_iso_extended_string(time);
            return Timestamp(time_t((pt - UNIX_TIME).total_seconds()));
        }
        catch (const std::exception &e)
        {
            try
            {
                time.insert(time.find("+"), ".000000");
                boost::posix_time::ptime pt = boost::posix_time::from_iso_extended_string(time);
                return Timestamp(time_t((pt - UNIX_TIME).total_seconds()));
            }
            catch (const std::exception &e2)
            {
                std::cerr << e2.what() << '\n';
            }
            std::cerr << e.what() << '\n';
            return Timestamp();
        }
    }

  private:
    time_t _timestamp;
};
//against defined but not used error
/*
static Timestamp T1 = Timestamp::fromUnixTimestamp("1550622596");
static Timestamp T2 = Timestamp::fromISO8601Timestamp("2019-02-20T00:29:56.162000+00:00");
static Timestamp T3 = Timestamp::fromISO8601Timestamp("2019-02-20T00:29:56+00:00");*/

static Timestamp T1 = Timestamp("1550622596");
static Timestamp T2 = Timestamp("2019-02-20T00:29:56.162000+00:00");
static Timestamp T3 = Timestamp("2019-02-20T00:29:56+00:00");

using namespace boost::gregorian;
using namespace boost::posix_time;
int main()
{
    std::string a = "2019-04-17 14:17:06";

    ptime pt = boost::posix_time::time_from_string(a);

    //get time until
    auto t2 = pt - second_clock::local_time();

    //std::cout << boost::posix_time::to_simple_string(t2) << std::endl;
    //add time
    auto t = pt + minutes(10);

    //get time until
    t2 = t - second_clock::local_time();

    //std::cout << boost::posix_time::to_simple_string(t2) << std::endl;

    //std::cout << boost::posix_time::to_simple_string(t);

    std::cout << T1.getISOTime() << std::endl;
    std::cout << T2.getISOTime() << std::endl;
    std::cout << T3.getISOTime() << std::endl;

    return 0;
}