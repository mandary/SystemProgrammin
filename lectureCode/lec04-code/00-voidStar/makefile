CC=gcc
CFLAGS=-std=c11 -Wall -g
SRCS=llist.c main.c
HEADERS=llist.h
TARGET=voidStar

${TARGET}: ${SRCS} ${HEADERS}
	${CC} ${CFLAGS} -o ${TARGET} ${SRCS}

clean:
	rm -f *~ *.o ${TARGET}

