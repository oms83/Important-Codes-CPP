#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;



int RondomNumber(int From, int To)
{
    return rand()% (To - From + 1) + From;
}
void PrintRondomNumber()
{
    cout << RondomNumber(1,10) << endl;
    cout << RondomNumber(1,10) << endl;
    cout << RondomNumber(1,10) << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    PrintRondomNumber();
}








// void CreatRondomNumber()
// {
//     srand(time(0));
//     for(int i=0; i<3; i++)
//     {
//         cout << rand()%10 + 1 << endl;
//     }
// }

// int main()
// {
//     CreatRondomNumber();
// }