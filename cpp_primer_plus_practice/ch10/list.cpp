#include "list.h"
#include <iostream>

using namespace std;

List::List() {
	item = NULL;
	max = 10;
	idx = 0;
}

List::List(int n) {
	item = NULL;
	max = n;
	idx = 0;
}

void List::add(int it) {
	if (isFull()) {
		cout << "the list is full, remove one before add."<<endl;
		return;
	}

	if (item == NULL) {
		item = new Node;
		item->element = it;
		item->next = NULL;
		idx++;
	} else {
		Item tmp = item;
		while(tmp) {
			if (tmp->next == NULL) {
				tmp->next = new Node;
				tmp->next->element = it;
				tmp->next->next = NULL;
				idx++;
				break;
			}
			tmp = tmp->next;
		}
	}
}

bool List::isEmpty() {
	return idx == 0;
}

bool List::isFull() {
	return idx == max;
}

void List::visit(void (*pf)(Item &)) {
	pf(item);
}

void show(Item &it) {
	Item tmp = it;
	while(tmp) {
		cout << "Item: " << tmp->element;
		cout << ", next address: " << tmp->next << endl;
		tmp = tmp->next;
	}
}
