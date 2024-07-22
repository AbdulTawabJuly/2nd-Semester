//#include<iostream>
//#include<fstream>
//#include<stdio.h>
//using namespace std;
//
//class Facebook
//{
//private:
//	char* UserID = new char[3];
//	char* FirstName;
//	char* LastName;
//	char** FriendIDs;
//	char** LikedPages;
//	char** PageList;
//	char** PageID;
//	int noOfFriends = 0;
//	int noOfPages = 0;
//public:
//	static int TotalUsers;
//	static int TotalPages;
//	static void InputTotal(ifstream& fan, ifstream& fun)
//	{
//		fan >> TotalUsers;
//		fun >> TotalPages;
//	}
//	int strlength(char* arr)
//	{
//		int i = 0;
//		while (arr[i] != '\0')
//		{
//			i++;
//		}
//		return i;
//	}
//	Facebook()
//	{
//		FirstName = NULL;
//		LastName = NULL;
//		FriendIDs = NULL;
//		LikedPages = NULL;
//		PageList = NULL;
//	}
//	char* getStringFromBuffer1(ifstream& fin)
//	{
//		char buffer[100] = { '\0' };
//		fin.getline(buffer, 100);
//		int len = strlength(buffer);
//		char* arr = new char[len + 1];
//		int j = 0;
//		for (j = 0; j < len; j++)
//		{
//			arr[j] = buffer[j];
//		}
//		arr[j] = '\0';
//		return arr;
//	}
//	char* getStringFromBuffer(ifstream& fon)
//	{
//		char buffer[100] = { '\0' };
//		fon >> buffer;
//		int len = strlength(buffer);
//		char* arr = new char[len+1];
//		int j = 0;
//		for ( j = 0; j < len; j++)
//		{
//			arr[j] = buffer[j];
//		}
//		arr[j] = '\0';
//		return arr;
//	}
//	char** GetIDs(ifstream & fin,int & friends)
//	{
//		char** array = new char* [10];
//		char* arr = new char[20];
//		for (int j = 0; j < 10; j++)
//		{
//			array[j] = NULL;
//		}
//		arr[0] = {'u'};
//		int i = 0;
//		/*while (arr[0] != '-')
//		{
//			arr = getStringFromBuffer(fin);
//			if (arr[0] == '-')
//			{
//				return array;
//			}
//			else
//			{
//				array[i] = arr;
//			}
//			i++;
//		}*/
//	//	friends = i;
//		
//		while (arr[0] != '-')
//		{
//			arr = getStringFromBuffer(fin);
//			if (arr[0] == '-')
//			{
//				break;
//			}
//			array[i] = arr;
//			i++;
//		}
//		friends = i;
//		return array;
//	}
//
//
//
//	//char** GetPages(ifstream& fin, int& Pages)
//	//{
//	//	char** array = new char* [10];
//	//	char* arr = new char[20];
//	//	for (int j = 0; j < 10; j++)
//	//	{
//	//		arr[j] = '\0';
//	//	}
//	//	int i = 0;
//	//}
//
//	void Input(ifstream& fin)
//	{
//		fin >> UserID;
//		//cout << UserID<<"\t";
//		FirstName = getStringFromBuffer(fin);
//		//cout << FirstName;
//		LastName = getStringFromBuffer(fin);
//		//cout << LastName<<endl;
//		FriendIDs = GetIDs(fin, noOfFriends);
//		/*for (int i = 0; i < noOfFriends; i++)
//		{
//			cout <<"\t" <<FriendIDs[i]<<"\t";
//		}
//		cout << endl;*/
//		LikedPages = GetIDs(fin, noOfPages);
//		/*for (int i = 0; i < noOfPages; i++)
//		{
//			cout << "\t" << LikedPages[i] << "\t";
//		}*/
//
//
//		/*LikedPages = GetIDs(fin, noOfPages); */
//
//	}
//	void Show_Detailed()
//	{
//		cout << "User's ID : " << this->UserID;
//		cout << "\nName : " << this->FirstName << " " << this->LastName<<endl;
//		cout << "User's Friend List : \t";
//		for (int i = 0; i < this->noOfFriends; i++)
//		{
//			cout << FriendIDs[i]<<"\t";
//		}
//		cout << endl<<endl<<endl;
//		//cout << endl << PageList[3];
//	}
//
//	void Inputpages(ifstream& fon)
//	{
//		char* buffer = new char[20];
//		char* buffer1 = new char[40];
//		fon >> TotalPages;
//		PageID = new char*[TotalPages];
//		PageList = new char* [TotalPages];
//		for (int i = 0; i < TotalPages; i++)
//		{
//			buffer = getStringFromBuffer(fon);
//			PageID[i] = buffer;
//			buffer1 = getStringFromBuffer1(fon);
//			PageList[i] = buffer1;
//		}
//	}
//	char* GetStFromBuffer()
//	{
//		char buffer[100] = { '\0' };
//		cin >> buffer;
//		int len = strlength(buffer);
//		char* arr = new char[len + 1];
//		int j = 0;
//		for (j = 0; j < len; j++)
//		{
//			arr[j] = buffer[j];
//		}
//		arr[j] = '\0';
//		return arr;
//	}
//
//	/static Facebook searchUser(Facebook t, char* arr)
//	{
//		for (int i = 0; i < Facebook::TotalUsers; i++)
//		{
//			char* userid = t[i].UserID;
//		}
//	}*/
//	static Facebook searchuser(Facebook* t, char* arr)
//	{
//		for (int i = 0; i < TotalUsers; i++)
//		{
//			int j = 0;
//			while (arr[j] != '\0')
//			{
//				if (arr[j] != t[i].UserID[j])
//				{
//					//goto a;
//				}
//				else
//				{
//					return t[i];
//				}
//				j++;
//			}
//		a:
//			cout << "";
//		}
//		cout << "User Not Found..." << endl;
//	}
//	Facebook& operator = (const Facebook& t)
//	{
//		
//
//
//	}
//};
//int Facebook::TotalUsers = 0;
//int Facebook::TotalPages = 0;
//void main()
//{
//	ifstream fin("data.txt");
//	ifstream fon("pages.txt");
//	fin >> Facebook:: TotalUsers;
//	int count = Facebook::TotalUsers;
//	Facebook* Users = new Facebook[count];
//	for (int i = 0; i < count; i++)
//	{
//		Users[i].Input(fin);
//		Users[i].Show_Detailed();
//	}
//
//	char* buffer=new char[3];
//	buffer[0] = buffer[1] = buffer[2] = {'\0'};
//	cin >> buffer;
//	Facebook temp=Facebook::searchuser(Users,buffer);
//	temp.Show_Detailed();
//	//temp = searchUser(temp, buffer);
//	/*Facebook Haris;
//	Haris.Input(fin);
//	Haris.Inputpages(fon);
//	Haris.Show_Friends();*/
///*
//	Facebook* Users = new Facebook[12];
//	for (int i = 0; i < 10; i++)
//	{
//		Users[i].Input(fin);
//		Users[i].Inputpages(fon);
//		Users[i].Show_Friends();
//	}
//	*/
//
//	//Haris.Show_Friends();
//	system("pause");
//}

