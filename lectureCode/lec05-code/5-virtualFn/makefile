CC = gcc
CFLAGS = -Wall -std=c11 -O2
SRCS=word_count_virtual.c file_reader_virtual.c 
HEADERS=file_reader_virtual.h
TARGET=wc

${TARGET}: ${SRCS} ${HEADERS}
	$(CC) $(CFLAGS) -o ${TARGET} ${SRCS}

clean:
	/bin/rm -f *.o  *~ ${TARGET}
