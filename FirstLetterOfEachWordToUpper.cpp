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
void PrintFirstLetter(string str)
{
    bool isFirstLetter = true;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]!=' ' && isFirstLetter)
        {
            cout << char(str[i]-32); // toupper(str[i])
        }
        else 
        {
            cout << str[i];
        }
        isFirstLetter = (str[i] == ' ' ? true : false);
    }
}
int main()
{
    PrintFirstLetter(GetAString());
}