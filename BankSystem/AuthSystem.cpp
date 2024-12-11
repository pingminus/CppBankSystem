#include "AuthSystem.h"
#include <iostream>

std::unordered_map<string, string> userDatabase;


bool RegisterUser(const std::string& username, const std::string& password) {
    // Check if the username already exists
    if (userDatabase.find(username) != userDatabase.end()) {
        std::cout << "Username: " << username << " already exists.\n";
        return false; // Username taken
    }
    else {
        // Add the username and password to the database
        userDatabase[username] = password;
        std::cout << "User registered successfully.\n";
        return true; // Registration successful
    }
}

bool LoginUser(const std::string& username, const std::string& password) {
    // Verify username and password
    if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password) {
        std::cout << "User logined successfully.\n";
        return true; // Login successful
    }
    else {
        std::cout << "Login failed";
        return false; // Invalid credentials
    }
}



