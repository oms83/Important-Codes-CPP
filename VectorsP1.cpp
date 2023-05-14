#include<vector>
#include<iostream>
using namespace std;

int main()
{
    // vector <int> vNumbers = {10, 20, 30, 40, 50};
    // cout << "Vector Numbers: ";
    // for (int Number : vNumbers) // هنا في كل دورة نحن عم نعمل نسخ لعناصر الفيكتور على النمبر يعني بكل دورة عم ينسخ عنصر الفيكتور على النمبر ليطبعه بهالحالة البرنامج بكون بطيئ نوعا ما 
    // {
    //     cout << Number << ' ';
    // } 
    vector <int> vNumbers = {10, 20, 30, 40, 50};
    cout << "Vector Numbers: ";
    for (int &Number : vNumbers) // لتفادي عملية النسخ منجعل النمبر يأشر على موقع العنصر فقط وما بتصير عملية النسخ وبكون البرنامج أسرع
    {
        cout << Number << ' ';
    } 

    string Names[3] = {"omer", "ali", "osman"};
    for(string &Name : Names) // هنا أيضاً نفس العملية 
    {
        cout << endl << Name; 
    }
}