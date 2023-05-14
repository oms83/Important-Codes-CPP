#include<iostream>
using namespace std;
int main()
{
    int *ptrX;
    float *ptrY;

    ptrX = new int;
    ptrY = new float;
    *ptrX = 45;
    *ptrY = 6.9;
    cout << *ptrX << endl;
    cout << *ptrY << endl;

    // مقاب كل نيو يجب استخدام ديليت 
    // وحجز مكان لهم في الذاكرة خلال فترة عمل البرنامج int النيو والديليت يساعدنا على زيادة سرعة البرنامج بدل أن نستخدم المتغيرات على شكل 
    // فإننا نستخدم النيو مع المؤشرات وننشئ متغيرات مؤقتة وعند الانتهاء من العمل على هذه المتغيرات نحذف مكانها من الرام 
    delete ptrX;
    delete ptrY;
}