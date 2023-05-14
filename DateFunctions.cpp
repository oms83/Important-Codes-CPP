#include<iostream>
#include<string>
#include<time.h>
#include<iomanip>
#include<vector>
#include<stdio.h>
using namespace std;


class clsDate
{

    private:

        short _Year=2000;
        short _Month=3;
        short _Day=8;

    
    public:

        clsDate() 
        { 
            time_t t = time(0); 
            tm* now = localtime(&t);     
            this->_Year = now->tm_year + 1900;     
            this->_Month = now->tm_mon + 1;     
            this->_Day = now->tm_mday; 
        }

        static string ReadString(string Message)
        {
            string S1;
            cout << Message;
            getline(cin, S1);
            return S1;
        }
        
        static int GetPositiveNumber(string Message)
        {
            int Number;
            do
            {
                cout << Message;
                cin >> Number;

            } while(Number<0);

            return Number;
        }

        static string NumberByText(int Number)
        {
            string Arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
                            "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
            string Tens[] = { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eigthy", "ninety" };

            if(Number<20)
                return  Arr[Number] + " ";
            else if(Number<100)
                return Tens[Number/10] + " " + NumberByText(Number%10);
            else if(Number<1000)
                return NumberByText(Number/100) + " hundred " + NumberByText(Number%100);
            else if(Number<1000000)
                return NumberByText(Number/1000) + " thousend " + NumberByText(Number%1000);
            else if(Number<1000000000)
                return NumberByText(Number/10000000) + " million " + NumberByText(Number%1000000);
            else if(Number<1000000000000)
                return NumberByText(Number/1000000000) + " billion " + NumberByText(Number%1000000000);
        }

        static bool isLeapYear(short Year)
        {
            return (Year%400==0) || (Year%100!=0 && Year%4==0);
        }

        static short NumberOfDayInYear(short Year)
        {
            return isLeapYear(Year) ? 366 : 365;
        }

        static short NumberOfDayInMonth(short Year, short Month)
        {
            short months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            // return (Month==2 && isLeapYear(Year)) ? 29 : months[Month-1];
            return (Month==2) ? (isLeapYear(Year) ? 29 : 28) : months[Month-1];
        } 

        static short NumberOfHoursInMonth(short Year, short Month)
        {
            return NumberOfDayInMonth(Year, Month) * 24;
        }

        static short NumberOfMinutesInMonth(short Year, short Month)
        {
            return NumberOfHoursInMonth(Year, Month) * 60;
        }

        static short NumberOfSecondsInMonth(short Year, short Month)
        {
            return NumberOfMinutesInMonth(Year, Month) * 60;
        }

        static short DayOfWeekOrder(short Year, short Month, short Day) 
        { 
            short a, y, m;     

            a = (14 - Month) / 12;
            y = Year - a;     
            m = Month + (12 * a) - 2;
            
            return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7; 
        
        }

        static string DayShortName(short DayOfWeekOrder) 
        { 
            string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; 
            return arrDayNames[DayOfWeekOrder]; 
        
        }
       
        static string MonthShortName(short Month)
        {
            string Months[12] = { "Jan", "Feb", "Mar", "Epr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
            return Months[Month-1];
        }

        static void PrintMonthCalendar(short Year, short Month)
        { 
            int NumberOfDays;
            int current = DayOfWeekOrder(Year, Month, 1);     
            NumberOfDays = NumberOfDayInMonth(Year, Month); 

            printf("\n  _______________%s_______________\n\n",MonthShortName(Month).c_str()); 

            printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); 

            int i;

            for (i = 0; i < current; i++)         
                printf("     "); 

            for (int j = 1; j <= NumberOfDays; j++)     
            {         
                printf("%5d", j); 
                if (++i == 7)         
                {             
                    i = 0;             
                    printf("\n");         
                    
                }  
            }   
            printf("\n  _________________________________\n"); 
        }
        
        static void PrintYearCalendar(short Year)
        {
            printf("\n  _________________________________");
            printf("\n  _______________%d______________", Year);
            printf("\n  _________________________________\n");

            for(short i=1; i<=12; i++)
            {
                PrintMonthCalendar(Year, i);
            }

        }
        
        static short DaysFromTheBeginningOfYear(short Year, short Month, short Day)
        {
            short Days = 0;

            for(short i=1; i<=Month-1; i++)
            {
                Days += NumberOfDayInMonth(Year, i);
            }

            return Day + Days;
        }
        
        void SetYear(short Year) 
        { 
            _Year = Year; 
        };

        void SetMonth(short Month) 
        { 
            _Month = Month;
        };

        void SetDay(short Day) 
        { 
            _Day = Day; 
        };

        short GetYear() 
        { 
            return _Year; 
        };
        
        short GetMonth() { 
            return _Month; 
        };
        
        short GetDay() 
        { 
            return _Day; 
        };

        // __declspec(property(get = GetYear, put = SetYear)) string Year;
        // __declspec(property(get = GetMonth, put = SetMonth)) string Month;
        // __declspec(property(get = GetDay, put = SetDay)) string Day;

        clsDate DateFromDayOrderInAYear(short Year, short Days)
        {
            clsDate Date;
            Date._Year = Year;
            Date._Month = 1;
            short MonthDays;
            while(true)
            {
                MonthDays = NumberOfDayInMonth(Year, Date._Month);
                if(Days > MonthDays)
                {
                    Days -= MonthDays;
                    Date._Month++;
                }
                else
                {
                    Date._Day = Days;
                    break;
                }
            }
            return Date;
        }        

        clsDate AddDaysToDate(clsDate& Date, int Days)
        {
            Days += DaysFromTheBeginningOfYear(Date._Year, Date._Month, Date._Day);
            short MonthDays=0;
            Date._Month = 1;
            while(true)
            {
                MonthDays = NumberOfDayInMonth(Date._Year, Date._Month);
                if(Days>MonthDays)
                {
                    Date._Month++;
                    Days -= MonthDays;
                    if(Date._Month>12)
                    {
                        Date._Month = 1;
                        Date._Year++;
                    }
                }
                else
                {
                    Date._Day = Days;
                    break;
                }
            }

            return Date;
        }

        static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
        {
            return (Date1._Year<Date2._Year) ? true : ( (Date1._Year == Date2._Year) ? (Date1._Month<Date2._Month ? true : ( (Date1._Month==Date2._Month) ? (Date1._Day<Date2._Day ? true : false):false)) : false );
        }
        
        static bool isDate1EqualDate2(clsDate Date1, clsDate Date2)
        {
            return (Date1._Year == Date2._Year) ? ( (Date1._Month == Date2._Month ? (Date1._Day == Date2._Day ? true : false) : false )) : false;
        }
        
        bool isLastDayInMonth()
        {
            return this->_Day == NumberOfDayInMonth(this->_Year, this->_Month);
        }
        
        bool isLastMonthInYear()
        {
            return this->_Month == 12;
        }
        
        clsDate IncreaseDateByOneDay()
        {
            if(this->isLastDayInMonth())
            {
                this->_Day = 1;
                if(this->isLastMonthInYear())
                {
                    this->_Year++;
                    this->_Month = 1;
                }
                else
                {
                    this->_Month++;
                }
            }
            else
            {
                this->_Day++;
            }

            return *this;
        }        
        
        void PrintDate()
        {
            cout << this->_Day << "/" << this->_Month << "/" << this->_Year << endl;
        }
        
        void SwapDate(clsDate& Date1, clsDate& Date2)
        {
            clsDate dTemp;
            dTemp._Day = Date1._Day;
            dTemp._Month = Date1._Month;
            dTemp._Year = Date1._Year;

            Date1._Day = Date2._Day;
            Date1._Month = Date2._Month;
            Date1._Year = Date2._Year;

            
            Date2._Day = dTemp._Day;
            Date2._Month = dTemp._Month;
            Date2._Year = dTemp._Year;
        }

        int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = true)
        {
            int Days=0;
            short SwapFlagValue = 1;

            if(!IsDate1BeforeDate2(*this, Date2) && !isDate1EqualDate2(*this, Date2))
            {
                SwapFlagValue = -1;
                SwapDate(*this, Date2);
            }
            while(IsDate1BeforeDate2(*this, Date2))
            {
                Days++;
                this->IncreaseDateByOneDay();
            }
            return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
        }

