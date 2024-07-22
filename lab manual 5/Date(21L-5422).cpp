#include"Date(21L-5422).h"
using namespace std;
Date::Date()
{
	Day = 01;
	Month = 01;
	Year = 1926;
}
void Date::Input()
{
	cout << "Enter Date: ";
	cin >> Day;
	if (Day < 1 || Day>31)
	{
		cout << "Invalid Date.Enter Again: ";
		cin >> Day;
	}
	cout << "Enter Month: ";
	cin >> Month;
	if (Month < 1|| Month > 12)
	{
		cout << "Invalid Month.Enter Again: ";
		cin >> Month;
	}
	cout << "Enter Year: ";
	cin >> Year;
	if (Year < 1)
	{
		cout << "Invalid Year.Enter Again: ";
		cin >> Year;
	}
}
void Date::Print()
{
	cout << Day << "-";
	cout << Month << "-";
	cout << Year ;
	cout << endl;
}
Date::Date(int date, int mon, int year)
{
	Day = date;
	Month = mon;
	Year = year;
}
Date Date::DateIncreament()
{
	if (Month < 13)
	{
		Date increament(Day, Month + 1, Year);
		return  increament;
	}
	else
	{
		cout << "Invalid Month" << endl;
	}
}
int Date::Compare(Date obj)
{
	if (Day > obj.Day)
	{
		return 1;
	}
	if (Day < obj.Day)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
Date::~Date()
{
	
}











