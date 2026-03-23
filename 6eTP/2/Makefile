CC = gcc
CFLAGS = -Wall -Wextra -g

make: redirection.c redirection
	${CC} ${CFLAGS} redirection.c -o redirection

make trois: pipeline.c pipeline
	${CC} ${CFLAGS} pipeline.c -o pipeline

clean:
	rm -rf *.o