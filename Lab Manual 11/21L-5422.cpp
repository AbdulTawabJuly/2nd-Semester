#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	char fname[50];
	char lname[50];
protected:
	int age;
public:
	Person();
	Person(const char*, const char*, int);
	void PrintInfo();
	void FacultyMember();
	void PrintStudent();
	void Gra();
	~Person();
};
Person::Person()
{
	cout << "Default Constructor Person() Called" << endl;
	strcpy_s(fname, "");
	strcpy_s(lname, "");
	age = 0;
}
Person::Person(const char* FN, const char* LN, int AGE)
{
	cout << "Overloaded Constructor Person() called" << endl;
	strcpy_s(fname, FN);
	strcpy_s(lname, LN);
	age = AGE;
}
void Person::Gra()
{
	cout << fname << " " << lname;
}
void Person::PrintStudent()
{
	cout << fname << " " << lname<<" is " << age << " years old";
}
void Person::FacultyMember()
{
	cout << fname << " " << lname<<", Age : "<<age<<" , ";
}
void Person::PrintInfo()
{
	cout << fname << " " << lname << " is " << age << " old" << endl;
}
Person::~Person()
{
	cout << "Destructor ~Person() Called" << endl;
}
class Student :public Person
{
private:
	float cgpa;
public:
	Student(const char*,const char*, int, float);
	void PrintStudent();
	void Gra();
	~Student();
};
Student::Student(const char* fname,const char* lname, int age, float CGPA) : Person(fname, lname, age)
{
	cout << "Default Constructor Student() Called" << endl;
	cgpa = CGPA;
}
void Student::Gra()
{
	cout << cgpa;
}
void Student::PrintStudent()
{
	Person::PrintStudent();
	cout <<" and his cgpa is " << cgpa;
}
Student::~Student()
{
	cout << "Destructor ~Student() Called" << endl;
}
class Faculty :public Person
{
private:
	int course_count;
	int NO;
public:
	Faculty(const char*,const char*, int, int,int);
	void PrintFaculty();
	~Faculty();
};
Faculty::Faculty(const char* fname,const char* lname, int age, int count,int no) : Person(fname, lname, age)
{
	cout << "Default Constructor Faculty() Called" << endl;
	course_count = count;
	NO = no;
}
void Faculty::PrintFaculty()
{
	Person::FacultyMember();
	cout << "Number of Courses : " << course_count<<" , ";
	cout << " EXT. " << NO << endl;;
}
Faculty::~Faculty()
{
	cout << "Destructor ~Faculty() Called" << endl;
}
class UnderGraduate :public Student
{
private:
	char fyp[50];
public:
	UnderGraduate(const char*, const char*, int, float, const char*);
	void PrintUnderGraduate();
	~UnderGraduate();
};
UnderGraduate::UnderGraduate(const char* fname, const char* lname, int age, float CGPA, const char* fyp_name) : Student(fname, lname, age, CGPA)
{
	cout << "Default Constructor UnderGraduate() Called" << endl;
	strcpy_s(fyp, fyp_name);
}
void UnderGraduate::PrintUnderGraduate()
{
	Person::Gra();
	cout << " is an Under Graduate student, his cgpa is ";
	Student::Gra();
	cout << " and Final Year Project is " << fyp << endl;
}
UnderGraduate::~UnderGraduate()
{
	cout << "Destructor ~UnderGraduate() Called" << endl;
}
class Graduate :public Student
{
private:
	char thesis[50];
public:
	Graduate(const char*, const char*, int, float,const char*);
	void PrintGraduate();
	~Graduate();
};
Graduate::Graduate(const char* fname, const char* lname, int age, float CGPA,const char* thesis_topic) :Student(fname, lname, age, CGPA)
{
	cout << "Default Constructor Graduate() Called" << endl;
	strcpy_s(thesis, thesis_topic);
}
void Graduate::PrintGraduate()
{
	Person::Gra();
	cout << " is a Graduate student, his cgpa is ";
	Student::Gra();
	cout << " and his thesis Document is " << thesis << endl;
}
Graduate::~Graduate()
{
	cout << "Destructor ~Graduate() Called" << endl;
}
int main()
{
	//Exercise 1 is to draw a design on paper
	//Exercise 2 is to implement that design
	//Exercise 3 is to create Constructors and Destructors
	
	//Exercise 4 is optional
	
	//Exercise 5
    Student s1("Ted","Thompson", 22,3.91);
	Faculty f1("Richard", "Karp", 45, 2, 420);

	//Exercise 6
	cout << endl;
	s1.PrintInfo();

	//Exercies 7 is to create PrintStudent() and PrintFaculty()
	s1.PrintStudent();
	cout << endl;
	f1.PrintFaculty();
	cout << endl;

	//Exercise 8 is to create PrintGraduate()  and  PrintUndergraduate()
	Graduate g1("Ted", "Thompson", 22, 3.91, "Distributed Algorithms");
	UnderGraduate ug1("Ted", "Thompson", 22, 3.91, "The Even Locator");

	g1.PrintGraduate();
	cout << endl;
	ug1.PrintUnderGraduate();
	cout << endl;

}