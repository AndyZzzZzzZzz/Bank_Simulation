/*
 * BankSimulation.cpp
 *
 * Description:
 * This file implements a simple bank simulation where customers arrive and are either served immediately 
 * if the teller is available or placed in a queue if the teller is busy. The simulation tracks customer 
 * arrivals and departures using events, which are managed in a priority queue. The bank line is represented 
 * as a queue of events waiting to be processed. The simulation calculates and outputs the total number of 
 * customers processed and the average wait time at the end.
 *
 * The program consists of the following key components:
 * - processArrival: Handles the arrival of customers, determining whether they are served immediately or 
 *   placed in a waiting line.
 * - processDeparture: Handles the departure of customers after they have been served, updating the queue 
 *   and managing the availability of the teller.
 * - outputEventProcessing: Outputs details of the event currently being processed, helping to track the 
 *   simulation's progress.
 * - Main Function: Initializes the simulation, reads customer data, processes all events, and outputs 
 *   the final statistics, including total customers processed and average wait time.
 *
 * This simulation demonstrates basic event-driven programming concepts using queues and priority queues. 
 * It provides insights into queue management, event handling, and the effects of processing time and 
 * arrival rates on customer wait times.
 *
 * Author: Kunpeng (Andy) Zhang
 * Last Modified: Sep. 2024
 */

#include <iostream>
#include <iomanip> // For std::setw, used to format the output
#include "../include/Event.h" // Include the Event class definition
#include "../include/EmptyDataCollectionException.h" // Include the exception class for empty data collections
#include "../include/PriorityQueue.h" // Include the PriorityQueue class definition
#include "../include/Queue.h" // Include the Queue class definition

using namespace std;

// Function: processArrival
// Purpose: This function processes an arrival event in the simulation. It determines whether the teller is available 
//          or if the customer needs to wait in the queue. If the teller is available, a departure event is scheduled 
//          immediately. If not, the customer is added to the queue.
// Parameters:
//   - newEvent: The arrival event being processed.
//   - eventPriorityQueue: The priority queue that stores and orders all events in the simulation.
//   - bankLine: The queue that represents the line of customers waiting for service at the bank.
//   - simulationTime: The current time in the simulation, updated to the time of the new event.
//   - tellerAvailable: A boolean flag indicating whether the teller is currently available.
void processArrival(Event& newEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int& simulationTime, bool& tellerAvailable) {
    // Remove the arrival event from the priority queue since it's being processed
    eventPriorityQueue.dequeue();

    // If the bank line is empty and the teller is available, process the customer immediately
    if (bankLine.isEmpty() && tellerAvailable) {
        // Calculate the departure time for this customer based on the current simulation time and their processing time
        int departureTime = simulationTime + newEvent.getLength();

        // Create a new departure event for this customer
        Event newDepartureEvent(Event::EventType::DEPARTURE, departureTime);

        // Add the departure event to the priority queue
        eventPriorityQueue.enqueue(newDepartureEvent);

        // Mark the teller as unavailable since they are now serving a customer
        tellerAvailable = false;
    } else {
        // If the teller is busy, add the customer to the bank line to wait for service
        bankLine.enqueue(newEvent);
    }
}

