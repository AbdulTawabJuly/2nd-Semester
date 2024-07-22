//#include<iostream>
//#include<string>
//using namespace std;
//int StringLength(string a)
//{
//	int counter = 0;
//	for (int i = 0; a[i] != '\0'; i++)\
//	{
//		counter++;
//	}
//	return counter;
//}
//char* copy(char* arr1, char *arr2, int length)
//{
//	int i = 0;
//	while (i < length)
//	{
//		arr1[i] = arr2[i];
//		i++;
//	}
//	arr1[i] = '10';
//}
//char** StringTokens(string TokenS)
//{
//	char* temp = new char[25];
//	int i = 0;
//	int length = StringLength(TokenS);
//	int spacecount = 0;
//	for (int i = 0; i <= length; i++)
//	{
//		if (TokenS[i] == ' ')
//			spacecount++;
//	}
//	char** Token = new char* [spacecount + 1];
//	int j = 0;
//	while (TokenS[j] != ' ')
//	{
//		temp[j] == TokenS[j];
//
//		while (temp[j] != '\0')
//		{
//
//		}
//	}
//	while (TokenS[i] != ' ')
//	{
//		temp[i] = TokenS[i];
//		i++;
//	}
//}
//int main()
//{
//	cout << "  Testing String Tokens  " << endl;
//	string TokenS = { '\0' };
//	cout << "Enter String : ";
//	getline(cin,TokenS);
//	cout<<StringTokens(TokenS);
//	cout << endl;
//
//}
//char* temp = new char[25];
//
//int length = StringLength(TokenS);
//int spacecount = 0;
//for (int i = 0; i <= length; i++)
//{
//	if (TokenS[i] == ' ')
//		spacecount++;
//}
//int wordcount = 0;
//int j = 0;
//char** Token = new char* [spacecount + 1];
//for (int i = 0; i < length; i++)
//{
//mark:
//	if (TokenS[i] = ' ')
//	{
//		for (; j <= spacecount;)
//		{
//			Token[j] = new char[wordcount];
//			copy(Token, , wordcount);
//			wordcount = 0;
//			j++;
//			goto mark;
//		}
//	}
//	wordcount++;
//}
//for (int k = 0; k < length)
//	/*for (int i = 0; i <= length; i++)
//	{
//		Token[i] = TokenS[i];
//		if (TokenS[i] == ' ')
//			spacecount++;
//	}*/
//
//	return Token;