/*
 * Queue.h
 * 
 * Description: This header file defines the Queue class, a templated link-based implementation of a 
 *              First-In-First-Out (FIFO) data structure. The Queue class provides essential operations 
 *              such as checking if the queue is empty, enqueuing (inserting) elements at the back, 
 *              dequeuing (removing) elements from the front, and peeking at the front element without 
 *              removing it. The underlying data structure is a singly-linked, doubly-headed linked list, 
 *              where each node contains an element of the queue and a pointer to the next node.
 *
 *              The Queue class is designed to be efficient, with all major operations (enqueue, dequeue, 
 *              and peek) having constant time complexity O(1). This efficiency makes it suitable for 
 *              scenarios that require frequent insertion and removal of elements, such as task scheduling 
 *              and buffering processes.
 *
 *              The class is fully templated, allowing it to handle elements of any data type, and it 
 *              includes exception handling mechanisms to ensure robust and safe operations. Specifically, 
 *              attempting to dequeue from or peek at an empty queue throws an EmptyDataCollectionException, 
 *              ensuring that invalid operations are safely managed.
 *
 * Class Invariant: 
 * - The queue is maintained in FIFO order, where the first element inserted is the first to be removed.
 * - The head pointer always points to the front (oldest element) of the queue, and the tail pointer always 
 *   points to the back (newest element).
 * - When the queue is empty, both the head and tail pointers are set to nullptr, and the size is 0.
 * - The size attribute accurately reflects the number of elements currently in the queue.
 *
 * Author: Kunpeng (Andy) Zhang
 * Date: Sep. 2024
 */

 
#ifndef QUEUE_H
#define QUEUE_H

#include "EmptyDataCollectionException.h"

template <typename ElementType>
class Queue {

    private:
    	
    	// Node structure representing each element in the queue
    	struct Node{
    		ElementType data;  // Element stored in this node
    		Node * next = nullptr;  // Pointer to the next node
    		
    		// Constructor to initialize a node with data and an optional next node
    		Node(ElementType& newData, Node* nextNode = nullptr)
            : data(newData), next(nextNode) {}
    	};
    	
    	int size;  // Number of elements in the queue
    	Node* head;  // Pointer to the front of the queue
    	Node* tail;  // Pointer to the back of the queue
    	
    public:

        // Description: Constructor that initializes an empty queue.
        Queue();
	
	    // Description: Destructor that frees all nodes in the queue.
	    ~Queue();
	 
	    // Description: Returns true if this Queue is empty, otherwise false.
	    // Postcondition: This Queue is unchanged by this operation.
	    // Time Efficiency: O(1)
	    bool isEmpty() const;

	    // Description: Inserts newElement at the back of this Queue.
	    //              Returns true if successful.
	    // Time Efficiency: O(1)
	    bool enqueue(ElementType & newElement);

	    // Description: Removes the element at the front of this Queue.
	    // Precondition: This Queue is not empty.
	    // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
	    // Time Efficiency: O(1)
	    void dequeue(); 

	    // Description: Returns (but does not remove) the element at the front of this Queue.
	    // Precondition: This Queue is not empty.
	    // Postcondition: This Queue is unchanged by this operation.
	    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
	    // Time Efficiency: O(1)
	    ElementType & peek() const;
	
        
};

// Include the implementation file (Queue.cpp) after the class definition
#include "../src/Queue.cpp"

#endif