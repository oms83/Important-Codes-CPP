#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream MyFile;
    MyFile.open("firstFile.txt", ios::out); // Write mode
    if(MyFile.is_open())
    {
        MyFile << "This is first line \n";
        MyFile << "This is scond line \n";
        MyFile << "This is thrid line \n";
        MyFile.close();
    }

}