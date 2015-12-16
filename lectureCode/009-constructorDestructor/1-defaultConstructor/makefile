CC=g++
CCFLAGS=-Wall -std=gnu++0x -g -O0
TARGETS=example

all: $(TARGETS)

example: Def.cc Def.h main.cc
	$(CC) $(CCFLAGS) -o $@ Def.cc main.cc

run:  example
	./example

check:  example
	valgrind --leak-check=full ./example

clean:
	rm -f *.o *~ $(TARGETS)
