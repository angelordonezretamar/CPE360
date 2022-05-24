#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

/*
Angel Tomas Ordonez Retamar
CPE 360 Final Project: A Day in the Life of a Queue part 2
I pledge my honor that I have abided by the Stevens Honor System
*/

int storeClock = 0;
int waitTime;
int orderTime, firstorderTime, SecondorderTime;
int Countcustomer = 0;
bool emptyLine = true;
bool singleLine = false;
double avgWait, avgService, avgQueue = 0;
int bestWait, bestService, bestQueue = 0;
int worstWait, worstService, worstQueue = 0;
int bestServiceTime, bestWaitTime, bestQueueTime = 0;
int worstQueueTime, worstServiceTime, worstWaitTime = 0;
float orderTimeSum, waitSum, serviceSum, queueCount, queueSum;

class Customer {
    public:
    int waitTime;
    int orderTime;
    int serviceTime;
    Customer *next;

    Customer() {
        serviceTime = waitTime = 0;
        orderTime = rand() % 6 + 1;
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
        Customer *temp = new Customer;
        Countcustomer++;

        if (head == NULL) head = temp;
        else {
            temp->next = head;
            head = temp;
        }
    }

    void dequeue() {
        Customer *temp, *find;
        temp = find = head;

        if (find == NULL) return;
        else if (find->next == NULL) {
            delete head;
            head = NULL;
        } 
        else {
            while (find->next != NULL) {
            temp = find;
            find = find->next;
        }
        temp->next = NULL;
        delete find;
        }
    }

    int queueSize() {
        int queueLength = 0;
        Customer *temp = head;
        while (temp != NULL) {
            temp = temp->next;
            queueLength++;
        }
        return queueLength;
    }

    int placeOrder() {
        Customer *find = head;
        if (find == NULL) return 0;
        while (find->next != NULL) {
            find = find->next;
        }
        return find->orderTime;
    }

    bool customerArrives() {
        int prob = rand() % 100 + 1;
        if (storeClock < 120) {
            if (prob <= 30) return true;
        }
        else if (storeClock < 210) {
            if (prob <= 10) return true;
        }
        else if (storeClock < 330) {
            if (prob <= 40) return true;
        }
        else if (storeClock < 570) {
            if (prob <= 10) return true;
        }
        else if (storeClock < 720) {
            if (prob <= 25) return true;
        }
        else if (storeClock < 900) {
            if (prob <= 20) return true;
        }
        else if (storeClock < 1020) {
            if (prob <= 10) return true;
        }
        return false;
    }
};

