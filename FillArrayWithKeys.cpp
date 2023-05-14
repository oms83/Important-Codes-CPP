#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
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
    switch(CharType)
    {
        case enCharType::SmallCharacter: 
        {
            return char(RondomNumber(97, 122));
        }  
        case enCharType::CapitalCharacter:
        {
            return char(RondomNumber(65, 90));
        }
        case enCharType::SpcialCharacter:
        {
            return char(RondomNumber(33, 47));
        }
        case enCharType::Digit:
        {
            return (char)RondomNumber(48, 57);
        }
    }
}   
string GenerateWord(enCharType CherType, short length)
{
    string word="";
    for(int i=1; i<=length; i++)
    {
        word = word + GetCharType(CherType);
    }
    return word;
}
string GenerateKeys()
{
    string Key="";
    Key = Key + GenerateWord(enCharType::CapitalCharacter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalCharacter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalCharacter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalCharacter, 4);
    return Key;
}

void FillArrayWithKeys(string arr[], int arrLength)
{
    for(int i=0; i<arrLength; i++)
    {
        arr[i] = GenerateKeys();
    }
}
void PrintArray(string arr[], int arrLength, string Message)
{
    cout << Message + " Array Elements:: ";
    for(int i=0; i<arrLength; i++)
    {
        cout << "\n" << arr[i];
    }
    cout << "\n";
}
int main()
{
    string arr[100];
    int arrLength;
    arrLength = ReadPositiveNumber("Enter Length for array: ");
    FillArrayWithKeys(arr, arrLength);
    PrintArray(arr, arrLength, "Generate");
}