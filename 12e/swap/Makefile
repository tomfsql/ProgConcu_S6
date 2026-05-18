CC = gcc
CFLAGS = -Wall -Wextra -g

make: write read init delete

write: write.c dijkstra.o
	${CC} ${CFLAGS} write.c dijkstra.o -o write

read: read.c dijkstra.o
	${CC} ${CFLAGS} read.c dijkstra.o -o read

init: init.c dijkstra.o
	${CC} ${CFLAGS} init.c dijkstra.o -o init

delete: clean.c dijkstra.o
	${CC} ${CFLAGS} clean.c dijkstra.o -o clean

clean:
	rm -f write read init delete