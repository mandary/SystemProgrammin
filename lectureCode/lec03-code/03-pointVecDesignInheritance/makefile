CC=gcc
CFLAGS=-std=c11 -Wall -g
SRCS=Tuple.c Point.c Vector.c App.c
HEADERS=Tuple.h Point.h Vector.h
TARGET=app

${TARGET}: ${SRCS} ${HEADERS}
	${CC} ${CFLAGS} -o ${TARGET} ${SRCS} -lm


clean:
	rm -f *.o *~ ${TARGET}
