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
            Matrix[i][j] = RandomNumber(0, 1n);
        }
    }
}
int MyRound(float Number)
{
    float part;
    part = Number - int(Number);
    if(Number>0)
    {
        if(part> .5)
            return int(Number+1);
        else
            return int(Number);
    }
    else
    {
        if(part> -.5)
            return int(Number);
        else
            return int(Number-1);
    }
    return Number;
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
int CheckToGivenNumber(int Matrix[][3], int Rows, int Cols, int Number)
{
    int Counter=0;
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            if(Matrix[i][j]==Number)
                Counter++;
        }
    }
    return Counter;
}
bool CheckToSparseMatrix(int Matrix[][3], int Rows, int Cols)
{
    return CheckToGivenNumber(Matrix, Rows, Cols, 0) > MyRound((Rows*Cols)/2);
}
void PrintResultSparseMatrix(int Matrix[][3], int Rows, int Cols)
{
    if(CheckToSparseMatrix(Matrix, 3, 3))
        cout << "\nYes: Sparse Matrix\n";
    else
        cout << "\nNo: Is Not Sparse Matrix\n";

}
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    GetMatrix(Matrix, 3, 3);
    cout << "\nRandom Matrix is: \n";
    PrintMatrix(Matrix, 3, 3);
    PrintResultSparseMatrix(Matrix, 3, 3);
}