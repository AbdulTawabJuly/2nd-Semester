#include"Point.h"
using namespace std;
Point::Point(int a,int b)
{
	cout << "Point() Called" << endl;
	x = a;
	y = b;
}
void Point::Print()
{
	cout << "(" << x << "," << y << ")" << endl;
}
Point::~Point()
{
	cout << "~Point() called" << endl;
}
