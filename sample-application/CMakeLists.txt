cmake_minimum_required(VERSION 3.25)
project(ODBC_Tester_App)

set(CMAKE_CXX_STANDARD 17)
#include_directories(/usr/local/include)
include_directories(/opt/homebrew/Cellar/unixodbc/2.3.11/include)


add_executable(ODBC_Tester_App main.cpp)
target_link_libraries(ODBC_Tester_App /Users/maia/duckdb_odbc/libduckdb_odbc.dylib)
