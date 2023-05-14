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
void MulMatrix(int FMatrix[3][3], int SMatrix[3][3], int MMatrix[3][3], short Rows, short Cols)
{
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            MMatrix[i][j] = SMatrix[i][j]*FMatrix[i][j];
        }
    }
}
void PrintMatirx(int Matrix[3][3], short Rows, short Cols)
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
int main()
{
    srand((unsigned)time(0));
    int MMatrix[3][3], FMatrix[3][3], SMatrix[3][3];
    GetMatrix(FMatrix, 3, 3);
    cout << "\nFrist Matrix:: \n";
    PrintMatrix(FMatrix, 3, 3);
    
    GetMatrix(SMatrix, 3, 3);
    cout << "\nSecond Matrix is:: \n";
    PrintMatrix(SMatrix, 3, 3);

    MulMatrix(FMatrix, SMatrix, MMatrix, 3, 3);
    cout << "\nMultiply Matrices\n";
    PrintMatrix(MMatrix, 3, 3);
}
