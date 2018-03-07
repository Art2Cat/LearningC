#include "LinkedList.h"
#include <stdlib.h>
#include "fatal.h"

List makeEmpty(List L) {
  if (L != NULL) {
    deleteList(L);
  }
  L = malloc(sizeof(struct Node));
  if (L == NULL) {
    FatalError("Out of memory!");
  }
  L->Next = NULL;
  return L;
}

bool isEmpty(List L) { return L->Next == NULL; }

bool isLast(Position P, List L) { return P->Next == NULL; }

Position find(ElementType X, List L) {
  Position P;

  P = L->Next;
  while (P != NULL && P->Element != X) {
    P = P->Next;
  }

  return P;
}

void deleteElement(ElementType X, List L) {
  Position P, TmpCell;

  P = findPrevious(X, L);
  /** Assumption of header use
   * X is found; delete it
   **/
  if (!isLast(P, L)) {
    TmpCell = P->Next;
    // Bypass deleted cell
    P->Next = TmpCell->Next;
    free(TmpCell);
  }
}

Position findPrevious(ElementType X, List L) {
  Position P;

  P = L;
  while (P->Next != NULL && P->Next->Element != X) {
    P = P->Next;
  }

  return P;
}

void insert(ElementType X, List L, Position P) {
  Position TmpCell;

  TmpCell = malloc(sizeof(struct Node));
  if (TmpCell == NULL) {
    FatalError("Out of space!!!");
  }

  TmpCell->Element = X;
  TmpCell->Next = P->Next;
  P->Next = TmpCell;
}

#if 0
/* START: fig3_14.txt */
        /* Incorrect DeleteList algorithm */

        void
        DeleteList( List L )
        {
            Position P;

/* 1*/      P = L->Next;  /* Header assumed */
/* 2*/      L->Next = NULL;
/* 3*/      while( P != NULL )
            {
/* 4*/          free( P );
/* 5*/          P = P->Next;
            }
        }
/* END */
#endif

void deleteList(List L) {
  Position P, Tmp;

  P = L->Next; /* Header assumed */
  L->Next = NULL;
  while (P != NULL) {
    Tmp = P->Next;
    free(P);
    P = Tmp;
  }
}

Position header(List L) { return L; }

Position first(List L) { return L->Next; }

Position advance(Position P) { return P->Next; }

ElementType retrieve(Position P) { return P->Element; }
