#include <iostream>
#include <unordered_map>
#include "AuthSystem.h"
#include "Bank.h"
#include <string>
#include <conio.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <algorithm>
using namespace std;

// Simplified GetInput function without beep and input hiding
string GetInput() {
    string input;
    getline(cin, input);  // Simple cin input instead of _getch()
    return input;
}

void displayMenu(int& choice) {
    string options[] = { "Register", "Login", "Exit" };
    int currentChoice = 0;
    bool done = false;

    while (!done) {
        system("cls");
        cout << "Welcome to pingplus C++ Bank!" << "\n\n";

        for (int i = 0; i < 3; ++i) {
            if (i == currentChoice)
                cout << "> ";
            else
                cout << "  ";
            cout << options[i] << endl;
        }

        char ch = _getch();

        if (ch == 72) { // Up Arrow
            currentChoice = (currentChoice - 1 + 3) % 3;
            Beep(1000, 100); // Beep on arrow key up
        }
        else if (ch == 80) { // Down Arrow
            currentChoice = (currentChoice + 1) % 3;
            Beep(1000, 100); // Beep on arrow key down
        }
        else if (ch == '\t') { // Tab key
            currentChoice = (currentChoice + 1) % 3;
            Beep(1000, 100); // Beep on tab key
        }
        else if (ch == 13) { // Enter key
            Beep(800, 80); // Beep on enter key
            choice = currentChoice + 1;
            done = true;
        }
    }
}

int main() {
    string username, password;
    int choice = 0;

    RegisterUser("dev", "admin");
    checkValidUser("dev");

    while (true) {
        displayMenu(choice);

        if (choice == 1) { // Register
            cout << "\nEnter username: ";
            username = GetInput();

            cout << "Enter password: ";
            password = GetInput();

            if (RegisterUser(username, password)) {
                LoadingScreen(20);
            }
            else {
                LoadingScreen(20);
            }

        }
        else if (choice == 2) { // Login
            cout << "\nEnter username: ";
            username = GetInput();

            cout << "Enter password: ";
            password = GetInput();

            if (LoginUser(username, password)) {
                LoadingScreen(20);
                checkValidUser(username);
                showWithdrawAndDepositMenu(username);
            }
            else {
                LoadingScreen(20);
            }

        }
        else if (choice == 3) { // Exit
            cout << "\nExiting...\n";
            break;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }

    return 0;
}
