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
vector <stClient> ReadLine(vector <string> &vSClient, string FileName)
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
            vSClient.push_back(line);
            Client = ConvertLineToRecord(line);
            vClient.push_back(Client);
        }

    }
    return vClient;
}
bool FindClientByAccountNumber(vector <stClient> &vClient, vector <string> &vSClient, stClient &Client, string AccountNumber)
{
    vClient = ReadLine(vSClient, FileName);
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
bool AskUserToDelete(vector <stClient> &vClient, vector <string> &vSClient, stClient &Client) 
{
    string ClientNumber = ReadClientAccountNumber();
    char DoYouWantToDelete = 'Y';
    if(FindClientByAccountNumber(vClient, vSClient, Client, ClientNumber))
    {
        PrintClientRecord(Client);
        cout << "\n\nDo you want delete this client [Y/N] ? ";
        cin >> DoYouWantToDelete;

        return (DoYouWantToDelete=='Y'||DoYouWantToDelete=='y') ? true : false;
    }
    else
    {
        cout << "\nClient With Account Number ("<< ClientNumber << ") Not Found. \n"; 
    }
    return false;
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
void DeleteClient()
{
    stClient Client;
    vector <stClient> vClient;
    vector <string> vSClient;
            
    if(AskUserToDelete(vClient, vSClient, Client))
    {   
        fstream MyFile;
        MyFile.open(FileName, ios::out);
        if(MyFile.is_open())
        {
            for(string &line : vSClient)
            {
                if(line != ConvertRecordToLine(Client))
                {
                    MyFile << line << endl;
                }
            }
            cout << "\n\nClient Deleted Successfully.\n";
        }
        
        MyFile.close();
    }
}
int main()
{
    DeleteClient();
}
