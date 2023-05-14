#include<iostream>
using namespace std;

class clsA
{
    public:

        clsA()
        {
            cout << "Hi, i am constructor\n";
        }
        ~clsA()
        {
            cout << "Hi, i am destructor\n";
        }
};

int main()
{
    clsA A;
    clsA *B = new clsA; // دالة الهدم ما بتشتغل اذا نحن ما علمنا حذف للمؤشر
    // B->~clsA(); // هيك
    delete B; // أو هيك
    // system("pause>0");
}