#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "MyList.h"

void printList(const List *list);

int main(int argc, char **argv) {
  List list;
  Item item = {
      222,
  };

  initList(&list);
  addItem(&list, item);

  unsigned int size = len(&list);

  for (int i = 0; i < 10; i++) {
    Item item = {
        i,
    };
    if (addItem(&list, item)) {
      printf("added : %d\n", i);
    }
  }

  size = len(&list);

  printf("size : %u\n", size);

  printList(&list);

  Item item1 = {
      5,
  };

  int idx = indexItem(&list, item1);

  printList(&list);

  if (idx != -1) {
    printf("%d index is : %d\n", item1.iValue, idx);
  }

  if (removeItem(&list, item1)) {
    puts("removed!\n");
  }

  printList(&list);
  return 0;
}

void printList(const List *list) {
  Node *nodes = *list;
  while (nodes != NULL) {
    printf("value: %d\n", nodes->item.iValue);
    nodes = nodes->next;
  }
}