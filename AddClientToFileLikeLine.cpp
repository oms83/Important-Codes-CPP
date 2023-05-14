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
void AddClientInfoToFile(stClient client)
{
    fstream ClientFile;
    ClientFile.open("Client.txt", ios::out | ios::app);
    if(ClientFile.is_open())
    {
        ClientFile << "Enter Account Number: " << client.Number << endl;
        ClientFile << "Enter PinCode: " << client.PinCode << endl;
        ClientFile << "Enter Name: " << client.Name << endl;
        ClientFile << "Enter Phone: " << client.Phone << endl;
        ClientFile << "Enter Account Balance: " << to_string(client.Balance) << endl;
        ClientFile << endl << endl;
    }
    ClientFile.close();
}
void GetClientInfo()
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
    AddClientInfoToFile(client);
}
void AskUser()
{
    char AddMore='Y';
    do
    {
        system("cls");
        cout << "Add more new client \n\n";
        GetClientInfo();
        cout << "Client Added Succuccfully, Do you want to add more clients [Y/N] ? ";
        cin >> AddMore;

    }while (AddMore=='Y' || AddMore=='y');
    
}
int main()
{
    AskUser();
}