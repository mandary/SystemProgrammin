#include "exampleClass.h"

ExampleClass::ExampleClass(std::string name, double w, double v) {
  this->name = name;
  weight = w;
  volume = v;
}

double ExampleClass::getWeight() {
  return weight;
}


void ExampleClass::setWeight(double w) {
  weight = w;
}
