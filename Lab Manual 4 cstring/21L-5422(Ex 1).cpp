//#include<iostream>
//using namespace std;
//int main()
//{
//	char charArray[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd' };
//	cout << charArray << endl;//garbage as it is not null terminated
// in the next question array is null terminated
//}

//#include<iostream>
//using namespace std;
//int StringLength(char* str)
//{
//	int counter = 0;
//	while (*str != '\0')
//	{
//		counter++;
//		str++;
//	}
//	return counter;
//}
//int main()
//{
//	char charArray[] = { 'a', 'c', 'b' ,'\0' };
//	char* str = charArray;
//	cout << "Size of char Array is " << StringLength(str);
//	system("pause");
//
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	char myStr1[5] = "Helo";
//	cout << "Initial String:\t" << myStr1 << endl;
//	int len = 0;
//	for (; myStr1[len] != '\0'; len++);
//	cout << "Lenght of myStr1:\t" << len << endl << endl << endl;
//	cout << "Enter another string of size 4 :";
//	cin >> myStr1;
//	cout << "String entered by the user is:" << myStr1 << endl;
//	for (len = 0; myStr1[len] != '\0'; len++);
//	cout << "Lenght of myStr1:\t" << len << endl << endl << endl;
//	cout << "Enter another string of size 5 or Greater :";
//	cin >> myStr1;
//	cout << "String entered by the user is:" << myStr1 << endl;
//	for (len = 0; myStr1[len] != '\0'; len++);
//	cout << "Lenght of myStr1:\t" << len << endl << endl << endl;
//	cout << "Program is going to terminate.\n";
//	//program crashes because when 4 characters area entered the array is null terminated and length is calculated null 
//	//but when 5 characters are entered no space for null so program breaks
//}