#include<iostream>
using namespace std;

class cls
{
    public:

        int Var;
        static int Counter;

        cls()
        {
        }
        static int func()
        {
            return 10;
        }
};

int cls::Counter=0;

int main()
{
    // يتم استدعاءها على مستوى الكلاس وليس على مستوى الكائن وبدون  انشاء اي كائن يمكنن أنا نستدعي دالة ستاتيك
    cout << cls::func() << endl;
    cls A;
    cout << A.func() << endl;
    
    system("pause>0");
}