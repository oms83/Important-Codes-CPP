// #include<iostream>
// // using namespace std;
// void PrintPrimeNumber(int num);

// bool CheckToNumber(int num)
// {
//     for(int i=2; i<=num/2; i++)
//     {
//         if(num%i==0)
//             return false;
//     }
//     return true;
// }
// void PrimeNumber(int num)
// {
//     for(int i=1; i<num; i++)
//     {
//         if(CheckToNumber(i))
//             PrintPrimeNumber(i);
//         else
//             continue;
//     }
// }
// void PrintPrimeNumber(int num)
// {
//     cout << "\n" << num << " is prime number\n";
// }
// int main()
// {
//     PrimeNumber(100);
// }


#include<iostream>
#include<string>
#include<cmath>
using namespace std;

enum enPrimeNotPrime { Prime=1, NotPrime=2 };
enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number/2);
    for(int Counter=2; Counter<=M; Counter++)
    {
        if(Number%Counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
}
void PrintPrimeNumber(int Number)
{
    cout << "\n";
    cout << "Prime Number From 1 to " << Number << " are: \n";
    for(int i=1; i<=Number; i++)
    {
        if(CheckPrime(i) == enPrimeNotPrime::Prime)
            cout << i << endl;
    }
}
int ReadPositiveNumber(string Message)
{
    int Number=0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number<=0);
    return Number;
    
} 
int main()
{
    PrintPrimeNumber(ReadPositiveNumber("Please enter a positive number : "));
}