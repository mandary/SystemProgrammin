CXX=g++
CXXFLAGS=-g -Wall -std=c++11
TARGETS=0-pointer 1-reference 2-callbyreference 5-styleguide 6-usepoint 7-usepointinline 8-usepointinitializer
BADTARGETS=3-brokencallbyrefconst 4-constmadness  9-usepointrefinitializer

allgood: 0 1 2 5 6 7 8

allbad: 3 4 9

0: 0-pointer

1: 1-reference

2: 2-callbyreference

3: 3-brokencallbyrefconst

4: 4-constmadness

5: 5-styleguide

6: 6-usepoint

7: 7-usepointinline

8: 8-usepointinitializer

9: 9-usepointrefinitializer

6-usepoint: 6-Point.cc 6-usepoint.cc 6-Point.h
	$(CXX) $(CXXFLAGS) 6-Point.cc 6-usepoint.cc -o 6-usepoint

7-usepointinline: 7-usepointinline.cc 7-PointInline.h
	$(CXX) $(CXXFLAGS) 7-usepointinline.cc -o 7-usepointinline

8-usepointinitializer: 8-usepointinitializer.cc 8-PointInitializer.h
	$(CXX) $(CXXFLAGS) 8-usepointinitializer.cc -o 8-usepointinitializer

9-usepointrefinitializer: 9-usepointrefinitializer.cc 9-PointRefInitializer.h
	$(CXX) $(CXXFLAGS) 9-usepointrefinitializer.cc -o 9-usepointrefinitializer

clean:
	rm -f *~ $(TARGETS) $(BADTARGETS)
