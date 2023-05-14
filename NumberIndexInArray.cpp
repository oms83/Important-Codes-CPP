#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;
    }while(Number<=0);
    return Number;
}
int RondomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
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
void GetArray(int arr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        arr[i] = RondomNumber(1, 100);
    }
}
int FoundTheElement(int arr[], int arrLength, int ElementToCheck)
{
    for(int i=0; i<arrLength; i++)
    {
        if(ElementToCheck==arr[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    srand((unsigned)time(NULL));
    short arrLength, ElementToCheck;
    int arr[100];
    arrLength = ReadPositiveNumber("Enter the length for array: ");
    GetArray(arr, arrLength);
    PrintArray(arr, arrLength);
    ElementToCheck = ReadPositiveNumber("Enter the element to check: ");
    cout << "Number you are looking for is:: " << ElementToCheck << endl;
    cout << "The number found at position:: " << FoundTheElement(arr, arrLength, ElementToCheck) << endl;
    cout << "The number found its order:: " << FoundTheElement(arr, arrLength, ElementToCheck)+1 << endl;

}