CC=gcc
CFLAGS=-std=c11 -Wall -g
SRCS=Point.c Vector.c App.c
HEADERS=Point.h Vector.h
TARGET=app

${TARGET}: ${SRCS} ${HEADERS}
	${CC} ${CFLAGS} -o ${TARGET} ${SRCS}


clean:
	rm -f *.o *~ ${TARGET}
