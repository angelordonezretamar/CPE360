#include <iostream>
using namespace std;

// Lecture 2/17/22
// More Pointers and Chrome Tabs

class chromeTab {
 public:
  int length;
  int width;
  chromeTab *next;  // NEW: use this every time I want to make a new tab.

  chromeTab() {
    // initialized brand new chrome tab with default attributes
    length = 40;
    width = 20;
    next = NULL;  // NEW
  }
};

int main() {
  chromeTab coolTab;
  //=============================
  // Creating and deleting chunks
  //=============================
  chromeTab *p;
  p = new chromeTab;  // create new chunks
  delete p;  // delete the chunk 'p' is pointing to // VERY IMPOTANT: this only
             // deletes the chunk, NOT p.

  // 1. Get a pointer
  // 2. Use that to get a "new" tab from the heap
  // 3. Use that pointer to manipulate this nameless object
  chromeTab *ptr;
  ptr = new chromeTab;

  // second chunk
  ptr->next = new chromeTab;
  // third chunk
  ptr->next->next = new chromeTab;

  // add something to the FRONT: a "temporary" pointer?
  // 1: get a temp pointer to create a new chunk
  // 2: connect this 'new' chunk to the existing train
  // 3: get 'ptr' to connect to this 'new' chunk
  chromeTab *temp;
  temp = new chromeTab;  /// 1: done

  temp->next = ptr;  // 2: done

  // ptr = temp;  // 3: get ptr to the first chunk
  ptr->next = temp;

  chromeTab *exp;
  exp = new chromeTab;
  cout << "Before delete: " << exp << endl;
  delete exp;
  exp = new chromeTab;
  cout << "Trying again: " << exp->length << endl;

  // add a new chunk to the middle
  // basically this new chunk should be the new "third" chunk
  temp = new chromeTab;
  temp->next = ptr->next->next;  // 2
  ptr->next->next = temp;        // 3

  // display chunks
  temp = ptr;
  int count = 0;
  while (temp != NULL) {
    cout << "Length: " << temp->length << endl;
    cout << "Chunk #: " << ++count << endl;
    temp = temp->next;
  }
  //so this displays chunks endlessly and will probably crash shit if it stays this way
  //since I borrowed this code from a friend since I missed this lecture I'm not sure if this is on purpose
  //gotta ask the professor
}