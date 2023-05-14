#include<iostream>
#include<string>
#include<cstdlib>
#include<stdbool.h>
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
void PrintArray(int arr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
        cout << arr[i] << " ";
}
int RondumNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
}
void AddElementArray(int arr[], int &arrLength, int Number)
{
    arrLength++;
    arr[arrLength-1] = Number;
}
void FillArray(int arr[], int &arrLength)
{
    for(int i=0; i<arrLength; i++)
        arr[i] = RondumNumber(1, 100);
}
void CopyArray(int arr1[], int arr2[], int arr1Length, int &arr2Length)
{
    bool AddMore=true;
    for(int i=0; i<arr1Length; i++)
    {
        cout << "\nDo you want to add more number? NO[0], Yes[1]: ";
        cin >> AddMore;
        if(AddMore)
            AddElementArray(arr2, arr2Length, arr1[i]);
        else
            break;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[100], arr2[100], arr1Length, arr2Length;
    arr1Length = ReadPositiveNumber("Enter length for array1: ");
    FillArray(arr1, arr1Length);
    cout << "Array1:: \n";
    PrintArray(arr1, arr1Length);
    CopyArray(arr1, arr2, arr1Length, arr2Length);
    cout << "\nArray2:: \n";
    PrintArray(arr2, arr2Length);

}




// #include<iostream>
// #include<string>
// #include<stdbool.h>
// using namespace std;
// int ReadPositiveNumber(string Message)
// {
//     int Number;
//     do
//     {
//         cout << Message;
//         cin >> Number;
//     } while(Number<0);
//     return Number;
// }
// void PrintArray(int arr[], int arrLength)
// {
//     for(int i=0; i<arrLength; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
// int RandumNumber(int From, int To)
// {
//     return rand()%(To-From+1) + From;
// }
// void FillArray(int OrginalArray[], short OrginalArraryLength)
// {
//     for(int i=0; i<OrginalArraryLength; i++)
//     {
//         OrginalArray[i] = RandumNumber(1, 100);
//     }
// }
// void CopyEmelentInArray(int CopyArray[], short &CopyArrayLength, int Number)
// {
//     CopyArrayLength++;
//     CopyArray[CopyArrayLength-1] = Number;
// }
// void CopyUserElementArray(int CopyArray[], int OrginalArray[], short &CopyArrayLength, short OrginalArraryLength)
// {
//     int i=0;
//     bool AddMore=true;
//     do
//     {
//         cout << "\nDo you want copy [" << i+1 << "] element of orginal array ?  No[0],Yes[1]::";
//         cin >> AddMore;
//         CopyEmelentInArray(CopyArray, CopyArrayLength, OrginalArray[i++]);
//     }while (AddMore&&(CopyArrayLength!=OrginalArraryLength));   
// }
// int main()
// {
//     int CopyArray[100], OrginalArray[100];
//     short CopyArrayLength, OrginalArraryLength;
//     OrginalArraryLength = ReadPositiveNumber("Enter length for orginal array:: ");
//     FillArray(OrginalArray, OrginalArraryLength);
//     cout << "Orginal Array:: \n";
//     PrintArray(OrginalArray, OrginalArraryLength);
//     CopyUserElementArray(CopyArray, OrginalArray, CopyArrayLength, OrginalArraryLength);
//     cout << "\nCopy Array:: \n";
//     PrintArray(CopyArray, CopyArrayLength);
// }