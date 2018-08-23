#include <iostream>

using namespace std;

class BankAccount {
	private:
		string name;
		string account;
		double deposit;
	public:
		BankAccount(string name, string account);
		void show();
		void payIn(double amount);
		void withdraw(double amount);
};

int main() {
	BankAccount account = BankAccount("Julia", "Julia_01");

	account.payIn(2000);
	account.show();
	account.withdraw(500);
	account.show();
	account.withdraw(2000);
	account.show();
	return 0;
}




BankAccount::BankAccount(string name, string account) { this->name = name;
	this->account = account;}

	void BankAccount::show() { cout << "BankAccount: { name: "
		<< name << ", account: " << account << ", deposit: " << deposit <<" }." << endl;
	}

void BankAccount::payIn(double amount) {
	deposit += amount;
}

void BankAccount::withdraw(double amount) {
	if (deposit < 0) {
		cout << "You don't have enough deposit to withdraw!\n";
		return;
	} else if (deposit < amount) {
		cout << "Base on your deposit balance, you could only withdraw "<< deposit << endl;
		return;
	}
	deposit -= amount;
}
