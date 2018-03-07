#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

void printList(LinkedList list);

int main(int argc, char **argv) {
  LinkedList list;
  list = (Position)malloc(sizeof(Position));
  Item value = 1;
  list->item = 0;
  list->next = NULL;
  list->previous = NULL;
  //   list = makeEmpty(list);
  insert(value, list, list);
  insert(3, list, list);
  puts("hello\n");
  printList(list);
  return 0;
}

void printList(LinkedList list) {
  Position p;
  p = list;
  while (p != NULL) {
    printf("%d, ", p->item);
    p = p->next;
  }
  puts("\n");
}
