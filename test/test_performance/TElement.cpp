#include "TElement.h"

TElement::TElement() :
    Value(0)
{
    // Empty
}

TElement::TElement(int value) :
    Value(value)
{
    // Empty
}

bool TElement::operator<(const TElement& other) const
{
    return Value < other.Value;
}

bool TElement::operator>(const TElement& other) const
{
    return Value > other.Value;
}

void TElement::set(int value)
{
    Value = value;
}

void TElement::add(int value) 
{
    Value += value;
}
