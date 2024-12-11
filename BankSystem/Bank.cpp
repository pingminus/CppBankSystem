#include "Bank.h"
#include "iostream"
#include <conio.h>
#include <Windows.h>


std::unordered_map<std::string, int> BankDatabase;

// Check if user exist
void checkValidUser(const std::string& username) {
	if (BankDatabase.find(username) == BankDatabase.end()) {
		BankDatabase[username] = 1000;
	}
}
// Handle Transactions
void Transaction(const int Money, const std::string& username){
    BankDatabase[username] += Money;
}

void showWithdrawAndDepositMenu(const std::string& username) {

	std::string options[] = { "withdraw","deposit" ,"exit"};
	int currentchoice = 0;
    int choice;


	
	bool done = false;
    while (!done) {

        system("cls"); 
        
        
        std::cout << "Your Bank Account stores: \n";
        std::cout << BankDatabase[username] << "$";
        std::cout << "\n";
        std::cout << "\n";


        for (int i = 0; i < 3; ++i) {
            if (i == currentchoice) {
                std::cout << ">";

            }
            else {
            }
            std::cout <<" " << options[i] << std::endl;
        }
        char ch = _getch();
        if (ch == 72) {         //Up Arrow 
            currentchoice = (currentchoice - 1 + 3) % 3;
        }
        else if (ch == 80) {   //Down Arrow
               currentchoice = (currentchoice + 1) % 3;
        }
        else if (ch == '\t') {  // Tab key (ASCII 9)
            currentchoice = (currentchoice + 1) % 3;  // Move to the next option
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
                done = true;
            }
        }
    }
    
        
 

}
