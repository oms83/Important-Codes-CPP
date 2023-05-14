#include<iostream>
#include<time.h>
#include<string>
#include<stdlib.h>

using namespace std;

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
            return char(RondomNumber(48, 57));
            break;
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    cout << GetCharType(enCharType::SmallCharacter) << endl;
    cout << GetCharType(enCharType::CapitalCharacter) << endl;
    cout << GetCharType(enCharType::SpcialCharacter) << endl;
    cout << GetCharType(enCharType::Digit) << endl;
}























// #include<iostream>
// #include<time.h>
// #include<stdlib.h>

// using namespace std;



// int RondomNumber(int From, int To)
// {
//     return rand()% (To - From + 1) + From;
// }
// void PrintRondom(int From, int To)
// {
//     cout << char(65+RondomNumber(From, To)) << endl;
//     cout << char(32 + RondomNumber(From, To)) << endl;
//     cout << RondomNumber(From, To) << endl;
//     cout << char(97+RondomNumber(From, To)) << endl;
// }
// int main()
// {
//     srand((unsigned)time(NULL));
//     PrintRondom(1,10);
// }