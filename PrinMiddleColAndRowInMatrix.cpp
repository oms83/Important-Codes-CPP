#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
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
void GetMatrix(int Matrix[][3], short Rows, short Cols)
{
    int k=1;
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
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
void PrintMiddleCol(int Matrix[][3], int Rows)
{
    int Middle = MyRound(Rows/2);   
    for(int i=0; i<Rows; i++)
    {
        // cout << setw(3) << Matrix[Middle][i] << "  ";
        printf("%0*d    ", 2, Matrix[Middle][i]);
    }
}
void PrintMiddleRow(int Matrix[][3], int Cols)
{
    int Middle = MyRound(Cols/2);   
    for(int i=0; i<Cols; i++)
    {
        // cout << setw(3) << Matrix[i][Middle] << "  ";
        printf("%0*d    ", 2, Matrix[i][Middle]);
    }
}
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    GetMatrix(Matrix, 3, 3);
    
    cout << "\nRandom Matrix is:: \n";
    PrintMatrix(Matrix, 3, 3);
    
    cout << "\nMiddle Row is:: \n";
    PrintMiddleRow(Matrix, 3);
    
    cout << "\nMiddle Col is:: \n";
    PrintMiddleCol(Matrix, 3);

}