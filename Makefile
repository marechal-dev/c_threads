CC=gcc

build: hello_thread.c forked_counter.c
	@echo "Compilling hello_thread.c..."
	${CC} hello_thread.c -o hello_thread.out
	@echo "Compilling forked_counter.c..."
	${CC} forked_counter.c -o forked_counter.out

clean: $(*.out)
	@echo "Removing '.out' files..."
	rm -f *.out