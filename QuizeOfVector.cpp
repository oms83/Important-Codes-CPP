#include<iostream>
#include<vector>
using namespace std;

void ReadNumber(vector <int> &vNumbers) // إذا ما حطينا & مع المعامل الفيكتور ما برجعلنا الفيكتور مليان لأنه بينسخ نسخة تانية منو جوا الفانكشن
// هون لازم نبعت الفيكتور كباي ريفرانس لأنه مو متل الأرّاي مشان يصير التعديل على الفيكتور الأساسي
// العمليات رح تم بشكل صحيح على الفيكتور المنسوخ ولكن برجعلنا فيكتور فاضي لأنه ما صار التعديل على الفيكتور الأساسي
{
    char EnterAgin = 'Y';
    int Number;
    do
    {
        cout << "Enter a number:: ";
        cin >> Number;
        vNumbers.push_back(Number);
        cout << "Do you want add a more number ? ";
        cin >> EnterAgin;
    }while(EnterAgin=='Y'||EnterAgin=='y');
}
void PrintNumbers(vector <int> &vNumbers) // وهون بعتناها كباي ريفيرانس مشان ما تصير عملية النسخ لأنه بحال كان حجم الفيكتور كتير كبير بصير البرنامج أبطء
{
    cout << "Vector Numbers:: ";
    for(int &Number : vNumbers)
    {
        cout << Number << "  ";
    }
}
int main()
{
    vector <int> vNumbers;
    ReadNumber(vNumbers);
    PrintNumbers(vNumbers);
}