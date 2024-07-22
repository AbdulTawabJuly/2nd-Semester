#include<iostream>
#include<fstream>
using namespace std;
class Helper
{
public:
	static int StringLength(char* str)
	{
		int i = 0, count = 0;
		while (str[i] != '\0')
		{
			i++;
			count++;
		}
		return count;
	}
	static void StringCopy(char*& dest, char*& str) {
		int length = StringLength(str);
		int i = 0;
		for (i = 0; i < length; i++)
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = '\0';

	}
	static char* GetStringFromBuffer(char* buffer)
	{
		int length = StringLength(buffer);
		char* temp = new char[length + 1];
		StringCopy(temp, buffer);
		return temp;
	}
};
class StudentRecord
{
private:
	static int TotalStudents;
	static int TotalQuizes;
	static int TotalAssignment;
	int* QuizObtained = new int[4];
	int* AssignmentObtained = new int[4];
	char* Name;
	char* RollNo;
public:

	StudentRecord()
	{
		for (int i = 0; i < 4; i++)
		{
			*(QuizObtained + i) = 0;
		}
		for (int i = 0; i < 4; i++)
		{
			*(AssignmentObtained + i) = 0;
		}
		Name = 0;
		RollNo = 0;
		TotalStudents++;
	}
	void ReadDataFromFile(ifstream& Read)
	{

		char temp[30];

		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		RollNo = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		Name = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 4; i++)
		{
			Read >> *(QuizObtained + i);
		}

		for (int i = 0; i < 4; i++)
		{
			Read >> *(AssignmentObtained + i);
		}

	}
	void PrintListView()
	{
		cout << RollNo << " " << Name << " ";
		for (int i = 0; i < 4; i++)
		{
			cout << *(QuizObtained + i) << " ";
		}
		for (int i = 0; i < 4; i++)
		{
			cout << *(AssignmentObtained + i) << " ";
		}
		cout << endl;
	}
	static int GetTotalStudents()
	{
		return TotalStudents;
	}
	static int GetTotalQuizes(ifstream& Read)
	{
		Read >> TotalQuizes;
		return TotalQuizes;
	}
	static int GetTotalAssignments(ifstream& Read)
	{
		Read >> TotalAssignment;
		return TotalAssignment;
	}
};
int StudentRecord::TotalStudents = 0;
int StudentRecord::TotalQuizes = 0;
int StudentRecord::TotalAssignment = 0;
StudentRecord* ReadDataFromFile(const char* file)
{
	ifstream Read;
	int totalStudents = 0;
	int TotalQ = 0;
	int TotalA = 0;
	Read.open("GradeSheet.txt");
	if (Read.is_open())
	{

		Read >> totalStudents;
		TotalQ = StudentRecord::GetTotalQuizes(Read);

		TotalA = StudentRecord::GetTotalAssignments(Read);
		static int* QuizTotal = new int[TotalQ];
		for (int i = 0; i < TotalQ; i++)
		{
			Read >> QuizTotal[i];
		}
		static int* AssignmentTotal = new int[TotalA];
		for (int i = 0; i < TotalA; i++)
		{
			Read >> AssignmentTotal[i];
		}
		StudentRecord* List = new StudentRecord[totalStudents];
		int i = 0;
		while (!Read.eof())
		{
			List[i].ReadDataFromFile(Read);
			i++;
		}
		return List;
	}
	else
	{
		return 0;
	}
}
//int StudentRecord::TotalStudents = 0;
int main()
{
	StudentRecord* List = ReadDataFromFile("GradeSheet.txt");
	int count = 0;
	if (List != 0)
	{
		count = StudentRecord::GetTotalStudents();
		cout << "Total Students: " << count << endl;
		cout << "Student List" << endl;
		for (int i = 0; i < count; i++)
		{
			List[i].PrintListView();
		}
	}

}
