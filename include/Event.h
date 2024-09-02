/*
 * Event.h
 * 
 * Description: This header file defines the Event class, which models arrival and departure events
 *              in a bank simulation. The class uses an enum class to represent the event type, ensuring
 *              type safety and clarity. Each event is characterized by its type (arrival or departure),
 *              the time it occurs, and the transaction length for arrival events. The Event class 
 *              provides constructors, accessors, mutators, and comparison operators necessary for
 *              managing and processing events within the simulation.
 *
 * Class Invariant: 
 * - Arrival events have a type of EventType::ARRIVAL.
 * - Departure events have a type of EventType::DEPARTURE.
 * 
 * Author: Andy Zhang
 * Last Modified: Sep. 2024
 */

#ifndef EVENT_H
#define EVENT_H

#include <iostream>  // For printing event details

class Event {

public:
    // Scoped enum for event types
    // - ARRIVAL: Represents an event where a customer arrives at the bank.
    // - DEPARTURE: Represents an event where a customer completes their transaction and leaves.
    enum class EventType { ARRIVAL, DEPARTURE };

private:
    EventType type;  // The type of the event (ARRIVAL or DEPARTURE)
    int time = 0;    // The time at which the event occurs
    int length = 0;  // The transaction length, relevant only for arrival events

public:
    // Constructors

    // Default Constructor
    // - Initializes the event with default values.
    // - By default, the event is an arrival event occurring at time 0 with a transaction length of 0.
    Event();

    // Constructor with event type and time
    // - Initializes an event with a specified type and time.
    // - The length is irrelevant for departure events and is initialized to 0.
    Event(EventType type, int time);

    // Constructor with event type, time, and length
    // - Initializes an event with a specified type, time, and length.
    // - This constructor is typically used for arrival events where the transaction length is known.
    Event(EventType type, int time, int length);
   
    // Getters

    // Description: Retrieves the type of the event (ARRIVAL or DEPARTURE).
    // Postcondition: Returns the type of the event.
    Event::EventType getType() const;  

    // Description: Retrieves the time at which the event occurs.
    // Postcondition: Returns the time of the event.
    int getTime() const;

    // Description: Retrieves the transaction length associated with the event.
    // Precondition: The event type must be ARRIVAL for the length to be meaningful.
    // Postcondition: Returns the transaction length for arrival events, or 0 for departure events.
    int getLength() const;
    
    // Setters

    // Description: Sets the type of the event (ARRIVAL or DEPARTURE).
    // Postcondition: The event type is updated to the specified value.
    void setType(Event::EventType aType);

    // Description: Sets the time at which the event occurs.
    // Postcondition: The event time is updated to the specified value.
    void setTime(int aTime);

    // Description: Sets the transaction length for an arrival event.
    // Precondition: The event type should be ARRIVAL. If the type is DEPARTURE, the length is set to 0.
    // Postcondition: The event length is updated if the event is of type ARRIVAL.
    void setLength(int aLength);
   
    // Description: Determines if the event is an arrival event.
    // Postcondition: Returns true if the event is an arrival event, false otherwise.
    bool isArrival() const;

    // Overloaded Operators

    // Description: Comparison operator to compare two events.
    // - Events are primarily compared by their time.
    // - If two events occur at the same time, ARRIVAL events are considered less than DEPARTURE events.
    // Postcondition: Returns true if this event occurs before or at the same time as the rhs event.
    bool operator<=(const Event& rhs) const;

    // For Testing Purposes

    // Description: Prints the details of the event for debugging and verification.
    // Postcondition: Outputs the event type, time, and length (if applicable) to the console.
    void print() const;

    // Comparison Operators
    bool operator<(const Event& other) const;  // Declaration of less-than operator
    bool operator>(const Event& other) const;  // Declaration of greater-than operator
};

#endif
