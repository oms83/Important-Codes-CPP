#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

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

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

string GetSeperator(int sep)
{
    string arr[3] = { "/", ".", "-" };
    return arr[sep - 1];
}

bool IndexIsItFound(vector <short> vIndex, short i)
{
    for (short& index : vIndex)
    {
        if (i == index)
            return false;
    }
    return true;
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

string FormatDate(string sDate)
{
    string Seperator = GetSeperator(RandomNumber(1, 3));
    string ConvertRecord = "";

    vector <string> vString = SplitString(sDate);
    vector <short> vIndex;


    while (true)
    {
        short Random = RandomNumber(0, 2);
        if (IndexIsItFound(vIndex, Random))
        {
            vIndex.push_back(Random);
            ConvertRecord += vString.at(Random) + Seperator;
            if (vIndex.size() == 3)
            {
                return ConvertRecord.substr(0, ConvertRecord.length() - Seperator.length());
            }
        }
    }
    return ConvertRecord;
}

void PrintDate(string sDate)
{

    for (short i = 1; i <= 5; i++)
    {
        cout << FormatDate(sDate) << "\n\n";
    }

    stDate Date = ConvertLineToRecord(sDate);
    cout << "Day: " << Date.Day << ", ";
    cout << "Month: " << Date.Month << ", ";
    cout << "Year: " << Date.Year << endl;
}

int main()
{
    system("cls");
    srand((unsigned)time(NULL));
    string sDate = ReadString("Enter Date [dd/mm/yyyy] : ");

    PrintDate(sDate);

    system("pause>0");
}
