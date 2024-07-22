#include<iostream>
#include<fstream>
using namespace std;
// <<------------------------Helper Class--------------------------->>
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
		while (str[i] != '\0')
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

	static int returnIndex(char* buffer)
	{
		int length = Helper::StringLength(buffer);
		int index = 0;
		if (length == 2)
		{
			index = (int)buffer[1] - 49;
		}
		else if (length == 3)
		{
			index = ((int)buffer[1] - 48) * 10 + ((int)buffer[2] - 49);
		}
		else if (length == 5)
		{
			index = (int)buffer[4] - 49;
		}
		else
		{
			index = ((int)buffer[4] - 48) * 10 + ((int)buffer[5] - 49);
		}
		return index;
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
	static bool Possible(int i)
	{
		if (i < 10)  // Max 10 
			return true;
		else
			return false;
	}

	static void ShowTitle()
	{
		cout << "  \t\t*********  **********  ********  *********  ********    *********  *********  **       **      " << endl;
		cout << "  \t\t*********  **********  ********  *********  ********    *********  *********  **      **      " << endl;
		cout << "  \t\t**         **      **  **        **         **     **   **     **  **     **  **    **        " << endl;
		cout << "  \t\t**         **      **  **        **         **     **   **     **  **     **  **  **          " << endl;
		cout << "  \t\t*********  **********  **        *********  **********  **     **  **     **  ***             " << endl;
		cout << "  \t\t*********  **********  **        *********  **********  **     **  **     **  **  **          " << endl;
		cout << "  \t\t**         **      **  **        **         **      **  **     **  **     **  **    **        " << endl;
		cout << "  \t\t**         **      **  **        **         **      **  **     **  **     **  **     **        " << endl;
		cout << "  \t\t**         **      **  ********  *********  **********  *********  *********  **      **       " << endl;
		cout << "  \t\t**         **      **  ********  *********  **********  *********  *********  **       **       " << endl;
		cout << endl << endl << endl;
	}

	static void ShowLine()
	{
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
};

class Object
{
private:

	char* ID;

public:

	Object();
	void SetID(char* );
	char* GetID();
	void PrintID();
	virtual void PrintName();
	virtual void PrintListView();

};

//<<------------------------------- Date Class-------------------------------------- >>
class Date
{
private:

	int day;
	int month;
	int year;

public:

	Date();
	Date(int, int, int);
	void InputDate(ifstream&);
	void SetDate(int, int, int);
	void PrintDate();
	//~Date();   // Date Class has only static members so no point of destructors
	void SetDate(Date);
	int GetDay();
	
};

//<<-------------------------------Activity Class-------------------------------------->>

class Activity
{
private:

	char* Value;
	int TypeofActivity;

public:

	Activity();
	void ReadData(ifstream& );
	void PrintMood();

};

//<<-------------------------------Comment Class-------------------------------------->>

class Comments :public Object
{
private:

	char* Text;
	Object* Commentator;

public:

	static int TotalComments;
	Comments();
	void SetCommentator(Object* );
	Object* GetCommentator();
	void SetText(char*);
	char* GetText();
	void PrintListView();

};
int Comments::TotalComments = 0;

//<<-------------------------------Post Class-------------------------------------->>

class Post :public Object
{
private:

	int PostType;
	char* PostID;
	Date SharedDate;
	Object* SharedBy;
	Object** LikedBy;
	Comments** comment;
	Activity* Mood;
	char* PostDescription;
	char* ValueofActivity;
	int CommentCount;
	int LikeCount;
	int SharedCount;

public:

	static int TotalPosts;
	Post();
	void ReadDataFromPostFile(ifstream& , Post* );
	void SetLiked(Object*);
	void SetLikedUser(Object** );
	Object** GetLikedBy();
	void AddComment(Comments* );
	void SetCommentstoPost(Comments**);
	void SetShared(Object* );
	int GetLikecount();
	void SetLikeCount(int );
	Object* GetShared();
	Date GetSharedDate();
	Comments** GetComment();
	void SetSharedDate(Date );
	int PostedDay();
	void SetCommentCount(int );
	int GetCommentCount();
	void SetPostDescription(char*);
	char* GetPostDescription();
	void PrintName(){};
	void PrintDetailedView();
	void PrintListView();

};

int Post::TotalPosts = 0;

//<<-----------------------------------Page Class------------------------------->>

class Pages :public Object
{
private:

	char* PageID;
	char* PageName;
	Post** TimelineP;

public:

	static int TotalPages;
	Pages();
	void ReadDataFromPageFile(ifstream&);
	static Pages* SetLikedPage(Pages**, char*);
	char* GetPageID();
	char* GetPageName();
	void ViewPosts();
	Pages* SearchPageByID(Pages **,char*);
	void AddPagePosttoTimeline(Post*&P)
	{
		if (TimelineP == NULL)
		{
			TimelineP = new Post * [10];

			for (int i = 0; i < 10; i++)
			{
				TimelineP[i] = 0;
			}
		}
		int i = 0;
		while (TimelineP[i] != 0)
		{
			i++;
		}
		TimelineP[i] = P;
	}

};

int Pages::TotalPages = 0;

//<<----------------------------User Class----------------------------->>

class Users :public Object
{
private:

	char* UserID;
	char* UserFName;
	char* UserLName;
	char** UserFriends;
	Pages** LikedPagesList;
	Users** FriendList;
	Post** TimelineU;
	int NoofFriends;
	int NoofLikedPages;
	int NoofPosts;

public:

	static int TotalUsers;
	Users();
	void ReadDataFromUserFile(ifstream&, Pages**, int, Users*);
	void ViewFriendList();
	void ViewLikedPages();
	char* GetUserFName();
	char* GetUserLName();
	char* GetUserID();
	int GetNoofFriends();
	int GetNoofLikedPages();
	void ViewPost();
	void PrintName();
	void ViewHome();
	Users* SearchUser(Users**,char*);
	void ViewTimeLine(Post**);
	void PrintTimeLineDetails();
	static void SetFriends(Users**, int);
	void AddUserPosttoTimeline(Post*& P)
	{
		if (TimelineU == NULL)
		{
			TimelineU = new Post * [10];

			for (int i = 0; i < 10; i++)
			{
				TimelineU[i] = 0;
			}
		}
		int i = 0;
		while (TimelineU[i] != 0)
		{
			i++;
		}
		TimelineU[i] = P;
	}

};

int Users::TotalUsers = 0;

//<<-------------------------------FaceBook Class-------------------------------------->>

class Facebook :public Users
{
private:

	Users** UserInfo;
	Pages** PageInfo;
	Post** PostInfo;
	Users* CurrentUser;

public:

	static Date currentDate;
	static int TotalComments;
	static int TotalPosts;
	static int TotalPages;
	static int TotalUsers;
	Facebook();
	/*~Facebook()
	{
		if (UserInfo != NULL)
		{
			for (int i = 0; i < TotalUsers; i++)
				delete[]UserInfo[i];
			delete[]UserInfo;
			UserInfo = NULL;
		}
		if (PageInfo != NULL)
		{
			for (int i = 0; i < TotalPages; i++)
				delete[]PageInfo[i];
			delete[]PageInfo;
			PageInfo = NULL;
		}
		delete[]CurrentUser;
		CurrentUser = NULL;

	}*/
	void LoadData();
	void LoadPost(ifstream&);
	void LoadComments(ifstream& );
	void LoadPages(ifstream& );
	void LoadUsers(ifstream& );
	Users* SetCurrentUser(Users** , char* );  //This Function Searches Given ID
	static int GetCurrentDay();
	void Run();

};

Date Facebook::currentDate(15,11,2017);
int Facebook::TotalComments = 0;
int Facebook::TotalPosts = 0;
int Facebook::TotalUsers = 0;
int Facebook::TotalPages = 0;

//---------------------------------------------------------------------------------

int main()
{
	{
		Helper::ShowTitle();
		Facebook fb;
		fb.LoadData();
		fb.Run();
	}
	cout << endl << endl << endl << endl << endl;
	return 0;
}

//------------------------------------------------------------------------------------
// Page Class Implementation

Pages::Pages()
{
	PageID = NULL;
	PageName = NULL;
	TimelineP = NULL;
}

void Pages::ReadDataFromPageFile(ifstream& Read)
{
	char temp[100] = { '\0' };
	/*for (int i = 0; i < 20; i++)
	{
		temp[i] = '\0';
	}*/
	Read >> temp;
	PageID = Helper::GetStringFromBuffer(temp);
	for (int i = 0; i < 100; i++)
	{
		temp[i] = '\0';
	}
	Read.getline(temp, 100);
	PageName = Helper::GetStringFromBuffer(temp);
}

Pages* Pages::SearchPageByID(Pages** PageInfo, char* SearchPage)  //This Function Searches Given ID
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			char* PageID = PageInfo[j][i].GetPageID();
			if (Helper::CompareString(PageID, SearchPage))
			{
				return PageInfo[j];
			}
		}
	}
	cout << "You Have Entered Wrong ID" << endl;
	return NULL;
}

