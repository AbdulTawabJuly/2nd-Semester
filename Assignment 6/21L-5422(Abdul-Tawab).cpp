//#include<iostream>
//#include<cstring>
//using namespace std;
//class Helper
//{
//public:
//	static int StringLength(char * str)
//	{
//		int i = 0;
//		int count = 0;
//		while (str[i] != '\0')
//		{
//			count++;
//			i++;
//		}
//		return count;
//	}
//	static void StringCopy(char*& dest, char*& src) {
//		int i = 0;
//		while (src[i] != '\0')
//		{
//			dest[i] = src[i];
//			i++;
//		}
//		dest[i] = '\0';
//
//	}
//	static char* GetStringFromBuffer(char* str)
//	{
//		int length = StringLength(str);
//		char* dest = new char[length + 1];
//		StringCopy(dest, str);
//		return dest;
//
//	}
//	static void ConCatenate(char* s1, char* s2)
//	{
//		int l1 = StringLength(s1);
//		int l2 = StringLength(s2);
//		int k=0,i=0;
//		int l3 = l1 + l2;
//		for (i = l1; i < l3; i++)
//		{
//			s1[i] = s2[k];
//			k++;
//		}
//		s1[i] = '\0';
//	}
//	static bool Compare(char* s1, char* s2)
//	{
//		int counter1 = StringLength(s1);
//		int counter2 = StringLength(s2);
//		bool Compare = true;
//		for (int i = 0; i < counter1; i++)
//		{
//			if (s1[i] == s2[i])
//			{
//				Compare = true;
//			}
//			else if (s1[i] > s2[i])
//			{
//				return 0;
//			}
//			else if (s1[i] < s2[i])
//			{
//				return -1;
//			}	
//		}
//		return Compare;
//	}
//};
//class MyString
//{
//private:
//	char* str;
//	int length; 
//public:
//	MyString operator+(const MyString&);
//	MyString& operator=(const MyString&);
//	char& operator[](int k);
//	bool operator<(MyString);
//	char* operator()(int, int);
//	bool operator!();
//	MyString();
//	MyString(const MyString&);
//	MyString(char*);
//	~MyString();
//
//	friend ostream& operator<<(ostream&, const MyString&);
//	friend istream& operator >> (istream&, MyString&);
//};
//char& MyString::operator[](int k)// This Operator Returns the given index only 
//{
//	int count = Helper::StringLength(str);
//	if (k >= 0 || k < count)
//	{
//		return str[k];
//	}
//	else
//	{
//		cout << "Invalid Index" << endl;
//	}
//
//}
//bool MyString:: operator!() // This tells if the str is null or not
//{
//	return (length==0&&!str==0);
//}
//MyString& MyString::operator=(const MyString& rhs) // Assignment Operator
//{
//	if (&rhs != this)
//	{
//		/*if (str!=0)
//		{
//			delete[] str;
//	    }*/
//		char temp[40] ={0};
//		int count = Helper::StringLength(rhs.str);
//		for (int i = 0; i < count; i++)
//		{
//			temp[i] = rhs.str[i];
//		}
//		str = Helper::GetStringFromBuffer(temp);
//	}
//	return *this;
//}
//
//MyString::MyString(const MyString& temp) // Copy Constructor
//{
//
//	length = temp.length;
//	str = new char[length + 1];
//
//	for (int i = 0; i < length; i++)
//		str[i] = temp.str[i];
//	str[length] = '\0';
//}
//
//char* MyString::operator()(int l, int k) //i=5,k=10  // This operator returns a Substring of K length from i Index
//{
//
//		if (l < 0 || k < 0 || l > length || k > length)
//			throw exception("Index out of range");
//	
//		char* temp = new char[k + 1];
//	
//		for (int i = 0; i <= k; i++)         
//			temp[i] = str[l + i];
//		temp[k] = '\0';
//	
//		return temp;
//}
//bool MyString::operator<(MyString rhs) // This operator Compare two String using Helper Function
//{
//	bool check = (Helper::Compare(str, rhs.str));
//	return check;
//}
//MyString::MyString() // Default Constructor
//{
//	length = 0;
//	str = new char('\0');
//}
//MyString::MyString(char* s) // Constructor
//{
//	length = 0;
//	int l = Helper::StringLength(s);
//	str = new char[l+1];
//	int i = 0;
//	for ( ; i < l; i++)
//	{
//		str[i] = s[i];
//	}
//	str[i] = '\0';
//}
//MyString ::~MyString()  // Destructor
//{
//	cout << "Destructor called"<<endl;
//	if(str)
//	delete [] str; 
//}
//ostream& operator<<(ostream& out, const MyString& obj) // Input Operator
//{
//	out << obj.str;
//	return out;
//}
//istream& operator>>(istream& in, MyString& obj) // Output Operator
//{
//	cout << "Enter String: ";
//	in >> obj.str;
//	return in;
//}
//MyString MyString ::operator+(const MyString& rhs) // String Adition Operator
//{
//	int l1 = Helper::StringLength(str);
//	int l2 = Helper::StringLength(rhs.str);
//	char* strnew = new char[l1 + l2 + 1];
//	Helper::StringCopy(strnew, str);
//	Helper::ConCatenate(strnew, rhs.str);
//	MyString result(strnew);
//	result.length = l1 + l2;
//	return result;
//}
// int main()
// {
//	MyString str1, str2, str3, str4;
//		if (!str1)
//		{
//			cout << "String 1 is Empty.\n";
//			cout << "Str 1 = " << str1 << endl << endl << endl;
//		}
//
//	cout << "Enter String 1:\t";
//	cin >> str1;
//	cout << "Enter String 2:\t";
//	cin >> str2;
//
//	cout << "\n\n\nUser Entered:\n";
//	cout << "String 1 = " << str1 << endl;
//	cout << "String 2 = " << str2 << endl << endl << endl;
//	
//	cout << "Before str1 = str1; str1 = " << str1 << endl;
//	str1 = str1;
//	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;
//	cout << "Before str4 = str3 = str1+str2\n";
//	cout << "str1 = " << str1 << endl;
//	cout << "str2 = " << str2 << endl;
//	cout << "str3 = " << str3 << endl;
//	cout << "str4 = " << str4 << endl;
//	
//	cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
//	str4 = str3 = str1 + str2;
//	cout << "str1 = " << str1 << endl;
//	cout << "str2 = " << str2 << endl;
//	cout << "str3 = " << str3 << endl;
//	cout << "str4 = " << str4 << endl;
//	cout << "\n\n\nEnter String 3:\t";
//	cin >> str3;
//	cout << "\n\n\nEnter String 4:\t";
//	cin >> str4;
//	cout << "\n\n\nstr3 = " << str3 << endl;
//	cout << "str4 = " << str4 << endl;
//	if (str3 < str4)
//		cout << "String 3 is Less than String 4.\n";
//	else
//		cout << "String 3 is NOT Less than String 4.\n";
//	MyString str5 = str1 + str2;
//	cout << "\n\n\nStr5:\t" << str5 << endl;
//	cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7).
//	str5[7] = '$';
//	cout << "\n\nStr5:\t" << str5 << endl;
//	cout << "\n\n\nstr5(5, 10):\t" << str5(3, 7) << endl;// Substring of lenght 10 starting from index 5.Function Call str5.operator()(5, 10) Let the returned MyString or char* leak
//	
//	return 0;
// }
