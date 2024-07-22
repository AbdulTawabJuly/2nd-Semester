#include<iostream>
using namespace std;

class MyString
{
	friend ostream& operator<<(ostream&, const MyString&);
	friend istream& operator>>(istream&, MyString&);

private:
	char* str;
	int length;	
	static int StrLen(char*);
	static char* GetStringFromBuffer(char*);
	void Concatenation(const MyString&);

public:
	
	MyString operator+(const MyString);
	MyString& operator=(const MyString&);
	bool operator<(MyString);	
	MyString();
	MyString(const MyString&);
	~MyString();
	bool operator!();
	char& operator[](int);
	char* operator()(int, int);
};

istream& operator>>(istream& in, MyString& tempStr) {

	char temp[50];
	cin.getline(temp, 50);
	tempStr.str = MyString::GetStringFromBuffer(temp);
	tempStr.length = MyString::StrLen(tempStr.str);

	return in;
}

ostream& operator<<(ostream& out, const MyString& tempStr) {

	out << tempStr.str;
	return out;
}


MyString::MyString() //Default Constructor
{
	length = 1;
	str = new char('\0');
}

MyString::MyString(const MyString& tempStr)  //Copy Constructor

{

	length = tempStr.length;
	str = new char[length + 1];

	for (int i = 0; i < length; i++)
		str[i] = tempStr.str[i];
	str[length] = '\0';
}

MyString::~MyString()  //Destrutor

{

	cout << "Destructor called" << endl;
	if (str)
		delete[] str;
}

int MyString::StrLen(char* tempStr)   //Finds String Length

{

	int count = 0;
	for (int i = 0; tempStr[i] != '\0'; i++)
		count++;

	return count;
}

char* MyString::GetStringFromBuffer(char* buffer) {

	int len = StrLen(buffer);
	char* newStr = new char[len + 1];

	for (int i = 0; i < len; i++)
		newStr[i] = buffer[i];
	newStr[len] = '\0';

	return newStr;
}

void MyString::Concatenation(const MyString& tempStr)
{

	char* MergedStr = new char[length + tempStr.length + 1];

	for (int i = 0; i < length; i++)
		MergedStr[i] = str[i];

	for (int i = 0; i < tempStr.length; i++)          //After storing first array store second right after it
		MergedStr[i + length] = tempStr.str[i];
	MergedStr[length + tempStr.length] = '\0';       //Place Null at the end

	delete[] str;
	str = MergedStr;

	length = length + tempStr.length;     //update length
}

MyString MyString::operator+(const MyString tempStr) // + operator
{

	MyString MergedString = *this;
	MergedString.Concatenation(tempStr);
	return MergedString;
}

MyString& MyString::operator=(const MyString& rhs)   // Assignment Operator
{

	if (&rhs != this) {        //Avoid self assignemnt

		length = rhs.length;
		delete[] str;
		str = new char[length];

		for (int i = 0; i < length; i++)
		{
			str[i] = rhs.str[i];
		}

		str[length] = '\0';
	}
	return *this;
}

bool MyString::operator<(MyString tempStr) //Compares two strings on basis of ascii value

{

	int count1 = 0, count2 = 0;

	for (int i = 0; i < length; i++)
	{
		count1 += str[i];
	}

	for (int i = 0; i < tempStr.length; i++)
	{
		count2 += tempStr.str[i];
	}

	return (count1 < count2);
}

bool MyString::operator!() {

	return (str[0] == '\0');       //returns true(0) if str is empty
}


char& MyString::operator[](int index)  //Return the char at the particular index
{

	if (index < 0 || index > length)
	{
		cout << "Index out of range" << endl;
	}

	return str[index];
}

char* MyString::operator()(int l, int k)  //Creates and returns sub string

{

	if (l < 0 || k < 0 || l > length || k > length)
	{
		cout << "Error Out of Range" << endl;
	}

	char* temp = new char[k + 1];

	for (int i = 0; i <= k; i++)
	{
		temp[i] = str[l + i];
	}
	temp[k] = '\0';

	return temp;
}

void main()
{
	MyString str1, str2, str3, str4;	

	if (!str1)
	{
		cout << "String 1 is Empty.\n";
		cout << "Str 1 = " << str1 << endl << endl << endl;
	}

	cout << "Enter String 1:\t";
	cin >> str1;


	cout << "Enter String 2:\t";
	cin >> str2;


	cout << "\n\n\nUser Entered:\n";
	cout << "String 1 = " << str1 << endl;
	cout << "String 2 = " << str2 << endl << endl << endl;

	cout << "Before str1 = str1; str1 = " << str1 << endl;
	str1 = str1;
	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;


	cout << "Before str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	str4 = str3 = str1 + str2;


	cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	cout << "\n\n\nEnter String 3:\t";
	cin >> str3;

	cout << "\n\n\nEnter String 4:\t";
	cin >> str4;


	cout << "\n\n\nstr3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	if (str3 < str4)
		cout << "String 3 is Less than String 4.\n";
	else
		cout << "String 3 is NOT Less than String 4.\n";

	MyString str5 = str1 + str2;
	cout << "\n\n\nStr5:\t" << str5 << endl;
	cout << "Str5[7]:\t" << str5[7] << endl;
	str5[7] = '$';

	cout << "\n\nStr5:\t" << str5 << endl;

	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;// Substring of lenght 10 starting from index 5 . Function Call str5.operator()(5,10) Let the returned MyString or char* leak

}
