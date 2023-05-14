#include<string>
#include<iostream>
#include<vector>
using namespace std;
string Join(vector <string> vString, string delim=" ")
{
    string str;
    for(string &s : vString)
    {
        str = str + s + delim;
    }
    return str.substr(0, str.length()-delim.length());
}
string Join(string arrString[], short len, string delim=" ")
{
    string vWord="";
    short i=0;
    for(i=0; i<len; i++)
    {
        if(i==len-1)
            break;
        vWord = vWord + arrString[i] + delim;
    }
    vWord += arrString[i];
    return vWord;
}
string Join1(string arrString[], short len, string delim=" ")
{
    string str="";
    for(short i=0; i<len; i++)
    {
        str = str + arrString[i] + delim;
    }
    return str.substr(0, str.length()-delim.length());
}
int main()
{
    vector <string> vString = { "omer", "ali", "osman", "yusuf" };
    string arrString[4] = { "omer", "ali", "osman", "yusuf" };
    cout << "After Join: " << Join(vString, "-") << endl;
    cout << "After Join: " << Join1(arrString, 4, "#") << endl;
}