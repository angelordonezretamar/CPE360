#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
Angel Tomas Ordonez Retamar
CPE 360 Final Project: A Day in the Life of a Queue part 2
I pledge my honor that I have abided by the Stevens Honor System
*/

int storeClock;

class Customer {
	public:
		int timeEnter; 
		int timeLeave;
		int waitTime; 
		int orderTime; 
		int orderWaitTime; 
   		Customer *next;

   		Customer() {
	  		timeEnter = storeClock; 
	  		timeLeave = 0; 
	  		waitTime = 0; 
	  		orderTime = rand() % 6 + 1; 
	  		orderWaitTime = orderTime;
	  		next = NULL;
   		}
};

class Queue {
  	public:
   	Customer *head;

   	Queue() {
	  	head = NULL;
   	}

   	void enqueue() {
	  	Customer *tmp = new Customer();
	  	cout << "New customer! Entered at time: " << tmp->timeEnter << " with an order that will take: " << tmp->orderTime << " minutes to prepare." << endl;

	  	if (head == NULL) { 
		 	head = tmp;
	  	} 
		else {
		 	Customer *another;
		 	another = head;
		 	while (another->next != NULL) { 
				another = another->next; 
			}
			another->next = tmp;
			tmp->next = NULL;
	  	}
   	}

   	void dequeue() {
	  	if (head == NULL) {
		 	cout << "The store is empty, so no customers can leave right now. This message is never gonna print anyway" << endl;
	  	} 
		else {
		 	Customer *tmp;
		 	tmp = head; 
		 	head = head->next; 
		 	cout << "A customer is heading out at time: " << storeClock << ". I hope they enjoyed their meal." << endl;
		 	delete tmp; 
	  	}
   	}	

   	int queueSize() { 
	  	Customer *tmp;
	  	tmp = head;
	  	int length = 0;
	  	while (tmp != NULL) {
		 	length++;
		 	tmp = tmp->next;
	  	}
	  	return length;
   	}

   	void waitInLine() {
	  	Customer *tmp;
	  	tmp = head->next;
	  	while (tmp != NULL) {
		 	tmp->waitTime++;
		 	tmp = tmp->next; 
	  	}
   	}
};

