#include<iostream>
using namespace std;
int main()
{
    int x = 10, y=5, k=7, *p;
    int &z = x; // الريفيرانس هو اسم الدلع للمتغير وعند انشاء ريفيرانس لا يتم حجز له مكان في الذاكرة لأنه عبارة عن عنوان للمتغير
    // لا يمكن استخدام الريفيرانس الواحد لأكثر من متغير على عكس المؤشر

    // &z = x; تعريف خاطئ
    cout << "x: " << x << endl;
    cout << "&z: " << &z << endl;
    
    // &z = k; تعريف خاطئ
    // المؤشر يحجز له مكان في الذاكرة ؛ هو متغير من يخزن عناوين متغيرات
    p = &x; // يمكننا استخدام المؤشر للتأشير على أكثر من متغير
    cout << "*p: " << *p << endl;
    cout << "p: " << p << endl;
    
    p = &y; // يمكننا استخدام المؤشر للتأشير على أكثر من متغير
    cout << "*p: " << *p << endl;
    cout << "p: " << p << endl;
}