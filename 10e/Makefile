CC = gcc
CFLAGS = -Wall -Wextra -g

make: ex1 ex2 ex3

ex1: ex1.c
	${CC} ${CFLAGS} ex1.c -o ex1

ex2 : ex2.c
	${CC} ${CFLAGS} ex2.c -o ex2

ex3 : ex3.c
	${CC} ${CFLAGS} ex3.c -o ex3
init: init.c dijkstra.o
	${CC} ${CFLAGS} init.c dijkstra.o -o init

delete: clean.c dijkstra.o
	${CC} ${CFLAGS} clean.c dijkstra.o -o clean

clean:
	rm -f ex1 ex2 ex3