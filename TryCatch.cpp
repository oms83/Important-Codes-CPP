#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> arr{10, 20, 30, 40, 50};
    try
    {
        cout << arr.at(5);
    }
    catch(...)
    {
        cout << "out of bound\n";
    }
}