Pages* Pages::SetLikedPage(Pages** Pages, char* ID)
{
	int i;
	for (i = 0; i < Pages::TotalPages; i++)
	{
		if (Helper::CompareString(Pages[i]->PageID, ID))
		{
			return Pages[i];
			//break;
		}
	}
}

void Pages::ViewPosts()
{                                                      //<--------- Here Might be an error because timeline isnt set yet
	for (int i = 0; i < Post::TotalPosts; i++)
	{
		int currentDay = Facebook::GetCurrentDay();
		int postedDay = TimelineP[i]->PostedDay();
		if (currentDay - postedDay == 1 || currentDay - postedDay == 0)
			TimelineP[i]->PrintDetailedView();
	}
}

char* Pages::GetPageID()
{
	return this->PageID;
}

char*Pages::GetPageName()
{
	return this->PageName;
}

//-----------------------------------------------------------------------------------------------
//Object Class Implementation

Object::Object()
{
	ID = NULL;
}

void Object::SetID(char* temp)
{
	ID = Helper::GetStringFromBuffer(temp);
}

char* Object::GetID()
{
	return ID;
}

void Object:: PrintID()
{
	cout << ID;
}

void Object::PrintName()
{
	PrintID();
}

void Object::PrintListView()
{
	cout << ID;
}

