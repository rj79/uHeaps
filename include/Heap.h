#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>

#ifdef ENABLE_IOSTREAM
#include <iostream>
#endif

#define PARENT(x) ((x - 1) >> 1)
#define LEFT_CHILD(x) ((x << 1) + 1)
#define RIGHT_CHILD(x) ((x << 1) + 2)
#define IS_ROOT(x) (x == 0)
/** A position is only leaf is there is neither a left nor right child. */
#define IS_LEAF(x, size) (LEFT_CHILD(x) + 1 > size)
#define EXISTS(x, size) (x < size)

/**
 * Base class for max-heap and min-heap implementations.
 * Contains common data and methods.
 */
template<typename T>
class Heap
{
public:
    
    Heap(uint16_t capacity);
    virtual ~Heap();

    /**
     * @return True if the heap is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @return True if the heap is full, false otherwise.
     */
    bool isFull() const;

    /**
     * @return The current number of elements in the heap.
     */
    uint16_t size() const;

    /**
     * @return The maximum number of elements the heap can hold.
     */
    uint16_t capacity() const;

    #ifdef ENABLE_IOSTREAM
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Heap<U>& heap);
    #endif
    
protected:
    T** Elements;
    uint16_t Capacity;
    uint16_t Size;

    void swap(uint16_t posA, uint16_t posB);
};

template <typename T>
Heap<T>::Heap(uint16_t maxSize) :
    Capacity(maxSize),
    Size(0)
{
    if (Capacity == 0) {
        Capacity = 1;
    }
    Elements = new T*[Capacity];
    for (uint16_t i = 0; i < Capacity; ++i) {
        Elements[i] = nullptr;
    }
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
void Heap<T>::swap(uint16_t posA, uint16_t posB)
{
    T* temp = Elements[posA];
    Elements[posA] = Elements[posB];
    Elements[posB] = temp;
}

#ifdef ENABLE_IOSTREAM
template <typename U>
std::ostream& operator<<(std::ostream& os, const Heap<U>& heap)
{
    os << "<Heap Size=" << heap.size() << " Capacity=" << heap.capacity() << " [";
    uint16_t size = heap.size();
    for (uint16_t i = 0; i < size; ++i) {
        os << *heap.Elements[i];
        if (i + 1 < size) {
            os << ", ";
        }
    }
    os << "]>";
    return os;
} 
#endif // UNITTEST_DEBUG

#endif
