#include"Circle.h"
using namespace std;
Circle::Circle(int x, int y, float r) : center(x, y)
{
	radius = r;
	cout << "Circle() called" << endl;
}
Circle::~Circle()
{
	cout<<"~Circle() called" << endl;
}
void Circle::Print()
{
	cout << "Radius : " << radius << endl;
	center.Print();
}