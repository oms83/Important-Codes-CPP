#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream MyFile;
    MyFile.open("File1.txt", ios::out);
    if(MyFile.is_open())
    {
        MyFile << "Hello";
        MyFile << "Omer";
    }
    MyFile.close();
}