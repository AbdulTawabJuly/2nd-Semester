//#include<iostream>
//using namespace std;
//#include<fstream>
//void OutputStrings(char* string)
//{
//	int i = 0;
//	while (string[i] != '\0')
//	{
//		cout << string[i];
//	}
//}
//int StringLength(char* string)
//{
//	int i = 0;
//	while (string[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}
//int CompareStrings(char* string1, char* string2)
//{
//	int check=0;
//	int string1Length = StringLength(string1);
//	int string2Length = StringLength(string2);
//	int i = 0;
//	while (  i < string1Length)
//	{
//		if (check == 0)
//		{
//			if (string1[i] <string2[i])
//			{
//				return -1;
//			}
//			if (string1[i] > string2[i])
//			{
//				return 1;
//			}
//			if (string1[i] == string2[i])
//			{
//				i++;
//			}
//		}
//	}
//
//}
//void BubbleSort(char*& string1, char* &string2)
//{
//	int check = CompareStrings(string1, string2);
//	if (check == 1)
//	{
//		char* temp;
//		temp = string1;
//		string1 = string2;
//		string2 = temp;
//	}
//}
//
//void StringCopy(char* string1, char* string2,int length)
//{
//	int i = 0;
//    while(string2[i]!='\0')
//	{
//		string1[i] = string2[i];
//		i++;
//	}
//	string1[i] = 0;
//}
//void StringConcatenation(char*& string1, char* string2)
//{
//	int length1 = StringLength(string1);
//	int length2 = StringLength(string2);
//	int k = 0;
//	for (int i = length1 + 1; i < length1 + length2; i++)
//	{
//		string1[i] = string2[k];
//		k++;
//	}
//}
//int WordCount(char* string)
//{
//	int i = 0; int wordcount = 0;
//	while (string[i] != '\0')
//	{
//		if (string[i] == ' ')
//		{
//			 wordcount++;
//		}
//		i++;
//	}
//	wordcount++;
//	return wordcount;
//}
//char** StringTokens(char* string)
//{
//	int i = 0;
//	char* buffer = new char[30];
//	for (int j = 0; j < 30; j++)
//	{
//		buffer[j] = '\0';
//	}
//	int l=0;
//	int wordcount = WordCount(string);
//	char** StringTokens = new char* [wordcount];
//	while(string[i]!='\0')
//	{ 
//		buffer[l] = string[i];
//		if (string[i] == ' ')
//		{
//			
//			int length = StringLength(buffer);
//			int k = 0;
//			StringTokens[k] = new char[length];
//			StringCopy(StringTokens[k], buffer, length);
//			k++;
//		}
//		l = 0;
//		i++;
//	}
//	return StringTokens;
//}
//char** StudentsList(ifstream& fin, int size)
//{
//	char* buffer = new char[30];
//	char** StudentList = new char* [size];
//	for (int i = 0; i < size; i++)
//	{
//		fin.getline(buffer, 30);
//		int bufferLength=StringLength(buffer);
//		StudentList[i] = new char[bufferLength];
//		StringCopy(StudentList[i], buffer,bufferLength);
//
//	}
//	return StudentList;
//}
//int main()
//{
//	ifstream fin;
//	fin.open("Data.txt");
//	char* string1 = new char[30];
//	fin.getline(string1, 30);
//	int string1Length = StringLength(string1);
//	char* string2 = new char[30];
//	fin.getline(string2, 30);
//	char* string3 = new char[string1Length + 14];
//	StringCopy(string3, string1, string1Length);
//	
//	int size;
//	fin >> size;
//	char**StudentList=StudentsList(fin, size);
//	
//	for (int i = 0; i < size; i++)
//	{
//		cout << StudentList[i];
//		cout << endl;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i + 1; j < size; j++)
//		{
//			BubbleSort(StudentList[i], StudentList[j]);
//		}
//	}
//	cout << endl << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << StudentList[i];
//		cout << endl;
//	}
//	cout << endl << endl;
//	char** stringTokens = StringTokens(string1);
//	for (int i = 0; i < size; i++)
//	{
//		cout << stringTokens[i];
//		cout << endl;
//	}
//
//}