#include <iostream>
using namespace std;

void strCount(string str);

int main() {
	string input;
	string next;
	cout << "Enter a line:\n";
	while (true) {
		cin >> input;
		if (input == "q") {
			break;
		}

		strCount(input);
		cout << "Enter next line(q to quit):\n";
	}
	cout << "Bye\n";
	return 0;
}

void strCount(string str) {
	static int total = 0;
	int count = str.size();
	cout << "\"" << str << "\" contains ";
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
