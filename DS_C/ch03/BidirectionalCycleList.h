#ifndef _BIDIRECTION_CYCLE_LIST_H
#define _BIDIRECTION_CYCLE_LIST_H
typedef int Item;

struct Node;

typedef struct Node *PtrToNode;

typedef PtrToNode DCLinkedList;

typedef PtrToNode Position;

struct Node {
  Position previous;
  Item item;
  Position next;
};

DCLinkedList initDCList(Item init_value);

DCLinkedList makeEmpty(DCLinkedList list);

_Bool isEmpty(DCLinkedList list);

_Bool isLast(Position p, DCLinkedList list);

Position find(Item x, DCLinkedList list);

void deleteElement(Item x, DCLinkedList list);

void insert(Item x, DCLinkedList list, Position p);

void deleteList(DCLinkedList list);

Position header(DCLinkedList list);

Position first(DCLinkedList list);

Position advance(DCLinkedList list);

Item retrieve(Position P);;

#endif