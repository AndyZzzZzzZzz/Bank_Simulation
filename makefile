all: BankSim 

BankSim: BankSimApp.o EmptyDataCollectionException.o Event.o 
	g++ -Wall -o BankSim BankSimApp.o EmptyDataCollectionException.o Event.o

BankSimApp.o: src/BankSimApp.cpp src/Queue.cpp include/Queue.h include/BinaryHeap.h include/Event.h include/PriorityQueue.h
	g++ -std=c++11 -Wall -c src/BankSimApp.cpp

Event.o: src/Event.cpp include/Event.h
	g++ -std=c++11 -Wall -c src/Event.cpp

EmptyDataCollectionException.o: src/EmptyDataCollectionException.cpp include/EmptyDataCollectionException.h
	g++ -std=c++11 -Wall -c src/EmptyDataCollectionException.cpp

clean: 
	rm -f BankSim *.o