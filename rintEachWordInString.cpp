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
void FindSpace(string str, vector <int> &vPosOfFirstLetter)
{
    for(int i=0; str[i]!='\0'; i++)
    {
        if( str[i]==' ' && str[i+1]!=' ')
            vPosOfFirstLetter.push_back(i+1);
    }
}
void PosOfLastLetter(string str, vector <int> &vPosOfLastLetter)
{
    for(int i=0; str[i]!='\0'; i++)
    {
        if( str[i]!=' ' && str[i+1]==' ')
            vPosOfLastLetter.push_back(i);
    }
    short len = str.length();
    if(str[len-1]!=' ')
        vPosOfLastLetter.push_back(len-1);
}
void CheckToFirstLetterInString(string str, vector <int> &vPosOfFirstLetter)
{
    if(str[0]!=32)
        vPosOfFirstLetter.push_back(0);
}
short vLength(vector <int> vPosOfLastLetter)
{
    short len=0;
    for(int &i : vPosOfLastLetter)
    {
        len++;
    }
    return len;
}
void PrintFirstLetter(string str, vector <int> vPosOfFirstLetter, vector <int> vPosOfLastLetter)
{
    int vlen = vLength(vPosOfLastLetter);
    for(short i=0; i<vlen; i++)
    {
        for(short j=vPosOfFirstLetter.at(i); j<=vPosOfLastLetter.at(i); j++)
        {
            cout << str[j];
        }
        cout << endl;
    }
}
int main()
{
    
    vector <int> vPosOfFirstLetter;
    vector <int> vPosOfLastLetter;
    string str = GetAString();
    CheckToFirstLetterInString(str, vPosOfFirstLetter);
    FindSpace(str, vPosOfFirstLetter);
    PosOfLastLetter(str, vPosOfLastLetter);
    PrintFirstLetter(str, vPosOfFirstLetter, vPosOfLastLetter);
}
// 0 1 2 3   4 5 6 7 8   9 10  11 12 13
// o m e r   a h m e d   m  e  m  e   s
 
