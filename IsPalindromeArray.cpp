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
void GetArray(int arr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        cout << "Enter [" << i+1 << "] element in the array:: ";
        cin >> arr[i];
    }   
}
int CheckPalindorme(int arr[], int arrLength)
{
    int Counter=0;
    for(int i=0; i<arrLength; i++)
        if(arr[i] == arr[arrLength-i-1])
                Counter++;
    return Counter;
}
bool IsItPalindrome(int arr[], int arrLength)
{
    return CheckPalindorme(arr, arrLength) == arrLength;  
}
int main()
{
    int arr[100], arrLength;
    arrLength = ReadPositiveNumber("Enter length for array:: ");
    GetArray(arr, arrLength);
    PrintArray(arr, arrLength);
    if(IsItPalindrome(arr, arrLength))
        cout << "\nYes";
    else 
        cout << "\nNo";
}