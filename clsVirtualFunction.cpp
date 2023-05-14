#include<iostream>
using namespace std;

class clsPerson 
{
    public:
        virtual void Print()
        {
            cout << "\nHi, i am person.. ";
        }
};

class clsEmplyee : public clsPerson
{
    public:
        void Print()
        {
            cout << "\nHi, i am Employee.. ";
        }
};

class clsStudent : public clsPerson
{
    public:
        void Print()
        {
            cout << "\nHi, i am sutdent.. ";
        }
};

int main()
{
    // clsEmplyee Employee1;
    // clsStudent Student1;

    // // الدوال موزعة بيطبع محتوى كل دالة التابعة للكلاس اللي أنشئنا منه كائن
    // Employee1.Print();
    // Student1.Print();

    // // الدوال غير موزعة بيطبع محتوى الدالة التابعة للكلاس الأساسي 
    // Employee1.Print();
    // Student1.Print();


    clsEmplyee Employee1;
    clsStudent Student1;

    clsPerson* Person1 = &Employee1;
    clsPerson* Person2 = &Student1;
    // بما منعمل أوب كاستنغ بهالحالة وما منستخدم الفيرشوال فانكشن كمان رح يطبع محتوى دالة الكلاس الأساسي حتى لو كانت دالة هي متكررة بالكلاسات المشتقة
    Person1->Print();
    Person2->Print();

    system("pause>0");

    
}


