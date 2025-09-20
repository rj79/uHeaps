#ifndef ELEMENT_H
#define ELEMENT_H

#ifdef ENABLE_IOSTREAM
#include <iostream>
#endif

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

  #ifdef ENABLE_IOSTREAM
  friend std::ostream& operator<<(std::ostream& stream, const Element& element);
  #endif

private:
  int Value;
};

#endif