//------------------------------ Activity Class Implementation ----------------------------------------------
Activity::Activity()
{
	Value = NULL;
	TypeofActivity = 0;
}

void Activity::ReadData(ifstream& fin)
{
	char temp[40] = { '\0' };
	fin >> TypeofActivity;
	fin >> temp;
	Value = Helper::GetStringFromBuffer(temp);
}

void Activity::PrintMood()
{
	if (TypeofActivity = 1)
	{
		cout << "Feeling " << Value;
	}
	if (TypeofActivity = 2)
	{
		cout << "Thinking About " << Value;
	}
	if (TypeofActivity = 3)
	{
		cout << "Making " << Value;
	}
	if (TypeofActivity = 4)
	{
		cout << "Celebrating " << Value;
	}
}

//---------------------------------------------------------------------------------------------
//Date Class Implementation

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}

void Date:: InputDate(ifstream& read)
{
	read >> day >> month >> year;
}

void Date::SetDate(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}

void Date::PrintDate()
{
	cout << "(";
	if (day <= 9)
	{
		cout << '0' << day << '/';
	}
	else
	{
		cout << day << '/';
	}
	if (month <= 9)
	{
		cout << '0' << month << '/';
	}
	else
	{
		cout << month << '/';
	}
	cout << year << ")\n";
}

