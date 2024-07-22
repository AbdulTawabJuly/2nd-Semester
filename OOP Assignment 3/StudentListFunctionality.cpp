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
//char* Copy(char *arr1,char*arr2,int size)
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
//		cout << List[i]<<endl;
//	}
//}
//char** BubbleSort(char** List, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i + 1; j < size; j++)
//		{
//			if(strcmp(List[i],List[j])>0)
//			{
//				char* temp = List[i];
//				List[i] = List[j];
//				List[j] = temp;
//			}
//		}
//	}
//	return List;
//}
//char** StudentFunctionality(ifstream& Read,int size)
//{
//	char** StudentsList = new char*[size];
//	char *buffer=new char[30];
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
//	int size=0;
//	Read >> size;
//	char** StudentList = StudentFunctionality(Read,size);
//	cout << " List of Students Before Sorting" << endl;
//	Display(StudentList, size);
//	cout << endl;
//	cout << " List of Students After Sorting" << endl;
//	BubbleSort(StudentList, size);
//	Display(StudentList, size);
//}