#include<iostream>
#include<string>
#include<cmath>
using namespace std;

enum enPrimeNotPrime { Prime=1, NotPrime=2 }; 
enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number/2);
    for(int Counter=2; Counter<=M; Counter++)
    {
        if(Number%Counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
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

void PrintArray(int arr[], int arrLength, string Message)
{
    cout << Message + " Array Elements:: ";
    for(int i=0; i<arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int CopyArray(int OrginalArr[], int CopyArr[], int arrLength)
{
    int len=0;
    for(int i=0; i<arrLength; i++)
    {
        if(CheckPrime(OrginalArr[i])==enPrimeNotPrime::Prime)
        {
            CopyArr[len++] = OrginalArr[i];
        }
    }
    return len;
}

int main()
{
    int OrginalArr[100], CopyArr[100], arrLength;
    GetArray(OrginalArr, arrLength);
    
    PrintArray(OrginalArr, arrLength, "Orginal");
    CopyArray(OrginalArr, CopyArr, arrLength);
    int len=CopyArray(OrginalArr, CopyArr, arrLength);
    PrintArray(CopyArr, len, "Prime");
}