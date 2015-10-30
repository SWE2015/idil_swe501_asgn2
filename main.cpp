#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LotteryTicket.h"


#define WIDTH 6 // holds how many numbers one lottery ticket has.

using namespace std;

int MasterTicket[WIDTH]; // declaration of the array that will hold target numbers.


//boolean existence check function to avoid duplicates in MasterTicket array.
inline bool existenceCheck(int value, int index){ // check all indexes before the current one for duplicates of value
    bool val;

    for(int j=0; j<index; j++){
        if(MasterTicket[j]==value){
            val = true;
            j = index; // terminate for loop if you came up with one duplicate
        }
        else
            val = false;
    }
    return val;
}

int main()
{
    char name[100];

    // get the name of employee

    cout << "\nHello, please enter the name of employee you want to generate a lottery ticket for: " << endl;
    cin >> name;

    cout << "Thanks! \n";

    // create a lottery ticket for given employee
    LotteryTicket newTicket(name);

    srand(time(0));

    int temp;

    cout << "\nWINNING NUMBERS: \n";

    // loop for assigning random values to MasterTicket
    for(int i=0; i<WIDTH; i++) {
        temp = 1 + rand() %20;
        while(existenceCheck(temp, i)){ // creates a new random number as long as there is a duplicate of the current value
            temp = 1 + rand() %20;
        }
        MasterTicket[i] = temp;

        cout << MasterTicket[i] << "  " ;
    }

    cout << endl;


    newTicket.printHits(MasterTicket);


    cout << "Max Number of hits: " << newTicket.maxHits() << endl;

    cout << "\n" << name << "'s Lucky Numbers are: \n\n";

    newTicket.printTicket();

}

