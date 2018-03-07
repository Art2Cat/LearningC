#include "queueli.h"
#include <stdlib.h>
#include "fatal.h"

#define MinQueueSize 5

int IsEmpty(Queue Q) { return Q->Size == 0; }

int IsFull(Queue Q) { return Q->Size == Q->Capacity; }

Queue CreateQueue(int MaxElements) {
  Queue Q;

  if (MaxElements < MinQueueSize) {
    Error("Queue size is too small");
  }

  Q = malloc(sizeof(struct QueueRecord));
  if (Q == NULL) {
    FatalError("Out of space!!!");
  }

  Q->List = NULL;

  //   Q->List = malloc(sizeof(Position));
  //   if (Q->List == NULL) {
  //     FatalError("Out of space!!!");
  //   }
  Q->Capacity = MaxElements;
  MakeEmpty(Q);

  return Q;
}

void MakeEmpty(Queue Q) {
  Q->Size = 0;
  Q->Front = 1;
  Q->Rear = 0;
}

static void DisposeList(List list) {
  Position p, tmp;
  if (list != NULL) {
    p = list->Next;
    list->Next = NULL;
    while (p != NULL) {
      tmp = p->Next;
      free(p);
      p = tmp;
    }
  }
}

void DisposeQueue(Queue Q) {
  if (Q != NULL) {
    DisposeList(Q->List);
    // free(Q->List);
    free(Q);
  }
}

static int Succ(int Value, Queue Q) {
  if (++Value == Q->Capacity) {
    Value = 0;
  }
  return Value;
}

void Enqueue(ElementType X, Queue Q) {
  if (IsFull(Q)) {
    Error("Full queue");
  } else {
    Q->Size++;
    Q->Rear = Succ(Q->Rear, Q);
    // Q->List[Q->Rear] = X;
    Position p = malloc(sizeof(struct Node));
    if (p == NULL) {
      FatalError("Out of space!!!");
    }
    p->Element = X;
    p->Next = NULL;
    p->Prev = NULL;
    if (Q->List == NULL) {
      Q->List = p;
    } else {
      Position tmp = Q->List;
      while (tmp->Next != NULL) {
        tmp = tmp->Next;
      }
      p->Prev = tmp;
      tmp->Next = p;
    }
  }
}

ElementType Front(Queue Q) {
  ElementType x = 0;
  if (!IsEmpty(Q)) {
	if (Q->List!=NULL) {
  	  x = Q->List->Element;
	}
    return x;
  }
  Error("Empty queue");
  return 0; /* Return value used to avoid warning */
}

static void deleteList(Queue Q) {
 Position p = Q->List;
    if (p->Next != NULL) {
      Q->List = p->Next;
      free(p);
    } else {
      Q->List = NULL;
      free(p);
    }
}

void Dequeue(Queue Q) {
  if (IsEmpty(Q)) {
    Error("Empty queue");
  } else {
    Q->Size--;
    deleteList(Q);
	Q->Front = Succ(Q->Front, Q);
  }
}

ElementType FrontAndDequeue(Queue Q) {
  ElementType X = 0;

  if (IsEmpty(Q)) {
    Error("Empty queue");
  } else {
    Q->Size--;
	X = Q->List->Element;
	deleteList(Q);
    Q->Front = Succ(Q->Front, Q);
  }
  return X;
}
