#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H
typedef int ElementType;

struct Node;

typedef struct Node *PtrToNode;

typedef PtrToNode LinkedList;

typedef PtrToNode Position;

struct Node {
  Position previous;
  ElementType element;
  Position next;
};

LinkedList makeEmpty(LinkedList list);

_Bool isEmpty(LinkedList list);

_Bool isLast(Position p, LinkedList list);

Position find(ElementType x, LinkedList list);

void deleteElement(ElementType x, LinkedList list);

void insert(ElementType x, LinkedList list, Position p);

void deleteList(LinkedList list);

Position header(LinkedList list);

Position first(LinkedList list);

Position advance(LinkedList list);

ElementType retrieve(Position P);

#endif