
#include <iostream>;
#include <unordered_map>;
#include "AuthSystem.h"
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Bank.h"
#include <chrono>
#include <thread>





void displayMenu(int& choice) {
    string options[] = { "Register", "Login", "Exit" }; // Menu options
    int currentChoice = 0; // Currently highlighted option
    bool done = false;

    while (!done) {
        system("cls");  // Clear the console screen

        // Display menu options with the current selection highlighted
        for (int i = 0; i < 3; ++i) {
            if (i == currentChoice) {
                cout << "> "; // Highlight the current option
            }
            else {
                cout << "  ";
            }
            cout << options[i] << endl;
        }

        char ch = _getch(); // Capture user input

        // Navigate the menu based on user input
        if (ch == 72) {         // Up Arrow
            currentChoice = (currentChoice - 1 + 3) % 3;
        }
        else if (ch == 80) {   // Down Arrow
            currentChoice = (currentChoice + 1) % 3;
        }
        else if (ch == '\t') {  // Tab key
            currentChoice = (currentChoice + 1) % 3;
        }
        else if (ch == 13) {    // Enter key
            choice = currentChoice + 1; // Set choice based on the selection
            done = true; // Exit the menu loop
        }
    }
}

// Main program
int main() {
    string username, password;
    int choice = 0;
    RegisterUser("dev", "admin");
    while (true) {
        // Display menu and get user choice
        displayMenu(choice);

        // Handle user choice
        if (choice == 1) { // Register
            cout << "\nEnter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            // register the user
            if (RegisterUser(username, password)) {
                LoadingScreen(20);
            }
            else {
                LoadingScreen(20);
            }


        }
        else if (choice == 2) { // Login
            cout << "\nEnter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            // log in the user
            if (LoginUser(username, password)) {
                LoadingScreen(20);

                
                checkValidUser(username); //If user is new create a bank account
                showWithdrawAndDepositMenu(username);
            }
            else {
                LoadingScreen(20);
            }

        }
        else if (choice == 3) { // Exit
            cout << "\nExiting...\n";
            break; // Exit the program
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }

    return 0;
}