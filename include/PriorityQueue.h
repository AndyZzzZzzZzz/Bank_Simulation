/*
 * PriorityQueue.h
 * 
 * Description: This header file defines the PriorityQueue class, a templated priority queue 
 *              implementation that organizes elements based on their priority. The class uses 
 *              a minimum binary heap as the underlying data structure, ensuring that elements 
 *              with the highest priority (smallest value in a min-heap) are always at the front 
 *              of the queue and can be efficiently accessed and removed. The PriorityQueue 
 *              class provides essential operations such as checking if the queue is empty, 
 *              inserting elements, removing the highest-priority element, and peeking at the 
 *              highest-priority element without removing it.
 *
 *              The PriorityQueue class is designed to handle various data types efficiently, 
 *              thanks to its templated design. It ensures that the most critical operations 
 *              have optimal time complexity: insertion and removal are O(log n) due to the 
 *              binary heap's properties, and checking if the queue is empty or peeking at 
 *              the highest-priority element are both O(1). The class includes exception handling 
 *              mechanisms to safely manage operations on an empty queue by throwing an 
 *              EmptyDataCollectionException when necessary.
 *
 * Class Invariant: 
 * - The priority queue maintains the heap property, where each parent node is less than or 
 *   equal to its child nodes (min-heap).
 * - The element with the highest priority is always at the root of the heap.
 * - The number of elements in the priority queue is accurately reflected by the size of the 
 *   binary heap.
 * - If the priority queue is empty, attempting to dequeue or peek throws an 
 *   EmptyDataCollectionException.
 *
 * Author: Kunpeng (Andy) Zhang
 * Last Modified: Sep. 2024
 */


#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
 
// Include exception file 
#include "EmptyDataCollectionException.h"
// Include binary heap file 
#include "BinaryHeap.h"

template <typename ElementType>
class PriorityQueue {
	
	private:
		BinaryHeap<ElementType> minheap;  // The underlying minimum binary heap

	public:
	
	// Constructor
	PriorityQueue();
	
	// Destructor
	~PriorityQueue();
	
	
	// Description: Returns true if this Priority Queue is empty, otherwise false.
	// Postcondition: This Priority Queue is unchanged by this operation.
	// Time Efficiency: O(1)
	bool isEmpty() const;

	// Description: Inserts newElement in this Priority Queue and 
	//              returns true if successful, otherwise false.
	// Time Efficiency: O(log2 n)
	bool enqueue(const ElementType& newElement);  // Parameter is now passed by const reference

	// Description: Removes (but does not return) the element with the next
	//              "highest" priority value from the Priority Queue.
	// Precondition: This Priority Queue is not empty.
	// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
	// Time Efficiency: O(log2 n)
	void dequeue();

	// Description: Returns (but does not remove) the element with the next 
	//              "highest" priority value from the Priority Queue.
	// Precondition: This Priority Queue is not empty.
	// Postcondition: This Priority Queue is unchanged by this operation.
	// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
	// Time Efficiency: O(1)
	ElementType& peek() const;
   
 };
   
// Include the implementation file (PriorityQueue.cpp) after the class definition
#include "../src/PriorityQueue.cpp"
 
#endif
