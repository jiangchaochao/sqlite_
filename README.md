# sqlite_ 对Sqlite3 查询功能封装

### 1. 不使用回调函数得到查询结果


```
db_manager *dbManager = db_manager::get_instance();
    if (!dbManager->connect_db())
    {
        printf("db error\n");
        return -1;
    }
    int column, row;
    char **res;
    char *errmsg;

    bool b = dbManager->search("select * from COMPANY", &res, &column, &row, &errmsg);
    if (b)
    {
        CResultSet *cResultSet = new CResultSet(res, column, row);
        while (cResultSet->Next())
        {
            cout << "ID:" << cResultSet->GetInt("ID") << endl;
            cout << "NAME:" << cResultSet->GetString("NAME") << endl;
            cout << "AGE:" << cResultSet->GetInt("AGE") << endl;
            cout << "ADDRESS:" << cResultSet->GetString("ADDRESS") << endl;
            cout << "SALARY:" << cResultSet->GetFloat("SALARY") << endl;
        }

        delete cResultSet;
    } else{
        return -1;
    }
    dbManager->disconnect_db();
    return 0;
```
