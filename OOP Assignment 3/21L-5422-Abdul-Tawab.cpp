#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int ArrayLength(char* arr)
{
	int counter = 0, i = 0;
	while (arr[i] != '\0')
	{
		i++;
		counter++;
	}
	return counter;
}

void StringConcatenate(char*& string1, char* string2)
{
	int  length1 = 0, length2 = 0, k = 0, i = 0;
	length1 = ArrayLength(string1);
	length2 = ArrayLength(string2);
	int length3 = length1 + length2;
	for (i = length1; i < length3; i++)   // This Loop starts putting letters at the end of first string
	{
		string1[i] = string2[k];
		k++;

	}
	string1[i] = '\0';  // NULL Terminated
	cout << " First String: " << string1 << endl;
	cout << " Second String: " << string2 << endl;
}

char* CopyToken(char arr1[])
{
	int i = 0, counter = 0;
	while (arr1[i] != '\0')
	{
		counter++;
		i++;
	}
	char* Copied = new char[counter + 1]; // Counter +1 -> for storing NULL at the end
	i = 0;
	while (arr1[i] != '\0')
	{
		Copied[i] = arr1[i];
		i++;
	}

	Copied[i] = '\0';
	return Copied;
}

int WordCount(char* string)
{
	int i = 0; int wordcount = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')  // Counting the number of spaces
		{
			wordcount++;
		}
		i++;
	}
	return wordcount;
}

void PrintToken(char** Ptstr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << Ptstr[i] << endl;;
	}
	cout << endl;

}

char** InversePrintToken(char** Token, int size)
{
	int start = 0, end = size - 1;
	while (start <= end)
	{
		char* temp = Token[start];
		Token[start] = Token[end];
		Token[end] = temp;
		start++;
		end--;
	}
	return Token;
}

void InverseSentPrint(char** Ptstr, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		cout << Ptstr[i] << " ";
	}
	cout << endl;
}

char** StringToken(char* strTok, int& rows)
{
	int Length = ArrayLength(strTok);
	int space = WordCount(strTok);
	char** Token = new char* [space + 1];// (space+1)-> because words are 1 greator than space count
	int j = 0;
	while (rows < space + 1) // rows means i (while i < last dynmically allocated row)
	{
		int t = 0;
		char temp[50] = ""; // temporary array for storing words
		while ((strTok[j] != ' ') && (rows < space)) // j should be less than the last row
		{
			temp[t] = strTok[j];
			j++;
			t++;
		}
		if (rows == space) // because in last row loop will iterate till NULL not space
		{
			while (strTok[j] != '\0')
			{
				temp[t] = strTok[j];
				j++;
				t++;
			}
		}
		temp[t] = '\0';
		Token[rows] = CopyToken(temp);
		rows++;
		j++;
	}
	delete[]strTok;
	return Token;
}

int CompareString(char* cstring1, char* cstring2)//This Function Compare String Letters one by one 
{
	int counter1 = ArrayLength(cstring1);
	int counter2 = ArrayLength(cstring2);
	bool Compare = true;

	if (Compare == true)
	{
		for (int i = 0; i < counter1; i++)
		{

			if (cstring1[i] > cstring2[i])
			{
				return 1;
			}
			else if (cstring1[i] < cstring2[i])
			{
				return -1;
			}
			else if (cstring1[i] = cstring2[i])
			{
				Compare = true;
			}

		}
	}

	if (Compare == true)
	{
		return 0;
	}

}

char* Copy(char* arr1, char* arr2, int size)// This Function Copies one array into another
{
	int i = 0;
	while (i < size)
	{
		arr1[i] = arr2[i];
		i++;
	}
	arr1[i] = '\0';
	return arr1;
}


int Compare(char* cstring1, char* cstring2)
{
	int check = 0;
	int counter1 = ArrayLength(cstring1);
	bool Greatorthancheck = true, Lessthancheck = true;
	for (int i = 0; i < counter1; i++)
	{
		if (check == 0)
		{
			if (cstring1[i] > cstring2[i])
			{
				return 1;
			}
			else if (cstring1[i] < cstring2[i])
			{
				return -1;
			}
			else
			{
				check = 0;
			}
		}
	}
}

