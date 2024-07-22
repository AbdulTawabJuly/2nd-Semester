#include<iostream>
using namespace std;
class Polynomial
{
	friend ostream& operator<<(ostream&, const Polynomial&);

private:
	int totalTerms=0;
	int* coeff;
	int* exp; 
public:
	Polynomial(int t ,int c[],int ex[])
	{
		int TotalTerms = t;
		coeff = new int[TotalTerms];
		for (int i = 0; i < TotalTerms; i++)
		{
			coeff[i] = c[i];
		}
		exp = new int[TotalTerms];
		for (int i = 0; i < TotalTerms; i++)
		{
			exp[i] = ex[i];
		}
	}
	bool operator!();
	bool operator!=(Polynomial);
	//Polynomial operator+(const Polynomial&);
	Polynomial& operator++();
	Polynomial operator++(int);
};
ostream& operator<<(ostream& co, const Polynomial&Poly)
{
	
	for (int i = 0; i < Poly.totalTerms; i++)
	{
		co << Poly.coeff[i] << "x" << "^" << Poly.exp[i];
		if (i < Poly.totalTerms-1)
			co << "+";
	}
		return co;
}
bool Polynomial::operator!()
{
	return  (totalTerms == 1 && coeff[0] == 0 && exp[0] == 0);
}

bool Polynomial::operator!=(Polynomial rhs)
{
	if (totalTerms != rhs.totalTerms)
	{
		return false;
	}
	int count = 0;
	for (int i = 0; i < totalTerms; i++)
	{
		if ((coeff[i] == rhs.coeff[i]) && (exp[i] == rhs.exp[i]))
		{
			count++;
		}
	}
	if (count = totalTerms)
		return false;
	else
		return true;
}
//Polynomial Polynomial::operator+(const Polynomial &rhs)
//{
//	
//}
Polynomial &Polynomial ::operator++()
{
	for (int i = 0; i < totalTerms; i++)
	{
		coeff[i] = coeff[i] + 1;
	}
	return *this;
}

Polynomial Polynomial::operator++(int)
{
	Polynomial temp=*this;
	for (int i = 0; i < totalTerms; i++)
	{
		coeff[i] = coeff[i] + 1;
	}
	return temp;

}
int main()
{
	int coeff_P1[3] = { 1,2,5 }; 
	int exp_P1[3] = { 4,2,0 }; 
	int coeff_P2[2] = { 4,3 }; 
	int exp_P2[2] = { 6,2 }; 
	Polynomial P1(3, coeff_P1, exp_P1);
	Polynomial P2(2, coeff_P2, exp_P2);
	cout << "P1 = " << P1 << endl; 
	cout << "P2 = " << P2 << endl; 

	if (!P1)
	cout << "P1 is not zero" << endl;

	if (P1 != P2)
	cout << "P1 is Not Equal to P2" << endl;

	//Polynomial P3 = P1 + P2; //Adds P1 and P2 and saves result in
	//P3.You may consume extra space for resultant Polynomial in Add function

	//cout << "P3 = " << P3 << endl; //Prints P3 = 4x^6+x^4+5x^2+5
	//P3 = 2 + P1; //Assume P1 already has a constant term, add 2 in it.
	//cout << "P3 = " << P3 << endl;
	//Following is not included in Sec F’s lab. Sec E will do everything in
	//this manual.

	cout << ++P1 << endl;
	cout << P1 << endl;

	cout << P1++ << endl; 
	cout << P1 << endl;



	return 0;
}