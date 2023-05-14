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
void AddEmelentInArray(int arr[], int &arrLength, int Number)
{
    arrLength++;
    arr[arrLength-1] = Number;
}
void InputUserNumberInArray(int arr[], int &arrLength)
{
    bool AddMore;
    do
    {
        AddEmelentInArray(arr, arrLength, ReadPositiveNumber("Please enter a number:: "));
        cout << "Do you want to add more number? NO[0], Yes[1]: ";
        cin >> AddMore;
    } while (AddMore);
    
}
int main()
{
    int arr[1000], arrLength;
    InputUserNumberInArray(arr, arrLength);
    cout << "Array Length: " << arrLength << endl;
    PrintArray(arr, arrLength);
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
// void ChageSize(int &arrLength)
// {
//     arrLength++;
// }
// void PrintArray(int arr[], int arrLength)
// {
//     cout << "\nArray:: ";
//     for(int i=0; i<arrLength; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
// bool Answer(int answer)
// {
//     return answer == 1;
// }
// void FillArray(int arr[], int &arrLength)
// {
//     int answer;
//     for(int i=0; i<arrLength; i++)  
//     {
//         arr[i] = ReadPositiveNumber("Please enter a number:: ");
//         cout << "Do you want to add more number? NO[0], Yes[1]: ";
//         cin >> answer;
//         if(Answer(answer))
//         {
//             ChageSize(arrLength);
//             continue;
//         }
//         else
//         {
//             break;
//         }
//     }
// }
// int main()
// {
//     int arr[100], arrLength=1;
//     FillArray(arr, arrLength);
//     PrintArray(arr, arrLength);
// }


