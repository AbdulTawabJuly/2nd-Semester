//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//int ArrayLength(char* arr)
//{
//	int counter = 0, i = 0;
//	while (arr[i] != '\0')
//	{
//		i++;
//		counter++;
//	}
//	return counter;
//}
//char* Copy(char* arr1, char* arr2, int size)
//{
//	int i = 0;
//	while (i < size)
//	{
//		arr1[i] = arr2[i];
//		i++;
//	}
//	arr1[i] = '\0';
//	return arr1;
//}
//void Display(char** List, int rows)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		cout << List[i] << endl;
//	}
//}
//
//int FunctionalityCompare(char* cstring1, char* cstring2)
//{
//	int check=0;
//	int counter1 = ArrayLength(cstring1);
//	bool Greatorthancheck = true, Lessthancheck = true;
//	for (int i = 0; i < counter1; i++)
//	{
//		if (check == 0)
//		{
//			if (cstring1[i] > cstring2[i])
//			{
//				return 1;
//				//Lessthancheck = true;
//			}
//			else if (cstring1[i] < cstring2[i])
//			{
//				return -1;
//				//Lessthancheck = false;
//			}
//			else
//			{
//				check = 0;
//				//Lessthancheck = true;
//			}
//		}
//	}
//}
//void compareString(char*& str1, char*& str2)
//{
//	int check = FunctionalityCompare(str1, str2);
//	if (check == 1)
//	{
//		char* temp = str1;
//		str1 = str2;
//		str2 = temp;
//	}
//	
//}
//
//char** StudentFunctionality(ifstream& Read, int size)
//{
//	char** StudentsList = new char* [size];
//	char* buffer = new char[30];
//	for (int i = 0; i < size; i++)
//	{
//		Read.getline(buffer, 30);
//		int Length = ArrayLength(buffer);
//		StudentsList[i] = new char[Length];
//		Copy(StudentsList[i], buffer, Length);
//	}
//	delete[] buffer;
//	return StudentsList;
//
//}
//int main()
//{
//	ifstream Read("Data1.txt");
//	int size = 0;
//	Read >> size;
//	char** StudentList = StudentFunctionality(Read, size);
//	cout << "List of Students Before Sorting" << endl;
//	Display(StudentList, size);
//	cout << endl;
//	cout << "List of Students After Sorting" << endl;
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i+1; j < size ; j++)
//		{
//			compareString(StudentList[i], StudentList[j]);
//
//		}
//	}
//	Display(StudentList, size);
//
//   
//}