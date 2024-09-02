/*
 * BinaryHeap.cpp
 * 
 * Description: This file implements the BinaryHeap class, a templated data structure that provides 
 *              efficient management of elements in a binary heap. A binary heap is a complete binary 
 *              tree where each node is smaller than or equal to its children (in the case of a min-heap), 
 *              ensuring that the smallest element is always at the root. This implementation supports 
 *              key operations such as insertion, retrieval, and removal of elements, while maintaining 
 *              the heap property.
 *
 *              The BinaryHeap class uses a dynamic array to store heap elements, with the array size 
 *              automatically expanding when the number of elements exceeds the current capacity. 
 *              The class includes utility methods like `reHeapUp` and `reHeapDown` to restore the 
 *              heap order after insertions and deletions. The expandHeap method ensures that the 
 *              heap can grow as needed, doubling the capacity when required.
 *
 *              This implementation is designed for efficiency, with insertion and removal operations 
 *              having logarithmic time complexity O(log n), while retrieval and checking the element 
 *              count are constant time operations O(1). The BinaryHeap class is templated, allowing it 
 *              to handle any data type that supports comparison operations, making it versatile for 
 *              various applications, such as priority queues, scheduling systems, and more.
 *
 * Class Invariant: 
 * - The binary heap maintains the heap property, where each parent node is less than or equal to 
 *   its child nodes in a min-heap configuration.
 * - The root element is always the smallest element in the heap.
 * - The dynamic array used to store heap elements can expand as needed to accommodate more elements.
 * - If the heap is empty, attempts to retrieve or remove an element will throw an 
 *   EmptyDataCollectionException.
 *
 * Author: Kunpeng (Andy) Zhang
 * Last Modified: Sep. 2024
 */

#include "../include/BinaryHeap.h"
#include <algorithm>  // For std::swap, std::copy

// Constructor to initialize array 
template<typename ElementType>
BinaryHeap<ElementType>::BinaryHeap(unsigned int capacity)
    : elements(new ElementType[capacity]), capacity(capacity), elementCount(0) {}

// Destructor
template<typename ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {
    delete[] elements;
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template<typename ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Inserts newElement into the Binary Heap. 
//              Returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template<typename ElementType>
bool BinaryHeap<ElementType>::insert(const ElementType& newElement) {
    // If elementCount reaches capacity, expand the heap
    if (elementCount == capacity) {
        expandHeap();
    }
    
    // Insert new element and reheap up to maintain heap property
    elements[elementCount] = newElement;
    reHeapUp(elementCount);
    elementCount++;
    
    return true;
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template<typename ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() const {
    if (elementCount == 0) {
        throw EmptyDataCollectionException();
    }
    return elements[0];
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template<typename ElementType>
void BinaryHeap<ElementType>::remove() {
    if (elementCount == 0) {
        throw EmptyDataCollectionException();
    }
    
    elements[0] = elements[elementCount - 1];
    elementCount--;
    
    if (elementCount > 0) {
        reHeapDown(0);
    }
}

// Utility method
// Description: Recursively puts the array back into a minimum Binary Heap.
// Postcondition: Minimum binary heap is weakly ordered
// Time efficiency: O(log2 n)
template<typename ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfChild) {
    unsigned int indexOfParent = (indexOfChild - 1) / 2;
    
    while (indexOfChild > 0 && elements[indexOfParent] > elements[indexOfChild]) {
        std::swap(elements[indexOfChild], elements[indexOfParent]);
        indexOfChild = indexOfParent;
        indexOfParent = (indexOfChild - 1) / 2;
    }
}

// Description: Recursively puts the array back into a minimum Binary Heap.
// Postcondition: Minimum binary heap is weakly ordered
// Time efficiency: O(log2 n)
template<typename ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {
    unsigned int indexOfMinChild = indexOfRoot;
    unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
    unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

    if (indexOfLeftChild < elementCount && elements[indexOfLeftChild] < elements[indexOfMinChild]) {
        indexOfMinChild = indexOfLeftChild;
    }

    if (indexOfRightChild < elementCount && elements[indexOfRightChild] < elements[indexOfMinChild]) {
        indexOfMinChild = indexOfRightChild;
    }

    if (indexOfMinChild != indexOfRoot) {
        std::swap(elements[indexOfRoot], elements[indexOfMinChild]);
        reHeapDown(indexOfMinChild);
    }
}

// Description: Expands the binary heap if elementCount reaches capacity.
// Postcondition: New binary heap is double its original size.
// Time efficiency: O(n)
template<typename ElementType>
void BinaryHeap<ElementType>::expandHeap() {
    capacity *= 2;
    ElementType* newHeap = new ElementType[capacity];
    
    // Use std::copy for better readability and potential optimizations
    std::copy(elements, elements + elementCount, newHeap);
    
    delete[] elements;
    elements = newHeap;
}
