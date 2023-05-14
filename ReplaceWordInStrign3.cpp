#include<iostream>
#include<string>
using namespace std;
string strReplace(string str, string From, string To)
{
    short pos=0;
    while((pos=str.find(From)) != str.npos)
    {
        str.erase(pos, From.length());
        str.insert(pos, To);
    }
    return str;
}
string strREplace(string str, string From, string To)
{
    short pos = str.find(From);
    while(pos != str.npos)
    {
        str.replace(pos, From.length(), To);
        pos = str.find(From);
    }
    return str;
}
int main()
{
    string str = "Hello my name is omer i am from syria but i live in turkiye";
    string ReplaceFrom = "omer";
    string ReplaceTo = "ali";
    cout << strReplace(str, ReplaceFrom, ReplaceTo) << endl;
    cout << strREplace(str, ReplaceFrom, ReplaceTo) << endl;
}