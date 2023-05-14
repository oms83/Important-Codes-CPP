#include<iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter total number of students: ";
    cin >> num;

    float *ptr;
    ptr = new float [num];

    cout << "Enter grades of students " << endl;
    for(int i=0; i<num; i++)
    {
        cout << "Enter " << i+1 << " student grades: ";
        cin >> *(ptr+i);
    }

    cout << "Student Grades \n";
    for(int i=0; i<num; i++)
    {
        cout << *(ptr+i) << endl;
    }
}