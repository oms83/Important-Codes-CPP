#include<iostream>
using namespace std;
int main()
{
    char Name[] = "Omer MEMES";
    char ch = 'O';
    printf("My name is : %s", Name);

    printf("Character is :: %c\n", ch);
    printf("Character is :: %*c\n", 2, ch);
    printf("Character is :: %*c\n", 3, ch);
    printf("Character is :: %*c\n", 4, ch);
    printf("Character is :: %*c\n", 5, ch);

}