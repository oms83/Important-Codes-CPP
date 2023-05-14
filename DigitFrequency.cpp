#include<iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number=0; 
    do
    {
        cout << Message;
        cin >> Number;
    }while(Number<=0);
    return Number;
}
void FoundFrequencyOfDigits(int Number)
{
    int Frequency[10]={0};
    while(Number>0)
    {
        Frequency[Number%10]++;
        Number /=10;
    }
    for(int i=0; i<10; i++)
    {
        cout << i << "=>" << Frequency[i] << endl;
    }
}

int main()
{
    FoundFrequencyOfDigits(ReadPositiveNumber("Enter a positive number :: "));
}


