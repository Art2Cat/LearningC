#ifndef MYLIST_H_
#define MYLIST_H_
#include <stdbool.h>

#define LEN 30

struct string {
  char Str[LEN];
};

typedef struct string String;

struct item {
  int iValue;
};

typedef struct item Item;

typedef struct node {
  Item item;
  struct node *next;
} Node;

typedef Node *List;

void initList(List *list);

bool isEmpty(const List *list);

bool addItem(List *list, Item item);

bool removeItem(List *list, Item item);

Item popItem(List *list, Item item);

bool containItem(const List *list, const Item item);

unsigned int len(const List *list);

int indexItem(const List *list, const Item item);

void removeAll(List *list);

#endif
