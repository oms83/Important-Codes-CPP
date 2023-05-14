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
int SumRows(int Matrix[3][3], int Rows, int Cols)
{
    int Sum=0;
    for(int i=0; i<Cols; i++)
    {
        Sum += Matrix[Rows][i];
    }
    return Sum;
}
void SumRowsArray(int Matrix[3][3], int arrSum[3], int Cols, int Rows)
{
    for(int i=0; i<Rows; i++)
    {
        arrSum[i] = SumRows(Matrix, i, Cols);
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
    int arrSum[3], Matrix[3][3];
    RandomMatrix(Matrix, 3, 3);
    cout << "Matrix:\n";
    PrintMatrix(Matrix, 3, 3);
    SumRowsArray(Matrix, arrSum, 3, 3);
    cout << "Sum Rows\n";
    PrintSumRows(arrSum, 3);
}