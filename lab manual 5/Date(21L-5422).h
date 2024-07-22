#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	int Day;
	int Month;
	int Year;
	int increament;

public:
	Date();

	Date DateIncreament();
	int Compare(Date);
	void Print();
	void Input();
	Date(int, int, int);
	~Date();
};
