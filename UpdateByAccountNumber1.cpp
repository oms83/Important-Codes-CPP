#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
const string FileName = "Client3.txt";

string ReadString()
{
    string S1; 
    cout << "Enter Account Number: ";
    getline(cin, S1);
    return S1;
}

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double Balance;
    bool MarkToUpdate = false;
};

string ConvertRecordToLine(stClient Client, string Seperator="#//#")
{
    string LineData;
    LineData += Client.AccountNumber + Seperator;
    LineData += Client.PinCode + Seperator;
    LineData += Client.Name + Seperator;
    LineData += Client.Phone + Seperator;
    LineData += to_string(Client.Balance);

    return LineData;
}

vector <string> SplitString(string  DataLine, string delim="#//#")
{
    vector <string> vString;
    short pos=0;
    string sWord;

    while( (pos = DataLine.find(delim)) != std::string::npos )
    {
        sWord = DataLine.substr(0, pos);

        if(sWord!="")
        {
            vString.push_back(sWord);
        }

        DataLine.erase(0, pos + delim.length());
    }
    if(DataLine!="")
    {
        vString.push_back(DataLine);
    }

    return vString;
}
stClient ConvertLineToRecord(string DataLine)
{
    vector <string> vString = SplitString(DataLine);

    stClient Client;
    Client.AccountNumber = vString.at(0);
    Client.PinCode = vString.at(1);
    Client.Name = vString.at(2);
    Client.Phone = vString.at(3);
    Client.Balance = stod(vString.at(4));

    return Client;
}

vector <stClient> LoadDataFromFile(string ClientstFileName)
{
    vector <stClient> vClient;
    stClient Client;

    fstream MyFile;
    
    MyFile.open(ClientstFileName, ios::in);

    if(MyFile.is_open())
    {
        string Line;
        while(getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClient.push_back(Client);
        }
    
    }    
 
      MyFile.close();

    return vClient;
}

bool FindClientByAccountNumber(vector <stClient> vClient, stClient &Client, string AccountNumber)
{
    for(stClient &C : vClient)
    {
        if(C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

bool MarkClientForUpdateByAccountNumber(vector <stClient> &vClient, string AccountNumber)
{
    for(stClient &C : vClient)
    {
        if(C.AccountNumber == AccountNumber)
        {
            C.MarkToUpdate = true;
            return true;
        }
    }
    return false;
}

vector <stClient> SaveDataToFile(vector <stClient> vClient, string ClientstFileName)
{
    fstream MyFile;
    MyFile.open(ClientstFileName, ios::out);

    if(MyFile.is_open())
    {
        string Line;
        for(stClient &Client : vClient)
        {
            Line = ConvertRecordToLine(Client);
            MyFile << Line << endl;
        }

    }
        MyFile.close();

    return vClient;
}

void PrintfClientInfo(stClient Client)
{
	cout << "\nThe following are the client details \n" << endl;
	cout << "Client Account Number : " << Client.AccountNumber << endl;
	cout << "Client Pine Code	   : " << Client.PinCode << endl;
	cout << "Client Name		   : " << Client.Name << endl;
	cout << "Client Phone          : " << Client.Phone << endl;
	cout << "Client Balance        : " << Client.Balance << endl;
}

stClient GetClientInfo(stClient &Client)
{
    Client.AccountNumber = Client.AccountNumber;

	cout << "Enter Pin Code: ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name: ";
	getline(cin, Client.Name);

	cout << "Enter Phone: ";
	getline(cin, Client.Phone);

	cout << "Enter Balance: ";
	cin >> Client.Balance;

	return Client;
}

void UpdateClientInfo(vector <stClient> &vClient)
{
    for(stClient &Client : vClient)
    {
        if(Client.MarkToUpdate == true)
        {
            GetClientInfo(Client);
            return;
        }
    }
}


void UpdateClientByAccountNumber(vector <stClient> vClient, string AccountNumber ,string ClientsFileName)
{
    char Answer = 'Y';
    stClient Client;
    if(FindClientByAccountNumber(vClient, Client, AccountNumber))
    {
        PrintfClientInfo(Client);

        cout << "\n\nAre you sure you want to update this client [Y/N] ? ";
        cin >> Answer;
        
        if(toupper(Answer)=='Y')
        {
            MarkClientForUpdateByAccountNumber(vClient, AccountNumber);
            UpdateClientInfo(vClient);
            SaveDataToFile(vClient, ClientsFileName);

            vClient = LoadDataFromFile(ClientsFileName);
			cout << "\n\nClient Updated Successfully. ";
        }
    }
    else
    {
        cout << "\nClient With Account Number (" << AccountNumber << ") Not Found. \n";
    }
}

int main()
{
    string AccountNumber = ReadString();
    vector <stClient> vClient = LoadDataFromFile(FileName);
    UpdateClientByAccountNumber(vClient, AccountNumber, FileName);
}