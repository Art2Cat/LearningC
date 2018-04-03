#ifndef _BINHEAP_H

typedef int ElementType;

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

struct HeapStruct {
  int capacity;
  int size;
  ElementType *elements;
} heapstruct_t;

PriorityQueue init(int maxElement);
void destroy(PriorityQueue pq);
void empty(PriorityQueue pq);
void insert(ElementType e, PriorityQueue pq);
ElementType delete_min(PriorityQueue pq);
ElementType find_min(PriorityQueue pq);
int is_empty(PriorityQueue pq);
int is_full(PriorityQueue pq);

#endif
