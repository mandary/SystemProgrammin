#include "Element.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
// Your code here

void Element::_copyFrom(const Element &other) {
	char *strtemp = strdup(other.strptr);
	if (strtemp) {
		if (strptr) free(strptr);
		strptr = strtemp;
	}
}

Element::Element(const char* str) {
	strptr = strdup(str);
}

Element::Element(const Element &other) : strptr(NULL) {
	_copyFrom(other);
}

Element::~Element() {
	free(strptr);
}

string Element::toString() const {
	string result = strptr;
	return result;
}

Element &Element::operator=(const Element &other) {
	_copyFrom(other);
	return *this;
}

bool Element::operator==(const Element &e2) const {
	if (strcmp(strptr, e2.strptr) != 0) {
		return false;
	} else {
		return true;
	}
}