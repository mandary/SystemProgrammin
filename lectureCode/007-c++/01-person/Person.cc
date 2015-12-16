#include "Person.h"

//--------------------------------------
// This is the Address constructor.
//--------------------------------------
Address::Address( std::string sn, 
		  std::string st,
		  std::string city,
		  std::string state ) {
  this->streetNumber = sn;  // you can explicity qualify instance variables
                            // using this
  street = st;              // but so long as the name is unambiugous, you don't
                            // have to
  this->city = city;
  this->state = state;
}

//--------------------------------------
// This is method toString of class Address
//--------------------------------------
std::string Address::toString() {
  std::string result = streetNumber + " " + street + "\n" + city + ", " + state;
  return result;
}

//--------------------------------------
// This is the Person constructor
//--------------------------------------
Person::Person(std::string fn, Address addr) : address(addr) {
  this->fn = fn;
  this->addr = addr;
}

//--------------------------------------
// This is the toString method of class Person
//--------------------------------------
std::string Person::toString() {
  return firstName + "\n" + address.toString();
}

