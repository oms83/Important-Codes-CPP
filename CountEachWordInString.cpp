#include<iostream>
#include<vector>
#include<string>
using namespace std;
string ReadString()
{
    string str;
    cout << "Enter any string: ";
    getline(cin, str);
    return str;
}
short CheckToFirstPositionInString(string str)
{
    return islower(tolower(str[0])) ? 1 : 0;
}
short CountSpace(string str)
{
    short Counter=0;
    Counter = CheckToFirstPositionInString(str);
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==32 && str[i+1]!=32 && str[i+1]!='\0')
            Counter++;
    }
    return Counter;
}
int main()
{
    string str = ReadString();
    cout << str << ": there are " << CountSpace(str) << " words \n"; 
}