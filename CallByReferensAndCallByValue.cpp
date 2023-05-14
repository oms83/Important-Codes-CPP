#include<iostream>
using namespace std;

void CallByRef(int &x) // رح يحصل التغير على القيمة الأساسية 
{
    x++;
}
void CallByVal(int x) // هون رح يتم إنشاء متغير جديد في الرام وتصير عليه العملية والمتغير الأساسي ما رح يأثر عليه شي
{
    x++;
}
int main()
{
    int x=10;
    CallByRef(x);
    cout << "Call By Referenc: " << x << endl; 
    CallByVal(x);
    cout << "Call By Value: " << x;  // 11 وهون رح يعطي كمان 11 لأنه استدعينا دالة كل باي ريفيرانس أولاً
}