#include <iostream>
using namespace std;

/*
Angel Tomas Ordonez Retamar
CPE 360-A
Queue HW Assignment
3/25/2022
I pledge my honor that I have abided by the Stevens Honor System
*/

class Chunk {
    public:
        int value;
        Chunk *next;

        Chunk() {
            value = 1;
            next = NULL;
        }
};

class Queue {
    public:
        Chunk *head;

        Queue() {
            head = NULL;
        }

    void enQueue(int x) {
            Chunk *temp = new Chunk; 
            temp->value = x;

            if(head == NULL) { 
                head = temp;
            }
            else {
                temp->next = head;
                head = temp;
            }
        }
    void deQueue() {
            Chunk *follow, *chase;
            if(head == NULL){
                cout << "The queue is empty, there is nothing to delete" << endl;
            } 
            else if (head->next == NULL){
                cout << "There is a lone chunk in the queue, deleting : " << head->value << endl;
                delete head;
                head = NULL;
            }
            else {
                follow = chase = head; 
                while(chase->next != NULL){
                    follow = chase;
                    chase = chase->next;
                }
                follow->next = NULL; 
                cout << "About to delete: " << chase->value << endl;
                delete chase; 
            }
        }
    void printContents() {
            Chunk *temp;

            if (head == NULL) {
                cout << "-------------" << endl;
                cout << "The queue is empty" << endl;
                cout << "-------------" << endl;
            }
            else {
                temp = head;
                cout << "-------------" << endl; //these are just to make it look nice
                while(temp != NULL) { //loop to display each chunk one by one
                    cout << temp->value << "--->";
                    temp = temp->next;
                }
                cout << " NULL" << endl; //how we end the display 
                cout << "-------------" << endl;
            }

    }
};

int main() {
    Queue Q;
    int choice, value;

    while(1) {
        cout << "Press 1 to enqueue" << endl;
        cout << "Press 2 to dequeue" << endl;
        cout << "Press 3 to display the contents of the queue" << endl;
        cin >> choice;
        switch(choice){
            case 1: cout << "Enqueue what? " << endl;
            cin >> value;
            Q.enQueue(value);
            break;

            case 2: Q.deQueue();
            break;

            case 3: Q.printContents();
            break;
            
            default: exit(1);
        }

    }
}