#include<iostream>
#include<string>
using namespace std;

string ReadPassword(string Message)
{
    string Password;
    cout << Message; 
    cin >> Password;
    return Password;
}
bool FoundThePassword(string Password)
{
    int counter=0;
    string word="";
    for(int i=65; i<=90; i++)
    {
        for(int j=65; j<=90; j++)
        {
            for(int k=65; k<=90; k++)
            {
                word += char(i);
                word += char(j);
                word += char(k);
                counter++;
                if(Password == word)
                {
                    cout << "\n\nThe Password is :: " << word << endl;
                    cout << "Founded atfer " << counter << " Trial" << endl;
                    return true;
                }
                word="";
            }
        }
    }
    return false;
}
int main()
{
    FoundThePassword(ReadPassword("Enter password than 3 letter:: "));
}