#include<iostream>
using namespace std;
int main()
{
    int a=10; 
    int &x=a; // متل أنه عم تشير عليها a هون ما رح يتم إنشاء مكان للإكس في الذاكرة بل رح يكون إلها نفس عنوان ال
    x++; // a وأي تغير على الاكس بغير على الـ
    cout << a << endl;
    cout << x << endl;

    cout << &x << endl;
    cout << &a << endl;

}