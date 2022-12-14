/*
 * Forked Counter
 *
 * Author: Pietro Piva Vieira
 *
 * Federal University of Rio Grande (FURG)
 * Information Systems
 * Class: Operation Systems
 *
 * Dependencies: stdio.h, unistd.h, stdlib.h, stdbool.h, sys/types.h, sys/wait.h
 *
 * Purpose: The purpose of this piece of code is to evaluate the behavior of a global variable
 * on forks of a parent process.
 *
 * Further readings: "man fork"
 */

// Declaring our dependencies
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

#define FAILED_FORK_CREATION_RETURN -1

// I'm not using Command Line arguments, so I'm passing "void" to our "main"
int main(void) {
	int globalCounter = 0;

	pid_t newProcess = fork();

	bool forkCreationFailed = newProcess == FAILED_FORK_CREATION_RETURN || newProcess < 0;
	if (forkCreationFailed) {
		printf("Could not create a new fork! Exiting...\n");
		return -1;
	}

	bool isChildProcess = newProcess == 0;
	if (isChildProcess) {
		printf("At Child (forked) process:\n");
		globalCounter++;
		printf("Process ID: %d | Address of 'counter': %p | Value: %d\n", (int)getpid(), &counter, counter);
		exit(0);
	} else {
		wait(NULL); // Waiting until the child has finished
		printf("At Parent process:\n");
		globalCounter--;
		printf("Process ID: %d | Address of 'counter': %p | Value: %d\n", (int)getpid(), &counter, counter);
	}

	return 0;
}
