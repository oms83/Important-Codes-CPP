#include<iostream>
#include<string>
using namespace std;


string ReadTheName(string Message)
{
    string Name;
    cout << Message; 
    getline(cin, Name);
    return Name;
}

string Encrypt(string Name, short EncryptionKey)
{
    for(int i=0; Name[i]!='\0'; i++)
    {
        Name[i] = char((int)Name[i] + EncryptionKey);
    }
    return Name;
}


string Decrypt(string Name, short EncryptionKey)
{
    for(int i=0; Name[i]!='\0'; i++)
    {
        Name[i] = char((int)Name[i] - EncryptionKey);
    }
    return Name;
}

void PrintName(string Name, short EncryptionKey)
{
    cout << "Orginal Name:: " << Name << endl;
    cout << "Encyption Name:: " << Encrypt(Name, EncryptionKey) << endl;
    cout << "Decryption Name:: " << Decrypt(Encrypt(Name, EncryptionKey), EncryptionKey) << endl;
}
int main()
{
    const short EncryptionKey=3;
    PrintName(ReadTheName("Enter your name:: "), EncryptionKey);
}



