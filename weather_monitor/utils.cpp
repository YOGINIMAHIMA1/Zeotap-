#include "utils.h"
#include <sstream>

std::string Utils::getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    std::ostringstream oss;
    oss << 1900 + ltm->tm_year << "-"
        << 1 + ltm->tm_mon << "-"
        << ltm->tm_mday;

    return oss.str();
}