/*Date::~Date()
{

}*/

void Date::SetDate(Date post)
{
	day = post.day;
	month = post.month;
	year = post.year;
}

int Date::GetDay()
{
	return day;
}

//-------------------------------------------------------------
//Comments Class Implementation

Comments::Comments()
{
	Text = NULL;
	Commentator = NULL;
}

void Comments::SetCommentator(Object* U)
{
	Commentator = U;
}

Object* Comments::GetCommentator()
{
	return Commentator;
}

void Comments::SetText(char* buffer)
{
	Text = Helper::GetStringFromBuffer(buffer);
}

char* Comments:: GetText()
{
	return Text;
}

void Comments::PrintListView()
{
	cout << "           ";
	Commentator->PrintName();
	cout << " wrote:" << '"';
	cout << Text << '"' << endl << endl;
}

//---------------------------------------------------------------------------
//User Class Implementation

Users::Users()
{
	UserID = NULL;
	UserFName = NULL;
	UserLName = NULL;
	UserFriends = NULL;
	FriendList = NULL;
	LikedPagesList = NULL;
	TimelineU = NULL;
	NoofFriends = 0;
	NoofLikedPages = 0;
	NoofPosts = 0;
}

void Users::ReadDataFromUserFile(ifstream& Read, Pages** PageInfo, int tPages, Users* UserData)
{
	//UserData = new Users; // It was Crashing if we Allocate Memory in the Previous Function

	char temp[20] = { '\0' };
	for (int i = 0; i < 20; i++)
	{
		temp[i] = '\0';
	}
	Read >> temp;
	UserData->UserID = Helper::GetStringFromBuffer(temp);
	for (int i = 0; i < 20; i++)
	{
		temp[i] = '\0';
	}
	Read >> temp;
	UserData->UserFName = Helper::GetStringFromBuffer(temp);
	for (int i = 0; i < 20; i++)
	{
		temp[i] = '\0';
	}
	Read >> temp;
	UserData->UserLName = Helper::GetStringFromBuffer(temp);
	for (int i = 0; i < 20; i++)
	{
		temp[i] = '\0';
	}
	Read >> temp;
	UserData->UserFriends = new char* [20];
	int i;
	for (i = 0; temp[0] != '-' || temp[1] != '1'; i++)
	{
		UserData->UserFriends[i] = Helper::GetStringFromBuffer(temp);
		Read >> temp;
	}
	UserData->NoofFriends = i;
	for (int i = 0; i < 20; i++)
	{
		temp[i] = '\0';
	}

	UserData->LikedPagesList = new Pages * [10];
	Read >> temp;
	int j;
	for (j = 0; temp[0] != '-' || temp[1] != '1'; j++)
	{
		//UserData->LikedPagesList[j] = new Pages;
		UserData->LikedPagesList[j] = Pages::SetLikedPage(PageInfo, temp);
		Read >> temp;
	}
	UserData->NoofLikedPages = j;
}

void Users:: ViewFriendList()
{
	cout << " Command: View Friend List" << endl;
	Helper::ShowLine();
	cout << this->GetUserFName() << " " << this->GetUserLName() << " ->   Friend List" << endl << endl;
	if (this->FriendList != NULL)
	{
		for (int i = 0; i < NoofFriends; i++)
		{
			cout << this->FriendList[i]->GetUserID() << "\t " << FriendList[i]->GetUserFName() << " " << FriendList[i]->GetUserLName() << endl;
		}
	}
	else
	{
		cout << this->GetUserFName() << " " << this->GetUserLName() << " Has No Friends" << endl;
	}
}

Users* Users::SearchUser(Users** Users, char* SearchUser)  //This Function Searches Given ID
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			char* UserID = Users[j][i].GetUserID();
			if (Helper::CompareString(UserID, SearchUser))
			{
				return Users[j];
			}
		}
	}
	cout << "You Have Entered Wrong ID" << endl;
	return NULL;
}

