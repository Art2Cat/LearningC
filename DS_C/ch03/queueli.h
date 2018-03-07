typedef int ElementType;

#ifndef _QUEUE_LIST_H_
#define _QUEUE_LIST_H_

struct Node;

typedef struct Node *PtrNode;

typedef PtrNode Position;

typedef PtrNode List;

struct QueueRecord;

typedef struct QueueRecord *Queue;

struct Node {
  Position Prev;
  ElementType Element;
  Position Next;
};

struct QueueRecord {
  int Capacity;
  int Front;
  int Rear;
  int Size;
  List List;
};

int IsEmpty(Queue Q);

int IsFull(Queue Q);

Queue CreateQueue(int MaxElements);

void DisposeQueue(Queue Q);

void MakeEmpty(Queue Q);

void Enqueue(ElementType X, Queue Q);

ElementType Front(Queue Q);

void Dequeue(Queue Q);

ElementType FrontAndDequeue(Queue Q);

#endif