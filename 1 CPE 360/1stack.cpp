#include <iostream>
using namespace std;

//1st concept "chunk"
class Chunk {
    public:
        int value;
        Chunk *next;

        Chunk() {
            value = -1;
            next = NULL;
        }
};

//2nd class called "Stack"
//this class is a stack of chunks, member functions needed to add, delete and display
class Stack {
    public:
    Chunk *top; //this is the top of the stack

    Stack() {
        top = NULL; //when we create an object of type stack, we get one pointer (top) and it is pointing to nothing to start
    }

    //now the member functions
    //1. add, in more "stacky" terminology it is called push
    void push(int x) {
    //step 1: get us a new chunk and put "x" inside the value portion
        Chunk *temp = new Chunk;
        temp->value = x;
    //step 2: to make this new chunk the top chunk in the stack
    //if the stack is empty, this chunk will just be the top one
    //else, we will have to move some pointers around
        if(top == NULL) {
            top = temp; //very simple to make the new chunk the top if the stack is empty
        }
        else {
            temp->next = top;
            top = temp;
        }

        cout << "Just added a new element: " << top->value << endl;
    }
    //2. delete, in "stacky" terminology it is called pop
    void pop() {
    //step 1 check to see if the stack is empty, if it is there is nothing to do here
    //step 2: if it's not empty, get rid of the first chunk
        if(top == NULL) {
        cout << "There is nothing to delete, the stack is empty" << endl;
        }
        else {
        Chunk *temp;
        temp = top; 
        top = top->next;
        cout << "About to delete: " << temp->value << endl;
        delete temp;
        }
    }
    //3. display, no other "stacky" way to call it
    void display(){
        Chunk *temp;
        temp = top;

        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next; //print, move on, print, move on
        }
    }
};


//main function
int main() {
    Stack S; //just need a stack object to test it out
    int choice, value; //some variables to assist/make it easier

    while(1) { //a while(1) loop is an infinite loop
        cout << endl;
        cout << "Press 1 to push to stack" << endl;
        cout << "Press 2 to pop from the stack" << endl;
        cout << "Press 3 to display contents" << endl;
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
            S.display();
            break;

            default: //when the choice is not one of the set cases
            cout << "Goodbye." << endl;
            exit(1); //we need this to get out of the while(1) loop since it is infinite
            break;
        }
        
    }
}