CC = gcc
CFLAGS = -Wall -Wextra -g -pthread

make: rdv

rdv: rdv.c
	${CC} ${CFLAGS} rdv.c -o rdv

clean:
	rm -f rdv rdv