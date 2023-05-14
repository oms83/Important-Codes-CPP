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
bool isUpper(char c)
{
    return (c>=65&&c<90) ? true:false;
}
bool isSmall(char c)
{
    return (c>=97&&c<122) ? true:false;
}

string InvertCharacterCase(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        if(isSmall(str[i]))
            str[i] = toupper(str[i]);
        else if(isUpper(str[i]))
            str[i] = tolower(str[i]);
    }
    return str;
}
int main()
{
    cout << InvertCharacterCase(GetAString()) << endl;
}

