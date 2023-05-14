#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int RondomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
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

void SumToArray(int arr1[], int arr2[], int sumArr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        sumArr[i] = arr1[i] + arr2[i];
    }
}

int main()
{
    int arr1[100], arr2[100], sumArr[100], arrLength;
    GetArray(arr1, arrLength);
    GetArray(arr2, arrLength);

    cout << "\nfrist array\n";
    PrintArray(arr1, arrLength);
    cout << "\nsecond array\n";
    PrintArray(arr2, arrLength);
    cout << "\nsummation of two array\n";
    SumToArray(arr1, arr2, sumArr, arrLength);
    PrintArray(sumArr, arrLength);



}