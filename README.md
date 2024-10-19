# Zeotap Assignment

This repository contains two applications developed for the Zeotap assignment:

1. **Rule Engine with AST**: A 3-tier rule engine that evaluates user eligibility based on dynamically created and evaluated rules represented using an Abstract Syntax Tree (AST).
2. **Real-Time Data Processing System for Weather Monitoring**: A real-time data processing system that monitors weather conditions using the OpenWeatherMap API and provides summarized insights with rollups and aggregates.

---

## Application 1: Rule Engine with AST

### Objective

Develop a rule engine application with a simple UI, API, and backend to determine user eligibility based on attributes like age, department, income, spend, etc. The engine uses an Abstract Syntax Tree (AST) to represent conditional rules, allowing dynamic creation, combination, and modification of these rules.

### Key Features

- **AST-based Rule Representation**: Parse rules into an AST structure for dynamic evaluation.
- **Rule Combination**: Combine multiple rules using logical operators (`AND`, `OR`).
- **Rule Evaluation**: Evaluate user data based on parsed rules.
- **SQLite Integration**: Store rules in a database for persistence.

### Design Choices

- **Data Structure**: The AST is represented using a `Node` structure, with fields:
  - `type`: Type of node (`operator` or `operand`).
  - `left`, `right`: References to child nodes for operators.
  - `value`: Operand value for condition nodes (e.g., `age > 30`).
- **Database**: SQLite is used for rule persistence and metadata storage.

### Database Schema

sql
CREATE TABLE rules (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    rule_string TEXT NOT NULL
);
# Sample Rule Representation
rule1: ((age > 30 AND department = 'Sales') OR (age < 25 AND department = 'Marketing')) AND (salary > 50000 OR experience > 5)
rule2: ((age > 30 AND department = 'Marketing')) AND (salary > 20000 OR experience > 5)
#  API Endpoints
- create_rule(rule_string): Parses a rule string and returns the AST representation.
-  combine_rules(rules): Combines multiple ASTs into one.
evaluate_rule(data): Evaluates the rule against a JSON data structure (e.g., {"age": 35, "department": "Sales", "salary": 60000}).

![image](https://github.com/user-attachments/assets/0d4cf395-a85d-4e70-92b9-12391b1cf8d7)

 #  Installation
#  Prerequisites
C++ Compiler (e.g., GCC or Clang).
- SQLite: Install SQLite for rule persistence.
- Docker (optional): If using Docker to containerize the application.
Build Instructions
`Clone the Repository:`

- git clone https://github.com/your-username/zeotap-rule-engine.git
- cd zeotap-rule-engine
- Install SQLite:

`sudo apt-get install sqlite3 libsqlite3-dev`
Compile the Application:

`g++ -std=c++11 RuleEngine.cpp -o rule_engine -lsqlite3`
- Run the Application:

- ./rule_engine

  ![image](https://github.com/user-attachments/assets/b009fdfc-12db-47bd-94a0-2767dc69fb70)

`Docker Setup`
- Build Docker Image:

- docker build -t rule-engine .
- Run Docker Container:


`docker run -d rule-engine`
`Test Cases`
- Create individual rules using create_rule.
- Combine rules using combine_rules.
- Evaluate the rules using sample JSON data in evaluate_rule.
- Future Enhancements
- Implement error handling for invalid rules.
- Modify existing rules dynamically.
#    Application 2: Real-Time Data Processing System for Weather Monitoring
` Objective`
- Develop a real-time data processing system that monitors weather conditions and provides summarized insights using rollups and aggregates. The system retrieves weather data from the OpenWeatherMap API and performs analysis to calculate daily weather summaries and trigger alerts.

#  Key Features
- Real-Time Weather Monitoring: Continuously retrieve weather data at configurable intervals (e.g., every 5 minutes).
`Rollups & Aggregates:`
- Calculate daily averages, maximum/minimum temperatures, and dominant weather conditions.
- User-configurable alert thresholds for extreme weather conditions.
- Visualization: Display daily weather summaries and alerts.
#  Design Choices
- API: OpenWeatherMap API is used to retrieve weather data for cities in India (Delhi, Mumbai, Chennai, Bangalore, Kolkata, Hyderabad).
-  Alert System: Triggers alerts if temperature exceeds user-defined thresholds for consecutive updates.
- Persistent Storage: Weather data is stored in a database for historical analysis.
# API Endpoints
- /weather/summary: Retrieves daily weather summaries.
- /weather/alerts: Displays active weather alerts.
- /weather/history: Shows historical weather trends.
#  Installation
`Prerequisites`
- g++ Compiler
- SQLite (for data storage)
OpenWeatherMap API Key: Sign up for a free API key here.
Build Instructions
Clone the Repository:

git clone https://github.com/your-username/weather-monitoring-system.git
cd weather-monitoring-system


Set Up Environment Variables:

export OWM_API_KEY='your-openweathermap-api-key'
Run the Application:

![image](https://github.com/user-attachments/assets/16d9b721-3e4c-45c2-ace4-822650b43305)


# docker run -d weather-monitor
- Test Cases
- Verify API connection to OpenWeatherMap.
- Simulate data retrieval at configurable intervals.
Test temperature conversions from Kelvin to Celsius/Fahrenheit.
Generate daily weather summaries and trigger alerts for extreme conditions.
Future Enhancements
Support for additional weather parameters (humidity, wind speed).
Extend alert system with email notifications.
Dependencies
For both applications, the dependencies are:

# SQLite for database operations.
Docker (optional) for containerized setup.
OpenWeatherMap API Key for real-time weather data.
Make sure to install the necessary dependencies before running the applications.

![image](https://github.com/user-attachments/assets/63bce9c6-fbb7-48eb-8733-8edfcee6ecbe)

# License
This project is licensed under the MIT License.

# Contact
- For any questions, feel free to reach out:

- Your Name: your.email@example.com

This `README.md` provides a clear and professional outline for both applications, covering installation instructions, design choices, API endpoints, test cases, and future improvements.
