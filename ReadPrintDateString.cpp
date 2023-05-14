#include<iostream>
#include<string>
#include<vector>
using namespace std;

string ReadString(string Message)
{
    string str;

    cout << Message;
    getline(cin >> ws, str);
    return str;
}

struct stDate
{
    short Year;
    short Month;
    short Day;
};

vector <string> SplitString(string  DataLine, string delim = "/")
{
    vector <string> vString;
    short pos = 0;
    string sWord;

    while ((pos = DataLine.find(delim)) != std::string::npos)
    {
        sWord = DataLine.substr(0, pos);

        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        DataLine.erase(0, pos + delim.length());
    }
    if (DataLine != "")
    {
        vString.push_back(DataLine);
    }

    return vString;
}

stDate ConvertLineToRecord(string DataLine)
{
    vector <string> vString = SplitString(DataLine);

    stDate Data;
    Data.Day = stoi(vString.at(0));
    Data.Month = stoi(vString.at(1));
    Data.Year = stoi(vString.at(2));
    
    return Data;
}

void PrintDate(stDate Date)
{
    
    cout << "Day: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;

    cout << "\nYou entered:  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl;
}

int main()
{
    system("cls");

    string sDate = ReadString("Enter Date [dd/mm/yyyy] : ");

    PrintDate(ConvertLineToRecord(sDate));
    
    system("pause>0");
}
