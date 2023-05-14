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
enum WhatToCount {SmallLetters=1, CapitalLetters=2, All=3};
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
int WhatToCountOfLetters(string str, WhatToCount WtToCount=WhatToCount::All)
{
    int Count=0;
    if(WhatToCount::All==WtToCount)
            return str.length();
    for(int i=0; i<str.length(); i++)
    {
        if(WhatToCount::CapitalLetters == WtToCount && isupper(str[i]))    
            Count++;
        if(WhatToCount::SmallLetters == WtToCount && islower(str[i]))    
            Count++;
    }
    return Count;
}
int main()
{
    string str = GetAString();
    cout << WhatToCountOfLetters(str) << " String Length " << endl;
    cout << WhatToCountOfLetters(str, WhatToCount::SmallLetters) << " Small Letter " << endl;
    cout << WhatToCountOfLetters(str, WhatToCount::CapitalLetters) << " Capital Letter " << endl;
}

