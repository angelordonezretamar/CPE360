#include <iostream>
using namespace std;

/*
example of using pointers and classes and attributes to make tabs on a browser.
every time a browser opens it just uses enough storage for one tab, when additional tabs are opened
it pulls from the heap to create them and puts the chunks back in the heap when they are closed
*/

class chromeTab{
    public:
    int length;
    int width;
    chromeTab *next; //this creates a pointer automatically in case we want to make another tab, helps with scaling (see appendix 1)

    chromeTab(){
        length = 40;
        width = 20;
    }
};

int main(){
    /* 
    Creating chunks:
    step one is to get a pointer 
    step two is use that pointer to get a new tab from the heap
    step three is to use that pointer to manipulate this nameless object

    deleting them:
    chromeTab *pointer;
    delete pointer; //this will delete the chunk that is being pointed to, not the pointer

    p will continue to point to that address, it will stay pointing at where that chunk used to be
    */


   cout << "this code makes chrome tabs using classes and pointers" << endl;
   cout << "Now I will make the first tab" << endl;
   chromeTab *ptr; //this is named variable ptr so it is going to live in the application space, that's step one done
   ptr = new chromeTab; //this is step 2, it is getting a new chrometab from the heap and giving it a length of 40 and a width of 20

   cout << "checking the first tab's length and width. L: " << ptr->length << ", W: " << ptr->width << endl; //here we just want to make sure we didn't mess up and we can get the values for l and w

   //step 3: manipulating values
   cout << "now we are gonna change the values of L and W" << endl;
   //How do we change the length to 80?
   ptr->length = 80;
   //How do we change the width to 100?
   ptr->width = 100;

   cout << "lets see those new values. L: " << ptr->length << ", W: " << ptr->width << endl;

   //say I want to make a new tab now
   cout << "now I'm making a second chrome tab" << endl;
   //lets make a new tab and make the length 180 and width 200
   chromeTab *anotherptr;
   anotherptr = new chromeTab;

   cout << "I'm changing the values for L and W" << endl;
   anotherptr->length = 180;
   anotherptr->width = 200;

   cout << "Lets see the values for our second tab. L: " << anotherptr->length << ", W: " << anotherptr->width << endl;

   // so yeah all that code works and all but it is not very elegant, this code following this comment is the better way
   // I want to make a new tab now, the right way
   cout << "making a third chrome tab now, the right way" << endl;
   ptr->next = new chromeTab; //the address of this second tab is right at the end of the first tab

   cout << "lets see that third tabs L and W, should be 40 and 20" << endl; //this is 40 and 20 since we are reaching back into the first tab to make the new tab and new pointer
   cout << "L: " << ptr->next->length << ", W: " << ptr->next->width << endl;

   //now say we want to change the L to 280 and W to 300
   cout << "changing values for L and W for that third tab" << endl;
   ptr->next->length = 280;
   ptr->next->width = 300;

   cout << "Lets make ANOTHER tab, the right way!" << endl;
   ptr->next->next = new chromeTab; // again this chrometab is going to have default values of 40 and 20
   cout << "Lets see those values for the new tab. L: " << ptr->next->next->length << ", W: " << ptr->next->next->width << endl;
   cout << "And now I'll change those values" << endl;
   ptr->next->next->length = 380;
   ptr->next->next->width = 400;
   cout << "Lets see those new values. L: " << ptr->next->next->length << ", W: " << ptr->next->next->width << endl;

   //now we will learn how to delete, what do we do when we are done with a chrome tab?
   delete ptr; //this deletes the first of the "good" tabs, and now we have also lost access to the rest of the ones that were made with it as a template








};  
   /*Appendix 1
   first section of code in int main is the basic way to do all this, but it has some problems.
   so this all works right but the problem is that we are polluting the appspace, this code does not scale well.
   we have to follow all 3 steps, but the problem is the scaling
   in order to fix this we need to change the structure.
   we want to create chrome tabs that have a built in pointer which allows us to create another tab if we wanted to build another tabs
   code that follows the comment in the int main will make use of the new pointer in the class chromeTab which is a more elegant and overall
   just a better way to handle the problem of making tabs
   */



