cmake_minimum_required(VERSION 3.15)
project(sqlite)

set(CMAKE_CXX_STANDARD 11)

add_executable(sqlite main.cpp CResultSet.cpp CResultSet.h db_manager.cpp db_manager.h)
target_link_libraries(sqlite  sqlite3)