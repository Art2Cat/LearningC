#include <stdio.h>
// #include "DoublyLinkedList.h"
#include "list.h"

void swapNode(Position p, Position *list);

// void printList(LinkedList list) {
//   Position p;
//   p = list;
//   while (p != NULL) {
//     printf("%d, ", p->element);
//     p = p->next;
//   }
//   puts("\n");
// }

void PrintList(const List L) {
  Position P = Header(L);

  if (IsEmpty(L))
    printf("Empty list\n");
  else {
    do {
      P = Advance(P);
      printf("%d ", Retrieve(P));
    } while (!IsLast(P, L));
    printf("\n");
  }
}

int main(int argc, char **argv) {
  List L;
  Position P, pd;
  int i;
  //   LinkedList list;
  //   list = makeEmpty(NULL);
  L = MakeEmpty(NULL);
  P = Header(L);
  //   pd = header(list);

  for (i = 0; i < 10; i++) {
    Insert(i, L, P);
    // insert(i, list, pd);

    P = Advance(P);
    // pd = advance(pd);
  }

  PrintList(L);
  //   printList(list);

  swapNode(L, &L);

  PrintList(L);
  return 0;
}

void swapNode(Position list, Position *L) {
  Position p, a, b, c;
  int i = 0;
  p = list;
  a = *L;
  while (p != NULL) {
    if (i % 2 == 0) {
      b = a->next;

      if (b != NULL) {
        c = b->next;
        b->next = c->next;
        c->next = b;
        a->next = c;
      }
    }
    p = p->next;

    i++;
  }
}

// void swapNodeD(LinkedList list) {
//   Position p = list;

//   while (p->next != NULL) {
//   }
// }
