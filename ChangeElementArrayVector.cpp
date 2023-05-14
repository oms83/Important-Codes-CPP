#include<vector>
#include<iostream>
using namespace std;
int main()
{
    
    vector <int> arr{34, 65, 23, 77, 88};

    for(int const &i : arr)
    {
        cout << i << " "; // غير قابلة للتغيير
    }
    cout << "\n";
    for(int &i : arr)
    {
        i = 20;
        cout << i << " "; 
    }
    cout << "\n";
    arr[0] = 5;
    arr[1] = 50;
    arr.at(2) = 70;
    arr.at(3) = 140;
    arr.at(4) = 100;
    for(int &i : arr)
    {
        cout << i << " ";
    }
    
    
}
