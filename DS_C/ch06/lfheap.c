#include "lfheap.h"
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

static PriorityQueue merge1(PriorityQueue dst, PriorityQueue source) {
  if (dst->left == NULL) {
    dst->left = source;
  } else {
    dst->right = merge(dst->right, source);
    if (dst->left->npl < dst->right->npl) {
      swap(dst);
    }
    dst->npl = dst->right->npl + 1;
  }
  return dst;
}

PriorityQueue merge(PriorityQueue dst, PriorityQueue source) {
  if (dst == NULL) {
    return source;
  } else if (source == NULL) {
    return dst;
  }

  if (dst->element < source->element) {
    return merge1(dst, source);
  } else {
    return merge1(source, dst);
  }
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
