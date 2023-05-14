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

vector <string> SplitString(string str, string delim=" ")
{
    vector <string> vString;
    string sWord;
    short pos=0;
    while( (pos = str.find(delim)) != std::string::npos )
    {
        sWord = str.substr(0, pos);
        if(sWord!="")
        {
            vString.push_back(sWord);
        }
        str.erase(0, pos+delim.length());
    }
    if(str!="")
    {
        vString.push_back(str);
    }
    return vString;
}
string ReverseWordsInString(string str)
{
    vector <string> vString;
    string str2 = "";
    vString = SplitString(str, " ");
    vector <string>::iterator iter = vString.end();
    while(iter!=vString.begin())
    {
        --iter;
        str2 += *iter + " ";
    }
    return str2.substr(0, str2.length()-1);
}
int main()
{
    string str = GetAString();
    cout << ReverseWordsInString(str);
}