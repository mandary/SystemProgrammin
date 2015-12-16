CC=g++
CCFLAGS=-Wall -std=gnu++0x -g -O0
TARGETS=example

all: $(TARGETS)

example: Example.cc Example.h Other.cc Other.h main.cc
	$(CC) $(CCFLAGS) -o $@ Example.cc Other.cc main.cc

run:  example
	./example

check:  example
	valgrind --leak-check=full ./example

clean:
	rm -f *.o *~ $(TARGETS)
