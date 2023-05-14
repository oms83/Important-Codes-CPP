#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
}
void AddRandomNumberToMatrix(int Matrix[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}
void PrintMatrix(int Matrix[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << setw(3) << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
void SumRows(int Matrix[3][3], int arrSum[])
{
    int Sum=0;
    for(int i=0; i<3; i++)
    {
        Sum=0;
        for(int j=0; j<3; j++)
        {
            Sum += Matrix[i][j];
        }
        arrSum[i] = Sum;
    }
}
void PrintRowsSum(int arrSum[])
{
    for(int i=0; i<3; i++)
    {
        cout << "Row " << i+1 << " Sum: " << arrSum[i] << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3], arrSum[3];
    AddRandomNumberToMatrix(Matrix);
    cout << "\nRandom Matrix is:: \n";
    PrintMatrix(Matrix);
    SumRows(Matrix, arrSum);
    cout << "\nSummation of matrix rows is::\n";
    PrintRowsSum(arrSum);
    system("pause>0");
}
