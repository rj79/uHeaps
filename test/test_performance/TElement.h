#ifndef TELEMENT_H
#define TELEMENT_H

class TElement
{
public:
    TElement();
    TElement(int value);
    void set(int value);
    bool operator<(const TElement& other) const;
    bool operator>(const TElement& other) const;
    void add(int value);
private:
    int Value;
};

#endif
