CC = gcc
CFLAGS = -Wall -Wextra -g

all: first second init delete

first: first.c dijkstra.o
	${CC} ${CFLAGS} first.c dijkstra.o -o first

second: second.c dijkstra.o
	${CC} ${CFLAGS} second.c dijkstra.o -o second

third: third.c dijkstra.o
	${CC} ${CFLAGS} third.c dijkstra.o -o third

init: init.c dijkstra.o
	${CC} ${CFLAGS} init.c dijkstra.o -o init

delete: clean.c dijkstra.o
	${CC} ${CFLAGS} clean.c dijkstra.o -o clean

clean:
	rm -f *.o