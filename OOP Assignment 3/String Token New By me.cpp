//#include<iostream>
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
//int StaticArrayLength(char arr[])
//{
//	int counter = 0, index = 0;
//	while (arr[index] != NULL)
//	{
//		index++;
//		counter++;
//	}
//	return counter;
//}
//
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
//	return wordcount;
//}
//void PrintToken(char** Ptstr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << Ptstr[i] << endl;;
//	}
//	cout << endl;
//}
//void InversePrintToken(char** Ptstr, int size)
//{
//	for (int i = size - 1; i >= 0; i--)
//	{
//		cout << Ptstr[i] << endl;
//	}
//	cout << endl;
//}
//void InverseSentPrint(char** Ptstr,int size)
//{
//	for (int i = size-1; i >=0; i--)
//	{
//		cout << Ptstr[i]<<" ";
//	}
//	cout << endl;
//}
//char* CopyToken(char arr1[])
//{
//	int i = 0,counter=0;
//	while (arr1[i]!='\0')
//	{
//		counter++;
//		i++;
//	}
//	char* Copied = new char[counter+1]; // Counter +1 -> for storing NULL at the end
//	i = 0;
//	while (arr1[i] != '\0')
//	{
//		Copied[i] = arr1[i];
//		i++;
//	}
//
//	Copied[i] = '\0';
//	return Copied;
//}
//char** StringToken(char *strTok)
//{
//	int Length = ArrayLength(strTok);
//	int space = WordCount(strTok);
//	char** Token = new char* [space + 1];
//	int i = 0,j=0;
//	while (i < space+1)
//	{
//			int t = 0;
//			char temp[50] = "";
//			while ((strTok[j] != ' ') && (i < space))
//			{
//				temp[t] = strTok[j];
//				j++;
//				t++;
//			}
//			if (i == space)
//			{
//			   while (strTok[j] != '\0')
//			   {
//						temp[t] = strTok[j];
//						j++;
//						t++;
//			   }
//			} 
//			temp[t] = '\0';
//			Token[i] = CopyToken(temp);
//			//cout<<Token[i]<<endl;
//			i++;
//		    j++;
//	}
//
//	
//	InverseSentPrint(Token, i);
//	delete[]strTok;
//	return Token;
//}
//int main()
//{
//	char* StringTok = new char[100];
//	cout << "Enter String :";
//	//cin.ignore();
//	cin.getline(StringTok, 100);
//	char** FinalTok=StringToken(StringTok);
//\
//	delete[]FinalTok;
//	FinalTok = NULL;
//}