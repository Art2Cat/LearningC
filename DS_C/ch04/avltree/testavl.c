#include "avltree.h"
#include <stdio.h>

void printTree(AvlTree T);

int main(int argc, char **argv) {
  AvlTree T;
  Position P;
  int i;
  int j = 0;

  T = MakeEmpty(NULL);
  for (i = 0; i < 50; i++, j = (j + 7) % 50) {
    T = Insert(j, T);
  }
  for (i = 0; i < 50; i++) {
    if ((P = Find(i, T)) == NULL || Retrieve(P) != i) {
      printf("Error at %d\n", i);
    }
  }
  printf("Preorder traversal of the constructed AVL "
         "tree is \n");
  printTree(T);
  for (i = 0; i < 50; i += 2)
    T = Delete(i, T);

  for (i = 1; i < 50; i += 2)
    if ((P = Find(i, T)) == NULL || Retrieve(P) != i)
      printf("Error at %d\n", i);
  for (i = 0; i < 50; i += 2)
    if ((P = Find(i, T)) != NULL)
      printf("Error at %d\n", i);

  printf("Min is %d, Max is %d\n", Retrieve(FindMin(T)), Retrieve(FindMax(T)));

  MakeEmpty(T);
  return 0;
}

void printTree(AvlTree root) {
  if (root != NULL) {
    printf("%d ", root->Element);
    printTree(root->Left);
    printTree(root->Right);
  }
}
