all: test

test:
	gcc -o test test.c
clean:
	rm test

