CC=gcc
CFLAGS=-std=c11 -Wall -g
SRCS=main.c
HEADERS=llist.h
TARGET=preProc

${TARGET}: ${SRCS} ${HEADERS}
	${CC} ${CFLAGS} -o ${TARGET} ${SRCS}

clean:
	rm -f *~ *.o ${TARGET}

