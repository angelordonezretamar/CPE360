#include <iostream>
using namespace std;

//literally just building legos, try not to lose chunks

class chunk{
public:
    int value;
    chunk *next;

    chunk(){
        value = -1; //value here doesn't matter, more important is what it sets next to
        next = NULL;
    }
};
//the putpose fo this lecture is to learn three things well:
//1. add a chunk in the front, middle, and end
//2. remove a chunk from the front, middle, and end
//3. display the values in a train of chunks

int main(){
//phase 0- jumpstart the process: lets get 3 chunks that are knitted together
//so we need a pointer = new <type>
    chunk *ptr;
    ptr = new chunk;
    ptr->next = new chunk; //using the pointer of the first chunk to grab a second
    ptr->next->next = new chunk; //using the pointer of the second chunk to grab a third
    //all these values are -1

//phase 1- now that we have 3 chunks let's add something new to the front, middle, and end
//front first
//we want a new pointer now
    chunk *temp;
//temp is gonna get us a brand new chunk
    temp = new chunk; //now we want to make this new chunk the first chunk in the train of 3 that we already have
    temp->next = ptr; //step 1
    ptr = temp;//step 2, now this chunk is the first in a line of 4
//adding to the middle
//get another new chunk
    temp = new chunk; //now we want to add this chunk to the middle (specifically beween chunks 2 and 3 in the train)
    temp->next = ptr->next->next; //step 1
    ptr->next->next = temp; //step 2
//adding to the end, this one will have a lot of arrows
// ptr->next->next->next->next = new chunk; we 
//we could just use that^ method, like when we mad ethe first 3 chunks
//but following the same way we did the beginning and middle:
    temp = new chunk;
    ptr->next->next->next->next->next = temp;

//Phase 2- not lets do the opposite and remove chunks from the fron, middle and end
//steps
//1st grab the address of the thing we want to delete
//then isolate it (reorganize the structure)
//and then finally, delete it

//removing from the front first
    temp = ptr; //step1
    ptr = ptr->next; //step2
    delete temp; //step3 (remember that this does not delete temp, cause temp is a variable, this deletes what temp is pointing to i.e. the first chunk)

//removing from the middle (right now the train is 5 chunks long)
//we want to remove the 3rd chunk
    temp = ptr->next->next; //step1
    ptr->next->next = ptr->next->next->next; //step2
    delete temp; //step3
//removing from the end
    temp = ptr->next->next->next; //step1, 4 chunks so 3 nexts
    ptr->next->next->next = NULL; //step2, set it to NULL keeping with the arbitrary values we set in the class
    delete temp; //step3,
/*another method to remove from the end:
delete ptr->next->next->next;
ptr->next->next->next = NULL;
*/

}