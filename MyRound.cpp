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
float GetFractionPart(float Number)
{
    return Number - int(Number);
}
int MyRound(float Number)
{
    int IntPart;
    IntPart = int(Number);
    float FractionPart = GetFractionPart(Number);
    if(abs(FractionPart)>=.5)
    {
        if(Number>0)
            return ++IntPart;
        else
            return --IntPart;
    } 
    else
    {
        return IntPart;
    }
}
int main()
{
    float Number = MyRound(ReadNumber("Enter any number:: "));
    cout << "MyRound:: " << Number; 
    cout << "\nC++ Round:: " << round(Number); 
}

// #include<iostream>
// #include<cmath>
// using namespace std;
// float GetFractionPart(float Number)
// {
//     return Number - (int)Number;
// }
// int MyRound(float Number)
// {
//     int IntPart = int(Number);
//     float FractionPart = GetFractionPart(Number);
//     if(abs(FractionPart)>=.5)
//     {
//         if(Number>0)
//             return ++IntPart;
//         else 
//             return --IntPart;
//     }
//     else
//     {
//         return IntPart;
//     }
// }
// int main()
// {
//     float Number;
//     cout << "Enter any number:: ", cin >> Number;
//     cout << "\nMyRound:: " << MyRound(Number);
// }