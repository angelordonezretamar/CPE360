//this is to learn randomness and probability

#include <iostream>
#include <stdlib.h> //extra include that helps out here
#include<time.h> //also extra that might help
using namespace std;

int main() {
    int secret;
    int guess, count = 0;

    srand(time(NULL)); //necessary for the simulation
    secret = rand()%10+1; //%10+1 makes sure that the number is between 1 and 10

    while(count < 3) { //you get 3 guesses
        cout << "Guess?" << endl;
        cin >> guess;
        if(guess == secret) {
            cout << "You got it!" << endl;
            exit(0);
        } 
        count++;
    }

    cout << "the secret number was: " << secret << endl;
    
}