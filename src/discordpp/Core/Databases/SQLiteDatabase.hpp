/**
 * @file SQLiteDatabase.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-05 03:33
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SQLITEDATABASE_HPP
#define SQLITEDATABASE_HPP

#include <sqlite3.h>
#include <string>
#include <vector>
#include <map>

namespace discordpp
{
class SQLiteDatabase
{
    public:
    SQLiteDatabase();
    SQLiteDatabase(const std::string& database_name);
    ~SQLiteDatabase();

    std::vector<std::map<std::string,std::string>> query(const std::string& queryStr);
    const int count(const std::string& expression);

    private:

    sqlite3* m_db;
    char* m_lastErrMsg;

};
} // namespace discordpp

#endif