/**
 * @file SQLiteDatabase.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-04-05 03:36
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "SQLiteDatabase.hpp"

#include "Util/constants.hpp"
#include <functional>

namespace discordpp
{

SQLiteDatabase::SQLiteDatabase() : SQLiteDatabase(constants::default_db_name)
{
}
SQLiteDatabase::SQLiteDatabase(const std::string &database_name)
{
    m_lastErrMsg = nullptr;
    int rc;
    rc = sqlite3_open("test.db", &m_db);
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
        sqlite3_close(m_db);
        return;
    }
    DEBUG("Database opened");
}
SQLiteDatabase::~SQLiteDatabase()
{
    sqlite3_close(m_db);
}

const int SQLiteDatabase::count(const std::string &expression)
{
    //auto promise = std::shared_ptr<std::promise<std::string>>(new std::promise<std::string>());
    int count = 0;
    char *zErrMsg = 0;
    std::string finalQuery = "SELECT COUNT(*) FROM " + expression;
    int rc = sqlite3_exec(m_db, finalQuery.c_str(),
                          [](void *count, int argc, char **argv, char **azColName) {
                              int *c = reinterpret_cast<int*>(count);
                              *c = atoi(argv[0]);
                              return 0;
                          },
                          &count, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    return count;
}

std::vector<std::map<std::string, std::string>> SQLiteDatabase::query(const std::string &queryStr)
{
    //auto promise = std::shared_ptr<std::promise<std::string>>(new std::promise<std::string>());

    DEBUG("Executing query" << queryStr);
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(m_db, queryStr.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        DEBUG("error: " << sqlite3_errmsg(m_db));
        return {};
    }
    std::vector<std::map<std::string, std::string>> returnvec;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        std::map<std::string, std::string> a;
        //const unsigned char *one = sqlite3_column_text(stmt, 0);
        //const unsigned char *two = sqlite3_column_text(stmt, 1);

        //DEBUG(sqlite3_column_table_name(stmt, 0));//table as expected.
        //DEBUG(sqlite3_column_database_name(stmt, 0));//database as expected.
        //DEBUG(sqlite3_column_count(stmt));//amount of columns
        //DEBUG(sqlite3_column_name(stmt,0));//column name as expected
        const int colcount = sqlite3_column_count(stmt);
        for (int i = 0; i < colcount; i++)
        {
            a[sqlite3_column_name(stmt, i)] = std::string(reinterpret_cast<const char *>(
                sqlite3_column_text(stmt, i)));
        }
        returnvec.push_back(a);
    }

    /*for(auto i : returnvec)
    {
        for (const auto &[k, v] : i)
        std::cout << "m[" << k << "] = " << v << std::endl;
        DEBUG("______________________");
    }*/

    if (rc != SQLITE_DONE)
    {
        DEBUG("error: " << sqlite3_errmsg(m_db));
        return {};
    }
    sqlite3_finalize(stmt);
    return returnvec;
}

} // namespace discordpp