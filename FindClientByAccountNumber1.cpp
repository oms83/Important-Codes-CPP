#include<iomanip>
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

const string FileName = "Client3.txt";
string ReadString()
{
	string str;
	cout << "Enter any string:: ";
	getline(cin, str);
	return str;
}

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double Balance;
};
stClient GetClientInfo()
{
	stClient Client;

	cout << "Enter Account Number: ";
	getline(cin >> ws, Client.AccountNumber);

	cout << "Enter Pin Code: ";
	getline(cin, Client.PinCode);

	cout << "Enter Name: ";
	getline(cin, Client.Name);

	cout << "Enter Phone: ";
	getline(cin, Client.Phone);

	cout << "Enter Balance: ";
	cin >> Client.Balance;

	return Client;
}
string ConvertRecordToLine(stClient Client, string seperator = "#//#")
{
	string LineData;
	LineData += Client.AccountNumber + seperator;
	LineData += Client.PinCode + seperator;
	LineData += Client.Name + seperator;
	LineData += Client.Phone + seperator;
	LineData += to_string(Client.Balance);
	return LineData;
}

vector <string> SplitString(string LineData, string seperator = "#//#")
{
	vector <string> vString;
	short pos = 0;
	string sWord;
	while ((pos = LineData.find(seperator)) != std::string::npos)
	{
		sWord = LineData.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		LineData.erase(0, pos + seperator.length());
	}
	if (LineData != "")
	{
		vString.push_back(LineData);
	}
	return vString;
}
stClient  ConvertLineToRecord(string LineData, string seperator = "#//#")
{
	vector <string> vString = SplitString(LineData, seperator);
	stClient Client;

	Client.AccountNumber = vString.at(0);
	Client.PinCode = vString.at(1);
	Client.Name = vString.at(2);
	Client.Phone = vString.at(3);
	Client.Balance = stod(vString.at(4));

	return Client;
}
void PrintfClientInfo(stClient Client)
{
	system("cls");
	cout << "\nThe following are the client details \n" << endl;
	cout << "Client Account Number : " << Client.AccountNumber << endl;
	cout << "Client Pine Code	   : " << Client.PinCode << endl;
	cout << "Client Name		   : " << Client.Name << endl;
	cout << "Client Phone          : " << Client.Phone << endl;
	cout << "Client Balance        : " << Client.Balance << endl;
	system("pause>0");
}
vector <string> LoadDataFromFileToVector(string ClientFileName = "Client3.txt")
{

	vector <string> vString;

	fstream MyFile;
	MyFile.open("Client3.txt", ios::in);

	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vString.push_back(Line);
		}
	}
	MyFile.close();
	return vString;
}
vector <stClient> LoadDataFromFileToVector1(string ClientFileName = "Client3.txt")
{

	vector <stClient> vClinet;
	stClient Client;
	fstream MyFile;
	MyFile.open(ClientFileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClinet.push_back(Client);
		}
	}
	MyFile.close();
	return vClinet;
}
bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
	vector <stClient> vClient = LoadDataFromFileToVector1();
	for (stClient& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}
void PrintResult()
{
	string AccountNumber = ReadString();
	stClient Client;
	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintfClientInfo(Client);
	}
	else
	{
		cout << "Client with account number (" << AccountNumber << ") not found. ";
	}
}
int main()
{
	PrintResult();
}