CC=g++
CCFLAGS=-Wall -std=gnu++0x -g -O0
ENABLE_MOVE=-D _USE_MOVE
DISABLE_OPT= -fno-elide-constructors
TARGETS=example example example-test

all: example example-move example-opt

#----------------------------------------------------------------------
# run/check without enabling the move operations or constructor ellision
example: Example.h Example.cc main.cc
	$(CC) $(CCFLAGS)  ${DISABLE_OPT} -o $@ Example.cc main.cc

run: example
	./example

check: example
	valgrind ./example

#----------------------------------------------------------------------
# run/check without enabling the move operations or constructor ellision
example-move: Example.h Example.cc main.cc
	$(CC) $(CCFLAGS) ${ENABLE_MOVE} ${DISABLE_OPT} -o $@ Example.cc main.cc

run-move: example-move
	./example-move

check-move: example-move
	valgrind ./example-move

#----------------------------------------------------------------------
# run/check with move operations and allowing construcgor elision

# this target doesn't use -fno-elide-constructors
example-opt: Example.h Example.cc main.cc
	$(CC) $(CCFLAGS) ${ENABLE_MOVE} -o $@ Example.cc main.cc

run-opt: example-opt
	./example-opt

check-opt: example-opt
	valgrind ./example-opt

#----------------------------------------------------------------------

ps: example
	make run >run.txt
	enscript -E -r -C -o outfile.ps  run.txt  makefile main.cc Example.h Example.cc
	ps2pdf outfile.ps

clean:
	rm -f *.o *~ example example-move example-opt run.txt outfile.ps outfile.pdf
