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
    bool MarkToDelete = false;
};


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
	cout << "\nThe following are the client details \n" << endl;
	cout << "Client Account Number : " << Client.AccountNumber << endl;
	cout << "Client Pine Code	   : " << Client.PinCode << endl;
	cout << "Client Name		   : " << Client.Name << endl;
	cout << "Client Phone          : " << Client.Phone << endl;
	cout << "Client Balance        : " << Client.Balance << endl;
	system("pause>0");
}


vector <stClient> LoadClientsDataFromFile(string FileName)
{

	vector <stClient> vClinet;
	stClient Client;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

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

bool FindClientByAccountNumber(string AccountNumber, stClient& Client, vector <stClient> vClient)
{
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient> &vClient)
{
	for (stClient& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
            C.MarkToDelete = true;
			return true;
		}
	}
	return false;
}

vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient> vClient)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if(MyFile.is_open())
    {
        string Line;

        for(stClient &Client : vClient)
        {
            if(Client.MarkToDelete==false)
            {
                Line = ConvertRecordToLine(Client);
                MyFile << Line << endl;
            }
        }

        MyFile.close();
    }
	return vClient;
}


bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient> vClient)
{
	stClient Client;
	char Answer = 'N';
	if (FindClientByAccountNumber(AccountNumber, Client, vClient))
	{
		PrintfClientInfo(Client);

		cout << "\n\nAre you sure you want to delete this client? ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClient);
			SaveClientsDataToFile(FileName, vClient);

			vClient = LoadClientsDataFromFile(FileName);
			cout << "\n\nClient Deleted Successfully. ";
			return true;
		}
	}
	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") Not Found. \n";
	}
	return false;

}

int main()
{
	string AccountNumber = ReadString();
	vector <stClient> vClient = LoadClientsDataFromFile(FileName);
	DeleteClientByAccountNumber(AccountNumber, vClient);
	 
}
// منقارن رقم المستخدم بالرقم الاساسي
//  اذا تساوو منعمل اشارة صح على اسم العميل
// بعدين بفور لوب منطبع كل شي خطا الا الصح على ملف جديد 
// A103#//#737#//#omer#//#05398914803#//#9500.000000
// A107#//#777#//#yusuf#//#05398564283#//#9500.000000
// A105#//#757#//#ali#//#0991771193#//#8500.000000
// A103#//#767#//#osman#//#5510461244#//#6500.000000
// A102#//#727#//#musa#//#0991667763#//#6900.000000
// A103#//#733#//#abdullah#//#05386814863#//#7500.000000
