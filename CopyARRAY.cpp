#include<iostream>
#include<string>
using namespace std;

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

void PrintArray(int arr[], int arrLength, string Message)
{
    cout << Message + " Array Elements:: ";
    for(int i=0; i<arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void CopyArray(int OrginalArr[], int CopyArr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        CopyArr[i] = OrginalArr[i];
    }
}

int main()
{
    int OrginalArr[100], CopyArr[100], arrLength;
    GetArray(OrginalArr, arrLength);
    
    PrintArray(OrginalArr, arrLength, "Orginal");
    CopyArray(OrginalArr, CopyArr, arrLength);
    PrintArray(CopyArr, arrLength, "Copied");
}