#include "Element.h"

#ifdef ENABLE_IOSTREAM
std::ostream& operator<<(std::ostream& os, const Element& element)
{
  os << "<Element Value=" << element.Value << ">";
  return os;
}
#endif
