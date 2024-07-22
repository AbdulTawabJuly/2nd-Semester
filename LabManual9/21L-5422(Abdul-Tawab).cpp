#include<iostream>
using namespace std;
class Helper // Helper Class For Extra Helping Functions
{
public:
	static int StringLength(const char str[])
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
		while (str[i] != '\0')
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = '\0';
	}
	static bool CompareString(char* arr1, const char arr2[])
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

class Student
{
private:
	char name[50];
	char rollNo[8];
	float cgpa;
public:
	Student(const char Name[], const char RollNo[], float GPA)
	{
		int length = Helper::StringLength(Name);
		int i;
		for (i = 0; i < 50; i++)
		{
			name[i] = '\0';
		}
		for (i = 0; i < length; i++)
		{
			name[i] = Name[i];
		}
		for (i = 0; i < 8; i++)
		{
			rollNo[i] = '\0';
		}
		int rolllength = Helper::StringLength(RollNo);
		for (int i = 0; i < rolllength; i++)
		{
			rollNo[i] = RollNo[i];
		}
		cgpa = GPA;
	}
	float GetCGPA()
	{
		return cgpa;
	}
	char* GetName()
	{
		return name;
	}
	void Print()
	{
		cout << name << " ( " << rollNo << " )" << endl;
	}
};

class Society
{
private:
	char name[50];
	Student* president;
	Student* members[5];
public:
	Society(const char Name[])
	{
		int i;
		for (i = 0; i < 50; i++)
		{
			name[i] = '\0';
		}
		int length = Helper::StringLength(Name);
		for (i = 0; i < length; i++)
		{
			name[i] = Name[i];
		}
		president = NULL;
		for (int i = 0; i < 5; i++)
			members[i] = NULL;
	}
	void PrintInfo()
	{
		cout << "Society Name: " << name << endl;
		if (president==NULL)
		{
			cout << "President: NOT AVAILABLE" << endl;
		}
		else
		{
			cout << "President: ";
				president->Print();
		}
		if (president == NULL)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << "Member " << i << ": NOT AVAILABLE" << endl;
			}
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				cout << "Member " << i << ": ";
				members[i]->Print();
			}
		}
			
	}
	void AppointPresident(Student& obj)
	{
		float CGPA =obj.Student::GetCGPA();
		char *name = obj.Student::GetName();
		if (president == NULL && CGPA>3.00)
		{
			president = &obj;
			cout << name<<" has been Appointed as the President"<<endl;
		}
		else if (president != NULL)
		{
			cout << name << "  cannot be appointed as President. President position is NOT vacant. " << endl;
		}
		else if (CGPA <= 3.00)
		{
			cout << name << "  cannot be appointed as President. CGPA criteria not met" << endl;
		}
	}
	void AddMember(Student& s)
	{
		char* temp = s.GetName();
		bool check = false;
		int count = 0;
		for (int i = 0; i < 5; i++)
		{
			if (members[i] == NULL)
			{
				for (int j = 0; j < 5; j++)
				{
					if (members[j] == &s)
					{
						cout<<temp<<" already exists in Members list"<<endl;
						break;
					}
					if (president == &s)
					{
						cout << temp << " is the president" << endl;
						break;
					}
					count++;
				}
				if (count == 5)
				{
					members[i] = &s;
					cout << temp << " has been added to members list successfully" << endl;
					check = true;
				}
				if (check == true)
				{
					break;
				}
			}
		}
		if (check == false)
		{
			cout << temp<<" cannot be added to members list. Member position is NOT vacant" << endl;
		}
	}
	void SuspendMember(const char Name[])
	{
		char *temp;
		int i = 0;
		for (int i = 0; i < 5; i++)
		{
			temp  = members[i]->GetName();
			if (Helper::CompareString(temp, Name))
			{
				cout << Name << " Found on the List. ";
				cout << Name << " has been SUSPENDED" << endl;
				members[i]=NULL;
				break;
			}
			else
			{
				cout << Name << " Not found on the List" << endl;
				break;
			}
		}
	}
};

int main()
{
	Student s1( "Hashim Amla", "12L1111", 3.99);
	s1.Print();
	Student s2("Virat Kohli", "13L1121", 3.45);
	s2.Print();
	Student s3("Quinton de Kock", "13L1126", 2.98);
	s3.Print();
	Student s4("Joe Root", "14L1361", 2.99);
	s4.Print();
	Student s5("Martin Guptil", "14L1124", 3.09);
	s5.Print();
	Student s6("Rohit Sharma", "15L1314", 3.19);
	s6.Print();
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
//---------------------------------------------------------------------
	Society sports("sports");
	sports.PrintInfo();
	cout << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
//---------------------------------------------------------------------
	sports.AppointPresident(s3);
	sports.AppointPresident(s1);
	sports.AppointPresident(s2);
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
//----------------------------------------------------------------------
	
	Student s7( "Robert Elen", "15L1334", 2.19);
	sports.AddMember(s3);
	sports.AddMember(s2);
	sports.AddMember(s3);
	sports.AddMember(s1);
	sports.AddMember(s4);
	sports.AddMember(s5);
	sports.AddMember(s6);
	sports.AddMember(s7);
	cout << endl;
	cout << "----------------------------------------------------SOCIETY INFO-----------------------------------------------------"<<endl;
	sports.PrintInfo();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
//---------------------------------------------------------------------
	sports.SuspendMember("abc");
	sports.SuspendMember("Martin Guptil");

//---------------------------------------------------------------------

}