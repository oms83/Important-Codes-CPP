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
            // printf("%0*d    ", 2, Matrix[i][j]);
            cout << setw(3) << Matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

bool CheckToGivenNumber(int SMatrix[][3], int Rows, int Cols, int Number)
{
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            if(SMatrix[i][j]==Number)
                return true;
        }
    }
    return false;
}
void PrintIntersectedNumber(int FMatrix[][3], int SMatrix[3][3], int Rows, int Cols)
{
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            if(CheckToGivenNumber(SMatrix, Rows, Cols, FMatrix[i][j]))
                cout << FMatrix[i][j] << "   ";
        }
    }
}
int main()
{
    srand((unsigned)time(0));
    int FMatrix[3][3], SMatrix[3][3];

    GetMatrix(FMatrix, 3, 3);
    cout << "\nFirst Random Matrix is: \n";
    PrintMatrix(FMatrix, 3, 3);

    GetMatrix(SMatrix, 3, 3);
    cout << "\nFirst Random Matrix is: \n";
    PrintMatrix(SMatrix, 3, 3);

    cout << "\nIntersected Number is: \n";
    PrintIntersectedNumber(FMatrix, SMatrix, 3, 3);
}