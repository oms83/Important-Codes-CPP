#include<iostream>
#include<string>
#include<vector>
#include<fstream>
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
int main()
{
        vector <string> vData;
        LoadDataFromFileToVector("firstFile.txt", vData);
        
        for(string Line : vData)
        {
            cout << Line << endl;
        }

}