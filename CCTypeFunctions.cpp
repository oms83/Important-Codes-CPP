#include<cctype>
#include<iostream>
#include<string>

using namespace std;
int main()
{
    cout << "toupper('a'):: " << toupper('a') << endl; // 65
    cout << "tolower('A'):: " << tolower('A') << endl; // 97
    cout << "toupper('a'):: " << char(toupper('a')) << endl; // A
    cout << "tolower('A'):: " << char(tolower('A')) << endl; // a
    cout << "isupper('a'):: " << isupper('a') << endl; // 0
    cout << "islower('a'):: " << islower('a') << endl; // 2 مو شرط يرجع واحد خلص برجع اي قيمية صحيحة موجبة
    cout << "isdigit('a'):: " << isdigit('a') << endl; // 0
    cout << "isdigit('7'):: " << isdigit('7') << endl; // 1
    cout << "ispunct(';'):: " << ispunct(';') << endl; // 16
    cout << "ispunct('.'):: " << ispunct(';') << endl; // 16  التحقق من الرموز
}