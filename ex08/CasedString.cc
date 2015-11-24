

#include "CasedString.h"
#include <cstdlib>
#include <string>

#include <iostream>

using std::cout;
using std::endl;

CasedString::CasedString() {
	str_ = nullptr;
	cout << "	Default constructor()" << endl;
}

CasedString::CasedString(const std::string str) {
	str_ = new std::string(str);
	cout << "	Constructor(" << str << ")" << endl;
}

CasedString::~CasedString() {
	if (str_ == NULL) cout << "	Destructor(null)" << endl;
	else cout << "	Destructor(" << *str_ << ")" << endl;
	delete str_;
}

CasedString::CasedString(const CasedString &other) {
	str_ = new std::string(*other.str_);
	cout << "	Copy constructor(" << *str_ << ")" <<endl;
}

CasedString &CasedString::operator=(const CasedString &str) {
	// self assignment protection
	if ( &str == this ) return *this;
	if ( str_ != NULL ) delete str_;
	str_ = new std::string(*str.str_);
	cout << "	Copy assign(" << *str_ << ")" <<endl;
	return *this;
}

CasedString::CasedString(CasedString &&other) noexcept {
	str_ = other.str_;
	other.str_ = NULL;
	cout << "	Move constructor(" << *str_ << ")" << endl;
}


CasedString &CasedString::operator=(CasedString &&str) {
	// self assignment protection
	if ( &str == this ) return *this;
	if ( str_ != NULL ) delete str_;
	str_ = str.str_;
	str.str_ = NULL;
	cout << "	Move assign(" << *str_ << ")" << endl;
	return *this;
}


