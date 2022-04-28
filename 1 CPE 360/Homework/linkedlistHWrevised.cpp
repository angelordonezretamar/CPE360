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

class linkedList{
  public:
    Chunk *head;
    int size;

    linkedList() {
      head = NULL;
      size = 0;
  }

  void insertAtHead(int x) {
    Chunk *temp = new Chunk;
    temp-> value = x;

    if(head == NULL) {
      head = temp;
    }
    else {
      temp->next = head;
      head = temp;
    }
    size++;
  }

  void insertAtPosition(int position, int value) {
    if(position > 0 && position <= size + 1) {
      Chunk *temp = new Chunk;
      temp-> value = value;

      if(position == 1) {
        insertAtHead(value);
    }
      else {
        Chunk *help = head;
        for(int i = 1; i < position - 1; i++)
          help = help -> next;
        temp->next = help->next;
        help->next = temp;
        size++;
        cout << "Position = " << position << endl;
      }
    }
    else {
      cout << "Sorry, the position is invalid." << endl;
      return;
    }
  }

  void removeFromPosition(int position) {
    if(position <= size) {
      if (position == size && size == 1) {
        delete head;
        head = NULL;
        size = 0;
        return;
      }

    if(position == 1) {
      if(head == NULL) {
        cout << "The linked list is empty. There is nothing to delete." << endl; 
      }
      else {
        Chunk *temp;
        temp = head;
        head = head -> next;
        cout << "Deleting: " << temp -> value << endl;
        delete temp;
        }
      }
    
    else if(position == size) {
      Chunk *follow, *chase;

      if (head == NULL) {
        cout << "The linked list is empty. There is nothing to delete." << endl; 
      }

      else if (head -> next == NULL) {
        cout << "There is one lone chunk, deleting: " << head -> value << endl;
        delete head;
        head = NULL;
      }

      else {
        follow = chase = head;
        while (chase -> next != NULL) {
          follow = chase;
          chase = chase -> next;
        }

        follow -> next = NULL;
        cout << "Deleting: " <<  chase -> value << endl;
        delete chase;
      }
    }

    else {
      Chunk *chase, *follow;
      chase = follow = head;
      for(int i = 1; i < position; i++) {
        follow = chase;
        chase = chase->next;
      }
      follow-> next = chase-> next;
      cout << "Deleting: " << chase -> value << endl;
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

    if(head == NULL) {
      cout << "The linked list is empty, there is nothing to display..." << endl;
    }
    else {
      temp = head;
      cout << "===================" << endl;
      while(temp != NULL) {
        cout << temp->value << " --> ";
        temp = temp-> next;
      }
      cout << " NULL" << endl;
      cout << "===================" << endl;
    }
  }
};

int main() {
  linkedList Three;
  int choice, value, position;

  while(1) {
    cout << "Press 1 to insert a value at the head" << endl;
    cout << "Press 2 to insert a value at a specific position" << endl;
    cout << "Press 3 to remove a value at a specific position" << endl;
    cout << "Press 4 to display the contents of the linked list" << endl;
    cout << "Press anything else to quit" << endl;
    cin >> choice;
    switch (choice) {
      case 1: cout << "Insert what?" << endl;
              cin >> value;
              Three.insertAtHead(value);
              break;

      case 2: cout << "Insert what?" << endl;
              cin >> value;
              cout << "Insert at which position?" << endl;
              cin >> position;
              Three.insertAtPosition(position, value);
              break;

      case 3: cout << "Remove the value at which position?" << endl;
              cin >> position;
              Three.removeFromPosition(position);
              break;
      
      case 4: Three.displayContents();
              break;

      default: cout << "Goodbye." << endl;
               exit (1);          
    }
  }

}