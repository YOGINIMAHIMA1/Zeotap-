#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
#include <sqlite3.h>

enum class NodeType { Operator, Operand };

struct Node {
    NodeType type;
    std::string value;  // Condition or operator
    Node* left;         // Left child
    Node* right;        // Right child

    Node(NodeType t, const std::string& val = "") : type(t), value(val), left(nullptr), right(nullptr) {}

    ~Node() {
        delete left;
        delete right;
    }
};

// Utility function to parse a rule and create the AST.
Node* create_rule(const std::string& rule_string) {
    std::istringstream ss(rule_string);
    std::string token;
    Node* root = nullptr;
    Node* current = nullptr;

    while (ss >> token) {
        if (token == "AND" || token == "OR") {
            Node* operatorNode = new Node(NodeType::Operator, token);
            operatorNode->left = current;
            current = operatorNode;
        } else if (token == "(" || token == ")") {
            // Ignore parentheses for now in this basic implementation
        } else {
            // Treat remaining tokens as conditions (e.g., "age > 30")
            Node* operandNode = new Node(NodeType::Operand, token);
            if (current && current->type == NodeType::Operator) {
                current->right = operandNode;
            } else {
                current = operandNode;
            }
        }
    }

    return current;
}

// Function to combine rules into a single AST using "AND" as the operator.
Node* combine_rules(Node* rule1, Node* rule2, const std::string& operatorType = "AND") {
    Node* root = new Node(NodeType::Operator, operatorType);
    root->left = rule1;
    root->right = rule2;
    return root;
}

// Function to evaluate a given AST against user data.
bool evaluate_rule(Node* root, const std::unordered_map<std::string, int>& data) {
    if (!root) return false;

    if (root->type == NodeType::Operand) {
        std::istringstream ss(root->value);
        std::string attribute, op;
        int value;
        ss >> attribute >> op >> value;

        auto it = data.find(attribute);
        if (it == data.end()) throw std::runtime_error("Attribute not found in user data");

        if (op == ">") {
            return it->second > value;
        } else if (op == "<") {
            return it->second < value;
        } else if (op == "=") {
            return it->second == value;
        } else {
            throw std::runtime_error("Invalid operator");
        }
    }

    if (root->type == NodeType::Operator) {
        if (root->value == "AND") {
            return evaluate_rule(root->left, data) && evaluate_rule(root->right, data);
        } else if (root->value == "OR") {
            return evaluate_rule(root->left, data) || evaluate_rule(root->right, data);
        } else {
            throw std::runtime_error("Invalid operator type");
        }
    }

    return false;
}

// Function to insert a rule into SQLite Database
void insertRule(sqlite3* db, const std::string& rule_string) {
    const char* insertSQL = "INSERT INTO rules (rule_string) VALUES (?);";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, rule_string.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
    }
    
    sqlite3_finalize(stmt);
}

// Function to setup the SQLite Database
void setupDatabase(sqlite3** db) {
    if (sqlite3_open("rules.db", db)) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(*db) << std::endl;
        return;
    }

    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS rules (id INTEGER PRIMARY KEY, rule_string TEXT NOT NULL);";
    char* errMsg = nullptr;

    if (sqlite3_exec(*db, createTableSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

int main() {
    // Test Data
    std::unordered_map<std::string, int> userData = {
        {"age", 35},
        {"salary", 60000},
        {"experience", 4}
    };

    // Create an AST from a rule string
    Node* rule1 = create_rule("age > 30 AND salary > 50000");
    Node* rule2 = create_rule("age < 25 OR experience > 5");

    // Combine the rules using AND operator
    Node* combinedRule = combine_rules(rule1, rule2);

    // Evaluate the combined rule
    bool result = evaluate_rule(combinedRule, userData);
    std::cout << "Is user eligible? " << (result ? "Yes" : "No") << std::endl;

    // Setup SQLite Database and insert rule
    sqlite3* db;
    setupDatabase(&db);
    insertRule(db, "age > 30 AND salary > 50000");

    // Close the database
    sqlite3_close(db);

    // Cleanup
    delete combinedRule;

    return 0;
}