// Function: processDeparture
// Purpose: This function processes a departure event in the simulation. It either moves the next customer in line 
//          to the teller or marks the teller as available if no customers are waiting.
// Parameters:
//   - newEvent: The departure event being processed.
//   - eventPriorityQueue: The priority queue that stores and orders all events in the simulation.
//   - bankLine: The queue that represents the line of customers waiting for service at the bank.
//   - simulationTime: The current time in the simulation, updated to the time of the new event.
//   - tellerAvailable: A boolean flag indicating whether the teller is currently available.
//   - cumulativeWaitTime: A running total of all customers' wait times, used to calculate the average wait time.
void processDeparture(Event& newEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int& simulationTime, bool& tellerAvailable, int& cumulativeWaitTime) {
    // Remove the departure event from the priority queue since it's being processed
    eventPriorityQueue.dequeue();

    // If there are customers waiting in the bank line, move the next customer to the teller
    if (!bankLine.isEmpty()) {
        // Get the next customer from the bank line
        Event customer = bankLine.peek();
        bankLine.dequeue();

        // Calculate the customer's wait time based on the current simulation time and their arrival time
        int waitTime = simulationTime - customer.getTime();
        cumulativeWaitTime += waitTime; // Update the cumulative wait time

        // Calculate the departure time for this customer based on the current simulation time and their processing time
        int departureTime = simulationTime + customer.getLength();

        // Create a new departure event for this customer
        Event newDepartureEvent(Event::EventType::DEPARTURE, departureTime);

        // Add the departure event to the priority queue
        eventPriorityQueue.enqueue(newDepartureEvent);
    } else {
        // If no customers are waiting, mark the teller as available
        tellerAvailable = true;
    }
}

// Function: outputEventProcessing
// Purpose: This helper function outputs a message indicating that an event is being processed. It formats 
//          the output to align the event times consistently.
// Parameters:
//   - event: The event being processed.
//   - type: A string indicating the type of event ("arrival" or "departure").
void outputEventProcessing(const Event& event, const std::string& type) {
    if (type == "arrival") {
        cout << "Processing an " << type << " event at time:" << setw(5) << event.getTime() << endl;
    } else { // type is "departure"
        cout << "Processing a " << type << " event at time:" << setw(4) << event.getTime() << endl;
    }
}

int main() {
    cout << "Simulation Begins" << endl;

    // Initialize the bank line (a queue of events representing customers waiting for service)
    Queue<Event> bankLine;
    // Initialize the event priority queue (a priority queue of events to be processed in the simulation)
    PriorityQueue<Event> eventPriorityQueue;
    // Initialize a boolean flag to track whether the teller is available
    bool tellerAvailable = true;
    // Initialize the simulation time
    int simulationTime = 0;
    // Variables to hold arrival and processing times for customers
    int arriveTime, processTime;
    // Initialize counters for the total number of customers and the cumulative wait time
    int customerCount = 0;
    int cumulativeWaitTime = 0;

    // Read customer arrival and processing times from input and create corresponding arrival events
    while (cin >> arriveTime >> processTime) {
        // Create a new arrival event
        Event newArrivalEvent(Event::EventType::ARRIVAL, arriveTime, processTime);

        // Add the arrival event to the event priority queue
        eventPriorityQueue.enqueue(newArrivalEvent);
        // Increment the customer count
        customerCount++;
    }

    // Process all events in the priority queue until it is empty
    while (!eventPriorityQueue.isEmpty()) {
        // Get the next event to process (either an arrival or a departure)
        Event newEvent = eventPriorityQueue.peek();
        // Update the simulation time to the time of this event
        simulationTime = newEvent.getTime();

        // Check if the event is an arrival or a departure and process accordingly
        if (newEvent.isArrival()) {
            // Output the processing of the arrival event
            outputEventProcessing(newEvent, "arrival");
            // Process the arrival event
            processArrival(newEvent, eventPriorityQueue, bankLine, simulationTime, tellerAvailable);
        } else {
            // Output the processing of the departure event
            outputEventProcessing(newEvent, "departure");
            // Process the departure event
            processDeparture(newEvent, eventPriorityQueue, bankLine, simulationTime, tellerAvailable, cumulativeWaitTime);
        }
    }

    // Calculate the average wait time for all customers
    float averageWaitTime = static_cast<float>(cumulativeWaitTime) / customerCount;

    // Output the final statistics of the simulation
    cout << "Simulation Ends" << endl;
    cout << "\nFinal Statistics:\n" << endl;
    cout << "    Total number of people processed: " << customerCount << endl;
    cout << "    Average amount of time spent waiting: " << averageWaitTime << endl;

    return 0;
}
