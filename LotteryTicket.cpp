#include "LotteryTicket.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


//boolean existence check function to avoid duplicates in LuckyNumbers Rows.
inline bool LotteryTicket::existenceCheck(int value, int RowIndex, int ColumnIndex){
    bool val;

    for(int j=0; j<RowIndex; j++){
        if(LuckyNumbers[ColumnIndex][j]==value){ // check only for rows if there is a duplicate in previous indexes
            val = true;
            j = RowIndex; // terminate for loop if you came up with one duplicate
        }
        else
            val = false;
    }
    return val;
}

LotteryTicket::LotteryTicket(char * s)
{
    // holds the name of employee that will have this ticket.
    EmployeeName = s;

    // creates HEIGHT many lottery tickets with unique values and stores all in LuckyNumbers array.
    for(int i=0; i<HEIGHT; i++) {
        for(int k=0; k<WIDTH; k++){
            temp = 1 + rand() %20;
            while(existenceCheck(temp, k, i)){
                temp = rand() %20;
            }
            LuckyNumbers[i][k] = temp;
        }
    }
}

// print lottery tickets
void LotteryTicket::printTicket() {

    for(int i=0; i<HEIGHT; i++){
        for (int k=0; k<WIDTH; k++){
            cout << LuckyNumbers[i][k] << "\t";
        }

        cout << endl;

    }
}

// check and print how many hits each lottery ticket has and print the result
void LotteryTicket::printHits(int master[]) {
    for(int i=0; i<HEIGHT; i++){
        numberOfHits = 0; // initialize to zero at the beginning of every Row because each row is a seperate Lottery Ticket.
        for(int k=0; k<WIDTH; k++){
            for(int j=0; j<WIDTH; j++){
                if(LuckyNumbers[i][k] == master[j]){
                    numberOfHits++;
                    j = WIDTH + 1;
                }

            }
        }
        AllNumberOfHits[i] = numberOfHits; // hold the number of hits for all tickets.
    }

    //print name of employee:
    cout << "\nThe number of hits " << EmployeeName << " has are: \n";

    //print the results
    for(int l=0; l<HEIGHT; l++){
        if(AllNumberOfHits[l]!=0){
            cout <<"row "<< (l+1)<< "\t:"<< AllNumberOfHits[l] << endl;
        }
    }
    cout << "\n\n";
}

// return maximum number of hits this employee has
int LotteryTicket::maxHits(){

    int max = 0;

    for(int l=0; l<HEIGHT; l++){
        if(AllNumberOfHits[l]>max){
            max = AllNumberOfHits[l];
        }
    }
    return max;
}
