#include<iostream>
#include<vector>
using namespace std;
string GetAString()
{
    string str;
    cout << "Enter any string: ";
    getline(cin, str);
    return str;
}
char Invert(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}
string InvertCharacterCase(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        str[i] = Invert(str[i]);    
    }
    return str;
}
int main()
{
    cout << InvertCharacterCase(GetAString()) << endl;
}

