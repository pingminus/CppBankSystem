#ifndef BANK_H
#define BANK_H
#include <unordered_map>
#include <string>

	extern std::unordered_map<std::string, int> BankDatabase;

	void showWithdrawAndDepositMenu(const std::string& username);
	void checkValidUser(const std::string& username);
	void Transaction(const int Money, const std::string& username);
	bool Transfer(const std::string& username, const std::string& receiver, const int money);
	void LoadingScreen(int length);
#endif