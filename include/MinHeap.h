#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include "heap_common.h"
#include "Heap.h"

template<typename T>
class MinHeap: public Heap<T>
{
public:
    
    MinHeap(uint16_t capacity);

    T* min();
    T* removeMin();
    void insert(T* element);

    template <typename S>
    friend std::ostream& operator<<(std::ostream& os, MinHeap<S>& heap);

private:
    void heapify(uint16_t pos);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, MinHeap<T>& heap)
{
    os << "<MinHeap Size=" << heap.size() << " Capacity=" << heap.maxSize() << " [";
    uint16_t size = heap.size();
    for (uint16_t i = 0; i < size; ++i) {
        os << *heap.get(i);
        if (i < size) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template <typename T>
MinHeap<T>::MinHeap(uint16_t capacity) :
    Heap<T>(capacity)
{
    // Empty
}

template <typename T>
T* MinHeap<T>::min()
{
    if (Heap<T>::isEmpty()) {
        throw;
    }
    return Heap<T>::Elements[0];
}

template <typename T>
T* MinHeap<T>::removeMin()
{
    if (Heap<T>::isEmpty()) {
        throw;
    }
    T* result = Heap<T>::Elements[0];
    Heap<T>::Elements[0] = Heap<T>::Elements[Heap<T>::Size - 1];
    --Heap<T>::Size; 
    heapify(0); 

    return result; 
}

template <typename T>
void MinHeap<T>::insert(T* element)
{
    if (Heap<T>::isFull()) {
        throw;
    }
    
    Heap<T>::Elements[Heap<T>::Size] = element;
    
    uint16_t pos = Heap<T>::Size;
    while (!Heap<T>::isRoot(pos) && *Heap<T>::Elements[pos] < *Heap<T>::Elements[parent(pos)]) { 
        Heap<T>::swap(pos, parent(pos));
        pos = parent(pos); 
    }

    ++Heap<T>::Size;
}

template <typename T>
void MinHeap<T>::heapify(uint16_t pos)
{
    if (!Heap<T>::isLeaf(pos)) {
        if (Heap<T>::exists(rightChild(pos))) {
            if (*Heap<T>::Elements[pos] > *Heap<T>::Elements[leftChild(pos)]
                || *Heap<T>::Elements[pos] > *Heap<T>::Elements[rightChild(pos)]) {

                // It is not a leaf and a right child exists, therefore a left 
                // child also exists
                if (*Heap<T>::Elements[leftChild(pos)] < *Heap<T>::Elements[rightChild(pos)]) {
                    Heap<T>::swap(pos, leftChild(pos));
                    heapify(leftChild(pos));
                }
                else {
                    Heap<T>::swap(pos, rightChild(pos));
                    heapify(rightChild(pos));
                }
            }
        }
        else {
            // It is not a leaf but there is no right child. 
            // Only a left child exists
            if (*Heap<T>::Elements[pos] > *Heap<T>::Elements[leftChild(pos)]) {
                Heap<T>::swap(pos, leftChild(pos));
                heapify(leftChild(pos));
            }
        }
    }
}

#endif
