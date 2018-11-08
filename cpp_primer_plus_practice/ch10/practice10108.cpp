#include "list.h"
#include <iostream>

using namespace std;
int main() {
	List list = List(3);
	cout << boolalpha;
	cout << "list is empty: " << list.isEmpty() << endl;
	list.add(4);
	list.add(42);
	list.add(43);
	cout << "list is full: " << list.isFull() << endl;
	auto pf = &show;
	list.visit(pf);

}
