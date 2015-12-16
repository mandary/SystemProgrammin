CXX=g++
CXXFLAGS=-Wall -std=c++11 -g
SRC=exampleMain.cc exampleClass.cc
HEADERS=exampleClass.h

person: ${SRC} ${HEADERS}
	$(CXX) $(CXXFLAGS) ${SRC} -o example

clean:
	rm -f *~ example
