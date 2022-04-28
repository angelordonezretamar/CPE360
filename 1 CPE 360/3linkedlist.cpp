#include <iostream>
using namespace std;

/*
Angel Tomas Ordonez Retamar
CPE 360-A
Linked List HW Assignment
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

class LinkedList {
    public:
        Chunk *head;
        int size;
            LinkedList() {
                head = NULL;
                size = 0;
            }
    void insertAtHead(int a) {
            Chunk *temp = new Chunk; 
            temp->value = a;

            if(head == NULL) { 
            head = temp;
            }
            else {
            temp->next = head;
            head = temp;
            }
    }
    void insertAtPosition(int pos, int a) {
    if(pos <= size +1) { 
            Chunk *temp = new Chunk;
            temp->value = a;
            if(pos == 1){
                Chunk *temp = new Chunk; 
                temp->value = a;

                if(head == NULL) { 
                head = temp;
                }
                else { 
                temp->next = head;
                head = temp;
                }
            }
            else {
                Chunk *help = head; 
                for(int i = 1; i <= a; i++){
                help = help->next;
                }
                temp->next = help->next; 
                help->next = temp; 
            }
            size++;
        }
        else {
            cout << "Sorry, the position is invalid" << endl;
            return;
        }
    }
    void removeFromPosition(int pos) {
        if(pos <= size){
            if (pos == size && size == 1){
                delete head;
                head = NULL;
                size = 0;
                return;
            }
            if(pos ==1) {
                if(head == NULL) {
                cout << "There is nothing to delete because the Linked List is empty..." << endl;
                }
                else {
                    Chunk *temp;
                    temp = head;
                    head = head->next;
                    cout << temp->value << " is going to be deleted." << endl;
                    delete temp;
                }
            }
            else if(pos == size){
                Chunk *follow, *chase;
                if(head == NULL){
                cout << "The queue is empty, there is nothing to delete" << endl;
                }    
                else if (head->next == NULL){ 
                cout << "There is a lone chunk in the List, deleting : " << head->value << endl;
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
            else {
                Chunk *chase, *follow;
                chase = follow = head;
                for(int i = 1; i<= pos; i++){
                    follow = chase;
                    chase = chase->next;
                }
                follow->next = chase->next;
                delete chase;
            }
            size--;
        }
        else {
            cout << "Sorry, the position is invalid" << endl;
            return;
        }
    }
    void displayContents() {
        Chunk *temp;

            if (head == NULL) {
                cout << "-------------" << endl;
                cout << "The List is empty" << endl;
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
    LinkedList L;
    int choice, value, pos;

    while(1) {
        cout << endl;
        cout << "Press 1 to insert to the head of the Linked List" << endl;
        cout << "Press 2 to insert to a specific position in the Linked List" << endl;
        cout << "Press 3 to delete a value from a position of your choice" << endl;
        cout << "Press 4 to display the contents of the Linked List" << endl;
        cout << "Press anything else to quit" << endl;
        cin >> choice;

        switch(choice) {
            case 1:
            cout << "Insert what?" << endl;
            cin >> value;
            L.insertAtHead(value);
            break;
        
            case 2: 
            cout << "Insert what?" << endl;
            cin >> value;
            cout << "Insert where?" << endl;
            cin >> value;
            L.insertAtPosition(pos, value);
            break;

            case 3:
            cout << "Remove the value at which position?" << endl;
            cin >> pos;
            L.removeFromPosition(pos);
            break;

            case 4:
            L.displayContents();
            break;

            default:
            cout << "Goodbye." << endl;
            exit(1);
            break;
        }
    }
}
