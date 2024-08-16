#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>

uint16_t parent(uint16_t id);
uint16_t leftChild(uint16_t id);
uint16_t rightChild(uint16_t id);

uint16_t parent(uint16_t id) 
{
    return (id - 1) / 2;
}

uint16_t leftChild(uint16_t id)
{
    return (id << 1) + 1;
}

uint16_t rightChild(uint16_t id)
{
    return (id << 1) + 2;
}

template<typename T>
class Heap
{
public:
    
    Heap(uint16_t capacity);
    virtual ~Heap();

    bool isEmpty() const;
    bool isFull() const;
    uint16_t size() const;
    uint16_t capacity() const;

protected:
    T** Elements;
    uint16_t Capacity;
    uint16_t Size;

    bool isRoot(uint16_t pos) const;
    bool isLeaf(uint16_t pos) const;
    bool exists(uint16_t pos) const;
    void swap(uint16_t posA, uint16_t posB);
};

template <typename T>
Heap<T>::Heap(uint16_t maxSize) :
    Capacity(maxSize),
    Size(0)
{
    if (Capacity == 0) {
        throw;
    }
    Elements = new T*[Capacity];
}

template <typename T>
Heap<T>::~Heap()
{
    delete[] Elements;
}

template <typename T>
bool Heap<T>::isEmpty() const
{
    return Size == 0;
}

template <typename T>
bool Heap<T>::isFull() const
{
    return Size == Capacity;
}

template <typename T>
uint16_t Heap<T>::size() const
{
    return Size;
}

template <typename T>
uint16_t Heap<T>::capacity() const
{
    return Capacity;
}

template <typename T>
bool Heap<T>::isRoot(uint16_t pos) const
{
    return pos == 0;
}

template <typename T>
bool Heap<T>::isLeaf(uint16_t pos) const 
{
    return (pos << 1) >= Size;
}

template <typename T>
bool Heap<T>::exists(uint16_t pos) const
{
    return pos < Size;
}

template <typename T>
void Heap<T>::swap(uint16_t posA, uint16_t posB)
{
    T* temp = Elements[posA];
    Elements[posA] = Elements[posB];
    Elements[posB] = temp;
}

#endif
