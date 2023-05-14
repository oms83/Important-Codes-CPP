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
short CountVowelLetters(string str)
{
    short Counter=0;
    for(short i=0; i<str.length(); i++)
    {
        if(isVowel(str[i]))
            Counter++;
    }
    return Counter;
}
int main()
{
    string str = GetAString();
    cout << "Vowel Count is : " << CountVowelLetters(str) << endl;
} 