#include<vector>
#include<string>
#include<iostream>
using namespace std;
string ReadString()
{
    string str;
    cout << "Enter any string: ";
    getline(cin, str);
    return str;
}
vector <string> SplitString(string str)
{
    vector <string> vString;
    short pos;
    string sWord;
    string delim = " ";
    while( (pos=str.find(delim)) != std::string::npos )
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
string ReverseString(vector <string> vString)
{
    short vLength = vString.size()-1;
    string EachWord="";
    short i=0; 
    for(i=vLength; i>=0; i--)
    {
        if(i==0)
            break;
        EachWord = EachWord + vString[i] + " ";
    }
    EachWord += vString[0];
    return EachWord;
}
void ReverseString(string str)
{
    short end = str.length()-1;
    short start=0;
    for(short i=str.length()-1; i>=0; i--)
    {
        if(i==0 || str[i]==32)
        {
            if(i==0)
            {
                start = 0;
            }
            else
            {
                start = i+1;
            }
            for(short j=start; j<=end; j++)
            {
                cout << str[j];
            }
            end = i-1;
            cout << " ";
        }
    }
}
int main()
{
    string str = ReadString();
    vector <string> vString = SplitString(str);
    cout << ReverseString(vString) << endl;
    ReverseString(str);
}