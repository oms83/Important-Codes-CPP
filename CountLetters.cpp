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
short CountLetters(string str, char c)
{
    short Count=0;
    for(short i=0; str[i]!='\0'; i++)
    {
        if(str[i]==c)
            Count++;
    }
    return Count;
}
int main()
{
    string str = GetAString();
    char ch = GetCharacter();
    cout << "Letter \"m\" Count = " << CountLetters(str, ch) << endl;
    system("pause>0");
}