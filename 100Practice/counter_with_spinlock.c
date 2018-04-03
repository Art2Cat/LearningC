#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 20
#define NUM_INCREMENTS 100000

typedef int pthread_spinlock_t;

int pthread_spin_init(pthread_spinlock_t *lock, int pshared) {
  __asm__ __volatile__("" ::: "memory");
  *lock = 0;
  return 0;
}

int pthread_spin_destroy(pthread_spinlock_t *lock) { return 0; }

int pthread_spin_lock(pthread_spinlock_t *lock) {
  while (1) {
    int i;
    for (i = 0; i < 10000; i++) {
      if (__sync_bool_compare_and_swap(lock, 0, 1)) {
        return 0;
      }
    }
    sched_yield();
  }
}

int pthread_spin_trylock(pthread_spinlock_t *lock) {
  if (__sync_bool_compare_and_swap(lock, 0, 1)) {
    return 0;
  }
  return EBUSY;
}

int pthread_spin_unlock(pthread_spinlock_t *lock) {
  __asm__ __volatile__("" ::: "memory");
  *lock = 0;
  return 0;
}

int counter;
pthread_spinlock_t spinlock;

void *addThings(void *threadId) {
  for (int i = 0; i < NUM_INCREMENTS; i++) {
    pthread_spin_lock(&spinlock);
    counter += 1;
    pthread_spin_unlock(&spinlock);
  }
  pthread_exit(NULL);
}

int main(int argc, char **argv) {

  pthread_spin_unlock(&spinlock);
  pthread_t threads[NUM_THREADS];
  long t;
  for (t = 0; t < NUM_THREADS; t++) {
    int rc = pthread_create(&threads[t], NULL, addThings, (void *)t);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(1);
    }
  }

  for (t = 0; t < NUM_THREADS; t++) {
    pthread_join(threads[t], NULL);
  }

  printf("Final value of counter is: %d\n", counter);
  pthread_exit(NULL);
}
