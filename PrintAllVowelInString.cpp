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
bool isVowel(char ch)
{
    ch = tolower(ch);
    return ( ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' );
}
void CountVowelLetters(string str)
{
    for(short i=0; i<str.length(); i++)
    {
        if(isVowel(str[i]))
            cout << str[i] << "\t";
    }
}
int main()
{
    string str = GetAString();
    cout << "Vowel Count is : " << CountVowelLetters(str) << endl;
} 