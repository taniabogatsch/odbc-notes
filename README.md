# odbc-notes
Keeping track of the many things learned while working on the ODBC driver.

### Setup - with CLion

I followed the instructions to install the ODBC driver [here](https://learn.microsoft.com/en-us/sql/connect/odbc/linux-mac/install-microsoft-odbc-driver-sql-server-macos?view=sql-server-ver16).
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
brew tap microsoft/mssql-release https://github.com/Microsoft/homebrew-mssql-release
brew update
HOMEBREW_ACCEPT_EULA=Y brew install msodbcsql18 mssql-tools18
```

In CLion, I added `DBUILD_ODBC_DRIVER=1` to `CLion - Settings - Build,Execution,Deployment - CMake - CMake options`.
Then, select `test_odbc` from the `Run/Debug Configurations` to run the tests. To run a specific test, click on `test_odbc`, then `Edit Configurations` and add the name of the test as the program's argument, e.g. `"Basic ODBC usage"`.

Alternatively, [here](https://github.com/duckdb/duckdb/tree/master/tools/odbc) are more instructions on how to use/fix ODBC (tests).

## FAQ

What are [handles](https://learn.microsoft.com/en-us/sql/odbc/reference/develop-app/handles?view=sql-server-ver16)

- `SQLHANDLE`: can be any handle
- there are five types of handles, e.g., statement handles
-  functions can therefore contain the specific type of the handle: `SQLHANDLE handle, SQLSMALLINT handle_type`
- `HSTMT`: [statement handle](https://learn.microsoft.com/en-us/sql/odbc/reference/develop-app/statement-handles?view=sql-server-ver16)



### Open Questions

- What is an `SQLHANDLE`?
- What is a `HSTMT`? I am assuming that this is short for handle-statement?

We often use handles, which are mostly pointers to memory locations.
- `HSTMT`: points to the metadata and the data of a statement
- `SQLHANDLE`: points to the data of a statement
