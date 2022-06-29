#include "Account.h"
double Account::getBalance() { return balance; }

//returns new balance or -1 if error 
double Account::deposit(double amount)
{
	if (amount > 0) balance += amount;
	else return -1;
	return balance;
}

//return new balance or -1 if invalid amount 
double Account::withdraw(double amount)
{
	if ((amount > balance) || (amount < 0)) return -1;
	else balance -= amount;
	return balance;
}