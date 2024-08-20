#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "Heap.h"

template<typename T>
class MaxHeap: public Heap<T>
{
public:
    
    MaxHeap(uint16_t capacity);

    T* getMax();
    T* removeMax();
    void insert(T* element);

private:
    void heapify(uint16_t pos);
};

template <typename T>
MaxHeap<T>::MaxHeap(uint16_t capacity) :
    Heap<T>(capacity)
{
    // Empty
}

template <typename T>
T* MaxHeap<T>::getMax()
{
    if (Heap<T>::isEmpty()) {
        throw;
    }
    return Heap<T>::Elements[0];
}

template <typename T>
T* MaxHeap<T>::removeMax()
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
void MaxHeap<T>::insert(T* element)
{
    if (Heap<T>::isFull()) {
        throw;
    }
    
    Heap<T>::Elements[Heap<T>::Size] = element;
    
    uint16_t pos = Heap<T>::Size;
    while (!Heap<T>::isRoot(pos) && *Heap<T>::Elements[pos] > *Heap<T>::Elements[parent(pos)]) { 
        Heap<T>::swap(pos, parent(pos));
        pos = parent(pos); 
    }

    ++Heap<T>::Size;
}

template <typename T>
void MaxHeap<T>::heapify(uint16_t pos)
{
    if (!Heap<T>::isLeaf(pos)) {
        if (Heap<T>::exists(rightChild(pos))) {
            if (*Heap<T>::Elements[pos] < *Heap<T>::Elements[leftChild(pos)]
                || *Heap<T>::Elements[pos] < *Heap<T>::Elements[rightChild(pos)]) {

                // It is not a leaf and a right child exists, therefore a left 
                // child also exists
                if (*Heap<T>::Elements[leftChild(pos)] > *Heap<T>::Elements[rightChild(pos)]) {
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
            if (*Heap<T>::Elements[pos] < *Heap<T>::Elements[leftChild(pos)]) {
                Heap<T>::swap(pos, leftChild(pos));
                heapify(leftChild(pos));
            }
        }
    }
}

#endif
