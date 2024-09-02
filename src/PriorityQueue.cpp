/*
 * PriorityQueue.cpp
 * 
 * Description: This file implements the PriorityQueue class, which is a templated priority queue 
 *              that provides efficient management of elements based on priority. The PriorityQueue 
 *              class uses a minimum binary heap as the underlying data structure, ensuring that 
 *              elements with the highest priority (lowest value in a min-heap) are always accessed 
 *              first. The class supports standard operations such as checking if the queue is empty, 
 *              inserting new elements, removing the element with the highest priority, and peeking 
 *              at the highest-priority element without removing it.
 *
 *              The PriorityQueue class is designed for efficiency, with the key operations (insertion 
 *              and removal) having logarithmic time complexity O(log n) due to the properties of the 
 *              binary heap. Checking if the queue is empty and peeking at the highest-priority element 
 *              are both constant time operations O(1). The class handles exceptions gracefully by 
 *              throwing an EmptyDataCollectionException if operations are attempted on an empty queue.
 *
 *              The class is fully templated, allowing it to handle any data type that supports 
 *              comparison operations, making it highly versatile for various applications, 
 *              such as task scheduling, simulation events, or any scenario where prioritized 
 *              processing is required.
 *
 * Class Invariant: 
 * - The PriorityQueue maintains the heap property, where each parent node is less than or equal 
 *   to its child nodes (min-heap).
 * - The element with the highest priority is always at the root of the heap and is the first to be 
 *   removed.
 * - The number of elements in the priority queue is accurately reflected by the size of the binary 
 *   heap.
 * - If the PriorityQueue is empty, attempting to dequeue or peek throws an EmptyDataCollectionException.
 *
 * Author: Kunpeng (Andy) Zhang
 * Last Modified: Sep. 2024
 */

#include "../include/PriorityQueue.h"

// Constructor
// Initializes the Priority Queue with a default capacity of 2
template <typename ElementType>
PriorityQueue<ElementType>::PriorityQueue() : minheap(2) {
    // No additional initialization needed
}

// Destructor
template <typename ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
    // Destructor logic not needed if minheap manages its own resources
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <typename ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return minheap.getElementCount() == 0;
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <typename ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement) {
    return minheap.insert(newElement);
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <typename ElementType>
void PriorityQueue<ElementType>::dequeue() {
    if (isEmpty()) {
        throw EmptyDataCollectionException();
    }
    minheap.remove();
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <typename ElementType>
ElementType& PriorityQueue<ElementType>::peek() const {
    if (isEmpty()) {
        throw EmptyDataCollectionException();
    }
    return minheap.retrieve();
}
