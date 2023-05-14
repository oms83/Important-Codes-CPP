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
    bool MarkForUpdate = false;
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
void PrintClientRecord(stClient Client)
{
    system("cls");
    cout << "The following are the client details: \n\n";
    cout << "Client Number   : " << Client.CLNumber << endl;
    cout << "Client Pin Code : " << Client.CLPinCode << endl;
    cout << "Client Name     : " << Client.CLName << endl;
    cout << "Client Phone    : " << Client.CLPhone << endl;
    cout << "Client Balance  : " << Client.CLBalance << endl;
}
string ConvertRecordToLine(stClient client, string seperator="#//#")
{
    string ConvertRecord="";
    ConvertRecord += client.CLNumber + seperator;
    ConvertRecord += client.CLPinCode + seperator;
    ConvertRecord += client.CLName + seperator;
    ConvertRecord += client.CLPhone + seperator;
    ConvertRecord += to_string(client.CLBalance);
    return ConvertRecord;
}
vector <stClient> LoadClientDataFromFile(string FileName)
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
bool FindClientByAccountNumber(vector <stClient> vClient, stClient &Client, string AccountNumber)
{
    vClient = LoadClientDataFromFile(FileName);
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
bool MarkClientForUpdateAccountNumber(string AccountNumber, vector <stClient> &vClient)
{
    for(stClient &C : vClient)
    {
        if(C.CLNumber == AccountNumber)
        {
            C.MarkForUpdate = true;
            return true;
        }
    }
    return false;
}
stClient UpdateClientInfo()
{
    stClient client;
    cout << "Enter PinCode: ";
    getline(cin >> ws, client.CLPinCode);
    cout << "Enter Name: ";
    getline(cin, client.CLName);
    cout << "Enter Phone: ";
    getline(cin, client.CLPhone);
    cout << "Enter Account Balance: ";
    cin >> client.CLBalance;
    return client;
}
vector <stClient> SaveClientDataToFile(string FileName, vector <stClient> vClient, string AccountNumber)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    string DataLine;

    if(MyFile.is_open())
    {
        for(stClient C : vClient)
        {
            if(C.MarkForUpdate == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
            else if(C.MarkForUpdate == true)
            {
                C = UpdateClientInfo();
                C.CLNumber = AccountNumber;
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClient;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient> &vClient)
{
    stClient Client;
    char Answer='N';
    if(FindClientByAccountNumber(vClient, Client, AccountNumber))
    {
        PrintClientRecord(Client);

        cout << "\n\nAre you sure you want to update this client? ";
        cin >> Answer;
        if(Answer=='Y'||Answer=='y')
        {
            MarkClientForUpdateAccountNumber(AccountNumber, vClient);
            SaveClientDataToFile(FileName, vClient, AccountNumber);

            vClient = LoadClientDataFromFile(FileName);
            cout << "\n\nClient Update Successfully. ";
            return true;
        }
    }
    else
    {
        cout << "\nClient With Account Number ("<< AccountNumber << ") Not Found. \n"; 
    }
    return false;

}
int main()
{
    vector <stClient> vClient = LoadClientDataFromFile(FileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClient);

}