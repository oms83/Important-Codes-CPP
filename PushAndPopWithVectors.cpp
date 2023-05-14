#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> Numbers;
    Numbers.push_back(10);
    Numbers.push_back(20);
    Numbers.push_back(30);
    Numbers.push_back(40);
    for(int &Number : Numbers)
    {
        cout << Number << endl;
    }
    Numbers.pop_back();
    Numbers.pop_back();
    Numbers.pop_back();
    Numbers.pop_back();
    for(int &Number : Numbers)
    {
        cout << Number << endl; // هون ما رح يطبعلنا شي لأنه الفيكتور فضيناه
    }
}