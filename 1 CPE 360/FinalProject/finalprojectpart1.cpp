#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
Angel Tomas Ordonez Retamar
CPE 360 Final Project: A Day in the Life of a Queue
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
   	Queue myStore;

   	int customerCount = 0; 
   	int queueLengthSum = 0; 
   	int minQueueLength[2] = {99999, 0}; 
   	int maxQueueLength[2] = {-1, 0}; 
   	int waitTimeSum = 0; 
   	int minWaitTime[2] = {99999, 0}; 
   	int maxWaitTime[2] = {-1, 0}; 
   	int serviceTimeSum = 0; 
   	int minServiceTime[2] = {99999, 0}; 
   	int maxServiceTime[2] = {-1, 0}; 
   	int spawnRand;

	cout << "Welcome to Ordonez Burgers!" << endl;
	cout << "All day we only play A Day in The Life by the Beatles here" << endl;

   	while (storeClock < 1020) { //while less than 1020min (8am-1am)
		storeClock++;
	  	if (storeClock <= 120) { //8am to 10am
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 30) {
				customerCount++;
				myStore.enqueue();
		 	}
	  	} 
	  	else if (storeClock > 120 && storeClock <= 210) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 10) {
				customerCount++;
				myStore.enqueue();
		 	} 
	  	} 
	  	else if (storeClock > 210 && storeClock <= 330) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 40) {
				customerCount++;
				myStore.enqueue();
		 	} 
	  	} 
	  	else if (storeClock > 330 && storeClock <= 570) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 10) {
				customerCount++;
				myStore.enqueue();
		 	} 
	  	} 
	  	else if (storeClock > 570 && storeClock <= 720) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 25) {
				customerCount++;
				myStore.enqueue();
		 	}
	  	} 
	  	else if (storeClock > 720 && storeClock <= 900) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 20) {
				customerCount++;
				myStore.enqueue();
		 	} 
	  	} 
	  	else if (storeClock > 900 && storeClock <= 1020) {
		 	spawnRand = rand() % 100 + 1;
		 	if (spawnRand <= 25) {
				customerCount++;
				myStore.enqueue();
		 	} 
	  	}
	  	else {
		 //past closing
		 //this should never trigger due to while loop
		 //I read the news today oh boy... About a lucky man who made the grade
	  	}

	  	if (myStore.head != NULL) { 
		 	if (myStore.head->next != NULL) {
				myStore.waitInLine(); 
		 	}
	  	}

	  	if (myStore.head != NULL) { 
		 	if (myStore.head->orderTime == 0) {
				cout << "Customer leaving..." << endl;
				int serviceTime = storeClock - myStore.head->timeEnter;
				int waitTime = serviceTime - myStore.head->orderWaitTime;
				int queueSize = myStore.queueSize();

				if (minWaitTime[0] > waitTime) {
			   	minWaitTime[0] = waitTime;
			   	minWaitTime[1] = storeClock;
				}
				if (maxWaitTime[0] < waitTime) {
			   	maxWaitTime[0] = waitTime;
			   	maxWaitTime[1] = storeClock;
				}
				if (minServiceTime[0] > serviceTime) {
			   	minServiceTime[0] = serviceTime;
			   	minServiceTime[1] = storeClock;
				}
				if (maxServiceTime[0] < serviceTime) {
			   	maxServiceTime[0] = serviceTime;
			   	maxServiceTime[1] = storeClock;
				}
				if (minQueueLength[0] > queueSize) {
			   	minQueueLength[0] = queueSize;
			   	minQueueLength[1] = storeClock;
				}
				if (maxQueueLength[0] < queueSize) {
			   	maxQueueLength[0] = queueSize;
			   	maxQueueLength[1] = storeClock;
				}

				waitTimeSum += waitTime;
				serviceTimeSum += serviceTime;
				queueLengthSum += queueSize;

				myStore.dequeue();
		 	} 
			else {
				myStore.head->orderTime--;
		 	}
	  	}
   	}

   	cout << "People left in line at closing: " << myStore.queueSize() << endl;
   	while (myStore.queueSize() != 0) {
	  	storeClock++; 
	  	if (myStore.head != NULL) {
		 	if (myStore.head->next != NULL) {
				myStore.waitInLine();
		 	}
	  	}

	  	if (myStore.head != NULL) { 
		 	if (myStore.head->orderTime == 0) {
				cout << "Customer departing" << endl;

				int serviceTime = storeClock - myStore.head->timeEnter;
				int waitTime = serviceTime - myStore.head->orderWaitTime;
				int queueSize = myStore.queueSize();

				if (minWaitTime[0] > waitTime) {
					minWaitTime[0] = waitTime;
					minWaitTime[1] = storeClock;
				}
				if (maxWaitTime[0] < waitTime) {
			   		maxWaitTime[0] = waitTime;
			   		maxWaitTime[1] = storeClock;
				}
				if (minServiceTime[0] > serviceTime) {
			   		minServiceTime[0] = serviceTime;
			   		minServiceTime[1] = storeClock;
				}
				if (maxServiceTime[0] < serviceTime) {
			   		maxServiceTime[0] = serviceTime;
			   		maxServiceTime[1] = storeClock;
				}
				if (minQueueLength[0] > queueSize) {
			   		minQueueLength[0] = queueSize;
			   		minQueueLength[1] = storeClock;
				}
				if (maxQueueLength[0] < queueSize) {
			   		maxQueueLength[0] = queueSize;
			   		maxQueueLength[1] = storeClock;
				}

				waitTimeSum += waitTime;
				serviceTimeSum += serviceTime;
				queueLengthSum += queueSize;

				myStore.dequeue();
		 	} 
			 else {
				myStore.head->orderTime--;
		 	}
	  	}
   	}

   	cout << "People left in line: " << myStore.queueSize() << endl;

   	cout << endl << "------------Avg------------" << endl;
   	cout << "Avg wait time: " << (double)waitTimeSum / customerCount << endl;
   	cout << "Avg service time: " << (double)serviceTimeSum / customerCount << endl;
   	cout << "Avg queue size: " << (double)queueLengthSum / 1020 << endl;

   	cout << "------------Best------------" << endl;
   	cout << "Min wait time: " << minWaitTime[0] << ", at time: " << minWaitTime[1] << endl;
   	cout << "Min service time: " << minServiceTime[0] << ", at time: " << minServiceTime[1] << endl;
   	cout << "Min queue size: " << minQueueLength[0] << ", at time: " << minQueueLength[1] << endl;

   	cout << "------------Worst------------" << endl;
   	cout << "Max wait time: " << maxWaitTime[0] << ", at time: " << maxWaitTime[1] << endl;
   	cout << "Max service time: " << maxServiceTime[0] << ", at time: " << maxServiceTime[1] << endl;
   	cout << "Max queue size: " << maxQueueLength[0] << ", at time: " << maxQueueLength[1] << endl;

   	cout << "------------Total------------" << endl;
   	cout << "Total wait time: " << waitTimeSum << endl;
   	cout << "Total service time: " << serviceTimeSum << endl;
   	cout << "Total customers: " << customerCount << endl;
}