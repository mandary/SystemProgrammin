CXX=g++
FLAGS=-Wall -g -std=c++11
SRCS=State.cc Automata.cc main.cc
HEADERS=State.h Automata.h
TARGET=regexp

${TARGET}: ${SRCS} ${HEADERS}
	${CXX} ${FLAGS} ${SRCS} -o $@

clean:
	rm -f *.o *~ ${TARGET}

