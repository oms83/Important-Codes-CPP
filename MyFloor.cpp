#include<iostream>
#include<cmath>
using namespace std;

float ReadNumber(string Message)
{
    float Number;
    cout << Message;
    cin >> Number;
    return Number;
}
int MyFloor(float Number)
{
    if(Number<0)
        return int(Number)-1;
    else
        return int(Number);
}
int main()
{
    float Number = MyFloor(ReadNumber("Enter any number:: "));
    cout << "MyFloor:: " << Number; 
    cout << "\nC++ Floor:: " << floor(Number); 
}

// #include<iostream>
// #include<cmath>
// using namespace std;
// float ReadNumber(string Message)
// {
//     float Number;
//     cout << Message;
//     cin >> Number;
//     return Number;
// }
// int MyFloor(float Number)
// {
//     int IntPart;
//     IntPart = int(Number);
//     if(IntPart<0)
//         return --IntPart;
//     else
//         return IntPart;
// }
// int main()
// {
//     float Number = MyFloor(ReadNumber("Enter any number:: "));
//     cout << "MyFloor:: " << Number; 
//     cout << "\nC++ Floor:: " << floor(Number); 
// }
