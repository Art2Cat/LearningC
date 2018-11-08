#include <iostream>
#include <cctype>
#include "stack.h"


int main() {
	using namespace std;
	Stack st;
	char ch;
	customer po;
	double total = 0.0;
	cout << "Please enter A to add a purchase order,\n"<< "P to process a Po, or Q to quit.\n";
	while(cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n') {
			continue;
		}
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}

		switch (ch) {
			case 'A':
			case 'a': cout << "Enter a customers to add: ";
								cin >> po.fullname >> po.payment;
								if (st.isFull() ) {
									cout << "stack already full\n";
								} else {
									st.push(po);
								}
								break;
			case 'P':
			case 'p': if (st.isEmpty()) {
									cout << "stack already empty\n";
								}	else {
									st.pop(po);
									total += po.payment;
									cout << "customers #" << po.fullname << ": " << po.payment << " popped\n";
								}
								break;

		}
		cout << "Please enter A to add a purchase order,\n"<< "P to process a Po, or Q to quit.\n";
	}
	cout << "total: " << total << endl;
	cout << "Bye\n";
	return 0;
}
