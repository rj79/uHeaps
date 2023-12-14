#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdint.h>
#include <iostream>

uint16_t parent(uint16_t id);
uint16_t leftChild(uint16_t id);
uint16_t rightChild(uint16_t id);

template<typename T>
class MinHeap
{
public:
    
    MinHeap(uint16_t maxSize);
    virtual ~MinHeap();

    const bool isEmpty();
    const bool isFull();
    const uint16_t size();
    const uint16_t maxSize();
    T& get(uint16_t pos);
    T& min();
    T removeMin();
    void insert(T element);

    template <typename S>
    friend std::ostream& operator<<(std::ostream& os, MinHeap<S>& heap);
private:
    T* Elements;
    uint16_t MaxSize;
    uint16_t Size;

    const bool isRoot(uint16_t pos);
    const bool isLeaf(uint16_t pos);
    const bool exists(uint16_t pos);
    void swap(uint16_t posA, uint16_t posB);
    void heapify(uint16_t pos);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, MinHeap<T>& heap)
{
    os << "<MinHeap Size=" << heap.size() << " MaxSize=" << heap.maxSize() << " [";
    uint16_t size = heap.size();
    for (uint16_t i = 0; i < size; ++i) {
        os << heap.get(i);
        if (i < size) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

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

template <typename T>
MinHeap<T>::MinHeap(uint16_t maxSize) :
    MaxSize(maxSize),
    Size(0)
{
    if (MaxSize == 0) {
        throw;
    }
    Elements = new T[MaxSize];
}

template <typename T>
MinHeap<T>::~MinHeap()
{
    delete[] Elements;
}

template <typename T>
const bool MinHeap<T>::isEmpty()
{
    return Size == 0;
}

template <typename T>
const bool MinHeap<T>::isFull()
{
    return Size == MaxSize;
}

template <typename T>
const uint16_t MinHeap<T>::size()
{
    return Size;
}

template <typename T>
const uint16_t MinHeap<T>::maxSize()
{
    return MaxSize;
}

template <typename T>
T& MinHeap<T>::get(uint16_t pos)
{
    if (!exists(pos)) {
        throw;
    }
    return Elements[pos];
}

template <typename T>
T& MinHeap<T>::min()
{
    if (isEmpty()) {
        throw;
    }
    return Elements[0];
}

template <typename T>
T MinHeap<T>::removeMin()
{
    //std::cout << "removeMin" << std::endl;
    if (isEmpty()) {
        throw;
    }
    T result = Elements[0];
    Elements[0] = Elements[Size - 1];
    --Size; 
    heapify(0); 

    //std::cout << "removeMin => " << result << std::endl;
    return result; 
}

template <typename T>
void MinHeap<T>::insert(T element)
{
    //std::cout << "insert " << element << std::endl;
    if (isFull()) {
        throw;
    }
    
    Elements[Size] = element;
    
    uint16_t pos = Size;
    //std::cout << Size << std::endl;
    while (!isRoot(pos) && Elements[pos] < Elements[parent(pos)]) { 
        swap(pos, parent(pos));
        pos = parent(pos); 
    }

    ++Size;
}

template <typename T>
const bool MinHeap<T>::isRoot(uint16_t pos) {
    return pos == 0;
}

template <typename T>
const bool MinHeap<T>::isLeaf(uint16_t pos) {
    return (pos << 1) >= Size;
}

template <typename T>
const bool MinHeap<T>::exists(uint16_t pos) {
    return pos < Size;
}

template <typename T>
void MinHeap<T>::swap(uint16_t posA, uint16_t posB)
{
    //std::cout << "swap " << posA << "(" << Elements[posA] << ") <-> " << posB << "(" << Elements[posB] << ")" << std::endl;
    T temp = Elements[posA];
    Elements[posA] = Elements[posB];
    Elements[posB] = temp;
}

template <typename T>
void MinHeap<T>::heapify(uint16_t pos)
{
    //std::cout << "heapify " << pos << std::endl;
    if (!isLeaf(pos)) {
        if (exists(rightChild(pos))) {
            if (Elements[pos] > Elements[leftChild(pos)]
                || Elements[pos] > Elements[rightChild(pos)]) {

                // It is not a leaf and a right child exists, therefore a left 
                // child also exists
                if (Elements[leftChild(pos)] < Elements[rightChild(pos)]) {
                    swap(pos, leftChild(pos));
                    heapify(leftChild(pos));
                }
                else {
                    swap(pos, rightChild(pos));
                    heapify(rightChild(pos));
                }
            }
        }
        else {
            // It is not a leaf but there is no right child. 
            // Only a left child exists
            if (Elements[pos] > Elements[leftChild(pos)]) {
                swap(pos, leftChild(pos));
                heapify(leftChild(pos));
            }
        }
    }
}

#endif
