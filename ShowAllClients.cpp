#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
const string FileName = "Client2.txt";
struct stClient
{
    string Number;
    string Phone;
    string Name;
    string PinCode;
    double Balance;
};
vector<string> SplitString(string str, string delim = "#//#") // 2
{
    vector<string> vString;
    string sWord;
    short pos = 0;
    while ((pos = str.find(delim)) != std::string::npos)
    {
        sWord = str.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        str.erase(0, pos + delim.length());
    }
    if (str != "")
    {
        vString.push_back(str);
    }
    return vString;
}
stClient ConvertLinetoRecord(string Line, string Seperator="#//#")
{
    stClient client;
    vector <string> vString = SplitString(Line, Seperator);

    client.Number = vString.at(0);
    client.PinCode = vString.at(1);
    client.Name = vString.at(2);
    client.Phone = vString.at(3);
    client.Balance = stod(vString.at(4));

    return client;
}
vector <stClient> LoadClientDataFromFile(string FileName)
{
    vector <stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);
    
    if(MyFile.is_open())
    {
        string line;
        stClient Client;

        while(getline(MyFile, line))
        {
            Client = ConvertLinetoRecord(line);
            vClients.push_back(Client);
        }
    }
    return vClients;
}
void PrintClientRecord(stClient Client)
{
    cout << "| " << left << setw(15) << Client.Number;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << Client.Balance;
}
void PrintAllClientData(vector <stClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Number";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    for(stClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}
int main()
{
    vector <stClient> vClients = LoadClientDataFromFile(FileName);
    PrintAllClientData(vClients);

}