void BubbleSort(char*& str1, char*& str2)
{
	int check = Compare(str1, str2); // Sorts two arrays using sorting algorithm
	if (check == 1)
	{
		char* temp = str1;
		str1 = str2;
		str2 = temp;
	}

}

char** StudentFunctionality(ifstream& Read, int size)
{
	char** StudentsList = new char* [size];
	char* temp = new char[30]; // temporary array use to store names
	for (int i = 0; i < size; i++)
	{
		Read.getline(temp, 30);   // Reading names into temp array
		int Length = ArrayLength(temp);// Finding its length
		StudentsList[i] = new char[Length];// Creating dynamic memory equal to length
		Copy(StudentsList[i], temp, Length); // Copying temp on ith row of 2D array
	}
	delete[] temp;
	return StudentsList;

}

void Display(char** List, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		cout << List[i] << endl;
	}
}

int main()
{
	cout << "  \"STRING CONCATENATION\" " << endl << endl;
	char* StringCat1 = new char[100];
	char* StringCat2 = new char[100];
	ifstream Read("Data1.txt");
	cout << " First String: ";
	Read.getline(StringCat1, 100);
	cout << StringCat1 << endl;
	cout << " Second String: ";
	Read.getline(StringCat2, 100);
	cout << StringCat2 << endl;
	cout << " After Concatenation" << endl;
	StringConcatenate(StringCat1, StringCat2);
	cout << endl;
	system("pause");
	delete[]StringCat1;
	StringCat1 = NULL;
	delete[]StringCat2;
	StringCat2 = NULL;

	cout << endl << "  \"STRING TOKEN\" " << endl << endl;
	char* StringTok1 = new char[100];
	int Rows = 0;
	Read.getline(StringTok1, 100);
	cout << "String : " << StringTok1 << endl;
	cout << "Tokens of String: " << endl;
	char** FinalTok = StringToken(StringTok1, Rows);
	PrintToken(FinalTok, Rows);
	cout << endl;
	system("pause");
	delete[]FinalTok;
	FinalTok = NULL;

	cout << endl << "  \"INVERSE STRING TOKEN\" " << endl << endl;
	char* StrInvTok = new char[100];
	Rows = 0;
	Read.getline(StrInvTok, 100);
	cout << "String : " << StrInvTok << endl;
	cout << "Inverse Tokens of String: " << endl;
	char** FinalInvTok = StringToken(StrInvTok, Rows);
	char**FinalPrint=InversePrintToken(FinalInvTok, Rows);
	PrintToken(FinalPrint, Rows);
	cout << endl;
	system("pause");
	delete[]FinalInvTok;
	FinalInvTok = NULL;
	
	cout << endl << "  \"REVERSE SENTENCE\" " << endl << endl;
	char* RevSent = new char[100];
	Rows = 0;
	Read.getline(RevSent, 100);
	cout << "String : " << RevSent << endl;
	cout << "Inverse of String: " << endl;
	char** FinalRevSent = StringToken(RevSent, Rows);
	InverseSentPrint(FinalRevSent, Rows);
	cout << endl;
	system("pause");
	delete[]FinalRevSent;
	FinalRevSent = NULL;

	cout << endl << "  \"STRING COMPARISON\" " << endl << endl;
	char* Compstr1 = new char[50];
	cout << "String 1: ";
	cin.getline(Compstr1, 100);
	char* Compstr2 = new char[50];
	cout << "String 2: ";
	cin.getline(Compstr2, 100);
	cout << "if(String1>String2)-->1" << endl;
	cout << "if(String1=String2)-->0" << endl;
	cout << "if(String1<String2)-->-1" << endl;
	cout << CompareString(Compstr1, Compstr2) << endl;
	system("pause");
	delete[]Compstr1;
	Compstr1 = NULL;
	delete[]Compstr2;
	Compstr2 = NULL;

	cout << endl << endl << "  \"STUDENTS FUNCTIONALITY\" " << endl << endl;

	int size = 0;
	Read >> size;
	char** StudentList = StudentFunctionality(Read, size);
	cout << "List of Students Before Sorting" << endl;
	Display(StudentList, size);
	cout << endl;
	cout << "List of Students After Sorting" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			BubbleSort(StudentList[i], StudentList[j]);

		}
	}
	Display(StudentList, size);
	return 0;
}