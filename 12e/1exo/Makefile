CC = gcc
CFLAGS = -Wall -Wextra -g -pthread

make: rdv common

rdv: rdv.c
	${CC} ${CFLAGS} rdv.c -o rdv

common: common.c
	${CC} ${CFLAGS} common.c -o common

clean:
	rm -f rdv common