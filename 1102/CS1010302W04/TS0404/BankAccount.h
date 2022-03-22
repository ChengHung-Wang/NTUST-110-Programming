
// Name: ¤ý¥¿§»
// Date: March 13, 2022
// Last Update: March 13, 2022
// Problem statement: Bank Account
class BankAccount {
private:
	int balance;
	static int total;
public:
	explicit BankAccount() {
		balance = 0;
	}

	explicit BankAccount(int num) : balance(num)
	{
		total += num;
	}
	void withdraw(int output);
	void save(int input);
	int getBalance();
	static int getAllMoneyInBank();
};