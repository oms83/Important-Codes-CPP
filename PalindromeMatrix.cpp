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
bool CheckToPalindromeMatrix(int Matrix[][3], int Rows, int Cols)
{
    short Max = Matrix[0][0];
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<MyRound(Cols); j++) // أو منقسم على 2 افضل
        {
            if(Matrix[i][j]!=Matrix[i][Cols-j-1])
                return false;
        }
    }
    return true;
}
void PrintResultOfPalindrome(int Matrix[][3], int Rows, int Cols)
{
    if(CheckToPalindromeMatrix(Matrix, Rows, Cols))
        cout << "It is palindrome matrix\n ";
    else
        cout << "It is not palindrome matrix\n ";
}
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3] = {
        {1, 2, 1},
        {2, 2, 2},
        {5, 6, 5}
    };
    
    GetMatrix(Matrix, 3, 3);
    cout << "\nRandom Matrix is: \n";
    PrintMatrix(Matrix, 3, 3);
    
    PrintResultOfPalindrome(Matrix, 3, 3);
    system("pause>0");
}