        clsDate GetDate()
        {
            cout << "\nEnter Day: ", cin >> this->_Day;
            cout << "Enter Month: ", cin >> this->_Month;
            cout << "Enter Year: ", cin >> this->_Year;
            cout << "\n";
            return *this;
        }

        clsDate IncreaseDateByXDays(int Days)
        {
            AddDaysToDate(*this, Days);
            return *this;
        }

        clsDate IncreaseDateByOneWeek()
        {
            for(int i=1; i<=7; i++)
            {
                this->IncreaseDateByOneDay();
            }
            return *this;
        }

        clsDate IncreaseDateByXWeeks(int Weeks)
        {
            for(int i=1; i<=Weeks; i++)
            {
                this->IncreaseDateByOneWeek();
            }
            return *this;
        }

        clsDate IncreaseDateByOneMonth()
        {
            if(this->_Month == 12)
            {
                this->_Month=1;
                this->_Year++;
            }
            else
            {
                this->_Month++;
            }

            short NumberOfDaysInCurrentMonth = NumberOfDayInMonth(this->_Year, this->_Month);

            if(this->_Day > NumberOfDaysInCurrentMonth)
            {
                this->_Day = NumberOfDaysInCurrentMonth;
            }
            return *this;
        }

        clsDate IncreaseDateByXMonths(int Months)
        {
            for(int i=1; i<=Months; i++)
            {
                this->IncreaseDateByOneMonth();
            }
            return *this;
        }

