CC = gcc
CFLAGS = -Wall -std=c11 -O2
SRCS=word_count_file_reader.c file_reader_inline.c
HEADERS=file_reader_inline.h 
TARGET=wc

${TARGET}: ${SRCS} ${HEADERS}
	ln -s file_reader_inline.h file_reader.h
	$(CC) $(CFLAGS) -o ${TARGET} ${SRCS}
	rm file_reader.h

clean:
	/bin/rm -f *.o  *~ file_reader.h ${TARGET}
