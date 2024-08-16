# About
uHeaps is a small library for working with binary min and max heaps that can be useful for implementing priority queues. Two template classes exist: MinHeap and MaxHeap. The template argument is a class which represents the elements in the heap. For a general description of binary heaps, see https://en.wikipedia.org/wiki/Binary_heap.

# Usage
First define a class which will represent an element of the heap. The element class must implement operator< and operator>.
Next instantiate a heap with the element class. See example below.

The MinHeap and MaxHeap classes don't do any memory management of the elements. It is the responsibility of the caller. The heap will only keep track of the heap order.

## Example element class
The following class represents an element which simply holds an integer value.

    class Element
    {
    public:
        Element(int value = 0): Value(value) {};

        // operator< is required by the heap classes
        bool operator<(const Element& other) {
            return Value < other.Value;
        }

        // operator> is required by the heap classes
        bool operator>(const Element& other) {
            return Value > other.Value;
        }
       
        // Optionally define operator<< to easily print the element contents.
        friend std::ostream& operator<<(std::ostream& os, const Element& element);

        // The actual value of this element
        int Value;
    };


# Application example
Using the above Example class definition:

    // Create a min heap which can hold up to 7 Elements.
    MinHeap<Element> heap(7);

    // Create some elements which can be inserted
    Element e1(3);
    Element e2(5);
    Element e3(1);

    // Insert them
    heap.insert(&e1);
    heap.insert(&e2);
    heap.insert(&e3);

    // Get the smallest element, which is e3
    Element* m = heap.min();

    // If an element is updated, it needs to be removed from the MinHeap, and then re-added 

    // Remove and return the smallest element. Note that the element is only removed from the heap, it still exists and has not been destroyed.
    m = heap.removeMin();

    // Update its value
    m->Value = 11;

    // Insert it into the heap again
    heap.insert(m);

    // Now, the min element is e1
    Element* m = heap.min();