int main() {
    srand(time(NULL));
    Queue TheStore;

    storeClock = orderTime = orderTimeSum = waitSum = avgWait = serviceSum = avgService = queueCount = queueSum = avgQueue = 0;
    bestWait = bestService = bestQueue = 99999;
    worstWait = worstService = worstQueue = -1;

    while (storeClock < 1020) {
        if ((storeClock <= 120) || (storeClock <= 330 && storeClock > 210) || (storeClock <= 720 && storeClock > 570)) {
            if (TheStore.customerArrives()) {
                if (TheStore.queueSize() == 0) emptyLine = true;
                else emptyLine = false;
                TheStore.enqueue();
                if (TheStore.queueSize() == 1) singleLine = true;
                else singleLine = false;
            }

        if (firstorderTime == 0) {
            if (emptyLine && singleLine) {
                firstorderTime = rand() % 6 + 1;
                Countcustomer++;
                orderTimeSum += firstorderTime;

                cout << "A customer has arrived for breakfast in the empty line with order time: " << firstorderTime << " minutes at " << storeClock / 60 << " hours" << endl;
            } 
            else {
                TheStore.dequeue();
                firstorderTime = rand() % 6 + 1;
                orderTimeSum += firstorderTime;

                cout << "The previous customer left and the new customer in line now has an order time: " << orderTime << " minutes at " << storeClock / 60 << " hours" << endl;
            }
        } 
        else if (SecondorderTime == 0 && orderTime != 0) {
            TheStore.dequeue();
            SecondorderTime = rand() % 6 + 1;
            orderTimeSum += SecondorderTime;

            cout << "The following customer in breakfast line now has an order time: " << SecondorderTime << " minutes at " << storeClock / 60 << " hours" << endl;
        }

        storeClock++;

        if (firstorderTime > 0) {
            firstorderTime--;

            Customer *find;
            find = TheStore.head;

            if (find == NULL) {
                //there is no one else in the line
            } 
            else if (find->next == NULL) {
                find->serviceTime++;
                serviceSum += find->serviceTime;

                if (find->serviceTime < bestService) {
                    bestService = storeClock;
                    bestService = find->serviceTime;
                }
                if (find->waitTime < bestWait) {
                    bestWaitTime = storeClock;
                    bestWait = find->waitTime;
                }
                if (find->serviceTime > worstService) {
                    worstServiceTime = storeClock;
                    worstService = find->serviceTime;
                }
                if (find->waitTime > worstWait) {
                    worstWaitTime = storeClock;
                    worstWait = find->waitTime;
                }
            }  
            else {
                Customer *temp;
                temp = TheStore.head;
                temp->serviceTime++;
                while (temp->next != NULL) {
                    temp->next->waitTime++;
                    temp->next->serviceTime++;

                    if (temp->next->serviceTime < bestService) {
                        bestServiceTime = storeClock;
                        bestService = temp->next->serviceTime;
                    }
                    if (temp->next->waitTime < bestWait) {
                        bestWaitTime = storeClock;
                        bestWait = temp->next->waitTime;
                    }
                    if (find->waitTime < bestWait) {
                        bestWaitTime = storeClock;
                        bestWait = find->waitTime;
                    }
                    if (temp->next->serviceTime > worstService) {
                        worstServiceTime = storeClock;
                        worstService = temp->next->serviceTime;
                    }
                    if (temp->next->waitTime > worstWait) {
                        worstWaitTime = storeClock;
                        worstWait = temp->next->waitTime;
                    }
                    if (find->waitTime > worstWait) {
                        worstWaitTime = storeClock;
                        worstWait = find->waitTime;
                    }

                    temp = temp->next;
                }
                waitSum += find->next->waitTime;
                serviceSum += find->serviceTime;
            }
        } 

        if (SecondorderTime > 0) {
            SecondorderTime--;

            Customer *find;
            find = TheStore.head;

            if (find == NULL) {
                //there is no one else in the line
            } 
            else if (find->next == NULL) {
                find->serviceTime++;
                serviceSum += find->serviceTime;

                if (find->serviceTime < bestService) {
                    bestService = storeClock;
                    bestService = find->serviceTime;
                }
                if (find->waitTime < bestWait) {
                    bestWaitTime = storeClock;
                    bestWait = find->waitTime;
                }
                if (find->serviceTime > worstService) {
                    worstServiceTime = storeClock;
                    worstService = find->serviceTime;
                }
                if (find->waitTime > worstWait) {
                    worstWaitTime = storeClock;
                    worstWait = find->waitTime;
                }
            } 
            else {
                Customer *temp;
                temp = TheStore.head;
                temp->serviceTime++;

                while (temp->next != NULL) {
                    temp->next->waitTime++;
                    temp->next->serviceTime++;

                    if (temp->next->serviceTime < bestService) {
                        bestServiceTime = storeClock;
                        bestService = temp->next->serviceTime;
                    }
                    if (temp->next->waitTime < bestWait) {
                        bestWaitTime = storeClock;
                        bestWait = temp->next->waitTime;
                    }
                    if (find->waitTime < bestWait) {
                        bestWaitTime = storeClock;
                        bestWait = find->waitTime;
                    }
                    if (temp->next->serviceTime > worstService) {
                        worstServiceTime = storeClock;
                        worstService = temp->next->serviceTime;
                    }
                    if (temp->next->waitTime > worstWait) {
                        worstWaitTime = storeClock;
                        worstWait = temp->next->waitTime;
                    }
                    if (find->waitTime > worstWait) {
                        worstWaitTime = storeClock;
                        worstWait = find->waitTime;
                    }

                    temp = temp->next;
                }
                waitSum += find->next->waitTime;
                serviceSum += find->serviceTime;
            }   
        }

        if (bestQueue > TheStore.queueSize()) {
            bestQueue = TheStore.queueSize();
            bestQueueTime = storeClock;
        }

        if (worstQueue < TheStore.queueSize()) {
            worstQueue = TheStore.queueSize();
            worstQueueTime = storeClock;
        }

        queueSum += TheStore.queueSize();
        queueCount++;
    }
    else if ((storeClock <= 210 && storeClock > 120) || (storeClock <= 570 && storeClock > 330) || (storeClock < 1020 && storeClock > 720)) {
        if (TheStore.customerArrives()) {
            if (TheStore.queueSize() == 0) emptyLine = true;
            else emptyLine = false;
            TheStore.enqueue();
            if (TheStore.queueSize() == 1) singleLine = true;
            else singleLine = false;
        }

        if (orderTime == 0) {
            if (emptyLine && singleLine) {
                orderTime = TheStore.placeOrder();
                Countcustomer++;
                orderTimeSum += orderTime;

                cout << "A customer has arrived in the empty line with order time: " << orderTime << " minutes at " << storeClock / 60 << " hours" << endl;
            } 
            else {
                TheStore.dequeue();
                orderTime = rand() % 6 + 1;
                orderTimeSum += orderTime;

                cout << "The previous customer left and the new customer in line now has an order time: " << orderTime << " minutes at " << storeClock / 60 << " hours" << endl;
            }
        }
        storeClock++;
        if (orderTime > 0) {
            orderTime--;

            Customer *find;
            find = TheStore.head;

            if (find == NULL) {
                // No one in line
            } 
            else if (find->next == NULL) {
                find->serviceTime++;
                serviceSum += find->serviceTime;

                if (find->serviceTime < bestService) {
                    bestService = storeClock;
                    bestService = find->serviceTime;
                }
                if (find->waitTime < bestWait) {
                    bestWaitTime = storeClock;
                    bestWait = find->waitTime;
                }
                if (find->serviceTime > worstService) {
                    worstServiceTime = storeClock;
                    worstService = find->serviceTime;
                }
                if (find->waitTime > worstWait) {
                    worstWaitTime = storeClock;
                    worstWait = find->waitTime;
                }
            }  
            else {
                Customer *temp;
                temp = TheStore.head;
                temp->serviceTime++;

                 while (temp->next != NULL) {
                    temp->next->waitTime++;
                    temp->next->serviceTime++;

                if (temp->next->serviceTime < bestService) {
                    bestServiceTime = storeClock;
                    bestService = temp->next->serviceTime;
                }
                if (temp->next->waitTime < bestWait) {
                    bestWaitTime = storeClock;
                    bestWait = temp->next->waitTime;
                }
                if (find->waitTime < bestWait) {
                    bestWaitTime = storeClock;
                    bestWait = find->waitTime;
                }
                if (temp->next->serviceTime > worstService) {
                    worstServiceTime = storeClock;
                    worstService = temp->next->serviceTime;
                }
                if (temp->next->waitTime > worstWait) {
                    worstWaitTime = storeClock;
                    worstWait = temp->next->waitTime;
                }
                if (find->waitTime > worstWait) {
                    worstWaitTime = storeClock;
                    worstWait = find->waitTime;
                }

                temp = temp->next;
            }
            waitSum += find->next->waitTime;
            serviceSum += find->serviceTime;
        }
    }

        if (bestQueue > TheStore.queueSize()) {
            bestQueue = TheStore.queueSize();
            bestQueueTime = storeClock;
        }

        if (worstQueue < TheStore.queueSize()) {
            worstQueue = TheStore.queueSize();
            worstQueueTime = storeClock;
        }

        queueSum += TheStore.queueSize();
        queueCount++;
    }
    }

    avgWait = waitSum / Countcustomer;
    avgQueue = queueSum / queueCount;
    avgService = serviceSum / Countcustomer;

    cout << endl;
    cout << "Today's Statistics" << endl;
    cout << "================================================" << endl;
    cout << "Total customer count: [ " << Countcustomer << " ]" << endl;
    cout << "Average wait time: [ " << avgWait << " ] minutes " << endl;
    cout << "Best wait time: [ " << bestWait << " ] minutes at time: " << bestWaitTime << endl;
    cout << "Worst wait time: [ " << worstWait << " ] minutes at time: " << worstWaitTime << endl;
    cout << "Average service time: [ " << avgService << " ] minutes " << endl;
    cout << "Best service time: [ " << bestService << " ] minutes at time: " << bestServiceTime << endl;
    cout << "Worst service time: [ " << worstService << " ] minutes at time: " << worstServiceTime << endl;
    cout << "Average queue size: [ " << avgQueue << " ]" << endl;
    cout << "Best queue length: [ " << bestQueue << " ] at time: " << bestQueueTime << endl;
    cout << "Worst queue length: [ " << worstQueue << " ] at time: " << worstQueueTime << endl;
    cout << "================================================" << endl;
    cout << endl;
}