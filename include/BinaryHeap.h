/*
 * BinaryHeap.h
 * 
 * Description: This header file defines the BinaryHeap class, a templated data structure that implements 
 *              a binary heap, specifically a min-heap. A binary heap is a complete binary tree where each 
 *              node is smaller than or equal to its children. This structure ensures that the smallest 
 *              element is always at the root, making it efficient for priority queue implementations and 
 *              other applications where the minimum element needs to be quickly accessed.
 *
 *              The BinaryHeap class is designed to be versatile and efficient, supporting operations 
 *              such as insertion, retrieval, and removal of elements while maintaining the heap property. 
 *              The class uses a dynamic array to store the heap elements, which automatically expands 
 *              when the number of elements exceeds the current capacity. Utility methods such as `reHeapUp` 
 *              and `reHeapDown` are used to restore the heap order after modifications.
 *
 *              The class provides an O(1) method for retrieving the number of elements in the heap, 
 *              and insertion and removal operations have a logarithmic time complexity O(log n). 
 *              The class is fully templated, allowing it to work with any data type that supports 
 *              comparison operations, making it ideal for a wide range of applications.
 *
 * Class Invariant: 
 * - The binary heap maintains the heap property, where each parent node is less than or equal to 
 *   its child nodes (min-heap).
 * - The root element is always the smallest element in the heap.
 * - The dynamic array used to store heap elements can expand as needed to accommodate more elements.
 * - If the heap is empty, attempts to retrieve or remove an element will throw an 
 *   EmptyDataCollectionException.
 *
 * Author: Kunpeng (Andy) Zhang
 * Last Modified: Sep. 2024
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "EmptyDataCollectionException.h"
#include <algorithm>  // For std::swap and std::copy

template<typename ElementType>
class BinaryHeap {
    private:
        ElementType* elements;  // Pointer to the dynamic array that stores heap elements
        unsigned int capacity;  // The current capacity of the array
        unsigned int elementCount;  // The number of elements currently in the heap

        // Utility methods to maintain the heap property
        void reHeapUp(unsigned int indexOfChild);
        void reHeapDown(unsigned int indexOfRoot);
        void expandHeap();  // Method to expand the dynamic array when capacity is reached

    public:
        // Constructor
        BinaryHeap(unsigned int capacity = 10);  // Default initial capacity

        // Destructor
        ~BinaryHeap();

        // Description: Returns the number of elements in the Binary Heap.
        // Postcondition: The Binary Heap is unchanged by this operation.
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Inserts newElement into the Binary Heap.
        //              Returns true if successful, otherwise false.
        // Time Efficiency: O(log2 n)
        bool insert(const ElementType& newElement);  // Now accepting const ElementType&

        // Description: Retrieves (but does not remove) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Postcondition: This Binary Heap is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(1)
        ElementType& retrieve() const;

        // Description: Removes (but does not return) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(log2 n)
        void remove();
};

#include "../src/BinaryHeap.cpp"

#endif  // BINARYHEAP_H
