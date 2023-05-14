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
int MinElementOfArray(int arr[], int arrLength)
{
    int Min = arr[0];
    for(int i=0; i<arrLength; i++)
    {
        if(Min>arr[i])
            Min = arr[i];
    }
    return Min;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength, Number; 
    GetArray(arr, arrLength);
    PrintArray(arr, arrLength);
    cout << "The Minimum Element In The Array Is ::" << MinElementOfArray(arr, arrLength);
}