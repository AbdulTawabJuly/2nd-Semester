#include"ComplexNumber.h"
#include<cstdlib>
#include<iostream>
using namespace std;
ComplexNumber::ComplexNumber()
{
	real = new int(1);
	imaginary = new int(1);

}
ComplexNumber::ComplexNumber(int r = 0,int i=0)
{
	cout << "Constructor Called "<< endl;
	real = new int(r);
	imaginary = new int(i);
}

//void ComplexNumber::InputS()
//{
//
//	cout << "Enter Real Number: ";
//	cin >> real;
//	cout << "Enter Imaginary Number : ";
//	cin >> *imaginary;
//
//}

void ComplexNumber::Input()
{
	
	cout << "Enter Real Number: ";
	cin >> *real;
	cout << "Enter Imaginary Number : ";
	cin >> *imaginary;

}
void ComplexNumber::Output()
{

	if (*imaginary > 0)
		cout << " Complexx Number = " << *real << "+" << *imaginary << "i" << endl;;
	if (*imaginary < 0)
		cout << " Complex Number = " << *real << *imaginary << "i"<<endl;
}
ComplexNumber::~ComplexNumber()
{

	cout << "Destructor Called  " << endl;
	if (real != 0) delete real;
	if (imaginary != 0) delete imaginary;
}
float ComplexNumber::Magnitude()
{
	float mag = 0, root = 0;
	root = ((*real) * (*real)) + ((*imaginary) * (*imaginary));
	mag = sqrt(root);
	cout << "Magnitude of Complex Number =" << mag;
	return mag;
}
