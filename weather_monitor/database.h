#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database {
public:
    Database(const std::string& dbName);
    void createTable();
    void insertWeatherData(const std::string& date, double avgTemp, double maxTemp, double minTemp, const std::string& dominantCondition);
    // Additional functions as needed
private:
    sqlite3* db;
};

#endif // DATABASE_H
