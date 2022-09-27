CC = gcc
CFLAGS = -g
LDFLAGS = -pthread

HELLO = hello_thread.c
FORKED = forked_counter.c
UTHREADS = unix_threads.c
ALL_TARGETS = ${HELLO} ${FORKED} ${UTHREADS}

.DEFAULT_GOAL := all

all: hello forked uthreads

hello: ${HELLO}
	@echo "Compilling hello_thread.c..."
	@${CC} ${CFLAGS} ${HELLO} -o hello_thread.out

forked: ${FORKED}
	@echo "Compilling forked_counter.c..."
	@${CC} ${CFLAGS} ${FORKED} -o forked_counter.out

uthreads: ${UTHREADS}
	@echo "Compilling unix_threads.c..."
	@${CC} ${CFLAGS} ${LDFLAGS} ${UTHREADS} -o unix_threads.out

clean: $(*.out)
	@echo "Removing '.out' files..."
	@rm -f *.out
