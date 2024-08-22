#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

class Element
{
public:
  Element() : Value(0) {};
  Element(int value): Value(value) {};
  void update(int newValue) {
    Value = newValue;
  }
  bool operator<(const Element& other) {
    return Value < other.Value;
  }
  bool operator>(const Element& other) {
    return Value > other.Value;
  }
  int value() const { return Value; };

  friend std::ostream& operator<<(std::ostream& stream, const Element& element);


private:
  int Value;
};

#endif