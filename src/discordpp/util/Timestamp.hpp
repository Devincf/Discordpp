#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

namespace discordpp::util{


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
}

#endif