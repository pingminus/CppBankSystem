#pragma once

#include <string>
#include <unordered_map>
using namespace std;

// Global data structure for user storage
extern unordered_map<string, string> userDatabase;

// Function declarations
bool RegisterUser(const string& username, const string& password);
bool LoginUser(const string& username, const string& password);

