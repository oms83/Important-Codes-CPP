#include<iostream>
#include<string>
#include<vector>
using namespace std;
string GetAString()
{
    string str;
    cout << "Enter any string: ";
    getline(cin, str);
    return str;
}
string TrimLeft(string str)
{
    short Counter=0;
    for(short i=0; i<str.length(); i++)
    {
        if(str[i]!=32)
        {
            return str.substr(i, str.length()-1-i);   
        }
    }

    return "";
}
string TrimRight(string str)
{
    short LastLetterPos=0;
    for(short i=(str.length()-1); i>=0; i--)
    {
        if(str[i]!=32)
        {
            return str.substr(0, i+1);
        }
    }
    return "";
}
int main()
{
    string str = GetAString();
    cout << "Left Trim  : " << TrimLeft(str) << endl;
    cout << "Right Trim : " << TrimRight(str) << endl;
    cout << "Trim       : " << TrimRight(TrimLeft(str)) << endl;
}
