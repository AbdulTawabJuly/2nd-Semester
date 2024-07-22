#include<iostream>
using namespace std;
class Polynomial
{
	friend ostream& operator<<(ostream&, const Polynomial&);

private:
	int totalTerms = 0;
	int* coeff;
	int* exp;
public:
	Polynomial(int t, int c[], int ex[])
	{
		totalTerms = t;
		coeff = new int[totalTerms];
		for (int i = 0; i < totalTerms; i++)
		{
			coeff[i] = c[i];
		}
		exp = new int[totalTerms];
		for (int i = 0; i < totalTerms; i++)
		{
			exp[i] = ex[i];
		}
	}
	bool operator!();
	bool operator!=(Polynomial);
	Polynomial operator+(const Polynomial&);
	Polynomial& operator++();
	Polynomial operator++(int);
};
ostream& operator<<(ostream& co, const Polynomial& Poly)
{

	for (int i = 0; i < Poly.totalTerms; i++)
	{
		co << Poly.coeff[i] << "x" << "^" << Poly.exp[i]<<" ";
		if (i < Poly.totalTerms - 1)
		{
			cout << "+";
		}
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
Polynomial Polynomial::operator+(const Polynomial& rhs)
{
	int noofcommonterms = 0;
	int c[10] = { 0 };
	int ex[10] = { 0 };
	int check = 0;
	for (int i = 0; i < totalTerms; i++)
	{
		for (int j = 0; j < rhs.totalTerms; j++)
		{
			if (exp[i] == rhs.exp[i])
			{
				noofcommonterms++;
			}
		}
	}
	Polynomial P3(totalTerms + rhs.totalTerms, c, ex);
	for (int i = 0; i < totalTerms; i++)
	{
		P3.coeff[i] = coeff[i];
		P3.exp[i] = exp[i];
	}
	int k = 0;
	for (int j = totalTerms; j < totalTerms + rhs.totalTerms; j++)
	{
		
		P3.coeff[j] = rhs.coeff[k];
		P3.exp[j] = rhs.exp[k];
		k++;
	}
	int length = totalTerms + rhs.totalTerms;
	int tempc = 0,tempe=0;
	for (int m = 0; m < length; m++)
	{
		for (int n = m+1; n < length; n++)
		{
			if (P3.exp[m] < P3.exp[n])
			{
				tempe = P3.exp[m];
				tempc = P3.coeff[m];

				P3.exp[m]=P3.exp[n];
				P3.coeff[m] = P3.coeff[n];

				P3.exp[n] = tempe;
				P3.coeff[n] = tempc;
			}
		}
	}
	int q = 0;
	for (int a = 0; a < length; a++)
	{
		for (int b = a + 1; b < length; b++)
		{
			
			if (P3.exp[a] == P3.exp[b])
			{
				
				for (q = a; q < length; q++)
				{
					if (P3.exp[q] == P3.exp[q + 1])
					{
						P3.exp[q] = P3.exp[q + 1];
						P3.coeff[q] = P3.coeff[q] + P3.coeff[q + 1];

					}
				}
				length--;
				b--;
			}
		}
	}
	 
	return P3;
}
Polynomial& Polynomial ::operator++()
{
	for (int i = 0; i < totalTerms; i++)
	{
		coeff[i] = coeff[i] + 1;
	}
	return *this;
}

Polynomial Polynomial::operator++(int)
{
	Polynomial temp = *this;
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
	cout << "P1  =  " << P1 << endl << endl;
	cout << "P2  =  " << P2 << endl << endl;

	if (!P1)
		cout << "P1 is Not zero" << endl << endl;

	if (P1 != P2)
		cout << "P1 is Not Equal to P2" << endl << endl;

	Polynomial P3 = P1 + P2; 

	cout << "P3=P1+P2" << endl;
	cout << "P3 = " << P3 << endl<<endl; 
	cout << "Pre Incrementing P1 " << endl;
	++P1;
	cout << P1 << endl<<endl;
	cout << "Pre Incrementing P2 " << endl;
	P2++;
	cout << P2 << endl;



	return 0;
}