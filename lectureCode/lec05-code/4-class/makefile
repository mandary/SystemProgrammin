CC = gcc
CFLAGS = -Wall -std=c11 -O2
SRCS=word_count_class.c file_reader_class.c
HEADERS=file_reader_class.h
TARGET=wc

${TARGET}: ${SRCS} ${HEADERS}
	$(CC) $(CFLAGS) -o ${TARGET} ${SRCS}

clean:
	/bin/rm -f *.o  *~ ${TARGET}
