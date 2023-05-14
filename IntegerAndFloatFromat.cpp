#include<iostream>
using namespace std;
int main()
{
    int Page=1, TotalPages=10;
    printf("The Page Number:: %d\n", Page);
    printf("Total Pages :: %d\n", TotalPages);

    printf("The Page Number:: %0*d\n", 2, Page); // The Page Number:: 01
    printf("The Page Number:: %0*d\n", 3, Page); // The Page Number:: 001
    printf("The Page Number:: %0*d\n", 4, Page); // The Page Number:: 0001
    printf("The Page Number:: %0*d\n", 5, Page); // The Page Number:: 00001

    float Number1=10.43, Number2=3.12;
    printf("The Page Number:: %.0*f\n", 2, Number1);
    printf("Total Pages :: %.0*f\n", 3, Number1/Number2);

    printf("The Page Number:: %.*f\n", 2, Number1); // The Page Number:: 10.43
    printf("The Page Number:: %.*f\n", 3, Number1); // The Page Number:: 10.430
    printf("The Page Number:: %.*f\n", 4, Number1); // The Page Number:: 10.43000
    printf("The Page Number:: %.*f\n", 5, Number1); // The Page Number:: 10.43000

}