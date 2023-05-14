#include<iostream>
using namespace std;
int ReadNumber()
{
    int Number;
    cout << "Enter a positive number:: ";
    cin >> Number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number! Enter a valid number :: ";
        cin >> Number;
    }
    return Number;
}
int main()
{
    int Number = ReadNumber();
    cout << "The entered number is :: " << Number << endl;
}