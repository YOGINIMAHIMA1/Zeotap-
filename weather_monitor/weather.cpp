#include "weather.h"
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include <iostream>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string Weather::fetchWeatherData(const std::string& city) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=7557f61e2a131211ec61d9b8f3dc86b3"; // Replace with your API key

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

double Weather::kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}
