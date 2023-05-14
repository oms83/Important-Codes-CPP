#include<iostream>
using namespace std;


void printTableHeader()
{
    cout << endl << endl << "\t\t\t Mutiplication Table from 1 to 10 \n\n" ;
    cout << "\t" ;
    for(int i=1; i<11; i++)
        cout << i << "\t" ;
    cout << "\n-----------------------------------------------------------------------------------\n";
}
string ColumSperator(int i)
{
    if(i<10)
        return "   |";
    else
        return "  | ";
}
void PrintMutiplicationTable()
{
    printTableHeader();
    for(int i=1; i<11; i++)
    {
        cout << " " << i << ColumSperator(i) << "\t";
        for(int j=1; j<11; j++)
        {
            cout << i*j << "\t";
        }
        cout << endl;
    }
}
int main()
{
    PrintMutiplicationTable();
}




// int main()
// {
//     cout << endl << endl << "                       Mutiplication Table from 1 to 10" << endl << endl ;
//     for(int i=1; i<11; i++)
//         cout << "\t" << i ;
//     cout << endl;
//     cout << "-----------------------------------------------------------------------------------" << endl;
//     for(int i=1; i<11; i++)
//     {
//         cout << setw(2) << i << "  |   ";
//         for(int j=1; j<11; j++)
//         {
//             cout << i*j << "\t";
//         }
//         cout << endl;
//     }
//     cout << endl;
//     cout << endl;

// }

