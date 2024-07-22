#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
void Input(ifstream& file1, int* Input, int size)  //This Function Reads Data From File
{
	for (int* iptr = Input; iptr < (Input + size); iptr++)
	{
		file1 >> *iptr;
	}
}
void Output(int* array, int size)  // This Function Prints Output 
{
	for (int* iptr = array; iptr < (array + size); iptr++)
	{
		cout << *iptr << " ";
	}
}
void BubbleSort(int* Input, int size, int counter) // This Function Sorts the Array According to BubbleSort Mechanism
{
	counter = 1;  // Counter is for Checking only the Sorted Array (In the first go it will check all the array, in the second go it will check all the array except the last element and so on ) 
	while (counter < size) //Comparing Counter with Size ( Counter should be less than Size) 
	{
		for (int i = 0; i < size - counter; i++)
		{
			if (*(Input + i) > *(Input + (i + 1))) //If 1st element is greator than 2nd element it will swap the two
			{
				int swap = *(Input + i);
				*(Input + i) = *(Input + (i + 1));
				*(Input + (i + 1)) = swap;
			}
		}
		counter++; // Increasing Counter at the end of every loop
	}
	Output(Input, size); // Printing the Sorted Array
}
void Merging(int* arr1, int* arr2, int* arr3, int Size1, int Size2, int Size3)  // This Function Merges Two Arrays Without Using Any Sorting Mechanism
{

	int Index1 = 0, Index2 = 0;
	bool Compare1 = true, Compare2 = true;

	for (int Index3 = 0; Index3 < Size3; Index3++) // This Loop is for the 3rd Array ( Resultant Array ) 
	{
		if (Compare1 == true && Compare2 == true)  // If both the checks are true than keep comparing
		{
			if (*(arr1 + Index1) < *(arr2 + Index2)) // Comparing elements of array1 and array2 
			{
				*(arr3 + Index3) = *(arr1 + Index1); // if element of array 1 is small place it in array 3
				Index1++; // keep incrementing Index 1 so that element of array 1 wont repeat
				if (Index1 == Size1) // if the index reaches the size than the check will become falls 
				{
					Compare1 = false;
				}
			}
			else
			{
				*(arr3 + Index3) = *(arr2 + Index2);// Otherwise place element of array 2 in array 3
				Index2++;
				if (Index2 == Size2)
				{
					Compare2 = false;
				}
			}
		}
		else
		{
			if (Compare1 == false) // if check 1 is false that means array one is completed than place element of array 2 in array 3 
			{
				*(arr3 + Index3) = *(arr2 + Index2);
				Index2++;
			}
			else //// if check 2 is false that means array two is completed than place element of array 1 in array 3 
			{
				*(arr3 + Index3) = *(arr1 + Index1);
				Index1++;
			}
		}
	}
	cout << "Size of Array 1: " << Size1 << endl;
	cout << "Array 1: ";
	Output(arr1, Size1);
	cout << endl << "Size of Array 2: " << Size2 << endl;
	cout << "Array 2: ";
	Output(arr2, Size2);
	cout << endl << "Size of Merged Array : " << Size3 << endl;
	cout << "Merged Array is: ";
	Output(arr3, Size3);
	cout << endl;
}
int main()
{
	cout << endl << "  Question No 1 \"BUBBLE SORT\"" << endl << endl;

	int size1Q1 = 0, size2Q1 = 0, sizeQ1 = 0, counter = 1;
	ifstream file("Data1.txt");
	file >> size1Q1;
	//Test Case 1
	cout << "Test Case 1" << endl;
	if (size1Q1 > 0)     // If Size is Greator than 0 only then it will create the Array 
	{
		int* InputData1Q1 = new int[size1Q1];    // Allocating Memory
		cout << "Size of the array is: " << size1Q1 << endl;
		cout << "Elements of Array before Sorting: ";
		Input(file, InputData1Q1, size1Q1);
		Output(InputData1Q1, size1Q1);
		cout << endl;
		cout << "Elements of Aray after Sorting: ";
		BubbleSort(InputData1Q1, size1Q1, counter);
		cout << endl << endl;

		delete[]InputData1Q1;  // Delocating Memory in the heap
		InputData1Q1 = NULL;
	}
	else  // if Size is less than 0 then it will show error message
	{
		cout << "Error: Size of the Array should be greator than 0" << endl;
		return 0;
	}

	file >> size2Q1;
	//Test Case 2
	cout << "Test Case 2" << endl;
	if (size2Q1 > 0)
	{
		int* InputData2Q1 = new int[size2Q1];   // Allocating Memory
		cout << "Size of the array is: " << size2Q1 << endl;
		cout << "Elements of Array before Sorting: ";
		Input(file, InputData2Q1, size2Q1);
		Output(InputData2Q1, size2Q1);
		cout << endl;
		cout << "Elements of Aray after Sorting: ";
		BubbleSort(InputData2Q1, size2Q1, counter);
		cout << endl << endl;

		delete[]InputData2Q1;  // Delocating Memory in the heap
		InputData2Q1 = NULL;
	}
	else
	{
		cout << "Error: Size of the Array should be greator than 0" << endl;
		return 0;
	}
	//Test Case 3
	file >> sizeQ1;
	cout << "Test Case 3" << endl;
	if (sizeQ1 > 0)
	{
		int* InputData3Q1 = new int[sizeQ1];  // Allocating Memory
		cout << "Size of the array is: " << sizeQ1 << endl;
		cout << "Elements of Array before Sorting: ";
		Input(file, InputData3Q1, sizeQ1);
		Output(InputData3Q1, sizeQ1);
		cout << endl;
		cout << "Elements of Aray after Sorting: ";
		BubbleSort(InputData3Q1, sizeQ1, counter);
		cout << endl << endl;

		delete[]InputData3Q1;  // Delocating Memory in the heap
		InputData3Q1 = NULL;
	}
	else
	{
		cout << "Error: Size of the Array should be greator than 0" << endl;

	}
	cout << endl << endl;
	cout << "  Question No 2\"MERGING ARRAYS\"" << endl << endl;

	int size1Q2 = 0, size2Q2 = 0, size3Q2 = 0;

	ifstream Read("Data2.txt");
	//Test Case 1
	cout << endl << "Test Case 1" << endl;
	Read >> size1Q2;
	if (size1Q2 > 0)   // If Size is Greator than 0 only then it will create the Array 
	{
		int* Arr1Q2 = new int[size1Q2];   //Allocating Memory
		Input(Read, Arr1Q2, size1Q2);
		Read >> size2Q2;
		if (size2Q2 > 0)
		{
			int* Arr2Q2 = new int[size2Q2]; //Allocating Memory
			Input(Read, Arr2Q2, size2Q2);
			size3Q2 = size1Q2 + size2Q2;
			int* Arr3Q2 = new int[size3Q2];  //Allocating Memory
			Merging(Arr1Q2, Arr2Q2, Arr3Q2, size1Q2, size2Q2, size3Q2);
			delete[]Arr1Q2;  // Delocating Memory in the heap
			Arr1Q2 = NULL;
			delete[]Arr2Q2;
			Arr2Q2 = NULL;
			delete[]Arr3Q2;
			Arr3Q2 = NULL;
		}
		else   // if Size is less than 0 then it will show error message
		{
			cout << "Error:Size of Array 2 is Less than 0. Which is Invalid" << endl;
		}
	}
	else
	{
		cout << "Error:Size of Array 1 is Less than 0. Which is Invalid" << endl;
	}

	//Test Case 2
	cout << endl << "Test Case 2" << endl;
	size1Q2 = 0, size2Q2 = 0, size3Q2 = 0;
	Read >> size1Q2;
	if (size1Q2 > 0)  // If Size is Greator than 0 only then it will create the Array 
	{
		int* Arr4Q2 = new int[size1Q2];   //Allocating Memory
		Input(Read, Arr4Q2, size1Q2);
		Read >> size2Q2;
		if (size2Q2 > 0)
		{
			int* Arr5Q2 = new int[size2Q2];
			Input(Read, Arr5Q2, size2Q2);
			size3Q2 = size1Q2 + size2Q2;
			int* Arr6Q2 = new int[size3Q2];
			Merging(Arr4Q2, Arr5Q2, Arr6Q2, size1Q2, size2Q2, size3Q2);
			delete[]Arr4Q2;
			Arr4Q2 = NULL;  // Delocating Memory in the heap
			delete[]Arr5Q2;
			Arr5Q2 = NULL;
			delete[]Arr6Q2;
			Arr6Q2 = NULL;
		}
		else  // if Size is less than 0 then it will show error message
		{
			cout << "Error:Size of Array 2 is Less than 0. Which is Invalid" << endl;
		}
	}
	else
	{
		cout << "Error:Size of Array 1 is Less than 0. Which is Invalid" << endl;
	}

	//Test Case 3
	cout << endl << "Test Case 3" << endl;
	size1Q2 = 0, size2Q2 = 0;
	Read >> size1Q2;
	if (size1Q2 > 0)  // If Size is Greator than 0 only then it will create the Array 
	{
		int* Arr7Q2 = new int[size1Q2];  //Allocating Memory
		Input(Read, Arr7Q2, size1Q2);
		Read >> size2Q2;
		if (size2Q2 > 0)
		{
			int* Arr8Q2 = new int[size2Q2];
			Input(Read, Arr8Q2, size2Q2);
			size3Q2 = size1Q2 + size2Q2;
			int* Arr9Q2 = new int[size3Q2];
			Merging(Arr7Q2, Arr8Q2, Arr9Q2, size1Q2, size2Q2, size3Q2);
			delete[]Arr7Q2;  // Delocating Memory in the heap
			Arr7Q2 = NULL;
			delete[]Arr8Q2;
			Arr8Q2 = NULL;
			delete[]Arr9Q2;
			Arr9Q2 = NULL;
		}
		else    // if Size is less than 0 then it will show error message
		{
			cout << "Error:Size of Array 2 is Less than 0. Which is Invalid" << endl;
		}
	}
	else
	{
		cout << "Error:Size of Array 1 is Less than 0. Which is Invalid" << endl;
	}


	system("pause");
	return 0;
}