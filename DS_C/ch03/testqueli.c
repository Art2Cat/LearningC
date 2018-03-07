#include <stdio.h>
#include "queueli.h"

int main(int argc, char **argv) {
  Queue Q;
  int i;

  Q = CreateQueue(12);

  for (i = 0; i < 10; i++) {
    Enqueue(i, Q);
  }

  while (!IsEmpty(Q)) {
    printf("%d\n", Front(Q));
    Dequeue(Q);
  }

  for (i = 0; i < 10; i++) {
    Enqueue(i, Q);
  }

  while (!IsEmpty(Q)) {
    printf("%d\n", FrontAndDequeue(Q));
  }

  DisposeQueue(Q);
  return 0;
}
