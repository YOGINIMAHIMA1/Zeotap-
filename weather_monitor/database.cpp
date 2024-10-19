#include "database.h"
#include <iostream>

Database::Database(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }
    createTable();
}

void Database::createTable() {
    const char* sql = "CREATE TABLE IF NOT EXISTS DailyWeather ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Date TEXT,"
                      "AvgTemp REAL,"
                      "MaxTemp REAL,"
                      "MinTemp REAL,"
                      "DominantCondition TEXT);";
    char* errMsg;
    sqlite3_exec(db, sql, nullptr, 0, &errMsg);
    if (errMsg) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void Database::insertWeatherData(const std::string& date, double avgTemp, double maxTemp, double minTemp, const std::string& dominantCondition) {
    // Implement the insertion logic here
    // Example:
    // std::string sql = "INSERT INTO DailyWeather (Date, AvgTemp, MaxTemp, MinTemp, DominantCondition) VALUES (?, ?, ?, ?, ?);"
}
