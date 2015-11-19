// Your .h file here

#ifndef __ELEMENT_H
#define __ELEMENT_H

#include <string>

using namespace std;

class Element {
private:
	char* strptr;

	void _copyFrom(const Element &other); // a deep copy function
public:
	Element(const char* str); // constructor
	Element(const Element &other); // copy constructor
	~Element(); // destructor

	string toString() const; // toString method requested

	Element &operator=(const Element &other); // overload assignment

	bool operator ==(const Element &e2) const; // overload equality comparison
};

#endif // __ELEMENT_H