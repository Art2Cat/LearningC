#include "fatal.h"
#include <stdlib.h>

typedef int ElementType;

#ifndef _AATree_H
#define _AATree_H

struct AANode;
typedef struct AANode *Position;
typedef struct AANode *AATree;

struct AANode {
  ElementType Element;
  AATree Left;
  AATree Right;
  int Level;
} aa_node_t;

AATree MakeEmpty(AATree T);
Position Find(ElementType X, AATree T);
Position FindMin(AATree T);
Position FindMax(AATree T);
AATree Initialize(void);
AATree Insert(ElementType X, AATree T);
AATree Remove(ElementType X, AATree T);
ElementType Retrieve(Position P);

extern Position NullNode;

#endif /* _AATree_H */

/* END */
