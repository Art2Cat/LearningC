#ifndef __LIST_H__
#define __LIST_H__

struct Node {
	int element;
	Node *next;
};

typedef Node * Item;

class List {
	private:
		int max;
		int idx;
		Item item;
	public:
		List();

		List(int n = 0);

		void add(int i);

		bool isEmpty();

		bool isFull();

		void visit(void (*pf) (Item &));

};

void show(Item &);
#endif
