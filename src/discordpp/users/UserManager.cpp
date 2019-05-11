#include "UserManager.hpp"
#include <iostream>

namespace discordpp
{

UserManager::UserManager()
{
}
UserManager::~UserManager()
{
}

int UserManager::amount() const
{
    return m_globalUsers.size();
}

bool UserManager::addUser(std::pair<Snowflake, std::shared_ptr<User>> userdata)
{
    auto ret = m_globalUsers.insert(userdata);
    if (!ret.second)
    {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
        return false;
    }
    return true;
}

bool UserManager::addUser(Snowflake id, std::shared_ptr<User> userptr)
{
    auto ret = m_globalUsers.insert({id, userptr});
    if (!ret.second)
    {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
        return false;
    }
    return true;
}

std::shared_ptr<User> UserManager::findUser(const Snowflake &snowflake)
{
    std::map<Snowflake, std::shared_ptr<User>>::iterator it = m_globalUsers.find(snowflake);
    if (it != m_globalUsers.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

} // namespace discordpp