void Users::ViewLikedPages()
{
	cout << " Command: View Liked Pages" << endl;
	Helper::ShowLine();
	cout << this->GetUserFName() << " " << this->GetUserLName() << " ->   Liked Pages" << endl << endl;
	for (int j = 0; j < this->NoofLikedPages; j++)
	{
		cout << this->LikedPagesList[j]->GetPageID() << "\t" << LikedPagesList[j]->GetPageName() << endl;
	}
}

void Users::ViewPost()
{                                                            // Extra Might delete after
		for (int i = 0; i < Post::TotalPosts; i++)
		{
			int currentDay = Facebook::GetCurrentDay();
			int postedDay = TimelineU[i]->PostedDay();
			if (currentDay - postedDay == 1 || currentDay - postedDay == 0)
				TimelineU[i]->PrintDetailedView();
		
	    }
}

char* Users::GetUserFName()
{
	return this->UserFName;
}
char* Users::GetUserLName()
{
	return this->UserLName;
}

char* Users::GetUserID()
{
	return this->UserID;
}

int Users::GetNoofFriends()
{
	return this->NoofFriends;
}

int Users::GetNoofLikedPages()
{
	return this->NoofLikedPages;
}

void Users::PrintName()
{
	cout << UserFName << " " << UserLName;
}

void Users::PrintTimeLineDetails()
{
	for (int i = 0; i < NoofPosts; i++)
	{
		int currentDay = Facebook::GetCurrentDay();
		int postedDay = TimelineU[i]->PostedDay();
		if (currentDay - postedDay == 1 || currentDay - postedDay == 0)
			TimelineU[i]->PrintDetailedView();
	}
}

void Users::ViewTimeLine(Post** PI)
{
	/*for (int i = 0; i < Post::TotalPosts; i++)
	{
	     Users::SetTimeline(PI[i]);
	}*/


	cout << this->GetUserFName() << " " << this->GetUserLName() << "\t->\tTime Line\n";
	for (int i = 0; i < NoofPosts; i++)
	{
		TimelineU[i]->PrintDetailedView();
		cout << endl;
	}
}

void Users::ViewHome()          // <---
{
	cout << this->GetUserFName() << " " << this->GetUserLName() << "\t->\tHome Page\n";
	for (int i = 0; i < NoofFriends; i++)
	{
		FriendList[i]->ViewFriendList();
		cout << endl;
	}
	for (int i = 0; i < NoofLikedPages; i++)
	{
		LikedPagesList[i]->ViewPosts();
		//FriendList[i]->ViewHome();
	}
}

void Users::SetFriends(Users** usersInfo, int TotalUsers)
{
	char* ID;
	for (int i = 0; i < TotalUsers; i++)
	{
		if (usersInfo[i]->NoofFriends != 0)
		{
			usersInfo[i]->FriendList = new Users * [usersInfo[i]->NoofFriends];
			for (int j = 0; j < usersInfo[i]->NoofFriends; j++)
			{
				ID = usersInfo[i]->UserFriends[j];
				for (int k = 0; k < TotalUsers; k++)
				{
					if (Helper::CompareString(usersInfo[k]->UserID, ID))
					{
						usersInfo[i]->FriendList[j] = new Users;
						usersInfo[i]->FriendList[j] = usersInfo[k];
						break;
					}
				}
			}
		}
		else
		{
			usersInfo[i]->FriendList = NULL;
		}
	}
}

//----------------------------------------------------------------------------------------
//Post Class Implementation

Post::Post() :SharedDate()
{
	PostType = 0;
	PostID = 0;
	SharedBy = NULL;
	LikedBy = NULL;
	PostDescription = NULL;
	ValueofActivity = NULL;
	comment = NULL;
	Mood = NULL;
	CommentCount = 0;
	LikeCount = 0;
	SharedCount = 0;
}

