//
// Created by jiangc on 2020/3/11.
//

#ifndef SQLITE_CRESULTSET_H
#define SQLITE_CRESULTSET_H

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <sqlite3.h>
using namespace std;

class CResultSet {
public:
    CResultSet(char ** res,  int column, int row);
    virtual ~CResultSet();
    bool Next();
    int GetInt(const char* key);
    float GetFloat(const char *key);
    double GetDouble(const char *key);
    char* GetString(const char* key);
private:
    char ** 		    res_;
    list<map<string, int>>::iterator it_;
    list<map<string, int>>	list_;
};


#endif //SQLITE_CRESULTSET_H
