#include <iostream>
#include <sql.h>
#include <sqlext.h>
#include <string>

void check_ret(SQLRETURN ret, std::string msg) {
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        std::cout << ret << ": " << msg << " failed" << std::endl;
        exit(1);
    }
    if (ret == SQL_SUCCESS_WITH_INFO) {
        std::cout << ret << ": " << msg << " succeeded with info" << std::endl;
    }
}

void run_set_stmt_attr(SQLHANDLE dbc) {
    SQLRETURN ret;
    HSTMT hstmt;

    ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &hstmt);
    check_ret(ret, "SQLAllocHandle(STMT)");

    uint64_t rowLen;
    rowLen = 256;
    ret = SQLSetStmtAttr(hstmt, SQL_ATTR_ROW_BIND_TYPE, &rowLen, SQL_IS_UINTEGER);
    check_ret(ret, "SQLSetStmtAttr");

    SQLULEN buf;
    ret = SQLGetStmtAttr(hstmt, SQL_ATTR_ROW_BIND_TYPE, &buf, sizeof(buf), NULL);
    check_ret(ret, "SQLGetStmtAttr");

    std::cout << "buf: " << buf << std::endl;
}

int main() {
    SQLHANDLE env;
    SQLHANDLE dbc;
    SQLRETURN ret;

    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    check_ret(ret, "SQLAllocHandle(ENV)");

    ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    check_ret(ret, "SQLSetEnvAttr");

    ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
    check_ret(ret, "SQLAllocHandle(DBC)");

    std::string dsn = "DSN=duckdbmemory";
    ret = SQLConnect(dbc, (SQLCHAR*)dsn.c_str(), SQL_NTS, NULL, 0, NULL, 0);
    check_ret(ret, "SQLConnect");

    std::cout << "Connected!" << std::endl;
    run_set_stmt_attr(dbc);

    ret = SQLDisconnect(dbc);
    check_ret(ret, "SQLDisconnect");
    ret = SQLFreeHandle(SQL_HANDLE_DBC, dbc);
    check_ret(ret, "SQLFreeHandle(DBC)");
    SQLFreeHandle(SQL_HANDLE_ENV, env);
    check_ret(ret, "SQLFreeHandle(ENV)");
}