void Post::ReadDataFromPostFile(ifstream& Read, Post* PostData)
{
	char temp[100] = { '\0' };
	Read >> PostData->PostType;
	Read >> temp;
	PostData->PostID = Helper::GetStringFromBuffer(temp);
	for (int i = 0; i < 100; i++)
	{
		temp[i] = '\0';
	}
	PostData->SharedDate.InputDate(Read);
	Read.ignore(1);
	Read.getline(temp, 100);
	PostData->PostDescription = Helper::GetStringFromBuffer(temp);
	for (int i = 0; i < 100; i++)
	{
		temp[i] = '\0';
	}
	if (PostType == 2)
	{
		PostData->Mood = new Activity;      // Without This it was throwing Exception that this is NULLPTR
		PostData->Mood->ReadData(Read);
	}
}

void Post::SetLiked(Object* LikingisFighting)
{
	if (LikedBy == NULL)
	{
		LikedBy = new Object * [10];
		for (int i = 0; i < 10; i++)
		{
			LikedBy[i] = NULL;
		}
	}
	if (Helper::Possible(LikeCount))
	{
		for (int i = 0; i < 10; i++)
		{
			if (LikedBy[i] == NULL)
			{
				LikedBy[i] = LikingisFighting;
				LikeCount++;
				break;
			}
		}
	}
	else
	{
		cout << "YOU HAVE REACHED YOUR LIKE LIMIT\n";
	}

}

void Post::SetLikedUser(Object** _liked)
{
	if (LikedBy == NULL)
	{
		LikedBy = new Object * [10];
		for (int i = 0; i < 10; i++)
			LikedBy[i] = 0;
	}

	for (int i = 0; i < LikeCount; i++)
	{
		LikedBy[i] = _liked[i];
	}
}

Object** Post:: GetLikedBy()
{
	return LikedBy;
}

void Post::AddComment(Comments* _Com)
{
	if (comment == NULL)
	{
		comment = new Comments * [10];
		for (int i = 0; i < 10; i++)
		{
			comment[i] = NULL;
		}
	}
	int flag = 1;
	if (Helper::Possible(CommentCount))
	{
		for (int i = 0; flag == 1; i++)
		{
			if (comment[i] == NULL)
			{
				comment[i] = new Comments;
				comment[i]->SetID(_Com->GetID());
				comment[i]->SetCommentator(_Com->GetCommentator());
				comment[i]->SetText(_Com->GetText());
				CommentCount++;
				flag = 0;
			}
		}
	}
}

//void Post::SetShared(Object* SharingisCaring)
//{
//	if (SharedBy == NULL)
//	{
//		SharedBy = SharingisCaring;
//		SharedCount++;
//	}
//	else
//	{
//		cout << "Shared Max Limit is Reached" << endl;
//	}
//}

void Post::SetShared(Object* u)
{
	if (Helper::Possible(SharedCount))
	{
		SharedBy = u;
	}
	else
	{
		cout << "MAXIMUM USERS HAVE SHARED\n";
	}
}

void Post::SetCommentstoPost(Comments** C)
{
	if (C != NULL)
	{
		if (comment == NULL)
		{
			comment = new Comments * [10];
			for (int i = 0; i < 10; i++)
			{
				comment[i] = 0;
			}
		}
		for (int i = 0; i < CommentCount; i++)
		{
			comment[i] = new Comments;
			comment[i]->SetCommentator(C[i]->GetCommentator());
			comment[i]->SetText(C[i]->GetText());
		}
	}
	else
		comment = NULL;
}

int Post::PostedDay()
{
	return SharedDate.GetDay();
}

int Post::GetLikecount()
{
	return LikeCount;
}

void Post::SetLikeCount(int _count)
{
	LikeCount = _count;
}

Object* Post::GetShared()
{
	return SharedBy;
}

