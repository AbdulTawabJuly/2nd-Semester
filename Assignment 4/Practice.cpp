//#include<iostream>
//#include<windows.h>
//#include<cstdlib>
//using namespace std;
//class ComplexNumber
//{
//private:
//	int real;
//	int imaginary;
//public:
//	
//	void Input(int);                                           // -
// 	void Output(int );                                         //  |       
//	bool IsEqual(ComplexNumber,ComplexNumber);                 //  |
//	ComplexNumber Conjugate(int );                             //  |
//	ComplexNumber Add(ComplexNumber,ComplexNumber);           //   |    --> Function Defination
//	ComplexNumber Subtract(ComplexNumber,ComplexNumber);      //   |
//	ComplexNumber Multiplication(ComplexNumber,ComplexNumber); //  |
//	float Magnitude(int ,int,float);                           //  |
//	                                                           // -
//
//};
//void ComplexNumber:: Input(int i)//Input Function
//{
//		cout << "Enter C" << i << endl;
//		cout << "Enter Real Number: ";
//		cin >> real;
//		cout << "Enter Imaginary Number : ";
//		cin >> imaginary;
//
//}
//void ComplexNumber::Output(int i)// Display Function
//{
//
//	if (imaginary > 0)
//		cout << " C" << i << " : " << real << "+" << imaginary << "i";
//	if (imaginary < 0)
//		cout << " C" << i << " : " << real << imaginary << "i";
//}
//bool ComplexNumber::IsEqual(ComplexNumber C1,ComplexNumber C2) // This Function Tells if two Complex Numbers are Equal or not
//{
//	if ((C1.real ==C2.real) && (imaginary == imaginary))
//		cout << "C1 is EQUAL to C2" << endl;
//	else
//		cout << "C1 is NOT EQUAL to C2" << endl;
//		
//	return 0 ;
//}
//ComplexNumber ComplexNumber::Conjugate(int i)// This Function Finds the Conjugate of a Complex Number
//{
//	cout << "Conjugate of C" << i << " :" << endl;
//	if (imaginary > 0)
//	{
//		cout << real << "-" << imaginary << "i" << endl;
//	}
//	else
//	{
//		imaginary = imaginary * -1;
//		cout << real << "+" << imaginary << "i" << endl;
//	}
//	return ComplexNumber();
//}
//
//ComplexNumber ComplexNumber::Add(ComplexNumber C1,ComplexNumber C2) // This Function Adds two Complex Numbers
//{
//	real = C1.real + C2.real;
//	imaginary = C1.imaginary + C2.imaginary;
//
//	return ComplexNumber();
//}
//
//ComplexNumber ComplexNumber::Subtract(ComplexNumber C1, ComplexNumber C2) // This Function Subtract two Complex Numbers
//{
//	real = C1.real - C2.real;
//	imaginary = C1.imaginary - C2.imaginary;
//
//	return ComplexNumber();
//}
//
//ComplexNumber ComplexNumber::Multiplication(ComplexNumber C1, ComplexNumber C2) // This Function Multiplies two Complex Number
//{
//	real = (C1.real * C2.real) - (C1.imaginary * C2.imaginary);
//	imaginary = (C1.real * C2.imaginary) + (C1.imaginary * C2.real);
//
//	return ComplexNumber();
//
//}
//
//float ComplexNumber::Magnitude(int i,int root,float mag ) // This Function finds the Magnitude
//{
//	root = (real * real) + (imaginary * imaginary);
//	mag = sqrt(root);
//	cout << "Magnitude of C" << i << " = "<<mag;
//	return mag;
//}
//
//int main()
//{
//	int root=0;
//	float mag = 0.0;
//	bool isEqual=true;
//	ComplexNumber C1{}, C2{},C3{};
//	C1.Input(1);
//	C1.Output(1);
//	cout << endl;
//	C2.Input(2);
//	C2.Output(2);
//	cout << endl;
//	C3.IsEqual(C1,C2);
//	cout << endl;
//	C1.Conjugate(1);
//	C2.Conjugate(2);
//	cout << endl;
//	C3.Add(C1, C2);
//	cout << "C1 + C2 -> ";
//	C3.Output(3);
//	cout << endl;
//	C3.Subtract(C1, C2);
//	cout << "C1 - C2 -> ";
//	C3.Output(3);
//	cout << endl;
//	C3.Multiplication(C1, C2);
//	cout << "C1 * C2 -> ";
//	C3.Output(3);
//	cout << endl;
//	C1.Magnitude(1,root,mag);
//	cout << endl;
//	C2.Magnitude(2, root,mag);
//	cout << endl;
//
//}