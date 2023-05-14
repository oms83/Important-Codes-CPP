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
void SumRowsArray(int Matrix[3][3], int arrSum[3], int Cols, int Rows)
{
    for(int i=0; i<Rows; i++)
    {
        arrSum[i] = SumCols(Matrix, Rows, i);
    }
}
void PrintSumRows(int arrSum[], int Rows)
{
    for(int i=0; i<Rows; i++)
    {
        cout << "Sum " << i+1 << " Sum: " << arrSum[i] << endl;
    }
}
int main()
{
    srand((unsigned)time(0));
    int arrSum[3], Matrix[3][3];
    RandomMatrix(Matrix, 3, 3);
    cout << "\nRandom Matrix is:\n";
    PrintMatrix(Matrix, 3, 3);
    SumRowsArray(Matrix, arrSum, 3, 3);
    cout << "\nSum Matrix Cols is:\n";
    PrintSumRows(arrSum, 3);
}