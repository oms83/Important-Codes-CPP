#include<iostream>
#include<stdio.h>
#include<iomanip>
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
            Matrix[i][j] = RandomNumber(10, 99);
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
int FindAMaxNumber(int Matrix[][3], int Rows, int Cols)
{
    short Max = Matrix[0][0];
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            if(Matrix[i][j]>Max)
                Max = Matrix[i][j];
        }
    }
    return Max;
}
int FindAMinNumber(int Matrix[][3], int Rows, int Cols)
{
    short Min = Matrix[0][0];
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            if(Matrix[i][j]<Min)
                Min = Matrix[i][j];
        }
    }
    return Min;
}
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    GetMatrix(Matrix, 3, 3);
    cout << "\nRandom Matrix is: \n";
    PrintMatrix(Matrix, 3, 3);
    cout << "\nMax Number In Matrix Is: " << FindAMaxNumber(Matrix, 3, 3) << endl;
    cout << "\nMin Number In Matrix Is: " << FindAMinNumber(Matrix, 3, 3) << endl;
    system("pause>0");
}