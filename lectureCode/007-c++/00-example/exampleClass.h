#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

#include <string>

class ExampleClass {
 private:
  std::string name;
  double      weight;
  double      volume;

 public:
  // This is the constructor
  ExampleClass(std::string name, double weight, double volume);
  // (There can also be a "destructor," but we'll delay looking at that)

  // class methods
  double getWeight();
  void setWeight(double w);
};

#endif // EXAMPLECLASS_H
