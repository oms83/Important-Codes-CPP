#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<cstdlib>
using namespace std;
int ReadAPositiveNumber()
{
    int Number=0;
    do
    {
        cout << "Enter a positive number: ";
        cin >> Number;
    }while(Number<0);
    return Number;
}
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
            Matrix[i][j] = RandomNumber(0, 10);
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
bool CheckToGivenNumber(int Matrix[][3], int Rows, int Cols, int Number)
{
    int Counter=0;
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            if(Matrix[i][j]==Number)
                return true;
        }
    }
    return false;
}
void PrintGivenNumberOfCount(int Matrix[][3], int Rows, int Cols, int Number)
{
    if(CheckToGivenNumber(Matrix, Rows, Cols, Number))
        cout << "\nYes is there\n";
    else
        cout << "\nNo is not\n";
 }
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    GetMatrix(Matrix, 3, 3);
    cout << "\nRandom Matrix is: \n";
    PrintMatrix(Matrix, 3, 3);
    PrintGivenNumberOfCount(Matrix, 3, 3, ReadAPositiveNumber());
}