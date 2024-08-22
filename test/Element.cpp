#include "Element.h"

std::ostream& operator<<(std::ostream& os, const Element& element)
{
  os << "<Element Value=" << element.Value << ">";
  return os;
}