Date Post::GetSharedDate()
{
	return SharedDate;
}
Comments** Post::GetComment()
{
	return comment;
}
void Post::SetSharedDate(Date obj)
{
	SharedDate = obj;
}

void Post::SetCommentCount(int C)
{
	CommentCount = C;
}

int Post::GetCommentCount()
{
	return CommentCount;
}

void Post::PrintDetailedView()
{
	if (SharedBy != NULL)
	{
		SharedBy->PrintName();
		cout << "shared :";
	}
	cout << "\"" << PostDescription << "\"" << "...";
	SharedDate.PrintDate();

	if (comment != NULL)
	{
		for (int i = 0; i < CommentCount; i++)
			comment[i]->PrintListView();
	}
}

void Post::PrintListView()
{
	cout << "\"" << PostDescription << "\"" << "...";
	SharedDate.PrintDate();
}

void Post::SetPostDescription(char* post)
{
	PostDescription = Helper::GetStringFromBuffer(post);
}

char* Post::GetPostDescription()
{
	return PostDescription;
}

void PrintName() {};

//----------------------------------------------------------------------------------
//FaceBook Class Implementation

Facebook::Facebook()
{
	UserInfo = NULL;
	PageInfo = NULL;
	PostInfo = NULL;
	CurrentUser = NULL;
}

/*Facebook::~Facebook()
{
	if (UserInfo != NULL)
	{
		for (int i = 0; i < TotalUsers; i++)
			delete[]UserInfo[i];
		delete[]UserInfo;
		UserInfo = NULL;
	}
	if (PageInfo != NULL)
	{
		for (int i = 0; i < TotalPages; i++)
			delete[]PageInfo[i];
		delete[]PageInfo;
		PageInfo = NULL;
	}
	delete[]CurrentUser;
	CurrentUser = NULL;

}*/

void Facebook::LoadData()
{
	ifstream Read;
	LoadPages(Read);
	LoadUsers(Read);
	LoadPost(Read);
	LoadComments(Read);

}

void Facebook::LoadPost(ifstream& Read)
{
	Read.open("Posts.txt");
	char temp[100] = { '\0' };
	Users* tempU=NULL;
	Pages* tempP = NULL;
	if (Read.is_open())
	{
		Read >> Post::TotalPosts;
		PostInfo = new Post * [Post::TotalPosts];
		int i = 0;
		while (!Read.eof() && i < Post::TotalPosts)
		{
			PostInfo[i] = new Post;
			PostInfo[i]->ReadDataFromPostFile(Read, PostInfo[i]);

			Read >> temp;    //  Reading Shared User/Page 
			int index = Helper::returnIndex(temp);
			if (temp[0] == 'u')
			{
				PostInfo[i]->SetShared(UserInfo[index]);
				//tempU->Users::SearchUser(UserInfo,temp);
				//tempU->AddUserPosttoTimeline(PostInfo[i]);// Search user by id
			}

			else if (temp[0] == 'p')
			{
				PostInfo[i]->SetShared(PageInfo[index]);
				//tempP->SearchPageByID(PageInfo, temp);
				//tempP->AddPagePosttoTimeline(PostInfo[i]); // search page by id
			}

			for (int i = 0; i < 100; i++)
			{
				temp[i] = '\0';
			}
			Read >> temp;
			for (int j = 0; temp[0] != '-' || temp[1] != '1'; j++)
			{
				index = Helper::returnIndex(temp);
				if (temp[0] == 'u')
				{
					PostInfo[i]->SetLiked(UserInfo[index]);
				}
				else if (temp[0] == 'p')
				{
					PostInfo[i]->SetLiked(PageInfo[index]);
				}
				Read >> temp;
			}
			i++;
		}
		Read.close();
	}
	else
	{
		cout << "Post File was not Properly Opened" << endl;
	}

}

