#include<iostream>
#include<string>
#include<stdbool.h>
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
int RondumNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
}
void FillArray(int arr[], int &arrLength)
{
    for(int i=0; i<arrLength; i++)
        arr[i] = RondumNumber(1, 100);
}
bool EvenNumber(int Number)
{
    return Number%2==0;
}
void CopyArray(int arr1[], int arr2[], int arr1Length, int &arr2Length)
{
    for(int i=0; i<arr1Length; i++)
    {
        if(EvenNumber(arr1[i]))
            arr2[arr2Length++] = arr1[i];
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[1000], arr2[1000], arr1Length, arr2Length;
    arr1Length = ReadPositiveNumber("Enter length for array:: ");
    FillArray(arr1, arr1Length);
    cout << "Array Length: " << arr1Length << endl;
    PrintArray(arr1, arr1Length);
    CopyArray(arr1, arr2, arr1Length, arr2Length);
    PrintArray(arr2, arr2Length);
}







