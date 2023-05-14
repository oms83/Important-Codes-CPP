#include<iostream>
#include<string>
using namespace std;
string GetAString()
{
    string str;
    cout << "Enter any string: ";
    getline(cin, str);
    return str;
}
void PrintEachWordInString(string str)
{
    string delim = " "; // delimiter
    cout << "Your string words are : \n";
    short pos = 0; 
    string sWord;// define a string variable

    // use find() function to get the position of the delimiters
    while( (pos=str.find(delim)) != std::string::npos ) // إذا كان الشي اللي عم نبحس عنه مو موجود ما بيدخل عاللوب
    {
        sWord = str.substr(0, pos);
        if(sWord != "")
        {
            cout << sWord << endl;
        }
        str.erase(0, pos+delim.length());
    }
    if(str != "")
    {
        cout << str << endl;
    }
}
int main()
{
    PrintEachWordInString(GetAString());
}
// |---omer-memes---
