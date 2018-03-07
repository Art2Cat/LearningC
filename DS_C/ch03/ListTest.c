#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void printList(List list);

int main(int argc, char **argv) {
  List list;
  list = makeEmpty(NULL);
  Position p = header(list);
  printList(list);
  insert(1, list, p);
  insert(3, list, list);
  puts("hello\n");
  printList(list);
  deleteElement(0, list);
  printList(list);
  deleteList(list);
  return 0;
}

void printList(List list) {
  Position p;
  p = list;
  while (p != NULL) {
    printf("%d, ", p->Element);
    p = p->Next;
  }
  puts("\n");
}