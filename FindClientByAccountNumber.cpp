#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;
const string FileName="Client2.txt";
struct stClient
{
    string CLNumber;
    string CLPinCode;
    string CLName;
    string CLPhone;
    double CLBalance;
};
string ReadClientAccountNumber()
{
    string AccountNum;
    cout << "Please Eter Account Number: ";
    cin >> AccountNum;
    return AccountNum;
}
vector <string> Split(string str, string delim)
{
    vector <string> vString;
    short pos=0;
    string sWord;
    while( (pos=str.find(delim)) != str.npos )
    {
        sWord = str.substr(0, pos);

        if(sWord != "")
        {
            vString.push_back(sWord);
        }

        str.erase(0, pos + delim.length());
    }

    if(str != "")
    {
        vString.push_back(str);
    }

    return vString;
}
stClient ConvertLineToRecord(string str, string seperator="#//#")
{
    stClient Client;
    vector <string> vString = Split(str, seperator);
    Client.CLNumber = vString.at(0); 
    Client.CLPinCode = vString.at(1); 
    Client.CLName = vString.at(2); 
    Client.CLPhone = vString.at(3); 
    Client.CLBalance = stod(vString.at(4));
    return Client; 
}
vector <stClient> ReadLine(string FileName)
{
    fstream MyFile;
    stClient Client;
    vector <stClient> vClient;
    MyFile.open(FileName, ios::in);
    if(MyFile.is_open())
    {
        string line;
        while(getline(MyFile, line))
        {
            Client = ConvertLineToRecord(line);
            vClient.push_back(Client);
        }

    }
    return vClient;
}


void PrintClientRecord(stClient Client)
{
    system("cls");
    cout << "The following are the client details: \n\n";
    cout << "Client Number   : " << Client.CLNumber << endl;
    cout << "Client Pin Code : " << Client.CLPinCode << endl;
    cout << "Client Name     : " << Client.CLName << endl;
    cout << "Client Phone    : " << Client.CLPhone << endl;
    cout << "Client Balance  : " << Client.CLBalance << endl;
    system("pause>0");
}
void CheckToClientNumber(vector <stClient> vClient, string ClientNumber)
{
    for(stClient Client : vClient)
    {
        if(Client.CLNumber == ClientNumber)
        {
            PrintClientRecord(Client);
            return;
        }
    }

    cout << "Client With Account Number ("<< ClientNumber << ") Not Found. \n"; 
    system("pause>0");
}
bool FindClientByAccountNumber(string AccountNumber, stClient &Client)
{
    vector <stClient> vClient = ReadLine(FileName);
    for(stClient C : vClient)
    {
        if(C.CLNumber == AccountNumber)
        {
            Client = C; 
            return true;
        }
    }
    return false;
    
}
int main()
{
    // string ClientNumber = ReadClientAccountNumber();
    // vector <stClient> vClient;
    // vClient = ReadLine(FileName);
    // CheckToClientNumber(vClient, ClientNumber);

    string ClientNumber = ReadClientAccountNumber();
    stClient Client;
    if(FindClientByAccountNumber(ClientNumber, Client))
    {
        PrintClientRecord(Client);
    }
    else
    {
        cout << "Client With Account Number ("<< ClientNumber << ") Not Found. \n"; 
    }
}
