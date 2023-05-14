#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
}
void GetMatrix(int Matrix[][3], short Rows, short Cols)
{
    int k=1;
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 10);
        }
    }
}
void PrintMatrix(int Matrix[][3], short Rows, short Cols)
{
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            printf("%0*d    ", 2, Matrix[i][j]);
        }
        cout << endl;
    }
}

int SumMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Sum=0;
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            Sum += Matrix[i][j];
        }
    }
    return Sum;
}
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    
    GetMatrix(Matrix, 3, 3);
    cout << "\nRandom Matrix is:: \n";
    PrintMatrix(Matrix, 3, 3);
    cout << "\nSummation Matrices " << SumMatrix(Matrix, 3, 3) << endl;
}
