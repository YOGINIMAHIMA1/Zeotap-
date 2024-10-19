#include "alerts.h"
#include <iostream>

void Alerts::checkAlerts(double currentTemp, double threshold) {
    if (currentTemp > threshold) {
        std::cout << "Alert: Temperature exceeded threshold: " << currentTemp << "°C" << std::endl;
    }
}
