//
// Created by jiangc on 2020/3/11.
//

#include "CResultSet.h"

/**
 * 构造方法，用于处理数据查询结果
 * @param res
 * @param column
 * @param row
 */
CResultSet::CResultSet(char **res, int column, int row) {
    if (NULL == res)
    {
        perror("res is null");
        return ;
    }
    this->res_ = res;
    int index = column;
    /**
     * 将数据保存到list中
     */
    for (int i = 0; i < row; i++) {
        map<string, int> map_v;
        for (int j = 0; j < column; j++)
        {
            map_v.insert(make_pair(res[j], index));
            index++;
        }
        list_.push_back(map_v);
    }

}

CResultSet::~CResultSet() {

}

bool CResultSet::Next() {
    static auto it = list_.begin();
    this->it_ = it;
    if (it != list_.end())
    {
        it++;
        return true;
    }
    sqlite3_free_table(res_);
    return false;
}

/**
 * 获取int值
 * @param key
 * @return
 */
int CResultSet::GetInt(const char *key) {
    if (it_ == list_.end())
    {
        return -1;
    }

    return atoi(res_[(*it_).find(key)->second]);
}



/**
 * 获取字符串值
 * @param key
 * @return
 */
char *CResultSet::GetString(const char *key) {
    if (it_ == list_.end())
    {
        return "";
    }
    return res_[(*it_).find(key)->second];
}

float CResultSet::GetFloat(const char *key) {
    if (it_ == list_.end())
    {
        return -1;
    }

    return atof(res_[(*it_).find(key)->second]);
}

double CResultSet::GetDouble(const char *key) {
    if (it_ == list_.end())
    {
        return -1;
    }

    return strtod(res_[(*it_).find(key)->second], NULL);
}


