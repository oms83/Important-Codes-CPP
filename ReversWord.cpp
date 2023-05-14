#include<string>
#include<iostream>
using namespace std;
string ReadString()
{
    string str;
    cout << "Enter any string: ";
    cin >> str;
    return str;
}
void ReversWord(string str)
{
    short start=0;
    short end = str.length()-1;
    for(short i=str.length()-1; i>=0; i--)
    {
        if(str[i]==32 || i==0)
        {
            if(i==0)
                start = 0;
            else
             start = i+1;
            for(short j=start; j<=end; j++)
                cout << str[j];
            end = i-1;
            cout << " ";
        }
    }
}
int main()
{
    // ReversWord(ReadString());
    string str = ReadString();
}