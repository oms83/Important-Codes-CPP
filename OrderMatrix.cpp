#include<iostream>
#include<iomanip>
using namespace std;
void GetMatrix(int Matrix[][3])
{
    int k=1;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            Matrix[i][j] = k++;
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
int main()
{
    int Matrix[3][3];
    GetMatrix(Matrix);
    cout << "\nRandom Matrix is:: \n";
    PrintMatrix(Matrix);
}
