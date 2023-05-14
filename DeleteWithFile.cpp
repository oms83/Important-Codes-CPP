#include<iostream>
#include<fstream>
#include<vector>
#include<string>
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
    MyFile.open(FileName, ios::app);
    if(MyFile.is_open())
    {
        for(string &Name : vData)
        {
            if(Name != "")
            {
                MyFile << Name << endl;
            }
        }
        MyFile.close();
    }
}
void DeleteRecordFromData(string FileName, string Record)
{
    vector <string> vData;
    LoadDataFromFileToVector(FileName, vData);
    for(string &Line : vData)
    {
        if(Line==Record)
        {
            Line = "";
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
    cout << "\n-------------------------------------------\n";
    DeleteRecordFromData("firstFile.txt", "ali");
    cout << "\n-------------------------------------------\n";
    PrintFileContent("firstFile.txt");

}