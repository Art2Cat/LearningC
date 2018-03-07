#include "BidirectionalCycleList.h"

#include <stdlib.h>
#include "fatal.h"

DCLinkedList initDCList(Item init_value) {
  DCLinkedList list;
  list = malloc(sizeof(struct Node));
  if (list == NULL) {
    FatalError("Out of memory!");
  }
  list->previous = NULL;
  list->item = init_value;
  list->next = NULL;
  return list;
}

DCLinkedList makeEmpty(DCLinkedList list) {
  if (list != NULL) {
    deleteList(list);
  }
  list = malloc(sizeof(struct Node));
  if (list == NULL) {
    FatalError("Out of memory!");
  }
  list->previous = NULL;
  list->next = NULL;
  return list;
}

_Bool isEmpty(DCLinkedList list) { return list == NULL || list->next == NULL; }

_Bool isLast(Position p, DCLinkedList list) { return p->next == NULL; }

Position find(Item x, DCLinkedList list) {
  Position p;
  if (list == NULL) {
    FatalError("list is NULL");
  }
  p = list;
  while (p != NULL && p->item != x) {
    p = p->next;
  }
  return p;
}

void deleteElement(Item x, DCLinkedList list) {
  Position p, prev, next;
  p = find(x, list);

  prev = p->previous;
  next = p->next;
  prev->next = next;
  next->previous = prev;

  free(p);
}

void insert(Item x, DCLinkedList list, Position prev) {
  Position tmpNode, nextNode;

  tmpNode = malloc(sizeof(Position));
  if (tmpNode == NULL) {
    FatalError("Out of space!!!");
  }

  tmpNode->item = x;
  Position header = list;
  if (header == prev) {
    tmpNode->previous = header;
    tmpNode->next = header;
    header->previous = tmpNode;
    header->next = tmpNode;
  } else {
    nextNode = prev->next;
    prev->next = tmpNode;
    if (nextNode != NULL) {
      nextNode->previous = tmpNode;
    }

    tmpNode->next = nextNode;
    tmpNode->previous = prev;
  }
}

void deleteList(DCLinkedList list) {
  Position p, tmp;
  if (list == NULL) {
    FatalError("list is NULL");
  }
  // Header assumed
  p = list->next;
  list->next = NULL;
  while (p != NULL) {
    tmp = p->next;
    free(p);
    p = tmp;
  }
}

Position header(DCLinkedList list) { return list; }

Position first(DCLinkedList list) { return list->next; }

Position advance(Position p) { return p->next; }

Item retrieve(Position p) { return p->item; }
