#include<vector>
#include<iostream>
using namespace std;
int main()
{
    
    vector <int> arr{34, 65, 23, 77, 88};
    cout << "Access Element using .at() \n";
    cout << "1. Element: " << arr.at(0) << endl;
    cout << "2. Element: " << arr.at(1) << endl;
    cout << "3. Element: " << arr.at(2) << endl;
    cout << "4. Element: " << arr.at(3) << endl;

    
    cout << "Access Element using [] \n";
    cout << "1. Element: " << arr[0] << endl;
    cout << "2. Element: " << arr[1] << endl;
    cout << "3. Element: " << arr[2] << endl;
    cout << "4. Element: " << arr[3] << endl;
    
}
