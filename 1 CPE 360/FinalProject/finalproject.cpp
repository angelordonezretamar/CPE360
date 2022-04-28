#include <iostream>
using namespace std;

class Customer {
    public:
        int in_time;
        int out_time;
        int order_time;
};

class Queue {
    public:
        Customer *head;
        Queue() {

        }
        
        void enqueue(int in_time, int order_time) {

        }

        void dequeue() {

        }
};


//gotta make a while loop to run the simulation of a day
main() {
    int TIME = 0, generator;
    int cumulative_time = 0; 
    int customer_count = 0;
    int cumulative_qlength = 0; //to get the average
    srand(time(NULL));
    
    //store hours, every minute of that day
    //this loop is where we will simulate everything that happens in the day the store is open 1020 minutes
    while(TIME < 1020) {
        //1. should a new customer arrive to the queue at this minute?
        //set up if statements for the time of day so we can see what the probability will be for someone entering the store
        if(TIME >= 0 && TIME <= 120) {
            //this is 8-10am so the probability is 0.3
            generator = rand()%100 + 1; //generating a random number from 1 to 100
            if(generator <= 30) { //checking if it is <=30 would mean that it has satisfied the 0.3% probability
                generator = rand()%6+1; //order time
                cout << "New customer has arrived at time: " << TIME << " with an order time of: " << generator << endl;
                //enqueue
            }
            //else if to set up all the other time slots

            }
        

        //2. is a customer going to place an order at this minute?
        int order = rand()%6+1; //random number between one and 6 (order time)

        //3. is a customer ready to leave the store at this minute?

        TIME++;
    }
}