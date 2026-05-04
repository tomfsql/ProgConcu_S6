CC = gcc
CFLAGS = -Wall -Wextra -g

make: p0 p1 init delete

p0: p0.c dijkstra.o
	${CC} ${CFLAGS} p0.c dijkstra.o -o p0

p1: p1.c dijkstra.o
	${CC} ${CFLAGS} p1.c dijkstra.o -o p1

p2: p2.c dijkstra.o
	${CC} ${CFLAGS} p2.c dijkstra.o -o p2

init: init.c dijkstra.o
	${CC} ${CFLAGS} init.c dijkstra.o -o init

delete: clean.c dijkstra.o
	${CC} ${CFLAGS} clean.c dijkstra.o -o clean

clean:
	rm -f p0 p1 init delete