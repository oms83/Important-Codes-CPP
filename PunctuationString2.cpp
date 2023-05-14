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
string Punctuation(string str)
{
    string S2="";
    for(int i=0; str[i]!='\0'; i++)
    {
        if(!ispunct(str[i]))
        {
            S2 += str[i];
        }
    }
    return S2;
}
int main()
{
    cout << Punctuation(GetAString());
}