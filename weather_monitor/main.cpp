#include <iostream>
#include <jsoncpp/json/json.h>
#include "weather.h"
#include "alerts.h"
#include "database.h"
#include "utils.h"

int main() {
    Database db("weather_data.db");

    // Example: Fetch data for a city
    std::string city = "Delhi";
    std::string weatherData = Weather::fetchWeatherData(city);

    // Parse the JSON response to extract relevant data
    Json::Value jsonData;
    Json::CharReaderBuilder reader;
    std::string errors;

    std::istringstream stream(weatherData);
    if (!Json::parseFromStream(reader, stream, &jsonData, &errors)) {
        std::cerr << "Failed to parse weather data: " << errors << std::endl;
        return 1;
    }

    double currentTemp = Weather::kelvinToCelsius(jsonData["main"]["temp"].asDouble());
    double maxTemp = Weather::kelvinToCelsius(jsonData["main"]["temp_max"].asDouble());
    double minTemp = Weather::kelvinToCelsius(jsonData["main"]["temp_min"].asDouble());
    std::string dominantCondition = jsonData["weather"][0]["main"].asString();

    std::cout << "Current Temperature: " << currentTemp << "°C" << std::endl;
    std::cout << "Max Temperature: " << maxTemp << "°C" << std::endl;
    std::cout << "Min Temperature: " << minTemp << "°C" << std::endl;
    std::cout << "Weather Condition: " << dominantCondition << std::endl;

    // Get current date for database entry
    std::string currentDate = Utils::getCurrentDate();

    // Example: Insert data into the database
    db.insertWeatherData(currentDate, (currentTemp + maxTemp + minTemp) / 3, maxTemp, minTemp, dominantCondition);

    // Check for alerts
    double threshold = 35.0;
    Alerts::checkAlerts(currentTemp, threshold);

    return 0;
}
