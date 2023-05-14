#include<iostream>
using namespace std;
char GetCharacter()
{
    char ch;
    cout << "Please enter a character: ";
    cin >> ch;
    return ch;
}
string isVowel(char c)
{
    if( c=='a' || c=='A' ||  c=='e' || c=='E' ||  c=='i' || c=='I' ||  c=='U' || c=='u' ||  c=='o' || c=='O' )
        return "Yes : is Vowel ";
    return "No: is not Vowel ";
}

int main()
{
    char ch = GetCharacter();
    cout << isVowel(ch) << endl;
    system("pause>0");
}