#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    cout << "Year                          : " << now->tm_year << endl;  // years since 1900
    cout << "Month                         : " << now->tm_mon << endl;   // Mon of Year 0 to 11
    cout << "Day                           : " << now->tm_mday << endl;  // Day of Mon 0 to 31
    cout << "Day                           : " << now->tm_hour << endl;  // Hour of Day 0 to 24
    cout << "Minute                        : " << now->tm_min << endl;   // Min of Hour since 0 to 59
    cout << "Second                        : " << now->tm_sec << endl;   // Sec of Min 0 to 61
    cout << "Week day (Days since sunday)  : " << now->tm_wday << endl;
    cout << "Year day (Days since jan 1st) : " << now->tm_yday << endl;
    cout << "Hour of daylight savings time : " << now->tm_isdst << endl;
}