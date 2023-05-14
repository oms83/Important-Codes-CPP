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
bool Character(char c)
{
    if( islower(tolower(c)) || c==' ' || isdigit(c))
        return false;
    return true;
}
string Punctuation(string str)
{
    for(int i=0; str[i]!='\0'; i++)
    {
        if(Character(str[i]))
        {
            str.erase(i, 1);
            i-=1;
        }
    }
    return str;
}
int main()
{
    cout << Punctuation(GetAString());
}