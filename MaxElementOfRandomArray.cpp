#include<iostream>
#include<time.h>
#include<string>
#include<stdlib.h>
using namespace std;

int RondomNumber(int From, int To)
{
    return rand()% (To - From + 1) + From;
}
void GetArray(int arr[], int &arrLength)
{
    cout << "Enter the length for array: ";
    cin >> arrLength;
    for(int i=0; i<arrLength; i++)
    {
        arr[i] = RondomNumber(1, 100);        
    }
}
void PrintArray(int arr[], int arrLength)
{
    cout << "Array Elements:: ";
    for(int i=0; i<arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int MaxElementOfArray(int arr[], int arrLength)
{
    int Max = arr[0];
    for(int i=0; i<arrLength; i++)
    {
        if(Max<arr[i])
            Max = arr[i];
    }
    return Max;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength, Number; 
    GetArray(arr, arrLength);
    PrintArray(arr, arrLength);
    cout << "The Maxsimum Element In The Array Is ::" << MaxElementOfArray(arr, arrLength);
}