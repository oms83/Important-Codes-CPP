#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
}
void AddRandomNumberToMatrix(int Matrix[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}
void PrintMatrix(int Matrix[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << setw(3) << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    AddRandomNumberToMatrix(Matrix);
    PrintMatrix(Matrix);
}