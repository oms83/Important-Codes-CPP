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
int SumRows(int Matrix[3][3], int Rows, int Cols)
{
    int Sum=0;
    for(int i=0; i<Cols; i++)
    {
        Sum += Matrix[Rows][i];
    }
    return Sum;
}
void PrintRowsSum(int Matrix[3][3], int Rows, int Cols)
{
    for(int i=0; i<Rows; i++)
    {
        cout << "Row " << i+1 << " Sum: " << SumRows(Matrix, i, Cols) << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    AddRandomNumberToMatrix(Matrix);
    cout << "\nRandom Matrix is:: \n";
    PrintMatrix(Matrix);
    cout << "\nSummation of matrix rows is::\n";
    PrintRowsSum(Matrix, 3, 3);
    system("pause>0");
}