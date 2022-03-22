// Name: ¤ý¥¿§»
// Date: March 13, 2022
// Last Update: March 13, 2022
// Problem statement: Bank Account
#include "BankAccount.h";

int BankAccount::total = 0;

void BankAccount::withdraw(int output) {
	balance -= output;
	total -= output;
}

void BankAccount::save(int input) {
	balance += input;
	total += input;
}

int BankAccount::getBalance() {
	return BankAccount::balance;
}

int BankAccount::getAllMoneyInBank() {
	return BankAccount::total;
}
