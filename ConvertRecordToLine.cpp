#include<iostream>
#include<string>
#include<vector>
using namespace std;
string GetAString(string Message)
{
    string str;
    cout << Message ;
    getline(cin, str);
    return str;
}
string Join(vector <string> vString, string delim="#//#")
{
    string str;
    for(string &s : vString)
    {
        str = str + s + delim;
    }
    return str.substr(0, str.length()-delim.length());
}
vector <string> FillInfoInVector()
{   
    vector <string> vString;
    string Number, Phone, Name, PinCode, Balance;
    Number = GetAString("Enter Account Number: ");   
    PinCode = GetAString("Enter PinCode: ");   
    Name = GetAString("Enter Name: ");   
    Phone = GetAString("Enter Phone: ");   
    Balance = GetAString("Enter Account Balance: ");   
    vString.push_back(Number);
    vString.push_back(PinCode);
    vString.push_back(Name);
    vString.push_back(Phone);
    vString.push_back(Balance);
    cout << "Clien Record For Saving IS: \n";
    return vString;
}
int main()
{

    cout << Join(FillInfoInVector());
}