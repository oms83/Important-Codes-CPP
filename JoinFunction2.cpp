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
int main()
{
    vector <string> vString = { "omer", "ali", "osman", "yusuf" };
    cout << "After Join: " << Join(vString, "-");
}