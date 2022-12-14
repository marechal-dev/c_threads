/* Hello from Forks!
 *
 * Author: Pietro Piva Vieira
 *
 * Federal University of Rio Grande (FURG)
 * Class: Operating Systems
 *
 * Dependencies: stdio.h, unistd.h, stdlib.h, stdbool.h, sys/types.h, sys/wait.h
 *
 * Purpose: To use Forks and study the behavior of them.
 */

// Declaring our dependencies
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define the return from a failed fork creation
#define FAILED_FORK_RETURN -1

int main(void) {
	pid_t myNewProcess = fork();

	bool forkCreationFailed = myNewProcess == FAILED_FORK_RETURN;
	if (forkCreationFailed) {
		printf("Fork could not be created!\n");
		return -1;
	}
	
	// If is the child process
	if (myNewProcess == 0) {
		printf("At Child! | Process ID: %d\n", (int)getpid());
		exit(0);
	} else {
		wait(NULL); // Waiting for child process to exit
		printf("At Parent! | Process ID: %d\n", (int)getpid());
	}

	return 0;
}

