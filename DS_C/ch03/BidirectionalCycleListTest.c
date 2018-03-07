#include <stdio.h>
#include <stdlib.h>
#include "BidirectionalCycleList.h"

void printList(DCLinkedList list);

int main(int argc, char **argv) {
  DCLinkedList list = initDCList(0);
  Item value = 1;
  insert(value, list, list);
  insert(3, list, list->next);
  puts("hello\n");
  printList(list);
  return 0;
}

void printList(DCLinkedList list) {
  Position h, p;
  h = list;
  p = list;
  while (p != NULL) {
    printf("%d, ", p->item);
    p = p->next;
    if (p == h) {
      break;
    }
  }
  puts("\n");
}
