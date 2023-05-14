#include<iostream>
#include<string>
using namespace std;
string ReadString()
{
    string str;
    cout << "Enter any string: ";
    getline(cin, str);
    return str;
}
short CountEachWordInString(string str)
{
    short Counter=0;
    string Space=" ";
    short Pos=0;
    string sWord;
    while( (Pos=str.find(Space)) != str.npos )
    {
        sWord = str.substr(0, Pos);
        if(sWord!="")
        {
            Counter++;
        }
        str.erase(0, Pos+Space.length());
    }
    if(str!="")
    {
        Counter++;
    }
    return Counter;
}
int main()
{
    string str = ReadString();
    cout << str << ": There are " << CountEachWordInString(str) << " words\n";
}