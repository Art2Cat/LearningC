#ifndef _LF_HEAP_H
#define _LF_HEAP_H

typedef int element_t;

struct TreeNode;

typedef struct TreeNode *PriorityQueue;

struct TreeNode {
  element_t element;
  PriorityQueue left;
  PriorityQueue right;
  int npl;
} tree_node_t;

PriorityQueue init();
element_t find_min(PriorityQueue p);
int is_empty(PriorityQueue p);
PriorityQueue merge(PriorityQueue dst, PriorityQueue source);

#define insert(x, p) insert1((x), p)
#define delete_min(p) delete_min1(p)

PriorityQueue insert1(element_t x, PriorityQueue p);
PriorityQueue delete_min1(PriorityQueue p);

#endif
