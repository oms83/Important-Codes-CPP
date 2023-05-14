#include<vector>
#include<iostream>
using namespace std;
int main()
{
    
    vector <int> arr{34, 65, 23, 77, 88};
    vector <int>::iterator iter;
    for(iter = arr.begin();  iter!=arr.end(); iter++)
    {
        cout << *iter << " ";
    }
    
    
    
}