#include <iostream>
using namespace std;

//lecture from 3/3/2022
//new type of data structure, a queue as opposed to stack
//with stacks you add and remove to the same end, in a queue you add and remove from opposite ends
//doesn't matter which end is which as long as the ends are opposite


//1st establish the chunks
class Chunk{
    public:
        int value;
        Chunk *next;

        Chunk() {
            value = -1;
            next = NULL;
        }
};

//queue of chunks
class Queue{
    public:
        Chunk *head;

        Queue() {
            head = NULL;
        }

        //add function (adding to the queue)
        void enqueue(int x) {
            //adding to the front so it is very similar to stack
            Chunk *temp = new Chunk; 
            temp->value = x;

            if(head == NULL) { //if the queue is empty:
                head = temp;
            }
            else { //if there is anything in the queue already:
                temp->next = head;
                head = temp;
            }
        }

        //subtrct function (removing from the queue)
        void dequeue() {
            //we need to remove from the back end, since we are adding to the front in the enqueue function
            Chunk *follow, *chase;

            if(head == NULL){
                cout << "The queue is empty, there is nothing to delete" << endl;
            } 
            else if (head->next == NULL){ //special condition for if there is only one thing in the queue
                cout << "There is a lone chunk in the queue, deleting : " << head->value << endl;
                delete head;
                head = NULL;
            }
            else {
                follow = chase = head; //we want chase to go find the last chunk and follow to end up at the second to last one
                while(chase->next != NULL){
                    //we want temp to keep moving down the queue until it gets to the last chunk
                    follow = chase; //allow follow to catch up to chase
                    chase = chase->next; //have chase move a step forward
                }
                follow->next = NULL; //make the second to last chunk officially the last chunk
                cout << "About to delete: " << chase->value << endl;
                delete chase; //delete the last chunk
                
            }
        }

        //display function
        void display() {
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
        cout << "Press 1 to enqueue (add to queue)" << endl;
        cout << "Press 2 to dequeue (delete from queue)" << endl;
        cout << "Press 3 to display the queue" << endl;
        cin >> choice;
        switch(choice){
            case 1: cout << "Enqueue what? " << endl;
            cin >> value;
            Q.enqueue(value);
            break;

            case 2: Q.dequeue();
            break;

            case 3: Q.display();
            break;
            
            default: exit(1);
        }

    }
}