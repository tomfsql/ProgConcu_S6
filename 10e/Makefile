CC = gcc
CFLAGS = -Wall -Wextra -g

make: main init delete

main: main.c dijkstra.o
	${CC} ${CFLAGS} main.c dijkstra.o -o main
init: init.c dijkstra.o
	${CC} ${CFLAGS} init.c dijkstra.o -o init

delete: clean.c dijkstra.o
	${CC} ${CFLAGS} clean.c dijkstra.o -o clean

clean:
	rm -f main ex2 ex3