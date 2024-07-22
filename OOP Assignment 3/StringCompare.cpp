//#include<iostream>'
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
//int CompareString(char* cstring1, char* cstring2)
//{
//	int counter1 = ArrayLength(cstring1);
//	int counter2= ArrayLength(cstring2);
//	bool Compare = true;
//	
//	for (int i = 0; i < counter1; i++)
//	{
//		
//		if (cstring1[i] > cstring2[i])
//		{
//			Compare=true;
//		}
//		else if (cstring1[i] < cstring2[i])
//		{
//			return -1;
//		}
//		else if (cstring1[i] = cstring2[i])
//	    {
//			Compare = false;
//		}
//
//	}
//	if (Compare == true)
//	{
//		return 1;
//	}
//	else if(Compare == false)
//	{
//		return 0;
//	}
//
//}
//int main()
//{
//	char* Comp1 = new char[20];
//	char* Comp2 = new char[20];
//	cout << "Enter First Word: ";
//	cin.getline(Comp1, 20);
//	cout << "Enter Second Word: ";
//	cin.getline(Comp2, 20);
//	cout << "  Comparing String" << endl;
//	cout << " Cstring1 < Cstring2 -> -1" << endl;
//	cout << " Cstring1 = Cstring2 -> 0" << endl;
//	cout << " Cstring1 > Cstring2 -> 1" << endl;
//	cout<<CompareString(Comp1, Comp2);
//
//}