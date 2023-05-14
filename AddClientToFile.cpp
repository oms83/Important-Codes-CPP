#include<fstream>
#include<vector>
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
    getline(cin >> ws, client.Number);
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
void AddClientInfoToFile(string ClientInfo)
{
    fstream ClientFile;
    ClientFile.open("Client2.txt", ios::out | ios::app);
    if(ClientFile.is_open())
    {
        ClientFile << ClientInfo << endl;
    }
    ClientFile.close();
}
void AddNewClient()
{
    stClient client = GetClientInfo(); 
    AddClientInfoToFile(ConvertRecordToLine(client));
}
void AskUser()
{
    char AddMore='Y';
    do
    {
            system("cls");
            cout << "Add more new client \n\n";
            AddNewClient();
            cout << "Client Added Succuccfully, Do you want to add more clients [Y/N] ? ";
            cin >> AddMore;

    }while (AddMore=='Y' || AddMore=='y');
    
}
int main()
{
    AskUser();
}