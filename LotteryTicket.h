#ifndef LOTTERYTICKET_H
#define LOTTERYTICKET_H


#define HEIGHT 3 // holds how many tickets will be given to each employee
#define WIDTH 6 // holds how many numbers one lottery ticket has. must be the same with the WIDTH defined in main!


class LotteryTicket
{
    public:
        LotteryTicket(char * s);
        void printHits(int master[]) ;
        void printTicket() ;
        inline bool existenceCheck(int value, int RowIndex, int ColumnIndex) ;
        int maxHits();


    protected:
    private:
        int LuckyNumbers[HEIGHT][WIDTH];
        int numberOfHits;
        int AllNumberOfHits[HEIGHT];
        int temp;

        char * EmployeeName;



};

#endif // LOTTERYTICKET_H
