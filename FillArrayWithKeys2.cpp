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
enum enCharType{SmallCharacter=1, CapitalCharacter=2, SpcialCharacter=3, Digit=4};
char GetCharType(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::CapitalCharacter:
        return char(RondomNumber(65, 90));
    case enCharType::SmallCharacter:
        return char(RondomNumber(97, 122));
    case enCharType::Digit:
        return char(RondomNumber(48, 57));
    case enCharType::SpcialCharacter:
        return char(RondomNumber(33, 47));
    }
    return ' '; 
}
string GeneraterWord(enCharType CharType, short length)
{
    string word = "";
    for(int i=0; i<length; i++)
    {
        word = word + GetCharType(CharType);
    }
    return word;
}
string GeneraterKey()
{
    string Key="";
    Key = Key + GeneraterWord(enCharType::CapitalCharacter, 6) + "-";
    Key = Key + GeneraterWord(enCharType::CapitalCharacter, 6) + "-";
    Key = Key + GeneraterWord(enCharType::CapitalCharacter, 6) + "-";
    Key = Key + GeneraterWord(enCharType::CapitalCharacter, 6);
    return Key;
}
void PrintArray(string arr[], int arrLength)
{
    cout << endl;
    for(int i=0; i<arrLength; i++)
    {
        cout << arr[i] << endl;
    }
}
void FillArrayWithKeys(string arr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        arr[i] = GeneraterKey();
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength;
    string arr[100];
    arrLength = ReadPositiveNumber("Enter the length for array:: ");
    FillArrayWithKeys(arr, arrLength);
    PrintArray(arr, arrLength);
}