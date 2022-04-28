#include <iostream>
using namespace std;

/*
Angel Tomas Ordonez Retamar
CPE 360-A
Stack HW Assignment
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

class Stack {
    public:
        Chunk *top;
        Stack() {
            top = NULL;
        }

    void push(int a) {
        Chunk *temp = new Chunk;
        temp->value = a;

        if(top == NULL) {
            top = temp;
        }
        else {
            temp->next = top;
            top = temp;
        }

        cout << "A new element: " << top->value << " has been added." << endl;
    }
    void pop() {
        if(top == NULL) {
            cout << "There is nothing to delete because the Stack is empty..." << endl;
        }
        else {
            Chunk *temp;
            temp = top;
            top = top->next;
            cout << temp->value << " is going to be deleted." << endl;
            delete temp;
        }
    }
    void displayContents() {
        Chunk *temp;
        temp = top;

        while(temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack S;
    int choice, value;

    while(1) {
        cout << endl;
        cout << "Press 1 to push to the stack" << endl;
        cout << "Press 2 to pop from the stack" << endl;
        cout << "Press 3 to display the stack's contents" << endl;
        cout << "Press anything else to quit" << endl;
        cin >> choice;

        switch(choice) {
            case 1:
            cout << "Push what?" << endl;
            cin >> value;
            S.push(value);
            break;
        
            case 2: 
            S.pop();
            break;

            case 3:
            S.displayContents();
            break;

            default:
            cout << "Goodbye." << endl;
            exit(1);
            break;
        }
    }

}