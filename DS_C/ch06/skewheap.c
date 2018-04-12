#include "skewheap.h"
#include <stdio.h>
#include <stdlib.h>

PriorityQueue init() { return NULL; }

element_t find_min(PriorityQueue p) {
  if (is_empty(p)) {
    return 0;
  }
  return p->element;
}

int is_empty(PriorityQueue p) { return p == NULL; }

static void swap(PriorityQueue p) {
  PriorityQueue tmp;
  tmp = p->left;
  p->left = p->right;
  p->right = tmp;
}

static void swap_element(PriorityQueue p, PriorityQueue p1) {
  element_t tmp;
  tmp = p->element;
  p->element = p1->element;
  p1->element = tmp;
}

PriorityQueue merge(PriorityQueue dst, PriorityQueue source) {
  // If one of the heaps is empty.
  if (dst == NULL) {
    return source;
  }
  if (source == NULL) {
    return dst;
  }

  // Make sure that dst has smaller value.
  if (dst->element > source->element) {
    swap_element(dst, source);
  }

  // Swap dst->left and dst->ight value.
  swap_element(dst->left, dst->right);

  // Merge source and dst->left and make merged tree as left of dst.
  dst->left = merge(source, dst->left);
  return dst;
}

PriorityQueue insert1(element_t x, PriorityQueue p) {
  PriorityQueue single;
  single = (PriorityQueue)malloc(sizeof(tree_node_t));
  if (single == NULL) {
    fprintf(stderr, "Out of space!!!");
    exit(EXIT_FAILURE);
  }

  single->element = x;
  single->npl = 0;
  single->right = NULL;
  single->left = NULL;
  p = merge(single, p);
  return p;
}

PriorityQueue delete_min1(PriorityQueue p) {
  PriorityQueue leftHeap, rightHeap;
  if (is_empty(p)) {
    fprintf(stderr, "PriorityQueue is empty");
    return p;
  }
  leftHeap = p->left;
  rightHeap = p->right;
  free(p);
  return merge(leftHeap, rightHeap);
}
