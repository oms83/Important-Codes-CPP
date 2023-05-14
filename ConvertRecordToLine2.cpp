#include<string>
#include<iostream>
using namespace std;

struct stClient
{
    string Number; 
    string Phone;
    string Name;
    string PinCode;
    double Balance;
};

stClient GetClientInfo()
{
    stClient client;
    cout << "Enter Account Number: ";
    getline(cin, client.Number);
    cout << "Enter PinCode: ";
    getline(cin, client.PinCode);
    cout << "Enter Name: ";
    getline(cin, client.Name);
    cout << "Enter Phone: ";
    getline(cin, client.Phone);
    cout << "Enter Account Balance: ";
    cin >> client.Balance;
    return client;
}
string ConvertRecordToLine(stClient client, string seperator="#//#")
{
    string ConvertRecord="";
    ConvertRecord += client.Number + seperator;
    ConvertRecord += client.PinCode + seperator;
    ConvertRecord += client.Name + seperator;
    ConvertRecord += client.Phone + seperator;
    ConvertRecord += to_string(client.Balance);
    return ConvertRecord;
}
int main()
{
    cout << ConvertRecordToLine(GetClientInfo());
}