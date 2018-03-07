typedef int ElementType;

#ifndef _List_H
#define _List_H
#include <stdbool.h>

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List makeEmpty(List list);

/**
 * Return true if L is empty
 **/
bool isEmpty(List list);

/**
 * Return true if P is the last position in list L
 * Parameter L is unused in this implementation
 **/
bool isLast(Position p, List list);

/**
 * Return Position of X in L;
 * NULL if not found
 **/
Position find(ElementType x, List list);

/**
 * Delete from a list
 * Cell pointed to by P->Next is wiped out
 * Assume that the position is legal
 * Assume use of a header node
 **/
void deleteElement(ElementType x, List list);

/* If X is not found, then Next field of returned value is NULL
 * Assumes a header
 **/
Position findPrevious(ElementType x, List list);

/**
 * Insert (after legal position P)
 * Header implementation assumed
 * Parameter L is unused in this implementation
 **/
void insert(ElementType x, List list, Position p);

/* Delete from a list */
/* Cell pointed to by P->Next is wiped out */
/* Assume that the position is legal */
/* Assume use of a header node */
void deleteList(List list);

Position header(List list);

Position first(List list);

Position advance(List list);

ElementType retrieve(Position P);

#endif

struct Node {
  ElementType Element;
  Position Next;
};