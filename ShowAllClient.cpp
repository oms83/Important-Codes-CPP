#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct stClient
{
    string Number;
    string Phone;
    string Name;
    string PinCode;
    double Balance;
};

stClient FillClientInfo(vector<string> vString) // 3
{
    stClient client;
    client.Number = vString.at(0);
    client.PinCode = vString.at(1);
    client.Name = vString.at(2);
    client.Phone = vString.at(3);
    client.Balance = stod(vString.at(4));
    return client;
}
vector<string> SplitString(string str, string delim = "#//#") // 2
{
    vector<string> vString;
    string sWord;
    short pos = 0;
    vString.clear();
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

void PrintfClientsInfo(stClient client)
{
    cout << "|" << setw(17) << left << client.Number << "|" << setw(10) << left << client.PinCode << "|" << setw(23) << left << client.Name << "|" << setw(13) << left << client.Phone << "|" << setw(11) << left << client.Balance << endl;
}
void PrintScreenHeader(short clientNumber)
{
    stClient client;
    system("cls");
    cout << "                          Client List (" << clientNumber << ") Client(s).";
    //              17              10                  23               13             14
    cout << "\n--------------------------------------------------------------------------------\n";
    cout << "| Account Number  | PinCode  | Client Name           | Phone       | Balance      ";
    cout << "\n--------------------------------------------------------------------------------\n";
}
short ClientsNumber()
{
    short Counter=0;
    fstream ClientFile;
    ClientFile.open("Client2.txt", ios::in);
    if (ClientFile.is_open())
    {
        string line;
        while (getline(ClientFile, line))
        {
            Counter++;
            cout << line << endl;
        }
    }
    ClientFile.close();
    return Counter;
}
void ReadClientInfo() 
{
    fstream ClientFile;
    ClientFile.open("Client2.txt", ios::in);
    if (ClientFile.is_open())
    {
        string line;
        while (getline(ClientFile, line))
        {
            PrintfClientsInfo(FillClientInfo(SplitString(line)));
        }
    }
    ClientFile.close();
}

int main()
{
    short ClientNumber;
    ClientNumber = ClientsNumber();
    PrintScreenHeader(ClientNumber);
    ReadClientInfo();
    cout << "--------------------------------------------------------------------------------\n";
}