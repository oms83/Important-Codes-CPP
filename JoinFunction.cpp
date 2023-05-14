#include<string>
#include<iostream>
#include<vector>
using namespace std;

string Join(vector <string> vString, string delim=" ")
{
    short len = vString.size();
    string vWord="";
    short i=0;
    for(i=0; i<len; i++)
    {
        if(i==len-1)
            break;
        vWord = vWord+ vString[i] + delim;
    }
    vWord += vString[i];
    return vWord;
}
int main()
{
    vector <string> vString = { "omer", "ali", "osman", "yusuf" };
    cout << "After Join: " << Join(vString, "==");
}