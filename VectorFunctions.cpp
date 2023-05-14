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
    cout << "First Element of Vector: " << vNumbers.front() << endl;
    cout << "Last Element of Vector: " << vNumbers.back() << endl;
    cout << "Vector Size: " << vNumbers.size() << endl;
    cout << "Vector Capacity: " << vNumbers.capacity() << endl; 
    cout << "Vector Empty: " << vNumbers.empty() << endl; // ترجع واحد أو صفر || صح أو خطأ
    // لطلب أول وآخر عنصر في الفيكتور يجب التحقق أولاً من أن الفيكتور يوجد فيه عناصر وإلا سوف نحصل على خطأ في حال كان الفيكتور فارغاً
}