#include "binheap.h"
#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 10
#define MIN_DATA (-32767)

static void error(char *t) {
  fprintf(stderr, "%s\n", t);
  exit(EXIT_FAILURE);
}

PriorityQueue init(int maxElement) {
  PriorityQueue h;
  if (maxElement < MIN_SIZE) {
    error("PriorityQueue size is too small");
  }
  h = (PriorityQueue)malloc(sizeof(heapstruct_t));
  if (h == NULL) {
    error("Out of space!!!");
  }
  h->elements = (ElementType *)malloc((maxElement + 1) * sizeof(ElementType));
  if (h->elements == NULL) {
    error("Out of space!!!");
  }

  h->capacity = maxElement;
  h->size = 0;
  h->elements[0] = MIN_DATA;
  return h;
}

void destroy(PriorityQueue pq) {
  free(pq->elements);
  free(pq);
}

void empty(PriorityQueue pq) { pq->size = 0; }

void insert(ElementType e, PriorityQueue pq) {
  int i;
  if (is_full(pq)) {
    error("PriorityQueue is full");
    return;
  }

  for (i = ++pq->size; pq->elements[i / 2] > e; i /= 2) {
    pq->elements[i] = pq->elements[i / 2];
  }
  pq->elements[i] = e;
}

ElementType delete_min(PriorityQueue pq) {
  int i, Child;
  ElementType MinElement, LastElement;

  if (is_empty(pq)) {
    error("Priority queue is empty");
    return pq->elements[0];
  }
  MinElement = pq->elements[1];
  LastElement = pq->elements[pq->size--];

  for (i = 1; i * 2 <= pq->size; i = Child) {
    /* Find smaller child */
    Child = i * 2;
    if (Child != pq->size && pq->elements[Child + 1] < pq->elements[Child]) {
      Child++;
    }

    /* Percolate one level */
    if (LastElement > pq->elements[Child]) {
      pq->elements[i] = pq->elements[Child];
    } else {
      break;
    }
  }
  pq->elements[i] = LastElement;
  return MinElement;
}

ElementType find_min(PriorityQueue pq) {
  if (!is_empty(pq)) {
    return pq->elements[1];
  }
  error("Priority Queue is Empty");
  return pq->elements[0];
}

int is_empty(PriorityQueue pq) { return pq->size == 0; }

int is_full(PriorityQueue pq) { return pq->size == pq->capacity; }
