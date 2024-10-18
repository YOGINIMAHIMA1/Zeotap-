# Zeotap Rule Engine Assignment

## Overview

- This **Rule Engine** project is a C++-based solution that parses and evaluates conditional rules to determine if a user meets certain criteria. The rules are represented using an **Abstract Syntax Tree (AST)**, allowing flexible evaluation of complex conditions. Additionally, the project integrates with **SQLite** to store and manage rule strings, enabling persistence for later use.

# The key functionalities include:
- Parsing and combining conditional rules using logical operators like `AND` and `OR`.
- Evaluating the rules against user data.
- Storing rules in an **SQLite** database for future retrieval and management.

# Features

- **AST-based Rule Parsing**: Efficiently parses rules into an AST structure for easier evaluation.
- **Rule Combination**: Combine multiple rules logically using operators.
- **Rule Evaluation**: Evaluate user data based on the parsed rules.
- **SQLite Integration**: Persist rules in a local SQLite database for future retrieval.
- **Dynamic Memory Management**: Efficient memory handling with proper cleanup of dynamically created AST nodes.

## Project Structure

├── RuleEngine.cpp   # Main source code file containing rule parsing, evaluation, and database operations
├── rules.db         # SQLite database for storing rules (created automatically)
└── README.md        # Project documentation (this file)
#  Getting Started
`Prerequisites`
- C++ Compiler: You will need GCC, Clang, or any modern C++ compiler supporting C++11 or later.
- SQLite: The project uses SQLite for persistent rule storage. Install SQLite before running the project.
- Make (optional): You can use Make to simplify the build process.
#  Installation
- Clone the repository:


`git clone https://github.com/your-username/zeotap-rule-engine.git`
`cd zeotap-rule-engine`
- Install SQLite (if not already installed):

`For Ubuntu/Debian:`

- sudo apt-get install sqlite3 libsqlite3-dev
`Compile the project:`

- g++ -std=c++11 RuleEngine.cpp -o rule_engine -lsqlite3
`Run the application:`

- ./rule_engine
 #  Code Functionality
- Rule Creation (create_rule)
-  The create_rule function parses a rule string into an AST, allowing it to be evaluated later. Each rule consists of conditions (e.g., age > 30) combined using logical operators (AND, OR).

#  Example:
- Node* rule = create_rule("age > 30 AND salary > 50000");
- Rule Combination (combine_rules)
- This function combines two rules (represented as ASTs) using a logical operator like AND or OR.

# Example:

- Node* combinedRule = combine_rules(rule1, rule2, "AND");
- Rule Evaluation (evaluate_rule)
- The evaluate_rule function evaluates the AST against user data, returning true or false depending on whether the user data meets the criteria specified by the rules.

# Example:


`std::unordered_map<std::string, int> userData = {
    {"age", 35},
    {"salary", 60000},
    {"experience", 4}
};
bool result = evaluate_rule(combinedRule, userData);`
- SQLite Integration
# The project uses SQLite to store and retrieve rules in a local database (rules.db). The insertRule function inserts rule strings into the database for future retrieval.

`Example:`

`sqlite3* db;
setupDatabase(&db);
insertRule(db, "age > 30 AND salary > 50000");`
# Example Usage
Here’s an example of how the system works:

`int main() {
    // Sample user data
    std::unordered_map<std::string, int> userData = {
        {"age", 35},
        {"salary", 60000},
        {"experience", 4}
    };`

    // Create individual rules
    Node* rule1 = create_rule("age > 30 AND salary > 50000");
    Node* rule2 = create_rule("age < 25 OR experience > 5");

    // Combine the rules using the "AND" operator
    Node* combinedRule = combine_rules(rule1, rule2);

    // Evaluate the combined rule against user data
    bool result = evaluate_rule(combinedRule, userData);
    std::cout << "Is user eligible? " << (result ? "Yes" : "No") << std::endl;

    // Set up SQLite database and store a rule
    sqlite3* db;
    setupDatabase(&db);
    insertRule(db, "age > 30 AND salary > 50000");

    // Close database connection and cleanup
    sqlite3_close(db);
    delete combinedRule;

    return 0;
}
Expected Output

`Is user eligible? Yes`
# Database Schema
- Rules are stored in an SQLite database with the following schema:

-sql

`CREATE TABLE IF NOT EXISTS rules (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    rule_string TEXT NOT NULL
);
`Future Improvements`
- Complex Condition Parsing: Extend the rule parser to handle more complex conditions, such as string comparisons.
- Error Handling: Improve exception handling for invalid input and unexpected edge cases.
- API Integration: Create a REST API to allow rule creation, evaluation, and management through HTTP requests.
`Contributions`
- Contributions to the project are welcome. To contribute:

`Fork the repository.`
- Create a new feature branch (git checkout -b feature/new-feature).
- Commit your changes (git commit -m 'Add new feature').
- Push to the branch (git push origin feature/new-feature).
- Open a Pull Request and describe the changes.

#  License
- This project is licensed under the MIT License. See the LICENSE file for more information.



This `README.md` provides a professional and detailed description of the Rule Engine project
