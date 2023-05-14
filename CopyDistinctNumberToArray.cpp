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
enum IsItNumber{Found=1, NotFound=2};
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
IsItNumber CheckToArray(int arr2[], int Number)
{
    int i=0;
    do
    {
        if(Number==arr2[i])
        return IsItNumber::Found;
    }while(arr2[i++]!=0);
    return IsItNumber::NotFound;
}
void CopyArray(int arr1[], int arr2[], int &arr1Length, int &arr2Length)
{
    for(int i=0; i<arr1Length; i++)
    {
        if(CheckToArray(arr2, arr1[i]) == IsItNumber::NotFound)
            arr2[arr2Length++] = arr1[i];
    }
}
int main()
{
    int arr1[1000], arr2[1000]={0}, arr1Length, arr2Length;
    arr1Length = ReadPositiveNumber("Enter length for array:: ");
    GetArray(arr1, arr1Length);
    cout << "Array Length: " << arr1Length << endl;
    PrintArray(arr1, arr1Length);
    CopyArray(arr1, arr2, arr1Length, arr2Length);
    PrintArray(arr2, arr2Length);
}