void Facebook::LoadComments(ifstream& Read)
{
	Read.open("Comments.txt");
	if (Read.is_open())
	{
		char temp[100] = { '\0' };
		Read >> Comments::TotalComments;
		int i = 0;
		while (!Read.eof() && i < Comments::TotalComments)
		{
			Read >> temp;
			Comments* Comment = new Comments;
			Comment->SetID(temp);
			for (int i = 0; i < 100; i++)
			{
				temp[i] = '\0';
			}
			Read >> temp;
			int PostIndex = Helper::returnIndex(temp);
			for (int i = 0; i < 100; i++)
			{
				temp[i] = '\0';
			}
			Read >> temp;
			int index = Helper::returnIndex(temp);
			if (temp[0] == 'u')
			{
				Comment->SetCommentator(UserInfo[index]);
			}
			else
			{
				Comment->SetCommentator(PageInfo[index]);
			}
			for (int i = 0; i < 100; i++)
			{
				temp[i] = '\0';
			}
			Read.getline(temp, 100);
			Comment->SetText(temp);
			PostInfo[PostIndex]->AddComment(Comment);
			i++;
		}

		
		Read.close();
	}
	else
	{
		cout << "Cooments File was not Properly Opened " << endl;
	}
}

void Facebook::LoadPages(ifstream& Read)
{

	Read.open("PagesData.txt");
	if (Read.is_open())
	{
		Read >> Pages::TotalPages;
		PageInfo = new Pages * [Pages::TotalPages];
		int i = 0;
		while (!Read.eof() && i < Pages::TotalPages)// 2nd Condition is for cases when it is still reading after end of file
		{
			PageInfo[i] = new Pages;
			PageInfo[i]->ReadDataFromPageFile(Read);
			i++;
		}
		Read.close();
	}
	else
	{
		cout << "Page File was not Properly Opened" << endl;
	}
}

void Facebook::LoadUsers(ifstream& Read)
{
	Read.open("StudentRecord.txt");
	if (Read.is_open())
	{
		Read >> Users::TotalUsers;
		UserInfo = new Users * [Users::TotalUsers];
		int i = 0;
		while (!Read.eof() && i < Users::TotalUsers)// 2nd Condition is for cases when it is still reading after end of file
		{
			UserInfo[i] = new Users;
			UserInfo[i]->ReadDataFromUserFile(Read, PageInfo, Pages::TotalPages, UserInfo[i]);
			i++;
		}
		Users::SetFriends(UserInfo, Users::TotalUsers);
		Read.close();
	}
	else
	{
		cout << "User File was not properly opened" << endl;
	}
}

Users* Facebook::SetCurrentUser(Users** Users, char* SearchUser)  //This Function Searches Given ID
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			char* UserID = Users[j][i].GetUserID();
			if (Helper::CompareString(UserID, SearchUser))
			{
				return Users[j];
			}
		}
	}
	cout << "You Have Entered Wrong ID" << endl;
	return NULL;
}

int Facebook::GetCurrentDay()
{
	return currentDate.GetDay();
}  

void Facebook::Run()
{
	char temp[10] = { 'u','7'};
	cout << "Command:\tSet current user to " << temp << endl;
	CurrentUser = SetCurrentUser(UserInfo, temp);
	if (CurrentUser != NULL)
	{
		cout << CurrentUser->GetUserFName() << " " << CurrentUser->GetUserLName() << "  Successfully set as Current User " << endl << endl;
		Helper::ShowLine();
		CurrentUser->ViewFriendList();
		cout << endl;
		Helper::ShowLine();
		CurrentUser->ViewLikedPages();
		//cout << endl;
		//Helper::ShowLine();
		//cout << endl;
		//CurrentUser->ViewTimeLine(PostInfo);
		cout << "Command:\tView Home\n";
		/*Helper::ShowLine();
		CurrentUser->ViewHome();
		Helper::ShowLine();
		cout << endl;*/
	}
}
