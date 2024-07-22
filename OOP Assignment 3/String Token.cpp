//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
//
//void TokenPrint(char** stringToken)
//{
//	for (int i = 0; i < 1; i++)
//	{
//		for (int j = i; j != ' '; j++)		//terminate with null and make ur c string hold null first
//		{
//			if (stringToken[i][j] != ' ')
//				cout << stringToken[i][j];
//			else if (stringToken[i][j] == ' ')
//				cout << endl;
//		}
//	}
//}
// char** StringTokens(char* string1)
//{
//	char** stringToken = new char* [20];
//	for (int i = 0; i < 20; i++)
//	{
//
//		stringToken[i] = new char[20];
//	}
//
//
//	for (int i = 0; i < 20; i++)
//	{
//		for (int j = i; j != ' '; j++)
//		{
//			stringToken[i][j] = string1[j];
//		}
//	}
//	return stringToken;
//	// DeallocateMemory(stringToken);
//}
// int main()
// {
//	 cout << "  Testing String Tokens" << endl << endl;
//	 cout << "Tokens of String 1 are as follows: " << endl;
//	 char* string1 = new char[30];
//	 cin.getline(string1, 30);
//	 char **stringFinal = StringTokens(string1);
//	 TokenPrint(stringFinal);			//no extra bits used
//
//	 cout << endl << endl;
// }