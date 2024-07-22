#include<iostream>
#include"ComplexNumber.h"
using namespace std;
int main()
{
	// --> 2
	/*ComplexNumber c1(0,0);
	c1.Input();
	c1.Output();*/

	//-->3
	
	//ComplexNumber* cptr = nullptr;

	//--> 4
	
	/*ComplexNumber c2(3, 5);
	c2.Input();
	cptr = &c2;
	cptr->Output();*/

	//-->5
	ComplexNumber Arr[5];
	for (int i = 0; i < 5; i++)
	{
		Arr[i].Input();
	}
	for (int i = 0; i < 5; i++)
	{
		Arr[i].Output();
		cout << endl;
		Arr[i].Magnitude();
		cout << endl;
	}

	//-->6
	/*int size=0;
	cout << "Enter Size of the Dynamic Array : ";
	cin >> size;
	ComplexNumber* Aptr = new ComplexNumber[size];
	for (int i = 0; i < size; i++)
	{
		Aptr[i].Input();
	}
	for (int i = 0; i < size; i++)
	{
		Aptr[i].Output();
		cout<<endl;
		Aptr[i].Magnitude();
		cout << endl;
	}

	delete[]Aptr;
	Aptr = NULL;*/
}