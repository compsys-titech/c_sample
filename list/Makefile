CC=gcc
CFLAGS=-Wall -O2 -g
LDFLAGS=

all: list

list: list.c
	${CC} ${CFLAGS} -o $@ $< ${LDFLAGS}

clean:
	rm -rf list *.dSYM
