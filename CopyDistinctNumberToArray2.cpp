#include<iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;
    } while(Number<0);
    return Number;
}
void PrintArray(int arr[], int arrLength)
{
    cout << "\nArray:: ";
    for(int i=0; i<arrLength; i++)
    {
        cout << arr[i] << " ";
    }
}
void GetArray(int arr[], int &arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        cout << "Enter [" << i+1 << "] element in the array:: ";
        cin >> arr[i];
    }   
}
int IsNumberInArray(int arr2[], int arr2Length, int Number)
{
    for(int i=0; i<arr2Length; i++)
    {
        if(arr2[i]==Number)
            return 1;
    }
    return 0;
}
void CopyArray(int arr1[], int arr2[], int &arr1Length, int &arr2Length)
{
    for(int i=0; i<arr1Length; i++)
    {
        if(!IsNumberInArray(arr2, arr2Length, arr1[i]))
            arr2[arr2Length++] = arr1[i];
    }
}
int main()
{
    int arr1[1000], arr2[1000], arr1Length, arr2Length;
    arr1Length = ReadPositiveNumber("Enter length for array:: ");
    GetArray(arr1, arr1Length);
    cout << "Array Length: " << arr1Length << endl;
    PrintArray(arr1, arr1Length);
    CopyArray(arr1, arr2, arr1Length, arr2Length);
    PrintArray(arr2, arr2Length);
}







