#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
enum enEqual {Equal=1, NotEqual=2};
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
enEqual CheckToEqual(int FMatrix[3][3], int SMatrix[3][3], short Rows, short Cols)
{
    int Sum=0;
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            if(FMatrix[i][j]!=SMatrix[i][j])
            return enEqual::NotEqual;
        }
    }
    return enEqual::Equal;
}
void EqualORNot(int FMatrix[][3], int SMatrix[][3], short Rows, short Cols)
{
    if(CheckToEqual(FMatrix, SMatrix, Rows, Cols) == enEqual::Equal)
        cout << "Yes: Matrices is equal \n";
    else
        cout << "No: Matrices is not equal \n";
}
int main()
{
    srand((unsigned)time(0));
    int FMatrix[3][3], SMatrix[3][3];
    
    GetMatrix(FMatrix, 3, 3);
    cout << "\nFirst Random Matrix is:: \n";
    PrintMatrix(FMatrix, 3, 3);

    GetMatrix(SMatrix, 3, 3);
    cout << "\nSecond Random Matrix is:: \n";
    PrintMatrix(SMatrix, 3, 3);

    EqualORNot(FMatrix, SMatrix, 3, 3);
}
