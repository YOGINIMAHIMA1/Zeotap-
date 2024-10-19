#ifndef WEATHER_H
#define WEATHER_H

#include <string>

class Weather {
public:
    static std::string fetchWeatherData(const std::string& city);
    static double kelvinToCelsius(double kelvin);
};

#endif // WEATHER_H
