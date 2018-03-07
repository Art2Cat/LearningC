#include "list.h"
#include <stdlib.h>
#include "fatal.h"

/* Place in the interface file */

List MakeEmpty(List L) {
  if (L != NULL) DeleteList(L);
  L = malloc(sizeof(Position));
  if (L == NULL) FatalError("Out of memory!");
  L->next = NULL;
  return L;
}

/* START: fig3_8.txt */
/* Return true if L is empty */

int IsEmpty(List L) { return L->next == NULL; }
/* END */

/* START: fig3_9.txt */
/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */

int IsLast(Position P, List L) { return P->next == NULL; }
/* END */

/* START: fig3_10.txt */
/* Return Position of X in L; NULL if not found */

Position Find(ElementType X, List L) {
  Position P;

  P = L->next;
  while (P != NULL && P->element != X) P = P->next;

  return P;
}
/* END */

/* START: fig3_11.txt */
/* Delete from a list */
/* Cell pointed to by P->next is wiped out */
/* Assume that the position is legal */
/* Assume use of a header node */

void Delete(ElementType X, List L) {
  Position P, TmpCell;

  P = FindPrevious(X, L);

  if (!IsLast(P, L)) /* Assumption of header use */
  {                  /* X is found; delete it */
    TmpCell = P->next;
    P->next = TmpCell->next; /* Bypass deleted cell */
    free(TmpCell);
  }
}
/* END */

/* START: fig3_12.txt */
/* If X is not found, then next field of returned value is NULL */
/* Assumes a header */

Position FindPrevious(ElementType X, List L) {
  Position P;

  P = L;
  while (P->next != NULL && P->next->element != X) P = P->next;

  return P;
}
/* END */

/* START: fig3_13.txt */
/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */

void Insert(ElementType X, List L, Position P) {
  Position TmpCell;

  TmpCell = malloc(sizeof(struct Node));
  if (TmpCell == NULL) {
    FatalError("Out of space!!!");
  }

  TmpCell->element = X;
  TmpCell->next = P->next;
  P->next = TmpCell;
}
  /* END */

#if 0
/* START: fig3_14.txt */
        /* Incorrect DeleteList algorithm */

        void
        DeleteList( List L )
        {
            Position P;

      P = L->next;  /* Header assumed */
      L->next = NULL;
      while( P != NULL )
            {
          free( P );
          P = P->next;
            }
        }
/* END */
#endif

/* START: fig3_15.txt */
/* Correct DeleteList algorithm */

void DeleteList(List L) {
  Position P, Tmp;

  P = L->next; /* Header assumed */
  L->next = NULL;
  while (P != NULL) {
    Tmp = P->next;
    free(P);
    P = Tmp;
  }
}
/* END */

Position Header(List L) { return L; }

Position First(List L) { return L->next; }

Position Advance(Position P) { return P->next; }

ElementType Retrieve(Position P) { return P->element; }
