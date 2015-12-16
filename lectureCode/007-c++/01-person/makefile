CXX=g++
CXXFLAGS=-Wall -std=c++11 -g

person: main.cc Person.cc Person.h
	$(CXX) $(CXXFLAGS) main.cc Person.cc -o person

clean:
	rm -f *~ person
