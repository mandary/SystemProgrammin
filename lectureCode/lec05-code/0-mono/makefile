CC = gcc
CFLAGS=-Wall -std=c11 -O2
SRCS=word_count_mono.c
HEADERS=
TARGET=wc

${TARGET}: ${SRCS} ${HEADERS}
	$(CC) $(CFLAGS) -o ${TARGET} word_count_mono.c

clean:
	/bin/rm -f *.o  *~ ${TARGET}
