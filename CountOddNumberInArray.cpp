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
bool OddNumber(int Number)
{
    return Number%2!=0;
}
int CountOfOddNumberInArray(int arr[], int arrLength)
{
    int Counter=0;
    for(int i=0; i<arrLength; i++)
    {
        if(OddNumber(arr[i]))
            Counter++;
    }
    return Counter;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[1000], arrLength;
    arrLength = ReadPositiveNumber("Enter length for array:: ");
    FillArray(arr, arrLength);
    cout << "Array Length: " << arrLength << endl;
    PrintArray(arr, arrLength);
    cout << "\nCount of odd numbers in array is :: " << CountOfOddNumberInArray(arr, arrLength) << endl;
}







