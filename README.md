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
