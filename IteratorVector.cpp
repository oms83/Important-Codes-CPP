#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    // vector <string> vString = {"omer", "ali", "osama"};
    // vector <string>::iterator iter;
    // for(iter=vString.begin(); iter!=vString.end(); iter++)
    // {
    //     cout << *iter << " ";
    // }
    string str = "omer,";
    str.erase(2,2);
    cout << str;
}