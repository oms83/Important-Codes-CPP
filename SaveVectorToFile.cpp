#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

void SaveVectorToFile(string FileName, vector <string> vData)
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
int main()
{
        vector <string> vData = {"omer", "ali", "osman", "yusuf"};
        SaveVectorToFile("firstFile.txt", vData);
}