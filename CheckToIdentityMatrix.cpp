#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<cstdlib>
using namespace std;
enum enIdentity {Identity=1, NotIdentity=2};
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
            Matrix[i][j] = RandomNumber(0, 1);
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
enIdentity IsItIdentity(int Matrix[3][3], short Rows, short Cols)
{
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            if( (i==j) && (Matrix[i][j]!=1) )
            {
                return enIdentity::NotIdentity;
            }
            else if( (i!=j) && (Matrix[i][j]!=0) )
            {
                return enIdentity::NotIdentity;
            }
        }
    }
    return enIdentity::Identity;
}
void CheckToIdentity(int Matrix[][3], short Rows, short Cols)
{
    if(IsItIdentity(Matrix, Rows, Cols) == enIdentity::Identity)
        cout << "Yes: Matrix is Identity\n";
    else
        cout << "No: Matrix is not Identity\n";
}
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    GetMatrix(Matrix, 3, 3);
    cout << "\nRandom Matrix is:: \n";
    PrintMatrix(Matrix, 3, 3);

    CheckToIdentity(Matrix, 3, 3);

}