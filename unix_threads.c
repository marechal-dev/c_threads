/* Unix Threads
 *
 * Author: Pietro Piva Viera
 *
 * Federal University of Rio Grande (FURG)
 * Class: Operating Systems
 *
 * Dependencies: stdio.h, stdlib.h, pthread.h
 *
 * Purpose: To utilize and study the behavior of Threads.
 *
 * Other information: This file is compilled under the "-pthread" flag.
 */

// Including our dependencies
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Method that will run on our Threads
void* doParallelLoop(void *arg);

// A simple global counter to increment on our threads
int globalCounter = 0;

// No CLI args, then void
int main(void) {
	// Declaring 5 Threads
	pthread_t threadIdA;
	pthread_t threadIdB;
	pthread_t threadIdC;
	pthread_t threadIdD;
	pthread_t threadIdE;

	// Getting the result from our threads
	void* threadResult;

	// Status for our creations and joins
	int creationStatus;
	int joinStatus;

	// Verifying errors on creation
	/*
	 * Basically, the "pthread_create" method returns "0" if the threads was successfully created and
	 * "-1" if it fails to create a new thread, so we need to verify if it's everything fine.
	 */
	creationStatus = pthread_create(&threadIdA, NULL, doParallelLoop, (void*)("Hello from Thread A!"));
	if (creationStatus != 0) {
		printf("Error creating Thread A!\n");
		return -1;
	}

	creationStatus = pthread_create(&threadIdB, NULL, doParallelLoop, (void*)("Hello from Thread B!"));
	if (creationStatus != 0) {
		printf("Error creating Thread B!\n");
		return -1;
	}

	creationStatus = pthread_create(&threadIdC, NULL, doParallelLoop, (void*)("Hello from Thread C!"));
	if (creationStatus != 0) {
		printf("Error creating Thread C!\n");
		return -1;
	}

	creationStatus = pthread_create(&threadIdD, NULL, doParallelLoop, (void*)("Hello from Thread D!"));
	if (creationStatus != 0) {
		printf("Error creating Thread D!\n");
		return -1;
	}

	creationStatus = pthread_create(&threadIdE, NULL, doParallelLoop, (void*)("Hello from Thread E!"));
	if (creationStatus != 0) {
		printf("Error creating Thread E!\n");
		return -1;
	}

	// Join status and printing the execution results for our threads
	/*
	 * Same as the "pthread_create" explanation"
	 */
	joinStatus = pthread_join(threadIdA, &threadResult);	
	if (joinStatus != 0) {
		printf("Error joining Thread A!\n");
		return -1;
	}	
	printf("Thread A execution finished. Return: %s\n", (char*)threadResult);

	joinStatus = pthread_join(threadIdB, &threadResult);
	if (joinStatus != 0) {
		printf("Error joining Thread B!\n");
		return -1;
	}
	printf("Thread B execution finished. Return: %s\n", (char*)threadResult);

	joinStatus = pthread_join(threadIdC, &threadResult);
	if (joinStatus != 0) {
		printf("Error joining Thread C!\n");
		return -1;
	}
	printf("Thread C execution finished. Return: %s\n", (char*)threadResult);

	joinStatus = pthread_join(threadIdD, &threadResult);	
	if (joinStatus != 0) {
		printf("Error joining Thread D!\n");
		return -1;
	}
	printf("Thread D execution finished. Return: %s\n", (char*)threadResult);

	joinStatus = pthread_join(threadIdE, &threadResult);
	if (joinStatus != 0) {
		printf("Error joining Thread E!\n");
		return -1;
	}
	printf("Thread E execution finished. Return: %s\n", (char*)threadResult);
	
	return 0;
}


void* doParallelLoop(void* arg) {
	int counter = 10;

	globalCounter++;
	printf("Global Counter at some Thread: %d\n", globalCounter);

	for (int i = 0; i < counter; i++) {
		printf("%s | Counter: %d | Address of Counter: %p\n", (char*)arg, i, &counter);
	}

	pthread_exit(arg);
}
