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
//
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
//void StringConcatenate(string a, string b)
//{
//	cout << "Enter First Sentence: ";
//	getline(cin, a);
//	cout << "Enter Second Sentence: ";
//	getline(cin, b);
//	string c = a + b;
//	cout << "String 1 : " <<c <<endl;
//	cout << "String 2 : " << b << endl;;
//}
//char** StringTokens(string TokenS)
//{
//	int length = StringLength(TokenS);
//	int spacecount = 0;
//	for (int i = 0; i <= length; i++)
//	{
//		if (TokenS[i] == ' ')
//			spacecount++;
//	}
//	int wordcount = 0;
//	int j = 0;
//	char** Token = new char*[spacecount+1];
//	for (int i = 0; i < length; i++)
//	{
//	    mark:
//		if (TokenS[i] = ' ')
//		{
//			for (;j <= spacecount;)
//			{
//				Token[j] = new char[wordcount];
//				wordcount = 0;
//				j++;
//				goto mark;
//			}
//		}
//		wordcount++;
//	} 
//	for(int k=0;k<length)
//	/*for (int i = 0; i <= length; i++)
//	{
//		Token[i] = TokenS[i];
//		if (TokenS[i] == ' ')
//			spacecount++;
//	}*/
//
//	return Token;
//}
//char* ReverseSentence(char*ReverseSent , int length)
//{
//	// int counter = ArrayLength(ReverseSent);
//	 char* AnswerSent = new char[length];
//	 int k = 0;
//		 for (int i = length; i >= 0; i--)
//		 {
//			 if (ReverseSent[i] == ' ')
//			 {
//				 for (int j = i + 1; j < length+1; j++)
//				 {
//					  AnswerSent[k]=ReverseSent[j];
//					  k++;
//				 }
//				 if (k != length)
//				 {
//					 ReverseSent[k] = ' ';
//					 k++; 
//				 }
//			 }
//			 else if (i == 0)
//			 {
//				 for (int j = i; j != ' '; j++)
//				 {
//					 AnswerSent[k] = ReverseSent[j];
//				 }
//			 }
//			                   
//		 }
//
//		 return AnswerSent;
//}
//int main()
//{
//	string sent1 = { '\0' }, sent2 = { '\0' };
//	StringConcatenate(sent1, sent2);
//
//	cout << "  Testing String Tokens  " << endl;
//	string TokenS = { '\0' };
//	
//	cout << "Enter String : ";
//	getline(cin,TokenS);
//	cout<<StringTokens(TokenS);
//	cout << endl;
//
//	cout << "  Testing Reverse String " << endl;
//	cout << "Enter Sentence: ";
//	char* ReverseSent = new char[100];
//	cin.getline(ReverseSent, 100);
//	int ReverseLength = ArrayLength(ReverseSent);
//	char* AnswerReverse = ReverseSentence(ReverseSent, ReverseLength);
//	//cout << AnswerReverse;
//	for (int i = 0; i < ReverseLength; i++)
//	{
//		cout << AnswerReverse[i];
//	}
//	cout <<endl<< "   Testing Student Functionality List " << endl;
//
//	system("pause");
//}