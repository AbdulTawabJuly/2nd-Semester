#include<iostream>
using namespace std;
class Helper // Helper Class For Extra Helping Functions
{
public:
	static int StringLength(const char str[])
	{
		int i = 0, count = 0;
		while (str[i] != '\0')
		{
			i++;
			count++;
		}
		return count;
	}
	static void StringCopy(char*& dest, char*& str) {
		int length = StringLength(str);
		int i = 0;
		while (str[i] != '\0')
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = '\0';
	}
	static bool CompareString(char* arr1, const char arr2[])
	{
		int i = 0;
		while (arr2[i] != '\0')
		{
			if (arr1[i] != arr2[i])
			{
				return 0;
			}
			i++;
		}
		return true;
	}
};
class Set
{
private:
	int* data;
	int size;
public:
	Set(int* arr=0, int size1=0)
	{
		size = size1;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = arr[i];
		}
	}

	void Display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " , ";
		}
		cout << endl;
	}

	friend ostream& operator<<(ostream& obj, Set& abc)
	{
		for (int i = 0; i <abc.size; i++)
		{
			obj << abc.data[i]<<" , ";
		}
		cout << endl;
		return obj;
	}

	Set& operator=(Set&D)
	{
		size = D.size;
		for (int i = 0; i < size; i++)
		{
			data[i] = D.data[i];
		}
		return *this;
	}
	Set& operator+(Set& ab)
	{
		int newsize = size +ab.size;
		int *data2 = new int[newsize];
		for (int i =0; i <size; i++)
		{
			data2[i] =this->data[i];
		}
		for (int i = size; i < newsize; i++)
		{
			data2[i] = ab.data[i];
		}
		data = data2;
		size = newsize;
		return *this;
	}
};
int main()
{
	int a[] = { 1,2,3,4,5,6 };
	int b[] = { 1,5,6,4,3 };

	Set A(a, 6);
	Set B(b, 5);

	cout << A;
	cout << B;

	cout << "Addition " << endl;
	Set Add;
	Add = A+B;

	cout << Add;
	cout << endl;
}
