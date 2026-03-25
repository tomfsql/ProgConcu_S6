CC = gcc
CFLAGS = -Wall -Wextra -g

all: first second

first: first.c dijkstra.o
	${CC} ${CFLAGS} first.c dijkstra.o -o first

second: second.c dijkstra.o
	${CC} ${CFLAGS} second.c dijkstra.o -o second


clean:
	rm -f first second dijkstra.o