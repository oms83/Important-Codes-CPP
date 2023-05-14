#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
}
void PrintMatrix(int Matrix[][3], int Rows, int Cols)
{
    for(int i=0; i<Rows; i++)
    {
        for(int j=0; j<Cols; j++)
        {
            cout << setw(3) << Matrix[i][j] << "   ";
        }
        cout << "\n";
    }
}
void RandomMatrix(int Matrix[3][3], int Rows, int Cols)
{
    for(int i=0; i<Rows; i++)
    {
        for(int j=0; j<Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
        cout << "\n";
    }
}
int SumCols(int Matrix[3][3], int Rows, int Cols)
{
    int Sum=0;
    for(int i=0; i<Rows; i++)
    {
        Sum += Matrix[i][Cols];
    }
    return Sum;
}
void PrintSumRows(int Matrix[3][3], int Rows, int Cols)
{
    for(int i=0; i<Rows; i++)
    {
        cout << "Sum " << i+1 << " Sum: " << SumCols(Matrix, Rows, i) << endl;
    }
}
int main()
{
    srand((unsigned)time(0));
    int Matrix[3][3];
    RandomMatrix(Matrix, 3, 3);
    cout << "\nRandom Matrix is:\n";
    PrintMatrix(Matrix, 3, 3);
    cout << "\nSum Matrix Cols is:\n";
    PrintSumRows(Matrix, 3, 3);
}