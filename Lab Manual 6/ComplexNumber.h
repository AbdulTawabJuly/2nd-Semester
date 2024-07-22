#pragma once
#include<iostream>
using namespace std;
class ComplexNumber
{
private:
	//int real = 0;
	//int imaginary = 0;
	int* real=0; 
	int* imaginary=0; 
public:
	ComplexNumber();

	ComplexNumber(int, int); 

	~ComplexNumber();


	//void InputS();

	void Input(); 

	void Output(); 

	float Magnitude(); 
};
