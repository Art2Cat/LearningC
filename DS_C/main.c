#include <stdio.h>
#include "list.h"

void printList(List list);

int main(int argc, char** argv) {
  List list;
  //   struct Node node = {1, NULL};
  ElementType value = 1;
  List list1 = MakeEmpty(list);
  Insert(value, list, NULL);

  printList(list);
  printf("hello world!");
  return 0;
}

void printList(List list) {
  Position p;

  struct Node* node;
  node = list;
  // p = list;
  while (node != NULL) {
    printf("%d, ", node->Element);
    node = node->Next;
  }
  puts("\n");
}