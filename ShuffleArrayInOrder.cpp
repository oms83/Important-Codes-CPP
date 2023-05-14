#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number=0; 
    do
    {
        cout << Message;
        cin >> Number;
    }while(Number<0);
    return Number;
}
int RondomNumber(int From, int To)
{
    return rand() % ( To - From + 1 ) + From;
}
void Swap(int &A, int &B)
{
    int Temp = A;
    A = B;
    B = Temp;
}
void FillElementInArray(int arr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        arr[i] = i+1;
    }
}
void CreatSuffleArray(int arr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        Swap(arr[RondomNumber(1, arrLength-1)], arr[RondomNumber(1, arrLength-1)]);
    }
}
void PrintArray(int arr[], int arrLength, string Message)
{
    cout << Message + " Array Elements:: ";
    for(int i=0; i<arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));
    int OrginalArr[100], arrLength;
    arrLength = ReadPositiveNumber("Enter Length for array:: ");
    FillElementInArray(OrginalArr, arrLength);
    PrintArray(OrginalArr, arrLength, "Orginal");
    CreatSuffleArray(OrginalArr, arrLength);
    PrintArray(OrginalArr, arrLength, "Shuffle");
    

}