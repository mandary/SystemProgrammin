#ifndef PERSON_H
#define PERSON_H

class Address {
 private:
  string streetNumber;
  string street;
  string city;
  string state;
 public:
  Address(string sn, string st, string city, string state);
  string toString();
}

class person {
 private:
  string firstName;
  Address address;
 public:
  Person(string fn, Address addr);
  string toString();
}

#endif // PERSON_H
