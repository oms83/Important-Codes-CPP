#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> vNumbers;
    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    cout << vNumbers.size() << endl; // 4

    if( (!vNumbers.empty()) || (vNumbers.size()>0) )
        vNumbers.pop_back();

    vNumbers.clear(); // بدل ما فضي الفيكتور عنصر عنصر بفضيه كله بمرة وحدة بهي الطريقة
    
    for(int &Number : vNumbers)
    {
        cout << Number << endl; // هون ما رح يطبعلنا شي لأنه الفيكتور فضيناه
    }
}