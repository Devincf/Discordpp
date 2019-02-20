#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

namespace discordpp::util{

class Timestamp
{
  public:
    Timestamp() : _timestamp(time(0)) {}
    Timestamp(time_t date) : _timestamp(date) {}
    ~Timestamp() {}

    const time_t getTimestamp() const { return _timestamp; }
    const std::string getISOTime() const
    {
        char buff[20];
        strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&_timestamp));
        return std::string(buff);
    }
    const std::string getUnixTime() const { return std::to_string(_timestamp); }

  private:
    time_t _timestamp;
};

Timestamp fromUnixTimestamp(const std::string &time)
{
    return Timestamp(static_cast<time_t>(strtol(time.c_str(), NULL, 10)));
}

Timestamp fromISO8601Timestamp(const std::string &time)
{
    boost::posix_time::ptime pt = boost::posix_time::from_iso_extended_string("2019-02-20T00:29:56.162000+00:00");
    return Timestamp(time_t((pt - boost::posix_time::ptime(boost::gregorian::date(1970,1,1))).total_seconds()));
}
}

#endif