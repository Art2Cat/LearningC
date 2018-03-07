#include "DoublyLinkedList.h"
#include <stdlib.h>
#include "fatal.h"

#define null NULL

LinkedList makeEmpty(LinkedList list) {
  if (list != null) {
    deleteList(list);
  }
  list = malloc(sizeof(struct Node));
  if (list == null) {
    FatalError("Out of memory!");
  }
  list->previous = null;
  list->next = null;
  return list;
}

_Bool isEmpty(LinkedList list) { return list == null || list->next == null; }

_Bool isLast(Position p, LinkedList list) { return p->next == null; }

Position find(ElementType x, LinkedList list) {
  Position p;
  if (list == null) {
    FatalError("list is null");
  }
  p = list;
  while (p != null && p->element != x) {
    p = p->next;
  }
  return p;
}

void deleteElement(ElementType x, LinkedList list) {
  Position p, prev, next;
  p = find(x, list);

  prev = p->previous;
  next = p->next;
  prev->next = next;
  next->previous = prev;

  free(p);
}

void insert(ElementType x, LinkedList list, Position prev) {
  Position tmpNode, nextNode;

  tmpNode = malloc(sizeof(struct Node));
  if (tmpNode == null) {
    FatalError("Out of space!!!");
  }

  tmpNode->element = x;
  if (prev != null) {
    nextNode = prev->next;
    prev->next = tmpNode;
    if (nextNode != null) {
      nextNode->previous = tmpNode;
    }
  }
  tmpNode->next = nextNode;
  tmpNode->previous = prev;
}

void deleteList(LinkedList list) {
  Position p, tmp;
  if (list == null) {
    FatalError("list is null");
  }
  // Header assumed
  p = list->next;
  list->next = null;
  while (p != null) {
    tmp = p->next;
    free(p);
    p = tmp;
  }
}

Position header(LinkedList list) { return list; }

Position first(LinkedList list) { return list->next; }

Position advance(Position p) { return p->next; }

ElementType retrieve(Position p) { return p->element; }
