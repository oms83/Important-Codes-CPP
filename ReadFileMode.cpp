#include<iostream>
#include<fstream>
using namespace std;
void ReadFile(string FileName)
{
    fstream myFile;
    myFile.open(FileName, ios::in);
    if(myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            cout << line << endl;
        }
        
        myFile.close();
    }

}
int main()
{
    ReadFile("firstFile.txt");
}