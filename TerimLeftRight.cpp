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
        if(str[i]==32)
        {
            Counter++;
        }
        else if(str[i]!=32)
        {
            break;
        }
    }
    str.erase(0, Counter);
    return str;
}
string TrimRight(string str)
{
    short LastLetterPos=0;
    for(short i=(str.length()-1); i>=0; i--)
    {
        if(str[i]!=32)
        {
            LastLetterPos = i;
            break;
        }
    }
    str.erase(LastLetterPos+1, str.length()-1);
    return str;
}
int main()
{
    string str = GetAString();
    cout << "Left Trim  : " << TrimLeft(str) << endl;
    cout << "Right Trim : " << TrimRight(str) << endl;
    cout << "Trim       : " << TrimRight(TrimLeft(str)) << endl;
}
