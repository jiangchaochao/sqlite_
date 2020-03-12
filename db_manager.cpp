//
// Created by jiangc on 2020/3/12.
//

#include "db_manager.h"

db_manager* db_manager::db_manager_ = new db_manager("../DatabaseName.db");
bool db_manager::is_open_ = false;

db_manager::db_manager(char *dbname) {
    this->db_name_ = dbname;
}
 db_manager *db_manager::get_instance() {
    return db_manager_;
}
/**
 * 连接数据库
 * @return
 */
bool db_manager::connect_db() {
    if (!is_open_)
    {
        int ret = sqlite3_open(db_name_, &db_);
        if (ret)
        {
            perror("Can't opened db\n");
            return false;
        }
        is_open_ = true;
    }
    return true;
}

/**
 * 关闭数据库
 */
void db_manager::disconnect_db() {
    sqlite3_close(db_);
}

/**
 * 执行sql语句
 * @param sql
 * @param data
 * @param errmsg
 * @return
 */
bool db_manager::exec(const char *sql, void *data, char **errmsg) {
    int rc = sqlite3_exec(db_, sql, NULL, data, errmsg);
    if (rc != SQLITE_OK)
    {
        perror(*errmsg);
        return false;
    }
    return true;
}

/**
 * 不带callback的查询， 结合CResultet这个类来使用
 * @param sql
 * @param res
 * @param column
 * @param row
 * @return
 */
bool db_manager::search(const char *sql, char ***res, int *column, int *row, char **errmsg) {

    int rc = sqlite3_get_table(db_, sql, res, row, column, errmsg);
    if (rc != SQLITE_OK)
    {
        perror(*errmsg);
        return false;
    }
    return true;
}


