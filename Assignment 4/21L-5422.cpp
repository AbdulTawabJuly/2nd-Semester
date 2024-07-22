#include<iostream>
using namespace std;
class ComplexNumber
{
private:
	int real;
	int imaginary;
public:
	ComplexNumber(int, int); //with default arguments     
	~ComplexNumber(); //Does Nothing.                      
	void Input();                                     
	void Output();                                    
	bool IsEqual(ComplexNumber);                        
	ComplexNumber Conjugate();                        
	ComplexNumber Add(ComplexNumber);                   
	ComplexNumber Subtract(ComplexNumber);               
	ComplexNumber Multiplication(ComplexNumber);       
	float Magnitude();                                
};

ComplexNumber::ComplexNumber(int r=0, int i=0)// Default Constructor
{
	real = r;
	imaginary = i;
}
ComplexNumber::~ComplexNumber() //Destructor
{
	//DOes nothimg
}
void ComplexNumber::Input()
{
	cout << "Enter Real Part: ";
	cin >> real;
	cout << "Enter Imaginary Part: ";
	cin >> imaginary;
}
void ComplexNumber::Output()
{
	if(imaginary>=0)
		cout<<real << " + " << imaginary << "i" << endl;
	else
		cout << real  << imaginary << "i" << endl;
}
bool ComplexNumber::IsEqual(ComplexNumber rhs) // This Function Tells if two Complex Numbers are Equal or not
{
	if ((real == rhs.real) && (imaginary == rhs.imaginary))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ComplexNumber ComplexNumber::Conjugate()// This Function Finds the Conjugate of a Complex Number
{
	// Changing Signs if Imaginary is less 0
	
		ComplexNumber Conjugate(real, imaginary*-1);
		return Conjugate;
	
}

ComplexNumber ComplexNumber::Add(ComplexNumber C1) // This Function Adds two Complex Numbers
{
	ComplexNumber result(real + C1.real, imaginary + C1.imaginary);
	return result;
}

ComplexNumber ComplexNumber::Subtract(ComplexNumber C1) // This Function Subtract two Complex Numbers
{
	ComplexNumber result(real - C1.real, imaginary - C1.imaginary);
	return result;
}

ComplexNumber ComplexNumber::Multiplication(ComplexNumber C1) // This Function Multiplies two Complex Number
{
	ComplexNumber result((real * C1.real) - (imaginary * C1.imaginary), (real * C1.imaginary) + (imaginary * C1.real));
	return result;
}

float ComplexNumber::Magnitude() // This Function finds the Magnitude
{
	float magnitude = sqrt((real * real) + (imaginary * imaginary));
	return magnitude;
}

int main()
{
	ComplexNumber C1, C2, C3,C4;
	cout << "Enter C1: " << endl;
	C1.Input();
	cout << endl;
	cout << "Enter C2: " << endl;
	C2.Input();
	cout << endl;
	cout << "C1: ";
	C1.Output();
	cout << "C2: ";
	C2.Output();
	cout << endl;
	if (C1.IsEqual(C2))
	{
		cout << "C1 is Equal to C2" << endl;
	}
	else
	{
		cout << "C1 is not Equal to C2" << endl;
	}
	cout << endl;
	C3=C1.Conjugate();
	cout << "Conjugate of C1 :";
	C3.Output();
	cout << endl;
	C3=C2.Conjugate();
	cout << "Conjugate of C2 :";
	C3.Output();
	cout << endl;
	C3=C1.Add(C2);
	cout << "C1 + C2 = ";
	C3.Output();
	cout << endl;
	C3=C1.Subtract(C2);
	cout << "C1 - C2 -> ";
	C3.Output();
	cout << endl;
	C4=C1.Multiplication(C2);
	cout << "C1 * C2 -> ";
	C4.Output();
	cout << endl;
	cout << "Magnitude of Complex Number = " ;
	cout << C1.Magnitude() << endl;
	cout << "Magnitude of Complex Number = ";
	cout<<C2.Magnitude()<<endl;
	cout << endl;

}