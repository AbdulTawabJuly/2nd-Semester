//#include<iostream>
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
//int WordCount(char* string)
//{
//	int i = 0; int wordcount = 0;
//	while (string[i] != '\0')
//	{
//		if (string[i] == ' ')
//		{
//			wordcount++;
//		}
//		i++;
//	}
//	wordcount++;
//	return wordcount;
//}
//
//void StringCopy(char* string1, char* string2, int length)
//{
//	int i = 0;
//	while (string2[i] != '\0')
//	{
//		string1[i] = string2[i];
//		i++;
//	}
//	string1[i] = 0;
//}
//void DisplayTokken(char** DisplayingTok)
//{
//	int length = ArrayLength(TokArr);
//	int spacecount = 0;
//	for (int i = 0; i < length; i++)
//	{
//		if (TokArr[i] == ' ')
//		{
//			spacecount++;
//		}
//	}
//	for(int i=0)
//}
//void StringTokens(char* TokArr)
//{
//	int length = ArrayLength(TokArr);
//		int spacecount = 0;
//		for (int i = 0; i < length; i++)
//		{
//			if (TokArr[i] == ' ')
//			{
//				spacecount++;
//			}
//		}
//		int wordcount = 0;
//		int j = 0;
//		char** Token = new char*[spacecount+1];
//		for (int i = 0; i < spacecount+1; i++)
//		{
//			for (int j=0;j<length;j++)
//			{
//				wordcount++;
//				if (TokArr[j]==' ')
//				{
//					Token[i] = new char[wordcount-1];
//					for (int k = 0; TokArr[k] != ' '; k++)
//					{
//						Token[i] = TokArr;
//					}
//					wordcount = 0;
//					
//				}
//			}	
//		} 
//		for (int i = 0; i < spacecount + 1; i++)
//		{
//				cout << Token[i];
//				cout << endl;
//
//		}
//		
//		//return Token;
//}
// int StringLength(char* string)
//{
//	int i = 0;
//	while (string[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}
//char** StringTokens(char* string)
//{
//	int i = 0;
//	char* buffer = new char[30];
//	for (int j = 0; j < 30; j++)
//	{
//		buffer[j] = '\0';
//	}
//	int l = 0;
//	int wordcount = WordCount(string);
//	char** StringTokens = new char* [wordcount];
//	while (string[i] != '\0')
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
//			l = 0;
//		}
//		l++;
//		i++;
//	}
//	return StringTokens;
//}
//int main()
//{
//	cout << "  Testing String Tokens" << endl << endl;
//	cout << "Tokens of String 1 are as follows: " << endl;
//	char* tokArr = new char[50];
//	cin.getline(tokArr, 50);
//	StringTokens(tokArr);
//	TokenPrint(stringFinal);			//no extra bits used
//
//	cout << endl << endl;
//}