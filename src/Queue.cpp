/* 
 * Queue.cpp
 *
 * Description: This file implements the Queue class using a link-based approach. The Queue class 
 *              models a First-In-First-Out (FIFO) data structure, where elements are added to the 
 *              back (tail) of the queue and removed from the front (head). The underlying data 
 *              structure is a singly-linked, doubly-headed linked list, where each node holds an 
 *              element of the queue and a pointer to the next node in the sequence. The class 
 *              supports operations to check if the queue is empty, add an element to the back 
 *              of the queue (enqueue), remove an element from the front (dequeue), and access the 
 *              front element without removing it (peek). The implementation ensures constant-time 
 *              (O(1)) complexity for these operations, making the Queue class efficient and suitable 
 *              for scenarios where a large number of enqueue and dequeue operations are performed.
 *
 *              The class is templated, allowing it to store elements of any data type. It manages 
 *              dynamic memory allocation for the nodes, ensuring that memory is properly allocated 
 *              and freed as elements are added and removed from the queue. The class is designed to 
 *              handle exceptions, specifically when attempting to dequeue from or peek at an empty 
 *              queue, by throwing an EmptyDataCollectionException.
 *
 * Class Invariant: 
 * - The queue is maintained in FIFO order.
 * - The head pointer always points to the front of the queue, and the tail pointer always points to the back.
 * - When the queue is empty, both the head and tail pointers are set to nullptr, and the size is 0.
 * - The size attribute accurately reflects the number of elements currently in the queue.
 *
 * Author: Kunpeng (Andy) Zhang
 * Date: Sep. 2024
 */

 
#include "../include/Queue.h"

template<typename ElementType>
Queue<ElementType>::Queue() : size(0), head(nullptr), tail(nullptr) {
    // Constructor body is empty because initialization is done using initializer list
}

// Destructor
// Description: Frees memory associated with the nodes in the linked list.
template<typename ElementType>
Queue<ElementType>::~Queue() {
    while (!isEmpty()) {
        dequeue();  // dequeue() already handles the memory release
    }
}

// isEmpty
// Description: Returns true if the Queue is empty, otherwise false.
template<typename ElementType>
bool Queue<ElementType>::isEmpty() const {
    return size == 0;
}

// enqueue
// Description: Inserts newElement at the back of the Queue.
// Time Efficiency: O(1)
template<typename ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement) {
    Node* myNode = new Node(newElement);

    if (isEmpty()) {
        head = tail = myNode;
    } else {
        tail->next = myNode;
        tail = myNode;
    }

    ++size;
    return true;  // Successful insertion
}

// dequeue
// Description: Removes the element at the front of the Queue.
// Precondition: The Queue is not empty.
// Exception: Throws EmptyDataCollectionException if the Queue is empty.   
// Time Efficiency: O(1)
template<typename ElementType>
void Queue<ElementType>::dequeue() {
    if (isEmpty()) {
        throw EmptyDataCollectionException();
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    --size;

    if (isEmpty()) {
        tail = nullptr;  // Ensure tail is null if the Queue is empty
    }
}

// peek
// Description: Returns the element at the front of the Queue without removing it.
// Precondition: The Queue is not empty.
// Exception: Throws EmptyDataCollectionException if the Queue is empty.
// Time Efficiency: O(1)
template<typename ElementType>
ElementType& Queue<ElementType>::peek() const {
    if (isEmpty()) {
        throw EmptyDataCollectionException();
    }

    return head->data;
}
