/*
 * Event.cpp
 *
 * Description: This implementation file defines the member functions of the Event class, which models
 *              the arrival and departure events within a bank simulation. The Event class supports the 
 *              creation and management of events, including functionality for retrieving event details, 
 *              comparing events, and determining if an event is an arrival. The class uses an enum class 
 *              for the event type to ensure clear and type-safe operations. Additional functionality includes
 *              a print method for debugging and verification purposes.
 * 
 * Author: Andy Zhang
 * Last Modified: Sep. 2024
 */

#include <iostream>
#include "../include/Event.h"

// Default Constructor
// Description: Initializes an Event object as an arrival event occurring at time 0 with a transaction length of 0.
// Postcondition: The event is set to type ARRIVAL, time 0, and length 0.
Event::Event() : type(EventType::ARRIVAL), time(0), length(0) { }

// Constructor with EventType and time
// Description: Initializes an Event object with a specified type and time. 
//              The length is initialized to 0, as it is only relevant for arrival events.
// Postcondition: The event is set to the specified type and time. Length is set to 0.
Event::Event(EventType aType, int aTime) : type(aType), time(aTime), length(0) { }

// Constructor with EventType, time, and length
// Description: Initializes an Event object with a specified type, time, and length. 
//              This constructor is typically used for arrival events where the transaction length is known.
// Postcondition: The event is set to the specified type, time, and length (if the type is ARRIVAL).
Event::Event(EventType aType, int aTime, int aLength) 
    : type(aType), time(aTime), length((aType == EventType::ARRIVAL) ? aLength : 0) { }

// Getters

// getType
// Description: Returns the type of the event (ARRIVAL or DEPARTURE).
// Postcondition: The event type is returned.
Event::EventType Event::getType() const {
   return type;
}

// getTime
// Description: Returns the time at which the event occurs.
// Postcondition: The event time is returned.
int Event::getTime() const {
   return time;
}

// getLength
// Description: Returns the transaction length for an arrival event. 
//              The length is meaningful only if the event type is ARRIVAL.
// Postcondition: The transaction length is returned if the event is an ARRIVAL, otherwise 0 is returned.
int Event::getLength() const {
   return length;
}

// Setters

// setType
// Description: Sets the type of the event to either ARRIVAL or DEPARTURE.
// Postcondition: The event type is updated to the specified value.
void Event::setType(Event::EventType aType) {
   type = aType;
}

// setTime
// Description: Sets the time at which the event occurs.
// Postcondition: The event time is updated to the specified value.
void Event::setTime(int aTime) {
   time = aTime;
}

// setLength
// Description: Sets the transaction length for the event. 
//              The length is only relevant for arrival events, and will be set to 0 for departure events.
// Postcondition: If the event is an ARRIVAL, the length is updated to the specified value. Otherwise, it is set to 0.
void Event::setLength(int aLength) {
   length = (type == EventType::ARRIVAL) ? aLength : 0;
}

// isArrival
// Description: Checks whether the event is an arrival event.
// Postcondition: Returns true if the event type is ARRIVAL, otherwise false.
bool Event::isArrival() const {
   return type == EventType::ARRIVAL;
}

// Overloaded Operators

// operator<=
// Description: Compares two Event objects based on their time. 
//              If the times are equal, ARRIVAL events are considered less than DEPARTURE events.
// Postcondition: Returns true if this event occurs before or at the same time as the rhs event. 
//                If times are equal, ARRIVAL events are considered earlier than DEPARTURE events.
bool Event::operator<=(const Event& rhs) const {
   if (time == rhs.getTime()) {
      return (type == rhs.getType()) || (type == EventType::ARRIVAL && rhs.getType() == EventType::DEPARTURE);
   } else {
      return time < rhs.getTime();
   }
}

// For Testing Purposes

// print
// Description: Outputs the details of the event to the console for debugging and verification.
//              This includes the event type (as "Arrival" or "Departure"), the time, and the length if applicable.
// Postcondition: The event details are printed to the console.
void Event::print() const {
   std::cout << "Event - Type: " << (type == EventType::ARRIVAL ? "Arrival" : "Departure") 
             << ", Time: " << time 
             << ((type == EventType::ARRIVAL) ? (", Length: " + std::to_string(length)) : "") 
             << std::endl;
}

// Comparison operator for less than
bool Event::operator<(const Event& other) const {
    return this->time < other.time;  // Assuming time is the attribute to compare
}

// Comparison operator for greater than
bool Event::operator>(const Event& other) const {
    return this->time > other.time;  // Assuming time is the attribute to compare
}
