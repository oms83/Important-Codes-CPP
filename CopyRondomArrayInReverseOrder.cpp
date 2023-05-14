#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int RondomNumber(int From, int To)
{
    return rand() % ( To - From + 1 ) + From;
}
void GetArray(int arr[], int &arrLength)
{
    cout << "Enter the length for array: ";
    cin >> arrLength;
    for(int i=0; i<arrLength; i++)
    {
        arr[i] = RondomNumber(1,100);
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

void CopyReveresArray(int OrginalArr[], int CopyArr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        CopyArr[i] = OrginalArr[arrLength-i-1];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int OrginalArr[100], CopyArr[100], arrLength;
    GetArray(OrginalArr, arrLength);
    
    PrintArray(OrginalArr, arrLength, "Orginal");
    CopyReveresArray(OrginalArr, CopyArr, arrLength);
    PrintArray(CopyArr, arrLength, "Copied");
}
