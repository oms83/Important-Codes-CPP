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
int CountSpace(string str)
{
    int count=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        if( str[i]==' ' && str[i+1]!=' ')
            count++;
    }
    return count;
}
bool CheckToFirstLetterInString(string str)
{
    return (str[0]!=32) ? true : false;
}
void FindSpace(string str, vector <int> &LetterArr)
{
    for(static int i=0; str[i]!='\0'; i++)
    {
        if(str[i]==32)
            LetterArr.push_back(i+1);
    }
}
void PrintFirstLetter(string str, vector <int> LetterArr )
{
     if(CheckToFirstLetterInString(str))
        cout << str[0] << endl;
    for(int i=0; i<CountSpace(str); i++)
    {
        cout << str[LetterArr.at(i)] << endl;
    }
}
int main()
{
    
    vector <int> LetterArr;
    string str = GetAString();
    FindSpace(str, LetterArr);
    PrintFirstLetter(str, LetterArr);
}
