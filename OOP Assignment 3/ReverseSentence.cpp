//#include<iostream>
//#include<string>
//using namespace std;
//char* ReverseSentence(char* ReverseSent, int length)
//{
//	 int counter = strlen(ReverseSent);
//	 char* AnswerSent = new char[length];
//	 int k = 0;
//		 for (int i = length; i >= 0; i--)
//		 {
//			 if (ReverseSent[i] == ' ')
//			 {
//				 for (int j = i + 1; j < length; j++)
//				 {
//					  AnswerSent[k]=ReverseSent[j];
//					  k++;
//				 }
//				 if (k == length-1)
//				 {
//					 ReverseSent[k] = '\0';
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
//
//int main()
//{
//		cout << "  Testing Reverse String " << endl;
//	cout << "Enter Sentence: ";
//	char* ReverseSent = new char[100];
//	cin.getline(ReverseSent, 100);
//	int ReverseLength = strlen(ReverseSent);
//	char* AnswerReverse = ReverseSentence(ReverseSent, ReverseLength);
//	//cout << AnswerReverse;
//	for (int i = 0; i < ReverseLength; i++)
//	{
//		cout << AnswerReverse[i];
//	}
//	
//}