//
// Created by jiangc on 2020/3/12.
//

#ifndef SQLITE_DB_MANAGER_H
#define SQLITE_DB_MANAGER_H

#include <stdio.h>
#include <sqlite3.h>
class db_manager {
public:
    static db_manager *get_instance();
    bool connect_db();
    void disconnect_db();
    bool exec(const char *sql, void *data, char **errmsg);
    bool search(const char *sql, char ***res, int *column, int *row, char **errmsg);
private:
    db_manager(char *dbname);
    char *db_name_;
    sqlite3 *db_;
    static db_manager *db_manager_;
    static bool is_open_;                       // 数据库是否打开
};


#endif //SQLITE_DB_MANAGER_H