        clsDate IncreaseDateByOneYear()
        {
            this->_Year++;
            return *this;
        }

        clsDate IncreaseDateByXYears(int Years)
        {
            this->_Year += Years; 
            return *this;
        }

        clsDate IncreaseDateByOneDecade()
        {
            this->_Year += 10; 
            return *this;
        }

        clsDate IncreaseDateByXDecades(int Decades)
        {
            this->_Year += 10*Decades; 
            return *this;
        }
        
        clsDate IncreaseDateByXCentury()
        {
            this->_Year += 100; 
            return *this;
        }

        clsDate IncreaseDateByXMillennium()
        {
            this->_Year += 1000; 
            return *this;
        }

        clsDate DecreaseDateByOneDay()
        {
            if(this->_Day==1)
            {
                if(this->_Month==1)
                {
                    this->_Day--;
                    this->_Month = 12;
                    this->_Day = 31;
                    this->_Year--;
                }
                else
                {
                    this->_Month--;
                    this->_Day = NumberOfDayInMonth(this->_Year, this->_Month);
                }
                
            }
            else
            {
                this->_Day--;
            }
            return *this;
        }

        clsDate DecreaseDateByXDays(int Days)
        {
            for(int i=1; i<=Days; i++)
            {
                this->DecreaseDateByOneDay();
            }
            return *this;
        }

        clsDate DecreaseDateByOneWeek()
        {
            for(int i=1; i<=7; i++)
            {
                this->DecreaseDateByOneDay();
            }
            return *this;
        }
        
        clsDate DecreaseDateByXWeeks(int Weeks)
        {
            for(int i=1; i<=Weeks; i++)
            {
                this->DecreaseDateByOneWeek();
            }
            return *this;
        }

        clsDate DecreaseDateByOneMonth()
        {
            if(this->_Month==1)
            {
                this->_Month=12;
                this->_Year--;
            }
            else
            {
                this->_Month--;
            }
            return *this;
        }

        clsDate DecreaseDateByXMonths(int Months)
        {
            for(int i=1; i<=Months; i++)
            {
                this->DecreaseDateByOneMonth();
            }
            return *this;
        }
        
        clsDate DecreaseDateByOneYear()
        {
            this->_Year--;
            return *this;
        }

        clsDate DecreaseDateByXYears(int Years)
        {
            this->_Year -= Years;
            return *this;
        }

        clsDate DecreaseDateByOneDecade()
        {
            this->_Year -= 10;
            return *this;
        }

        clsDate DecreaseDateByXDecades(int Decades)
        {
            this->_Year -= 10*Decades;
            return *this;
        }

        clsDate DecreaseDateByOneCentury()
        {
            this->_Year -= 100;
            return *this;
        }

        clsDate DecreaseDateByOne()
        {
            this->_Year -= 100;
            return *this;
        }

