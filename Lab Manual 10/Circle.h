#pragma once
#include"Point.h"
#include<iostream>
using namespace std;
class Circle
{
private:
	Point center;
	float radius;
public:

	Circle(int, int, float);
	~Circle();
	void Print();
};