int main() {
	srand(time(NULL));
   	Queue line1;
	Queue line2;

   	int customerCount = 0; 
	int line1Length, line2Length = 0;
   	int queueLengthSum = 0; 
   	int minQueueLength1[2], minQueueLength2[2] = {99999, 0}; 
   	int maxQueueLength1[2], maxQueueLength2[2] = {-1, 0}; 
   	int waitTimeSum = 0; 
   	int minWaitTime1[2], minWaitTime2[2] = {99999, 0}; 
   	int maxWaitTime1[2], maxWaitTime2[2] = {-1, 0}; 
   	int serviceTimeSum = 0; 
   	int minServiceTime1[2], minServiceTime2[2] = {99999, 0}; 
   	int maxServiceTime1[2], maxServiceTime2[2] = {-1, 0}; 
   	int spawnRand;

   	while (storeClock < 1020) { //while less than 1020min (8am-1am)
		storeClock++;
	  	if (storeClock <= 120) { //8am to 10am
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 30) {
				customerCount++;
				if(line1Length == line2Length) {
					line1.enqueue();
					line1Length++;
				}
				if(line1Length > line2Length) {
					line2.enqueue();
					line2Length++;
				}
				if(line2Length > line1Length) {
					line1.enqueue();
					line1Length++;
				}
		 	}
	  	} 
	  	else if (storeClock > 120 && storeClock <= 210) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 10) {
				customerCount++;
				if(line1Length == line2Length) {
					line1.enqueue();
					line1Length++;
				}
				if(line1Length > line2Length) {
					line2.enqueue();
					line2Length++;
				}
				if(line2Length > line1Length) {
					line1.enqueue();
					line1Length++;
				}
		 	} 
	  	} 
	  	else if (storeClock > 210 && storeClock <= 330) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 40) {
				customerCount++;
				if(line1Length == line2Length) {
					line1.enqueue();
					line1Length++;
				}
				if(line1Length > line2Length) {
					line2.enqueue();
					line2Length++;
				}
				if(line2Length > line1Length) {
					line1.enqueue();
					line1Length++;
				}
		 	} 
	  	} 
	  	else if (storeClock > 330 && storeClock <= 570) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 10) {
				customerCount++;
				if(line1Length == line2Length) {
					line1.enqueue();
					line1Length++;
				}
				if(line1Length > line2Length) {
					line2.enqueue();
					line2Length++;
				}
				if(line2Length > line1Length) {
					line1.enqueue();
					line1Length++;
				}
		 	} 
	  	} 
	  	else if (storeClock > 570 && storeClock <= 720) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 25) {
				customerCount++;
				if(line1Length == line2Length) {
					line1.enqueue();
					line1Length++;
				}
				if(line1Length > line2Length) {
					line2.enqueue();
					line2Length++;
				}
				if(line2Length > line1Length) {
					line1.enqueue();
					line1Length++;
				}
		 	}
	  	} 
	  	else if (storeClock > 720 && storeClock <= 900) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 20) {
				customerCount++;
				if(line1Length == line2Length) {
					line1.enqueue();
					line1Length++;
				}
				if(line1Length > line2Length) {
					line2.enqueue();
					line2Length++;
				}
				if(line2Length > line1Length) {
					line1.enqueue();
					line1Length++;
				}
		 	} 
	  	} 
	  	else if (storeClock > 900 && storeClock <= 1020) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 25) {
				customerCount++;
				if(line1Length == line2Length) {
					line1.enqueue();
					line1Length++;
				}
				if(line1Length > line2Length) {
					line2.enqueue();
					line2Length++;
				}
				if(line2Length > line1Length) {
					line1.enqueue();
					line1Length++;
				}
		 	} 
	  	}
	  	else {
		 //past closing
		 //this should never trigger due to while loop
		 //and though the news was rather sad... well I just had to laugh, I saw the photograph
	  	}

	  	if (line1.head != NULL) { 
		 	if (line1.head->next != NULL) {
				line1.waitInLine(); 
		 	}
	  	}
		if (line2.head != NULL) {
			if (line2.head->next != NULL) {
				line2.waitInLine();
			}
		}

	  	if (line1.head != NULL) { 
		 	if (line1.head->orderTime == 0) {
				cout << "Customer leaving from line 1..." << endl;
				int serviceTime1 = storeClock - line1.head->timeEnter;
				int waitTime1 = serviceTime1 - line1.head->orderWaitTime;
				int queueSize1 = line1.queueSize();

				if (minWaitTime1[0] > waitTime1) {
			   	minWaitTime1[0] = waitTime1;
			   	minWaitTime1[1] = storeClock;
				}
				if (maxWaitTime1[0] < waitTime1) {
			   	maxWaitTime1[0] = waitTime1;
			   	maxWaitTime1[1] = storeClock;
				}
				if (minServiceTime1[0] > serviceTime1) {
			   	minServiceTime1[0] = serviceTime1;
			   	minServiceTime1[1] = storeClock;
				}
				if (maxServiceTime1[0] < serviceTime1) {
			   	maxServiceTime1[0] = serviceTime1;
			   	maxServiceTime1[1] = storeClock;
				}
				if (minQueueLength1[0] > queueSize1) {
			   	minQueueLength1[0] = queueSize1;
			   	minQueueLength1[1] = storeClock;
				}
				if (maxQueueLength1[0] < queueSize1) {
			   	maxQueueLength1[0] = queueSize1;
			   	maxQueueLength1[1] = storeClock;
				}

				waitTimeSum += waitTime1;
				serviceTimeSum += serviceTime1;
				queueLengthSum += queueSize1;

				line1.dequeue();
		 	} 
			else {
				line1.head->orderTime--;
		 	}
	  	}
		if (line2.head != NULL) {
			if (line2.head->orderTime == 0) {
				cout << "Customer leaving from line 2..." << endl;
				int serviceTime2 = storeClock - line2.head->timeEnter;
				int waitTime2 = serviceTime2 - line2.head->orderWaitTime;
				int queueSize2 = line2.queueSize();

				if  (minWaitTime2[0] > waitTime2) {
					minWaitTime2[0] = waitTime2;
					minWaitTime2[1] = storeClock;
				}
				if (maxWaitTime2[0] < waitTime2) {
					maxWaitTime2[0] = waitTime2;
					maxWaitTime2[1] = storeClock;
				}
				if (minServiceTime2[0] > serviceTime2) {
					minServiceTime2[0] = serviceTime2;
					minServiceTime2[1] = storeClock;
				}
				if (maxServiceTime2[0] < serviceTime2) {
					maxServiceTime2[0] = serviceTime2;
					maxServiceTime2[1] = storeClock;
				}
				if (minQueueLength2[0] > queueSize2) {
					minQueueLength2[0] = queueSize2;
					minQueueLength2[1] = storeClock;
				}
				if (maxQueueLength2[0] < queueSize2) {
					maxQueueLength2[0] = queueSize2;
					maxQueueLength2[1] = storeClock;
				}

				waitTimeSum += waitTime2;
				serviceTimeSum += serviceTime2;
				queueLengthSum += queueSize2;

				line2.dequeue();
			} 
			else {
				line2.head->orderTime--;
			}
		}
   	}

   	cout << "People waiting (both lines) at closing: " << line1.queueSize()+line2.queueSize() << endl;
   	while (line1.queueSize() != 0 || line2.queueSize() != 0) {
	  	storeClock++; 
	  	if (line1.head != NULL) {
		 	if (line1.head->next != NULL) {
				line1.waitInLine();
		 	}
	  	}
		if (line2.head != NULL) {
			if (line2.head->next != NULL) {
				line2.waitInLine();
			}
		}

	  	if (line1.head != NULL) { 
		 	if (line1.head->orderTime == 0) {
				cout << "Customer departing from line 1..." << endl;

				int serviceTime1 = storeClock - line1.head->timeEnter;
				int waitTime1 = serviceTime1 - line1.head->orderWaitTime;
				int queueSize1 = line1.queueSize();

				if (minWaitTime1[0] > waitTime1) {
					minWaitTime1[0] = waitTime1;
					minWaitTime1[1] = storeClock;
				}
				if (maxWaitTime1[0] < waitTime1) {
			   		maxWaitTime1[0] = waitTime1;
			   		maxWaitTime1[1] = storeClock;
				}
				if (minServiceTime1[0] > serviceTime1) {
			   		minServiceTime1[0] = serviceTime1;
			   		minServiceTime1[1] = storeClock;
				}
				if (maxServiceTime1[0] < serviceTime1) {
			   		maxServiceTime1[0] = serviceTime1;
			   		maxServiceTime1[1] = storeClock;
				}
				if (minQueueLength1[0] > queueSize1) {
			   		minQueueLength1[0] = queueSize1;
			   		minQueueLength1[1] = storeClock;
				}
				if (maxQueueLength1[0] < queueSize1) {
			   		maxQueueLength1[0] = queueSize1;
			   		maxQueueLength1[1] = storeClock;
				}

				waitTimeSum += waitTime1;
				serviceTimeSum += serviceTime1;
				queueLengthSum += queueSize1;

				line1.dequeue();
		 	} 
			 else {
				line1.head->orderTime--;
		 	}
	  	}
		if (line2.head != NULL) {
			if (line2.head->orderTime == 0) {
				cout << "Customer departing from line 2" << endl;

				int serviceTime2 = storeClock - line2.head->timeEnter;
				int waitTime2 = serviceTime2 - line2.head->orderWaitTime;
				int queueSize2 = line2.queueSize();

				if (minWaitTime2[0] > waitTime2) {
					minWaitTime2[0] = waitTime2;
					minWaitTime2[1] = storeClock;
				}
				if (maxWaitTime2[0] < waitTime2) {
			   		maxWaitTime2[0] = waitTime2;
			   		maxWaitTime2[1] = storeClock;
				}
				if (minServiceTime2[0] > serviceTime2) {
			   		minServiceTime2[0] = serviceTime2;
			   		minServiceTime2[1] = storeClock;
				}
				if (maxServiceTime2[0] < serviceTime2) {
			   		maxServiceTime2[0] = serviceTime2;
			   		maxServiceTime2[1] = storeClock;
				}
				if (minQueueLength2[0] > queueSize2) {
			   		minQueueLength2[0] = queueSize2;
			   		minQueueLength2[1] = storeClock;
				}
				if (maxQueueLength2[0] < queueSize2) {
			   		maxQueueLength2[0] = queueSize2;
			   		maxQueueLength2[1] = storeClock;
				}

				waitTimeSum += waitTime2;
				serviceTimeSum += serviceTime2;
				queueLengthSum += queueSize2;

				line2.dequeue();
			}
			else {
				line2.head->orderTime--;
			}
		} 
   	}

   	cout << "People left in line 1: " << line1.queueSize() << endl;
	cout << "People left in line 2: " << line2.queueSize() << endl;

   	cout << endl << "------------Avg------------" << endl;
   	cout << "Avg wait time: " << (double)waitTimeSum / customerCount << endl;
   	cout << "Avg service time: " << (double)serviceTimeSum / customerCount << endl;
   	cout << "Avg queue size: " << (double)queueLengthSum / 1020 << endl;

   	cout << "------------Best------------" << endl;
	cout << "line 1: " << endl;
   	cout << "Min wait time: " << minWaitTime1[0] << ", at time: " << minWaitTime1[1] << endl;
   	cout << "Min service time: " << minServiceTime1[0] << ", at time: " << minServiceTime1[1] << endl;
   	cout << "Min queue size: " << minQueueLength1[0] << ", at time: " << minQueueLength1[1] << endl;
	cout << "Line 2: " << endl;
	cout << "Min wait time: " << minWaitTime2[0] << ", at time: " << minWaitTime2[1] << endl;
   	cout << "Min service time: " << minServiceTime2[0] << ", at time: " << minServiceTime2[1] << endl;
   	cout << "Min queue size: " << minQueueLength2[0] << ", at time: " << minQueueLength2[1] << endl;	

   	cout << "------------Worst------------" << endl;
	cout << "line 1: " << endl;
   	cout << "Max wait time: " << maxWaitTime1[0] << ", at time: " << maxWaitTime1[1] << endl;
   	cout << "Max service time: " << maxServiceTime1[0] << ", at time: " << maxServiceTime1[1] << endl;
   	cout << "Max queue size: " << maxQueueLength1[0] << ", at time: " << maxQueueLength1[1] << endl;
	cout << "line 2: " << endl;
	cout << "Max wait time: " << maxWaitTime2[0] << ", at time: " << maxWaitTime2[1] << endl;
   	cout << "Max service time: " << maxServiceTime2[0] << ", at time: " << maxServiceTime2[1] << endl;
   	cout << "Max queue size: " << maxQueueLength2[0] << ", at time: " << maxQueueLength2[1] << endl;

   	cout << "------------Total------------" << endl;
   	cout << "Total wait time: " << waitTimeSum << endl;
   	cout << "Total service time: " << serviceTimeSum << endl;
   	cout << "Total customers: " << customerCount << endl;
}