        bool isItEndOfWeek()
        {
            return DayOfWeekOrder(this->_Year, this->_Month, this->_Day) == 6;
        }

        bool isItWeekEnd()
        {
            short WeekEndDays = DayOfWeekOrder(this->_Year, this->_Month, this->_Day);
            return WeekEndDays==6 || WeekEndDays == 5;
        }

        bool isItBusinessDay()
        {
            return !this->isItWeekEnd();
        }

        short DaysUntilTheEndOfWeek()
        {
            return 6-this->DayOfWeekOrder(this->_Year, this->_Month, this->_Day);
        }

        short DaysUntilTheEndOfMonth()
        {
            return NumberOfDayInMonth(this->_Year, this->_Month) - this->_Day;
        }
        
        short DaysUntilTheEndOfYear()
        {
            clsDate Date;
            Date._Day = 31;
            Date._Month = 12;
            Date._Year = this->_Year;
            return this->GetDifferenceInDays(Date);
        }

};
int main()
{
    system("cls");
    clsDate Date1;
    clsDate Date2;
    
    // cout << Date1.NumberByText(Date1.GetPositiveNumber("Enter any number: "));
    // cout << Date1.isLeapYear(Date1.GetPositiveNumber("Enter Any Year: ")) << endl;
    // cout << Date1.NumberOfDayInMonth(2000, 2) << endl;
    // cout << Date1.DayShortName(Date1.DayOfWeekOrder(5,3,2023));
    // Date1.PrintMonthCalendar(2000, 3);
    // Date1.PrintYearCalendar(2000);
    // cout << clsDate::DaysFromTheBeginningOfYear(2023, 3, 6) << endl;
    // Date1 = Date1.DateFromDayOrderInAYear(2023, 65);
    // cout << Date1.GetDay() << "/" << Date1.GetMonth() << "/" << Date1.GetYear() << endl;

    // Date1.SetDay(6);
    // Date1.SetMonth(3);
    // Date1.SetYear(2023);
    // cout << Date1.GetDay() << "/" << Date1.GetMonth() << "/" << Date1.GetYear() << endl;
    // Date1.AddDaysToDate(Date1, 60);
    // cout << Date1.GetDay() << "/" << Date1.GetMonth() << "/" << Date1.GetYear() << endl;
    

    Date1.SetDay(5);
    Date1.SetMonth(3);
    Date1.SetYear(2023);

    Date2.SetDay(15);
    Date2.SetMonth(3);
    Date2.SetYear(2023);

    // cout << clsDate::isDate1EqualDate2(Date1, Date2) << endl;
    // cout << clsDate::IsDate1BeforeDate2(Date1, Date2) << endl;
    // cout << Date1.isLastMonthInYear() << endl;
    // cout << Date1.isLastDayInMonth() << endl;
    // Date1.PrintDate();
    // Date1.IncreaseDateByOneDay();
    // cout << Date1.GetDifferenceInDays(Date2, true) << endl;
    // Date1.GetDate();
    // cout << Date1.GetDifferenceInDays(Date2, true) << endl;
    // Date1.PrintDate();
    // Date1.IncreaseDateByXDays(55);
    // Date1.PrintDate();
    // Date1.IncreaseDateByOneWeek();
    // Date1.PrintDate();
    // Date1.IncreaseDateByOneMonth();
    // Date1.PrintDate();
    // Date1.IncreaseDateByXMillennium();
    // Date1.PrintDate();
    // Date1.IncreaseDateByOneDecade();
    // Date1.PrintDate();
    // Date1.PrintDate();
    // Date1.DecreaseDateByXDecades(5);
    // Date1.PrintDate();
    // cout << Date1.DaysFromTheBeginningOfYear(2023,3 ,6 ) << endl;
    // Date1.PrintDate();
    // cout << Date1.GetDifferenceInDays(Date2, true) << endl;
    // cout << Date1.DaysUntilTheEndOfWeek() << endl;
    // Date1.PrintDate();
    // cout << Date1.DaysUntilTheEndOfMonth() << endl;
    // cout << Date1.DaysUntilTheEndOfYear() << endl;
    Date1.PrintDate();
    Date2.PrintDate();
    cout << Date1.GetDifferenceInDays(Date2) << endl;
    cout << clsDate::CalculateVacationDays(Date1, Date2);

    
}