#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

void LoadDataFromFileToVector(string FileName, vector <string> &vData)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if(MyFile.is_open())
    {
        string Line;
        while(getline(MyFile, Line))
        {
            vData.push_back(Line);
        }
        MyFile.close();
    }
}
void SaveVectorToFile(string FileName, vector <string> &vData)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if(MyFile.is_open())
    {
        for(string &Line : vData)
        {
            if(Line !="")
            {
                MyFile << Line << endl;
            }
        }        
        MyFile.close();
    }
}
void UpdateRecordFromFile(string FileName, string Record, string UpdateTo)
{
    vector <string> vData;
    LoadDataFromFileToVector(FileName, vData);
    for(string &Line : vData)
    {
        if(Line == Record)
        {
            Line = UpdateTo;
        }
    }
    SaveVectorToFile(FileName, vData);
}
void PrintFileContent(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if(MyFile.is_open())
    {
        string Line;
        while(getline(MyFile, Line))
        {
            cout << Line << endl;
        }
        MyFile.close();
    }
}
int main()
{
    PrintFileContent("firstFile.txt");
    UpdateRecordFromFile("firstFile.txt", "ali", "omer");
    cout << "\n----------------------------------------------\n";
    PrintFileContent("firstFile.txt");
    cout << "\n----------------------------------------------\n";
}