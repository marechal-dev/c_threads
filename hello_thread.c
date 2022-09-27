#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define FAILED_FORK_RETURN -1

int main(void) {
	pid_t myNewProcess = fork();

	bool forkCreationFailed = myNewProcess == FAILED_FORK_RETURN;
	if (forkCreationFailed) {
		printf("Fork could not be created!\n");
		return -1;
	}

	printf("(almost) Parallel Programming!\n");

	return 0;
}
