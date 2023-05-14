#include<iostream>
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
void GetArray(int arr[], int &arrLength)
{
    cout << "Enter the length for array: ";
    cin >> arrLength;
    cout << "\nEnter the elements in array:\n";
    for(int i=0; i<arrLength; i++)
    {
        cout << "Element [" << i+1 << "] : ";
        cin >> arr[i];
    }
}
void PrintArray(int arr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int TimeRepeated(int Number, int arr[], int arrLength)
{
    int Counter=0;
    for(int i=0; i<arrLength; i++)
    {
        if(arr[i]==Number)
            Counter++;
    }
    return Counter;
}
int main()
{
    int arr[100], arrLength, Number; 
    GetArray(arr, arrLength);
    Number = ReadPositiveNumber("Enter the number you want to check: ");
    cout << "The Array\n";
    PrintArray(arr, arrLength);
    cout << "\nNumber: " << Number;
    cout << "Is repeated: " << TimeRepeated(Number, arr, arrLength);

}