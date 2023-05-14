#include<iostream>
#include<cmath>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number=0;
    do
    {
        cout << Message ;
        cin >> Number;
    } while (Number<=0);
    return Number;
}
bool isPerfectNumber(int Number)
{
    int Sum=0;
    for(int i=1; i<Number; i++)
    {
        if(Number%i == 0)
            Sum+=i;
    }
    return Sum==Number;
}
void PrintResults(int Number)
{
    if(isPerfectNumber(Number))
        cout << Number << " is a perfect number\n";
    else
        cout << Number << " is not a perfect number\n";
}
int main()
{
    PrintResults(ReadPositiveNumber("Enter a positve number: "));
}






// #include<iostream>
// #include<cmath>
// using namespace std;
// int IsItPerfect(int Sum, int Number)
// {
//     if(Sum == Number)
//        cout << Number << " is a perfect number";
//     else
//        cout << Number << " is not a perfect number";
// }
// int CheckPerfect(int Number)
// {
//     int Sum=0;
//     int M = round(Number/2);
//     for(int Counter=1; Counter<=M; Counter++)
//     {
//         if(Number%Counter == 0)
//             Sum += Counter;
//     }
//     IsItPerfect(Sum, Number);
// }
// int ReadNumber(string Message)
// {
//     int Number=0;
//     do
//     {
//         cout << Message;
//         cin >> Number;
//     } while (Number<=0);
//     CheckPerfect(Number);
// }
// int main()
// {
//     CheckPerfect(ReadNumber("Enter a positive Number: "));
// }