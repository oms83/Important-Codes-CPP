#include<iostream>
#include<time.h>
#include<string>
#include<stdlib.h>
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
int RondomNumber(int From, int To)
{
    return rand()% (To - From + 1) + From;
}
enum enCharType{SmallCharacter=1, CapitalCharacter=2, SpcialCharacter=3, Digit=4};
char GetCharType(enCharType CharType)
{
    switch(CharType)
    {
        case enCharType::SmallCharacter: 
        {
            return char(RondomNumber(97, 122));
            break;
        }  
        case enCharType::CapitalCharacter:
        {
            return char(RondomNumber(65, 90));
            break;
        }
        case enCharType::SpcialCharacter:
        {
            return char(RondomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return (char)RondomNumber(48, 57);
            break;
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
void PrintGenerateKeys(int length)
{
    for(int i=1; i<=length; i++)
        cout << GenerateKeys() << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    PrintGenerateKeys(ReadPositiveNumber("How many need to create Generate Keys:: "));
}




// #include<iostream>
// #include<time.h>
// #include<string>
// #include<stdlib.h>
// using namespace std;

// int ReadPositiveNumber(string Message)
// {
//     int Number=0; 
//     do
//     {
//         cout << Message;
//         cin >> Number;
//     }while(Number<0);
//     return Number;
// }
// int RondomNumber(int From, int To)
// {
//     return rand()% (To - From + 1) + From;
// }
// enum enCharType{SmallCharacter=1, CapitalCharacter=2, SpcialCharacter=3, Digit=4};
// char GetCharType(enCharType CharType)
// {
//     switch(CharType)
//     {
//         case enCharType::SmallCharacter: 
//         {
//             return char(RondomNumber(97, 122));
//             break;
//         }  
//         case enCharType::CapitalCharacter:
//         {
//             return char(RondomNumber(65, 90));
//             break;
//         }
//         case enCharType::SpcialCharacter:
//         {
//             return char(RondomNumber(33, 47));
//             break;
//         }
//         case enCharType::Digit:
//         {
//             return char(RondomNumber(48, 57));
//             break;
//         }
//     }
// }   
// string CreatGenerateKeys(int Number)
// {
//     string Keys="";
//     for(int i=1; i<=Number; i++)
//     {
//         for(int j=1; j<=4; j++)
//         {
//             for(int k=1; k<=4; k++)
//             {
//                 Keys = Keys + GetCharType(enCharType::Digit);
//             }
//             if(j==4) return Keys;
//             Keys += "-";
//         }
//         return Keys;
//         Keys="";
//     }
// }
// void PrintGenerateKeys(int Number)
// {
//     cout << endl;
//     cout << endl;
//     for(int i=1; i<=Number; i++)
//     {
//         cout << CreatGenerateKeys(Number) << endl;
//     }
// }
// int main()
// {
//     srand((unsigned)time(NULL));
//     PrintGenerateKeys(ReadPositiveNumber("How many need to create Generate Keys:: "));
// }