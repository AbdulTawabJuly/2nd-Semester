#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Helper // Helper Class For Extra Helping Functions
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
		int length=StringLength(str);
		int i = 0;
		while(str[i]!='\0')
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = '\0';
	}
	static char* GetStringFromBuffer(char *buffer) // This Allocates New Memory
	{
		int length = StringLength(buffer);
		char* temp = new char[length + 1];
		StringCopy(temp, buffer);
		return temp;
	}
	static void QuizMinMaxMarks(ifstream& obj, int Max[], int Min[])
	{
		for (int i = 0; i < 1; i++)
		{
			obj >> Max[i];
		}
	}
	static bool CompareString(char* arr1, char* arr2)
	{
		int i = 0;
		while (arr2[i] != '\0')
		{
			if (arr1[i] != arr2[i])
			{
				return 0;
			}
			i++;
		}
		return true;
	}
	

};
class StudentRecord
{
private:
	static int TotalStudents; 
	static int TotalQuizes;
	static int TotalAssignment;
	int QT[4] = { 14,10,10,10 };
	int AT[4] = {45,53,50,55};
	int AssignmentTotal[4] = { 0 };
	int* QuizObtained;
	int*AssignmentObtained;
	char* FName;
	char* LName;
	char* RollNo;
	int* QuizMax = new int[4];
	int* QuizMin = new int[4];
	int* AssMax = new int[4];
	int* AssMin = new int[4];
	int QuizTotal[4] = { 0 };
	int AssTotal[4] = { 0 };
public:
	StudentRecord()
	{
		QuizObtained = 0;
		AssignmentObtained = 0;
		FName = 0;
		LName =  0 ;
		RollNo = 0;
		TotalStudents++;
	}
	~StudentRecord()
	{
		if(AssignmentObtained!=nullptr)
		delete[]AssignmentObtained;

		if(QuizObtained!=nullptr)
		delete[]QuizObtained;

		if(LName!=nullptr)
		delete[]LName;

		if(FName!=NULL)
		delete[]FName;

		if(RollNo!=NULL)
		delete[]RollNo;
	}
	StudentRecord& operator=(const StudentRecord&);
	StudentRecord(const StudentRecord&);
	void ReadDataFromFile(ifstream& Read)
	{
		char temp[30]={0};
		for (int i = 0; i < 30; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		RollNo = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 30; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		FName = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 30; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		LName = Helper::GetStringFromBuffer(temp);
		int i = 0;
		QuizObtained = new int[TotalQuizes];
		while(i<TotalQuizes)
		{
			Read >> QuizObtained[i];
			i++;
		}
		int j = 0;
		AssignmentObtained = new int[TotalAssignment];
		while(j<TotalAssignment)
		{
			Read >> AssignmentObtained[j];
			j++;
		}
	}
	static StudentRecord* SearchStudent(StudentRecord* student, char* rollNo)
	{
		for (int i = 0; i < 49; i++)   //This Function Search Roll No Given
		{
			char* std = student[i].GetRollNo();
			if (Helper::CompareString(std, rollNo))
			{
				return (student + i);
			}
		}
		return NULL;
	}
	void PrintListView()
	{
		cout << RollNo << "\t";
		cout << FName << " ";
		cout << LName << "\t\t\t";
		for (int i = 0; i < TotalQuizes; i++)
		{
			cout << *(QuizObtained + i) << "\t";
		}
		cout << "  ";
		for (int i = 0; i < TotalAssignment; i++)
		{
			cout << *(AssignmentObtained + i) << "\t";
		}
		int total = GetTotalMarks();
		cout << total;
		cout << endl<<endl ;
	}
	int GetTotalMarks()
	{
		int Total = 0;
		for (int i = 0; i < TotalQuizes ; i++)
		{
			Total = Total+QuizObtained[i];
		}
		for (int j = 0; j < TotalAssignment; j++)
		{
			Total = Total + AssignmentObtained[j];
		}
		return Total;
	}
	int* GetQuizMaxMarks()
	{
		return QuizMax;
	}
	int* GetQuizMinMarks()
	{
		return QuizMin;
	}
	int* GetAssignmentMaxMarks()
	{
		return AssMax;
	}
	int* GetAssignmentMinMarks()
	{
		return AssMin;
	}
	void PrintDetailedView()
	{
		cout << "STUDENT INFORMATION" << endl;
		cout << "Name : " << FName << " " << LName << endl;
		cout << "Roll No : " << RollNo << endl;
		cout << "\"QUIZZES MARKS\"" << endl;
		for (int i = 0; i < TotalQuizes; i++)
		{
			cout << "Quiz " << i << ":"<<QuizObtained[i]<<" / "<<QT[i] << endl;
		}
		cout << "\"ASSIGNMENT MARKS\"" << endl;
		for (int i = 0; i < TotalAssignment; i++)
		{
			cout << "Assignmet " << i << ":" << AssignmentObtained[i]<<" / "<<AT[i] << endl;
		}
		cout << endl;
		int total =this-> GetTotalMarks();
		cout << "Total: " << total<<"/247";
		cout << endl;
	}
	void PrintClassStatistics(StudentRecord *List)
	{
		int* QuizMx = GetQuizMaxMarks();
		int* QuizMn = GetQuizMinMarks();
		int* AssMx = GetAssignmentMaxMarks();
		int* AssMn = GetAssignmentMinMarks();
		int QuizAvg[4] = { 0 };
		int AssignmentAvg[4] = { 0 };
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 49; i++)   // Comparing Each Entry of List for Min and Max Marks
			{
				if (QuizMax[j] < List[i].QuizObtained[j])
				{
					QuizMax[j] = List[i].QuizObtained[j];
				}
				if (AssMax[j] < List[i].AssignmentObtained[j])
				{
					AssMax[j] = List[i].AssignmentObtained[j];
				}
			}
			for (int i = 0; i < 49; i++)
			{
				QuizAvg[j] += List[i].QuizObtained[j];
				AssignmentAvg[j] += List[i].AssignmentObtained[j];
			}
			QuizAvg[j] = QuizAvg[j] / 49;
			AssignmentAvg[j] = AssignmentAvg[j] / 49;
		}
		for (int i = 0; i < 4; i++)
		{
			QuizMin[i] = 10;
		}
		for (int i = 0; i < 4; i++)
		{
			AssMin[i] = 40;
		}
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 49; i++)
			{
				if (QuizMin[j] > List[i].QuizObtained[j])
				{
					QuizMin[j] = List[i].QuizObtained[j];
				}
				if (AssMin[j] > List[i].AssignmentObtained[j])
				{
					AssMin[j] = List[i].AssignmentObtained[j];
				}
			}
		}
		cout << "-----------------------------------\"CLASS STATISTICS\"---------------------------------" << endl<<endl;
		cout<<"\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\t" << endl<<endl;
		cout << "Total:\t";
		for (int i = 0; i < 4; i++)
		{
			cout << QT[i] << "\t";
		}
		for (int i = 0; i < 4; i++)
		{
			cout << AT[i] << "\t";
		}
		cout << endl;
		cout << "Maximum: ";
		for (int i = 0; i < 4; i++)
		{
			cout << QuizMax[i] << "\t";
		}
		for (int i = 0; i < 4; i++)
		{
			cout<<AssMax[i] << "\t";
		}
		cout << endl;
		cout << "Minimum: ";
		for (int j = 0; j < 4; j++)
		{
			cout << QuizMin[j] << "\t" ;
		}
		for (int i = 0; i < 4; i++)
		{
			cout << AssMin[i] << "\t";
		}
		cout << endl;
		cout << "Average: ";
		for (int k = 0; k < 4; k++)
		{
			cout << QuizAvg[k] << "\t";
		}
		for (int k = 0; k < 4; k++)
		{
			cout << AssignmentAvg[k] << "\t";
		}
		cout << endl;
	}
	
	char* GetRollNo()
	{
		return this->RollNo;
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
	static int GetTotalAssignments(ifstream&Read)
	{
		Read >> TotalAssignment;
		return TotalAssignment;
	}
};
StudentRecord &StudentRecord::operator=(const StudentRecord& rhs)
{   // Assignment Constructor  
	if (&rhs != this)
	{
		if (RollNo != NULL)
			delete[]RollNo;
		if (FName != NULL)
			delete[]FName;
		if (LName != NULL)
			delete[]LName;
		if (QuizObtained != NULL)
			delete[]QuizObtained;
		if (AssignmentObtained != NULL)
			delete[]AssignmentObtained;

		int count = 0;
		char temp[20] = { '\0' };
		int i = 0;
		for (; rhs.RollNo[i] != '\0';)
		{
			temp[i] = rhs.RollNo[i];
			i++;
		}
		
		RollNo = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		i = 0;
		for (; rhs.FName[i] != '\0';)
		{
			temp[i] = rhs.FName[i];
			i++;
		}
		FName = Helper::GetStringFromBuffer(temp);

		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		i = 0;
		for (; rhs.LName[i] != '\0';)
		{
			temp[i] = rhs.LName[i];
			i++;
		}
		LName = Helper::GetStringFromBuffer(temp);

		QuizObtained = new int[4];
		for (int i = 0; i < 4; i++)
		{
			QuizObtained[i] = (rhs.QuizObtained[i]);
		}

		AssignmentObtained = new int[4];
		for (int j = 0; j < 4; j++)
		{
			AssignmentObtained[j] = (rhs.AssignmentObtained[j]);
		}
	}
	return *this;
}
StudentRecord::StudentRecord(const StudentRecord& rhs)
{  // Copy Constructor 
	int count = 0;
	char temp[20] = { '\0' };
	int i = 0;
	for (; rhs.RollNo[i] != '\0';)
	{
		temp[i] = rhs.RollNo[i];
		i++;
	}
	RollNo = Helper::GetStringFromBuffer(temp);
	for (int i = 0; i < 20; i++)
	{
		temp[i] = '\0';
	}
	i = 0;
	for (; rhs.FName[i] != '\0';)
	{
		temp[i] = rhs.FName[i];
		i++;
	}
	FName = Helper::GetStringFromBuffer(temp);
	for (int i = 0; i < 20; i++)
	{
		temp[i] = '\0';
	}
	i = 0;
	for (; rhs.LName[i] != '\0';)
	{
		temp[i] = rhs.LName[i];
		i++;
	}
	LName = Helper::GetStringFromBuffer(temp);
	QuizObtained = new int[4];
	for (int i = 0; i < 4; i++)
	{
		QuizObtained[i] = (rhs.QuizObtained[i]);
	}
	AssignmentObtained = new int[4];
	for (int j = 0; j < 4; j++)
	{
		AssignmentObtained[j] = (rhs.AssignmentObtained[j]);
	}
}
int StudentRecord::TotalStudents = 0;
int StudentRecord::TotalQuizes = 0;
int StudentRecord::TotalAssignment = 0;
StudentRecord* ReadDataFromFile(const char* file)
{
	ifstream Read;
	int totalStudents = 0;
	int TotalQ = 0;
	int TotalA = 0;
	int QuizTotal[4] = { 0 };
	int AssignmentTotal[4] = { 0 };
	Read.open(file);
	if (Read.is_open())
	{
		Read >> totalStudents;
		TotalQ =StudentRecord::GetTotalQuizes(Read);
		TotalA=StudentRecord::GetTotalAssignments(Read);
		for (int i = 0; i < TotalQ; i++)
		{
			Read >> *(QuizTotal + i);
		}
		
		for (int i = 0; i < TotalA; i++)
		{
			Read >> *(AssignmentTotal + i);
		}
		StudentRecord* List = new StudentRecord[totalStudents+1];
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
int main()
{

	StudentRecord* List = ReadDataFromFile("Gradesheet.txt");
	int count = 0;
	if (List != 0)
	{
		count = StudentRecord::GetTotalStudents()-1;
		cout << "                                 \"FLEX REPORT\"         " << endl<<endl;
		cout << "  Total Students: " << count << endl;
		cout << "----------------------------------------\"STUDENT LIST\"---------------------------------------------------------" << endl<<endl;
		cout << "ROLLNO \t\tNAME\t\t\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\tTOTAL" << endl<<endl;
		{
			for (int i = 0; i < count; i++)
			{
				List[i].PrintListView();
			}
		}
		cout << endl;
		cout << "----------------------------------------- \"STUDENT LIST AFTER SORTING\" ----------------------------------------" << endl<<endl;
		for (int i = 0; i < count; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (List[i].GetTotalMarks() > List[j].GetTotalMarks())
				{
					/*StudentRecord temp = List[i];
					List[i] = List[j];
					List[j] = temp;*/

					StudentRecord temp;
					temp = List[i];
					List[i] = List[j];
					List[j] = temp;
				}
			}
		}
		cout << "ROLLNO \t\tNAME\t\t\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\tTOTAL" << endl << endl;
		{
			for (int i = 0; i < count; i++)
			{
				List[i].PrintListView();
			}
		}
		cout << endl;
		cout << "--------------------\"PRINTING STUDENT DATA\"---------------------" << endl;
		char RollNo[9] = { '1','5','L','-','4','3','2','1' ,'\0' };
		StudentRecord* arr = NULL;
		arr = StudentRecord::SearchStudent(List, RollNo);
		if (arr == NULL)
		{
			cout << "STUDENT NOT FOUND" << endl;
		}
		else
		{
			arr->PrintDetailedView();
		}
		cout << endl;
		List->PrintClassStatistics(List);
		if (List)
			delete[] List;
	}

	return 0;
}
