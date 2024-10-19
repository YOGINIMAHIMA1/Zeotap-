#      Weather Monitoring System
`The Weather Monitoring System is a real-time application designed to track weather conditions in major cities across India. It retrieves live weather data from the OpenWeatherMap API, processes it to calculate daily summaries such as temperature averages, maximums, and minimums, and triggers alerts for extreme conditions. All weather data is stored in a SQLite database for persistence and later analysis.`

#    Table of Contents
- Project Overview
- Objectives
- Architecture
- Data Source
- Setup Instructions
- Usage
- Database Structure
- Key Features
- Testing
- Conclusion
# Project Overview
- This system monitors weather conditions in real-time by retrieving data from the OpenWeatherMap API. It processes and 
 summarizes the weather data, calculates key metrics (average, max, and min temperature), and stores it for later reference 
  in an SQLite database.

# Objectives
* Retrieve weather data continuously from OpenWeatherMap API.
* Process weather data to compute daily summaries (averages, highs, lows).
* Implement customizable alert thresholds for extreme weather conditions.
* Persist data in a SQLite database for analysis.
* Provide a command-line interface for users to interact with the system.
# Architecture
* Data Retrieval Layer: Fetches weather data from the OpenWeatherMap API.
* Processing Layer: Calculates daily weather aggregates (average, max, min temperatures).
* Storage Layer: Uses SQLite to store processed data.
* User Interface: Command-line interface for configuring settings and viewing weather data.
`Data Source`
- This project retrieves weather data from the OpenWeatherMap API. Key parameters used include:

- main: Main weather condition (e.g., Rain, Clear).
- temp: Current temperature in Kelvin (converted to Celsius).
- feels_like: Feels like temperature in Celsius.
- dt: Unix timestamp for data retrieval time.
- Note: You will need an API key from OpenWeatherMap to access the API.

# Setup Instructions
`Prerequisites`
- C++ Compiler (e.g., g++)
- SQLite3 library
- cURL library
- JSONCPP library
- Installation
- Install the required dependencies (for Ubuntu users):

 `sudo apt install libcurl4-openssl-dev libsqlite3-dev libjsoncpp-dev`
Clone this repository:

- git clone <repository_url>
- cd weather_monitor
- Compile the source code:


`g++ -o weather_monitor main.cpp weather.cpp alerts.cpp database.cpp utils.cpp -lcurl -lsqlite3 -ljsoncpp`
- Replace the placeholder API key in weather.cpp:

const std::string API_KEY = "YOUR_REAL_API_KEY";
Usage
To run the application:


./weather_monitor
By default, the application will:

- Fetch weather data every 5 minutes.
- Store daily summaries (average, max, min temperature) in the SQLite database.
- Trigger alerts based on predefined thresholds.
- You can modify the weather-fetching interval and alert thresholds by editing the source code.

# Database Structure
The application uses a SQLite database weather_data.db. The key table DailyWeather is structured as follows:

`Column Name	Data Type	Description`
- id	INTEGER	Auto-incrementing primary key
- date	TEXT	Date of the weather observation
- avg_temp	REAL	Average temperature for the day
- max_temp	REAL	Maximum temperature for the day
- min_temp	REAL	Minimum temperature for the day
- condition	TEXT	Dominant weather condition
# Key Features
- Real-Time Data Fetching: Automatically retrieves weather data at regular intervals.
- Daily Summaries: Calculates daily weather averages, maximums, and minimums.
- Alerts: Customizable thresholds for extreme weather conditions.
- Data Persistence: Stores historical data in SQLite for analysis.
# Testing
`Test Cases`
- API Connection: Verify the successful connection to the OpenWeatherMap API.
- Data Retrieval: Simulate API calls and ensure correct data parsing.
- Temperature Conversion: Check that temperatures are correctly converted from Kelvin to Celsius.
- Daily Summaries: Validate that the daily aggregates (avg, max, min temperatures) are correctly calculated.
- Alerts: Ensure alerts are triggered when the set thresholds are exceeded.
# Conclusion
- The Weather Monitoring System provides an efficient way to track weather conditions in real-time. It processes the retrieved data, summarizes key information, and offers customizable alerts for extreme weather conditions. The SQLite database ensures persistence of weather data, allowing users to analyze past weather patterns.

# License
- This project is licensed under the MIT License. See the LICENSE file for more details.

# Contact
- For any questions or support, please feel free to reach out to [your_email@example.com].

`This README.md provides an overview of the system, setup instructions, and how to run the project. You can update the repository URL and contact details based on your project specifics.`