//
//
//#include<iostream>
//using namespace std;
//
//class Student
//{
//private:
//	char name[50];
//	char rollNo[8];
//	float gpa;
//public:
//	Student(const char* r = 0, const char* n = 0, float g = 0)
//	{
//		int i;
//		name[0] = '\0';
//		for (i = 0; n[i] != '\0'; i++)
//		{
//			name[i] = n[i];
//		}
//		name[i] = '\0';
//		int j;
//		rollNo[0] = '\0';
//		for (j = 0; r[j] != '\0'; j++)
//		{
//			rollNo[j] = r[j];
//		}
//		rollNo[j] = '\0';
//		gpa = g;
//	}
//	void Print()
//	{
//		cout << name << "(" << rollNo << ")" << endl;
//	}
//	float Getgpa()
//	{
//		return gpa;
//	}
//	char* GetName()
//	{
//		return name;
//	}
//	~Student()
//	{
//	}
//};
//class Society
//{
//private:
//	char name[50];
//	Student* president;
//	Student* members[5];
//	static int currentMembersCount;
//public:
//	Society(const char* n = 0)
//	{
//		int i;
//		for (i = 0; n[i] != '\0'; i++)
//		{
//			name[i] = n[i];
//		}
//		name[i] = '\0';
//		president = nullptr;
//		members[0] = nullptr;
//	}
//	void PrintInfo()
//	{
//		cout << "Society Name: " << name << endl;
//		cout << "President:\t";
//		if (president == 0)
//		{
//			cout << "Not Available" << endl;
//		}
//		else
//		{
//			president->Print();
//		}
//		for (int i = 0; i < 5; i++)
//		{
//			cout << "Member " << i + 1 << ":\t";
//			if (members[i] == 0)
//			{
//				cout << "Not Available" << endl;
//			}
//			else
//			{
//				members[i]->Print();
//			}
//
//		}
//	}
//	void AppointPresident(Student& p)
//	{
//		if (president == 0)
//		{
//			if (p.Getgpa() > 3.00)
//			{
//				cout << p.GetName() << " has been appointed as President." << endl;
//				president = &p;
//			}
//			else
//			{
//				cout << p.GetName() << " cannot be appointed as President. CGPA criteria not met." << endl;
//			}
//		}
//		else
//		{
//			cout << p.GetName() << " cannot be appointed as President. President position is NOT vacant" << endl;
//		}
//	}
//	void AddMember(Student& m)
//	{
//		int i = 0;
//		bool check = false;
//		bool check2 = true;
//		for (i = 0; i < 5; i++)
//		{
//			if (members[i] == 0)
//			{
//				check = true;
//				if (&m == president)
//				{
//					cout << "President cannot be added to Members list." << endl;
//					break;
//				}
//				else
//				{
//					for (int j = 0; j < i; j++)
//					{
//						if (&m == members[j])
//						{
//							cout << m.GetName() << " already exists in Members list." << endl;
//							check2 = false;
//							break;
//						}
//
//					}
//					if (check2 == true)
//					{
//						cout << m.GetName() << " has been added to members list successfully." << endl;
//						members[i] = &m;
//						currentMembersCount++;
//						break;
//					}
//					break;
//				}
//			}
//		}
//		if (check == false)
//		{
//			cout << m.GetName() << " cannot be added to members list. Member position is NOT vacant" << endl;
//		}
//	}
//
//	void SuspendMember(const char* memberName)
//	{
//		int total = currentMembersCount;
//		bool check = false;
//		int size = strlen(memberName);
//		char* temp = 0;
//		for (int i = 0; i < total; i++)
//		{
//			temp = members[i]->GetName();
//			for (int j = 0; j < size; j++)
//			{
//				if (memberName[j] == temp[j])
//				{
//					check = true;
//				}
//				else
//				{
//					check = false;
//					break;
//				}
//			}
//			if (check == true)
//			{
//				check = true;
//				cout << memberName << " has been suspended from " << name << " society" << endl;
//				members[i] = NULL;
//				currentMembersCount--;
//				break;
//			}
//		}
//
//		if (check == false)
//			cout << memberName << " NOT found in the Member list" << endl;
//	}
//	~Society()
//	{
//	}
//};
//int Society::currentMembersCount = 0;
//
//int main()
//{
//	Student s1("12L1111", "Hashim Amla", 3.99);
//	Student s2("13L1121", "Virat Kohli", 3.45);
//	Student s3("13L1126", "Quinton de Kock", 2.98);
//	Student s4("14L1361", "Joe Root", 2.99);
//	Student s5("14L1124", "Martin Guptil", 3.09);
//	Student s6("15L1314", "Rohit Sharma", 3.19);
//
//	Society sports("Sports");
//
//	sports.PrintInfo();
//
//	sports.AppointPresident(s3);
//	sports.AppointPresident(s1);
//	sports.AppointPresident(s2);
//
//	cout << endl << endl << endl;
//	Student s7("15L1334", "Robert Elen", 2.19);
//	sports.AddMember(s3);
//	sports.AddMember(s2);
//	sports.AddMember(s3);
//	sports.AddMember(s1);
//	sports.AddMember(s4);
//	sports.AddMember(s5);
//	sports.AddMember(s6);
//	sports.AddMember(s7);
//	sports.PrintInfo();
//
//	cout << endl << endl << endl;
//	sports.SuspendMember("abc");
//	sports.SuspendMember("Martin Guptil");
//	sports.PrintInfo();
//
//
//	cout << endl << endl << endl;
//	Society ieee("IEEE");
//	ieee.AppointPresident(s5);
//	ieee.PrintInfo();
//
//	system	("pause");
//	return 0;
//}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//#include<fstream>
//using namespace std;
//
//
//class helper
//{
//public:
//	static char* getStringfromBuffer(char* str)
//	{
//		int count = 0;
//		while (str[count] != '\0')
//		{
//			count++;
//		}
//		char* ptr = new char[count];
//		int i = 0;
//		while (i < count)
//		{
//			ptr[i] = str[i];
//			i++;
//		}
//		ptr[count] = '\0';
//		return ptr;
//	}
//
//
//	static bool compare(char* asd, char* jkl)
//	{
//		int counta = 0;
//		while (asd[counta] != '\0')
//		{
//			counta++;
//		}
//		int countb = 0;
//		while (jkl[countb] != '\0')
//		{
//			countb++;
//		}
//		if (counta == countb)
//		{
//			for (int i = 0; i < countb; i++)
//			{
//				if (asd[i] != jkl[i])
//				{
//					break;
//				}
//				else
//					if (i == countb - 1)
//					{
//						return true;
//					}
//			}
//			return false;
//		}
//		return false;
//	}
//
//};
//
//
//
//class Pages
//{
//	char* ID;
//	char* title;
//public:
//	static Pages** getpages(ifstream& fin, int& totalpages)
//	{
//		fin >> totalpages;
//		Pages** pg;
//		pg = new Pages * [totalpages];
//		for (int i = 0; i < totalpages; i++)
//		{
//			char buffer[100] = "";
//			fin >> buffer;
//			pg[i] = new Pages;
//			pg[i]->ID = helper::getStringfromBuffer(buffer);
//			fin.getline(buffer, 100);
//			pg[i]->title = helper::getStringfromBuffer(buffer);
//		}
//		return pg;
//	}
//
//
//	char* getter()
//	{
//		return ID;
//	}
//	void operator=(const Pages& asd)
//	{
//		this->ID = asd.ID;
//		this->title = asd.title;
//	}
//	void showpages()
//	{
//		cout << ID << '\t' << title << endl;
//	}
//};
//
//
//class User
//{
//	char* id = NULL;
//	User* friendList = NULL;
//	int friendnumber = 0;
//	char* first_Name = NULL;
//	char* second_Name = NULL;
//	int pagesnumber = 0;
//	Pages* liked_pages = NULL;
//public:
//
//
//	static User** getuserdata(ifstream& fin, Pages** page, int totalpages)
//	{
//		int totaluser;
//		fin >> totaluser;
//		char buffer[100] = "\0";
//		User** usd = new User * [totaluser];
//		char** temp = new char* [totaluser];
//		char** temptr = new char* [totaluser];
//		for (int i = 0; i < totaluser; i++)
//		{
//			usd[i] = new  User;
//			fin >> buffer;
//			usd[i]->id = helper::getStringfromBuffer(buffer);
//			fin >> buffer;
//			usd[i]->first_Name = helper::getStringfromBuffer(buffer);
//			fin >> buffer;
//			usd[i]->second_Name = helper::getStringfromBuffer(buffer);
//			fin >> buffer;
//			temp[i] = new char* [totaluser];
//			temptr[i] = new char* [totalpages];
//			while (buffer != "-1")
//			{
//				int p = 0;
//				if (buffer[p] == '-')
//				{
//					if (buffer[p + 1] == '1')
//					{
//						break;
//					}
//				}
//				else
//				{
//					temp[i][usd[i]->friendnumber] = helper::getStringfromBuffer(buffer);
//					usd[i]->friendnumber++;
//					fin >> buffer;
//				}
//			}
//			fin >> buffer;
//			while (buffer != "-1")
//			{
//
//				int p = 0;
//				if (buffer[p] == '-')
//				{
//					if (buffer[p + 1] == '1')
//					{
//						break;
//					}
//				}
//				else
//				{
//					temptr[i][usd[i]->pagesnumber] = helper::getStringfromBuffer(buffer);
//					usd[i]->pagesnumber++;
//					fin >> buffer;
//				}
//			}
//		}
//		for (int i = 0; i < totaluser; i++)
//		{
//			usd[i]->friendList = new User[usd[i]->friendnumber];
//			for (int j = 0; j < usd[i]->friendnumber; j++)
//			{
//				for (int t = 0; t < totaluser; t++)
//				{
//					char* id = usd[t]->id;
//					if (helper::compare(temp[i][j], id))
//					{
//						*(usd[i]->friendList + j) = *usd[t];
//						break;
//					}
//				}
//			}
//			usd[i]->liked_pages = new Pages[usd[i]->pagesnumber];
//			for (int j = 0; j < usd[i]->pagesnumber; j++)
//			{
//				for (int t = 0; t < totalpages; t++)
//				{
//					char* id = page[t]->getter();
//					if (helper::compare(temptr[i][j], id))
//					{
//						*(usd[i]->liked_pages + j) = *page[t];
//						break;
//					}
//				}
//			}
//		}
//		return usd;
//	}
//
//
//
//	char* getter()
//	{
//		return this->id;
//	}
//	friend ofstream& operator<<(ofstream& ost, User* us)
//	{
//		ost << us->first_Name << " " << us->second_Name;
//		return ost;
//	}
//	void operator=(const User& asd)
//	{
//		this->first_Name = asd.first_Name;
//		this->id = asd.id;
//		this->second_Name = asd.second_Name;
//	}
//	char* getfirstname()
//	{
//		return first_Name;
//	}
//	char* getsecondname()
//	{
//		return second_Name;
//	}
//	void showUser()
//	{
//		cout << " User ID :\t" << this->id << "\t" << this->first_Name << " " << this->second_Name << endl;
//	}
//	void showdetailedUser()
//	{
//		cout << " User ID :\t\t\t\t" << this->first_Name << " " << this->second_Name << endl;
//		for (int i = 0; i < 120; i++)
//			cout << "_";
//		cout << endl;
//		if (friendList != NULL)
//		{
//			cout << "\t\t\t\t\t\t\tFriend List\n";
//			for (int i = 0; i < 120; i++)
//				cout << "_";
//			cout << endl;
//			if (friendnumber > 0) {
//				for (int i = 0; i < friendnumber; i++)
//				{
//					cout << "F" << i + 1 << ":\t";
//					friendList[i].showUser();
//				}
//			}
//			else
//			{
//				cout << "No Friend at the moment\n";
//			}
//		}
//		for (int i = 0; i < 120; i++)
//			cout << "_";
//		cout << endl << endl;
//		cout << "\t\t\tPages Liked\n";
//		for (int i = 0; i < 120; i++)
//			cout << "_";
//		cout << endl;
//		if (pagesnumber > 0)
//		{
//			for (int i = 0; i < pagesnumber; i++)
//				liked_pages[i].Pages::showpages();
//		}
//		else
//		{
//			cout << "no Page liked yet\n";
//		}
//	}
//};
//
//
//
//
//class Facebook
//{
//	Pages** page;
//	User** user;
//public:
//	void load(ifstream& fin, ifstream& fun)
//	{
//		int totalpages = 0;
//		page = Pages::getpages(fin, totalpages);
//		user = User::getuserdata(fun, page, totalpages);
//	}
//
//
//	void run()
//	{
//		int i = 7;
//		cout << "Command\t\t\t\t\tSet current user to ID no u" << i << "\n";
//		for (int i = 0; i < 120; i++)
//			cout << "_";
//		cout << endl << endl << endl;
//		cout << "\t\t\t\t" << this->user[i - 1]->getfirstname() << this->user[i - 1]->getsecondname() << " is successfully set as current user\n";
//		for (int i = 0; i < 120; i++)
//			cout << "_";
//		cout << endl << endl << endl;
//		user[i - 1]->showdetailedUser();
//	}
//};
//
//
//void main()
//{
//	Facebook Fb;
//	ifstream fin;
//	fin.open("Pages.txt");
//	ifstream fun;
//	fun.open("Data.txt");
//	Fb.load(fin, fun);
//	Fb.run();
//}