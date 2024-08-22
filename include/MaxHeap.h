#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "Heap.h"

/**
 * A min-heap implementation.
 */
template<typename T>
class MaxHeap: public Heap<T>
{
public:
    /**
     * Create a max heap that can hold pointers to up to the specified number of 
     * elements.
     * @param capacity The max amount of elements the heap can contain.
     */  
    MaxHeap(uint16_t capacity);

    /**
     * Return the largest element in the heap.
     * @return The largest element in the heap.
     */
    T* getMax() const;

    /**
     * Inserts a new element in the heap. If an element is inserted which has 
     * the same rank as an already existing element, the already existing
     * element will be placed before the new element.
     * @param element The element to insert.
     * @return The element pointer if there was enough space left to insert, 
     * nullptr otherwise.
     */
    T* insert(T* element);

    /**
     * Removes the largest element in the heap. The element is not deleted, it 
     * it just removed from the heap.
     * @return A pointer to the removed element.
     */
    T* removeMax();

    /**
     * Updates the heap to be ordered again after the largest element has been 
     * changed. This is more efficient than calling x = removeMax() and then 
     * insert(x) after x has been updated.
     */
    void updateMax();

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
T* MaxHeap<T>::getMax() const
{
    if (Heap<T>::isEmpty()) {
        return nullptr;
    }
    return Heap<T>::Elements[0];
}

template <typename T>
T* MaxHeap<T>::removeMax()
{
    if (Heap<T>::isEmpty()) {
        return nullptr;
    }
    T* result = Heap<T>::Elements[0];
    Heap<T>::Elements[0] = Heap<T>::Elements[Heap<T>::Size - 1];
    --Heap<T>::Size; 
    std::cerr << "After removeMax before heapify: " << *this << std::endl;
    heapify(0); 

    return result; 
}

template <typename T>
void MaxHeap<T>::updateMax()
{
    heapify(0);
}

template <typename T>
T* MaxHeap<T>::insert(T* element)
{
    if (Heap<T>::isFull()) {
        return nullptr;
    }
    
    Heap<T>::Elements[Heap<T>::Size] = element;
    
    uint16_t pos = Heap<T>::Size;
    while (!Heap<T>::isRoot(pos) && *Heap<T>::Elements[pos] > *Heap<T>::Elements[parent(pos)]) { 
        Heap<T>::swap(pos, parent(pos));
        pos = parent(pos); 
    }

    ++Heap<T>::Size;

    return element;
}

template <typename T>
void MaxHeap<T>::heapify(uint16_t pos)
{
    if (!Heap<T>::isLeaf(pos)) {
        if (Heap<T>::exists(rightChild(pos))) {
            if (*Heap<T>::Elements[pos] < *Heap<T>::Elements[leftChild(pos)]
                || *Heap<T>::Elements[pos] < *Heap<T>::Elements[rightChild(pos)]) {
                // It is not a leaf and both left and right children exist
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
            // It is leaf and only a left child exists
            if (*Heap<T>::Elements[pos] < *Heap<T>::Elements[leftChild(pos)]) {
                Heap<T>::swap(pos, leftChild(pos));
                heapify(leftChild(pos));
            }
        }
    }
}

#endif
