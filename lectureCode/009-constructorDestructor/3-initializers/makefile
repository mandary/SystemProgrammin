CC=g++
CCFLAGS=-Wall -std=gnu++0x -g -O0 -fno-elide-constructors

initializer: initializer.cc
	$(CC) $(CCFLAGS)  ${DISABLE_OPT} -o $@ initializer.cc

clean:
	rm -f *.o *~ initializer
