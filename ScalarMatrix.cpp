#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<cstdlib>
using namespace std;
enum enScalar {Scalar=1, NotScalar=2};
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
enScalar IsItScalar(int Matrix[3][3], short Rows, short Cols)
{
    int FirstDaigElement = Matrix[0][0];
    for(short i=0; i<Rows; i++)
    {
        for(short j=0; j<Cols; j++)
        {
            if( (i==j) && (Matrix[i][j] != FirstDaigElement) ) 
            {
                return enScalar::NotScalar;
            }
            else if( (i!=j) && (Matrix[i][j]!=0) )
            {
                return enScalar::NotScalar;
            }
        }
    }
    return enScalar::Scalar;
}
void CheckToScalar(int Matrix[][3], short Rows, short Cols)
{
    if(IsItScalar(Matrix, Rows, Cols) == enScalar::Scalar)
        cout << "Yes: Matrix is Scalar\n";
    else
        cout << "No: Matrix is not Scalar\n";
}
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3] = {
        {9, 0, 0},
        {0, 9, 0},
        {0, 0, 9}
    };
    // GetMatrix(Matrix, 3, 3);
    cout << "\nRandom Matrix is:: \n";
    PrintMatrix(Matrix, 3, 3);

    CheckToScalar(Matrix, 3, 3);
    system("Pause>0");

}