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
int CountSmallLetter(string str)
{
    int Scount=0;
    for(int i=0; i<str.length(); i++)
    {
        if(islower(str[i]))    
            Scount++;
    }
    return Scount;
    
}
int CountCapitalLetter(string str)
{
    int Ccount=0;
    for(int i=0; i<str.length(); i++)
    {
        if(isupper(str[i]))    
            Ccount++;
    }
    return Ccount;
    
}
int main()
{
    string str = GetAString();
    cout << str.length() << " String Length " << endl;
    cout << CountSmallLetter(str) << " Small Letter " << endl;
    cout << CountCapitalLetter(str) << " Capital Letter " << endl;
}

