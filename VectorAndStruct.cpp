#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct stClient
{
    string Name="omer";
    string Surname="memes";
    string age="22";
    int salary = 9600;
};


int main()
{
    vector <stClient> vClient;
    stClient Client;
    vClient.push_back(Client);
    for(stClient client : vClient)
    {
        cout << client.Name <<endl;
        cout << client.Surname <<endl;
        cout << client.age <<endl;
        cout << client.salary <<endl;
    }
    cout << vClient.size() << endl;
    for(stClient client : vClient)
    {

    }
}