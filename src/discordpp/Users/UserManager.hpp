#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP

#include <memory>

#include "Objects/Snowflake.hpp"
#include "User.hpp"

namespace discordpp{
    class UserManager{
        public:
        UserManager();
        ~UserManager();

        bool addUser(std::pair<Snowflake,std::shared_ptr<User>>);
        bool addUser(Snowflake,std::shared_ptr<User>);

        std::shared_ptr<User> findUser(const Snowflake& snowflake);

        private:
        std::map<Snowflake, std::shared_ptr<User>> m_globalUsers;
    };
}

#endif