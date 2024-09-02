# Bank Simulation

## Overview

This project implements a simple bank simulation where customers arrive and are either served immediately if the teller is available or placed in a queue if the teller is busy. The simulation tracks customer arrivals and departures using events, which are managed in a priority queue. The bank line is represented as a queue of events waiting to be processed. The simulation outputs the total number of customers processed and the average wait time at the end.

## Features

- **Event-Driven Simulation:** Simulates bank operations using event-driven programming techniques.
- **Queue Management:** Manages customer queues efficiently with FIFO (First-In, First-Out) order using a custom queue implementation.
- **Priority Queue:** Manages events (arrivals and departures) using a priority queue implemented with a binary heap.
- **Performance Insights:** Calculates average wait time and tracks the total number of customers processed.

## Project Structure

The project is organized into the following directories and files:

```plaintext
Bank_Simulation/
├── Makefile                       # Build and test automation
├── README.md                      # Project documentation
├── src/                           # Source code directory
│   ├── BankSimulation.cpp         # Main driver file
│   ├── Event.cpp                  # Event class implementation
│   ├── PriorityQueue.cpp          # PriorityQueue class implementation
│   ├── Queue.cpp                  # Queue class implementation
│   └── BinaryHeap.cpp             # BinaryHeap class implementation
├── include/                       # Header files directory
│   ├── Event.h                    # Event class definition
│   ├── PriorityQueue.h            # PriorityQueue class definition
│   ├── Queue.h                    # Queue class definition
│   ├── BinaryHeap.h               # BinaryHeap class definition
│   └── EmptyDataCollectionException.h  # Custom exception class for empty data collections
├── input/                         # Test input files directory
│   ├── sample_input_1.txt         # Sample input case 1
│   ├── sample_input_2.txt         # Sample input case 2
│   └── sample_input_3.txt         # Sample input case 3
├── output/                        # Test output files directory
│   ├── sample_output_1.txt        # Expected output for sample input case 1
│   ├── sample_output_2.txt        # Expected output for sample input case 2
│   └── sample_output_3.txt        # Expected output for sample input case 3
├── tests/                         # Testing scripts directory
│   ├── test_case_1.py             # Python script to validate test case 1
│   ├── test_case_2.py             # Python script to validate test case 2
│   └── test_case_3.py             # Python script to validate test case 3
```
## Getting Started

### Prerequisites

To build and run this project, you will need:

- A C++ compiler that supports C++11 (e.g., `g++`, `clang++`)
- Python 3.x (for running test scripts)
- Make (for using the `Makefile`)

### Building the Project

To build the project, run the following command in the root directory:

```sh
make
```
This will compile the source code in the src/ directory and place the resulting executable in the main directory.

### Running the Simulation 
You can run the compiled executable with an input file as follows:

```sh
./bin/BankSim < input/sample_input_1.txt
```
Replace sample_input_1.txt with the appropriate input file you wish to use.

### Running the Tests
### Running the Tests

To run the tests, you need to navigate to the `tests` directory and run each Python test script individually. Each script is designed to validate the output of the C++ program against expected results.

1. Navigate to the `tests` directory:

   ```sh
   cd tests
   ```
2. Run each test script:
    ```sh
    python3 test_case_1.py
    python3 test_case_2.py
    python3 test_case_3.py
    ```
Each test script will execute the C++ program with the corresponding input file from the input/ directory, compare the output with the expected results in the output/ directory, and display whether the test passed or failed.

### Clean Up 
To remove the compiled binary and object files, run:

```sh 
make clean
```

### Process Flow

- **Arrival Events:** Customers arrive at the bank at specified times. If the teller is available, the customer is served immediately, and a departure event is scheduled. If the teller is busy, the customer is placed in a queue.

- **Departure Events:** When a customer finishes being served, they depart, and the next customer in the queue (if any) is served. The simulation tracks the wait time for each customer.

- **Final Statistics:** Once all events have been processed, the simulation outputs the total number of customers processed and the average wait time.
