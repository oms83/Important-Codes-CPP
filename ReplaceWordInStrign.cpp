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
vector <string> ReplaceWord(vector <string> vString, string From, string To)
{
    vector <string>::iterator iter;
    for(iter=vString.begin(); iter!=vString.end(); iter++)
    {
        if(*iter==From)
        {
            *iter = To;
        }
    }
    return vString;
}
char Invert(char c)
{
    return isupper(c) ? tolower(c) : tolower(c);
}
string InvertCharacterCase(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        str[i] = Invert(str[i]);    
    }
    return str;
}
vector <string> ReplaceWordMatchCase(vector <string> vString, string From, string To)
{
    vector <string>::iterator iter;
    for(iter=vString.begin(); iter!=vString.end(); iter++)
    {
        if(InvertCharacterCase(*iter)==InvertCharacterCase(From))
        {
            *iter = To;
        }
    }
    return vString;
}
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
    string str = GetAString();
    vector <string> vString = SplitString(str, " ");
    cout << Join(ReplaceWord(vString, "omer", "ali")) << endl;
    cout << Join(ReplaceWordMatchCase(vString, "Omer", "ali")) << endl;

}

