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
string  PrintFirstLetter(string str)
{
    bool isFirstLetter = true;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]!=' ' && isFirstLetter)
            str[i] = toupper(str[i]);
        isFirstLetter = (str[i] == ' ' ? true : false);
    }
    return str;
}
int main()
{
    cout << PrintFirstLetter(GetAString());
}