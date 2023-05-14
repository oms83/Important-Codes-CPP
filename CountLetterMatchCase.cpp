#include<iostream>
#include<string>
using namespace std;
string GetAString()
{
    string str;
    cout << "Enter any string: ";
    getline(cin, str);
    return str;
}
char GetCharacter()
{
    char ch;
    cout << "Please enter a character: ";
    cin >> ch;
    return ch;
}
enum WhatToCount {OneCase=1, MatchCase=2};
short CountLetters(string str, char c, WhatToCount WtToCount=WhatToCount::MatchCase)
{
    short Count=0;
    for(short i=0; str[i]!='\0'; i++)
    {
        if( WhatToCount::OneCase==WtToCount && str[i]==c)
            Count++;
        if( (WhatToCount::MatchCase== WtToCount) && (str[i]==c || str[i]==char(c+32) || str[i]==char(c-32)))
            Count++;
    }
    return Count;
}
int main()
{
    string str = GetAString();
    char ch = GetCharacter();
    cout << "Letter \"" << ch << "\" Count = " << CountLetters(str, ch, WhatToCount::OneCase) << endl;
    cout << "Letter \"" << char(tolower(ch)) << "\" Or \"" << char(toupper(ch)) << "\" Count = " << CountLetters(str, ch, WhatToCount::MatchCase) << endl;
    system("pause>0");
}