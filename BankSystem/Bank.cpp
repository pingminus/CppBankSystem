#include "Bank.h"
#include "iostream"
#include <conio.h>
#include <Windows.h>
#include <thread>
#include <vector>

std::unordered_map<std::string, int> BankDatabase;
std::unordered_map<std::string, std::vector<std::string>> TransactionHistories;
        
// Check if user exist
void checkValidUser(const std::string& username) {
	if (BankDatabase.find(username) == BankDatabase.end()) {
		BankDatabase[username] = 1000;
		TransactionHistories[username] = {};
	}
}
// Handle Transactions
void Transaction(const int Money, const std::string& username){
    BankDatabase[username] += Money;
	TransactionHistories[username].push_back(std::to_string(Money));
}
void TransactionHistory(const std::string& username) {
    std::cout << "\n";

    std::cout << "-------------------\n";
	std::cout << "Transaction History\n";
	std::cout << "-------------------\n";
	for (const auto& transaction : TransactionHistories[username]) {
        std::cout << transaction << "\n";
        
	}
	system("pause");
}

void showWithdrawAndDepositMenu(const std::string& username) {

	std::string options[] = { "withdraw","deposit" , "Transfer","Transaction history","exit"};
	int currentchoice = 0;
    int choice;


	
	bool done = false;
    while (!done) {

        system("cls"); 
        std::cout << "Welcome " << username << std::endl;
        std::cout << "-------------------------" << std::endl;

        std::cout << "Your Bank Account stores:\n";
        std::cout << BankDatabase[username] << "$";
        std::cout << "\n";
        std::cout << "\n";


        for (int i = 0; i < 4; ++i) {
            if (i == currentchoice) {
                std::cout << ">";

            }
            else {
            }
            std::cout <<" " << options[i] << std::endl;
        }
        char ch = _getch();
        if (ch == 72) {         //Up Arrow 
            currentchoice = (currentchoice - 1 + 5) % 5;
        }
        else if (ch == 80) {   //Down Arrow
               currentchoice = (currentchoice + 1) % 5;
        }
        else if (ch == '\t') {  // Tab key (ASCII 9)
            currentchoice = (currentchoice + 1) % 5;  // Move to the next option
        }
        else if (ch == 13) {    //Enter
            choice = currentchoice + 1;
            int WithdrawAndDepositMoney = 0;

            if (choice == 1) { // Withdraw
                std::cout << "How much do you want to withdraw?\n- ";
                std::cin >> WithdrawAndDepositMoney;
                if (WithdrawAndDepositMoney < 0) {
                    std::cerr << "Invalid input: Withdraw amount cannot be negative.\n";
                    system("pause");
                    continue;
                }
                WithdrawAndDepositMoney = -WithdrawAndDepositMoney;
                Transaction(WithdrawAndDepositMoney, username);
            }
            if (choice == 2) { // Deposit
                std::cout << "How much do you want to deposit?\n+ ";
                std::cin >> WithdrawAndDepositMoney;
                if (WithdrawAndDepositMoney < 0) {
                    std::cerr << "Invalid input: Deposit amount cannot be negative.\n";
                    system("pause");
                    continue;
                }
                Transaction(WithdrawAndDepositMoney, username);
            }
            if (choice == 3) {
                int TransferMoney;
                std::string receiver;
                std::cout << "Recipient Account name: ";
                std::cin >> receiver;
                std::cout << "Amount to Transfer: ";
                std::cin >> TransferMoney;
                
                std::cout << "\n";
                Transfer(username, receiver, TransferMoney);
                
                
                
                LoadingScreen(60);
                
                
                    
            }
            if (choice == 4) {
				TransactionHistory(username);
            }
            if (choice == 5) {
                done = true;
            }
        }
    }
}
void LoadingScreen(int length) {

    const int total_length = 28;  // Total length of the line
    std::string line(total_length, '-');  // Create a line filled with dashes

    // Print the initial line
    std::cout << line << std::flush;

    for (int i = 0; i < total_length; ++i) {
        // Overwrite the i-th character with an equals sign
        line[i] = '=';

        // Move the cursor back to the beginning of the line
        std::cout << "\r" << line << std::flush;

        // Add a small delay for smoothness
        std::this_thread::sleep_for(std::chrono::milliseconds(length)); // Adjust for speed
    }

    std::cout << "\n";  
}
bool Transfer(const std::string& username, const std::string& receiver, const int money) {
    // Check if the transfer amount is valid
    if (money <= 0) {
        std::cout << "Invalid transaction: Amount must be greater than zero.\n";
        return false;
    }

    // Check if the user has enough balance
    if (BankDatabase[username] < money) {
        std::cout << "Insufficient funds in your account.\n";
        return false;
    }

    // Check if the receiver exists in the database
    if (BankDatabase.find(receiver) == BankDatabase.end()) {
        std::cout << "Receiver does not exist.\n";
        return false;
    }

    // Check if the user is trying to transfer money to themselves
    if (username == receiver) {
        std::cout << "You cannot transfer money to your own account.\n";
        return false;
    }

    // Perform the transfer if all checks pass
    BankDatabase[username] -= money;
    BankDatabase[receiver] += money;

    std::cout << "Transfer successful! " << money << "$ has been transferred to " << receiver << ".\n";
    return true;
}
