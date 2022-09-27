/*
 * Forked Counter
 * Written by: Pietro Piva Vieira
 *
 * Information Systems, Federal University of Rio Grande (FURG)
 * Class: Operation Systems
 *
 * Created at: 26/09/2022, 22:00
 * Last update: 26/09/2022, 22:53
 *
 * Dependencies: stdio.h, unistd.h, stdbool.h
 *
 * Purpose: The purpose of this piece of code is to evaluate the behavior of a global variable
 * on forks of a parent process.
 */

// Declaring our libraries
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

// Declaring a falue return value for fork creation (for semantics)
// Read "man fork" if needed
#define FAILED_FORK_RETURN -1

int counter = 0;

// I'm not using Command Line arguments, so I'm passing "void" to our "main"
int main(void) {
	printf("Address of 'counter' (before 'fork'): %p | Value: %d\n", &counter, counter);
	pid_t myNewProcess = fork();

	bool forkCreationFailed = myNewProcess == FAILED_FORK_RETURN;
	if (forkCreationFailed) {
		printf("Fork could not be created!\n");
		return -1; // We can exit the execution if no forks are created, because we need them!
	}

	counter++;
	printf("Address of 'counter' (after 'fork'): %p | Value: %d\n", &counter, counter);

	return 0;
}
