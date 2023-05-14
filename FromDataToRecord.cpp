#include<vector>
#include<string>
#include<iostream>
using namespace std;

struct stClient
{
    string Number; 
    string Phone;
    string Name;
    string PinCode;
    double Balance;
};
vector <string> Split(string str, string delim)
{
    short pos=0;
    string sWord="";
    vector <string> vString;
    while((pos=str.find(delim)) != std::string::npos)
    {
        sWord = str.substr(0, pos);
        if(sWord!="")
        {
            vString.push_back(sWord);
        }
        str.erase(0, pos+delim.length());
    }
    if(str!="")
    {
        vString.push_back(str);
    }    
    return vString;
    
}
stClient FillClientInfo(vector <string> vString)
{
    stClient client;
    client.Number = vString.at(0);
    client.PinCode = vString.at(1);
    client.Name = vString.at(2);
    client.Phone = vString.at(3);
    client.Balance = stod(vString.at(4));
    return client;
}
void PrintClientInfo(stClient client)
{
    cout << "Enter Account Number: " << client.Number << endl;
    cout << "Enter PinCode: " << client.PinCode << endl;
    cout << "Enter Name: " << client.Name << endl;
    cout << "Enter Phone: " << client.Phone << endl;
    cout << "Enter Account Balance: " << client.Balance << endl;
}

int main()
{
    PrintClientInfo(FillClientInfo(Split("A101#//#737#//#Omer#//#5398914803#//#9850.000000", "#//#")));

}
// A101#//#737#//#Omer#//#5398914803#//#9850.000000