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
string ReplaceWordInString(string S1, string From, string To)
{
    short pos=0;
    while( (pos=S1.find(From)) != S1.npos )
    {
        S1 = S1.replace(pos, From.length(), To);
    }
    
    return S1;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}


void PrintDate(stDate Date)
{
    cout <<"\n"<< FormateDate(Date) <<"\n";     
    cout <<"\n"<< FormateDate(Date, "yyyy/dd/mm") <<"\n";     
    cout <<"\n"<< FormateDate(Date, "mm/dd/yyyy") <<"\n";     
    cout <<"\n"<< FormateDate(Date, "mm-dd-yyyy") <<"\n";     
    cout <<"\n"<< FormateDate(Date, "dd-mm-yyyy") <<"\n";     
    cout <<"\n"<< FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") <<"\n";
}

int main()
{
    system("cls");
    srand((unsigned)time(NULL));
    string sDate = ReadString("Enter Date [dd/mm/yyyy] : ");

    stDate Date = ConvertLineToRecord(sDate);

    PrintDate(Date);
    

    system("pause>0");
}
