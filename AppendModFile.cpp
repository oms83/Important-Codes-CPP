#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream MyFile;
    MyFile.open("firstFile.txt", ios::out | ios::app); // Write mod or append
    if(MyFile.is_open())
    {
        MyFile << "This is 4. line \n";
        MyFile << "This is 5. line \n";
        MyFile.close();
    }

}