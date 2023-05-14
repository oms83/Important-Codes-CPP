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
short vLength(vector <string> vString)
{
    short Counter=0;
    for(string &s : vString)
    {
        Counter++;
    }
    return Counter;
}
void PrintVString(vector <string> vString)
{
    for(string &s : vString)
    {
        cout << s << endl;
    }
}
int main()
{
    string str = GetAString();
    vector <string> vString = SplitString(str, " ");

    cout << "Tokens: " <<  vLength(vString) << endl;
    cout << "Tokens: " <<  vString.size() << endl;
    PrintVString(vString);
}