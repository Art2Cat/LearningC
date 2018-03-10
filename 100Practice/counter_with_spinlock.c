#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 20
#define NUM_INCREMENTS 100000

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
