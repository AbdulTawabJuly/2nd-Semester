//#include<iostream>
//#include<windows.h>
//#include<fstream>
//using namespace std;
//
//// <<------------------------Helper Class--------------------------->>
//class Helper
//{
//public:
//	static int StringLength(char* str)
//	{
//		int i = 0, count = 0;
//		while (str[i] != '\0')
//		{
//			i++;
//			count++;
//		}
//		return count;
//	}
//	static void StringCopy(char*& dest, char*& str) {
//		int length = StringLength(str);
//		int i = 0;
//		while (str[i] != '\0')
//		{
//			dest[i] = str[i];
//			i++;
//		}
//		dest[i] = '\0';
//	}
//	static char* GetStringFromBuffer(char* buffer)
//	{
//		int length = StringLength(buffer);
//		char* temp = new char[length + 1];
//		StringCopy(temp, buffer);
//		return temp;
//	}
//
//	static int returnIndex(char* buffer)
//	{
//		int length = Helper::StringLength(buffer);
//		int index = 0;
//		if (length == 2)
//		{
//			index = (int)buffer[1] - 49;
//		}
//		else if (length == 3)
//		{
//			index = ((int)buffer[1] - 48) * 10 + ((int)buffer[2] - 49);
//		}
//		else if (length == 5)
//		{
//			index = (int)buffer[4] - 49;
//		}
//		else 
//		{
//			index = ((int)buffer[4] - 48) * 10 + ((int)buffer[5] - 49);
//		}
//		return index;
//	}
//
//	static bool CompareString(char* arr1, char* arr2)
//	{
//		int i = 0;
//		while (arr2[i] != '\0')
//		{
//			if (arr1[i] != arr2[i])
//			{
//				return 0;
//			}
//			i++;
//		}
//		return true;
//	}
//	static bool Possible(int i)
//	{
//		if (i < 10)  // Max 10 
//			return true;
//		else
//			return false;
//	}
//
//	static void ShowTitle()
//	{
//		cout << "  \t\t*********  **********  ********  *********  ********    *********  *********  **       **      " << endl;
//		cout << "  \t\t*********  **********  ********  *********  ********    *********  *********  **      **      " << endl;
//		cout << "  \t\t**         **      **  **        **         **     **   **     **  **     **  **    **        " << endl;
//		cout << "  \t\t**         **      **  **        **         **     **   **     **  **     **  **  **          " << endl;
//		cout << "  \t\t*********  **********  **        *********  **********  **     **  **     **  ***             " << endl;
//		cout << "  \t\t*********  **********  **        *********  **********  **     **  **     **  **  **          " << endl;
//		cout << "  \t\t**         **      **  **        **         **      **  **     **  **     **  **    **        " << endl;
//		cout << "  \t\t**         **      **  **        **         **      **  **     **  **     **  **     **        " << endl;
//		cout << "  \t\t**         **      **  ********  *********  **********  *********  *********  **      **       " << endl;
//		cout << "  \t\t**         **      **  ********  *********  **********  *********  *********  **       **       " << endl;
//		cout << endl << endl << endl;
//	}
//
//	static void ShowLine()
//	{
//		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
//	}
//};
//
//class Facebook;
//class Activity;
//class Object;
//class Post;
//class Users;
//class Pages;
// 
// 
////<<-------------------------------Object Class-------------------------------------->>
//class Object
//{
//private:
//	char* ID;
//public:
//
//	Object()
//	{
//		ID = NULL;
//	}
//
//	void SetID(char* temp)
//	{
//		ID = Helper::GetStringFromBuffer(temp);
//	}
//
//	char* GetID()
//	{
//		return ID;
//	}
//
//	void PrintID()
//	{
//		cout << ID;
//	}
//
//	virtual void PrintName()
//	{
//		PrintID();
//	}
//
//	virtual void PrintListView()
//	{
//		cout << ID;
//	}
//};
//
////<<-----------------------------------Page Class------------------------------->>
//
//class Pages :public Object
//{
//private:
//	char* PageID;
//	char* PageName;
//public:
//	static int TotalPages;
//	Pages()
//	{
//		PageID = NULL;
//		PageName = NULL;
//	}
//
//	void ReadDataFromPageFile(ifstream& Read)
//	{
//		char temp[100] = { '\0' };
//		/*for (int i = 0; i < 20; i++)
//		{
//			temp[i] = '\0';
//		}*/
//		Read >> temp;
//		PageID = Helper::GetStringFromBuffer(temp);
//		for (int i = 0; i < 100; i++)
//		{
//			temp[i] = '\0';
//		}
//		Read.getline(temp, 100);
//		PageName = Helper::GetStringFromBuffer(temp);
//	}
//
//	static Pages* SetLikedPage(Pages** Pages, char* ID)
//	{
//		int i;
//		for (i = 0; i < Pages::TotalPages; i++)
//		{
//			if (Helper::CompareString(Pages[i]->PageID, ID))
//			{
//				return Pages[i];
//				//break;
//			}
//		}
//	}
//
//	char* GetPageID()
//	{
//		return this->PageID;
//	}
//
//	char* GetPageName()
//	{
//		return this->PageName;
//	}
//};
//int Pages::TotalPages = 0;
//
////<<----------------------------User Class----------------------------->>
//
//class Users :public Object
//{
//private:
//	char* UserID;
//	char* UserFName;
//	char* UserLName;
//	char** UserFriends;
//	Pages** LikedPagesList;
//	Users** FriendList;
//	Post** Timeline;
//	int NoofFriends;
//	int NoofLikedPages;
//	int NoofPosts;
//public:
//	static int TotalUsers;
//	Users()
//	{
//		UserID = NULL;
//		UserFName = NULL;
//		UserLName = NULL;
//		UserFriends = NULL;
//		FriendList = NULL;
//		LikedPagesList = NULL;
//		Timeline = NULL;
//		NoofFriends = 0;
//		NoofLikedPages = 0;
//		NoofPosts = 0;
//	}
//	void ReadDataFromUserFile(ifstream& Read, Pages** PageInfo, int tPages, Users* UserData)
//	{
//		//UserData = new Users; // It was Crashing if we Allocate Memory in the Previous Function
//
//		char temp[20] = { '\0' };
//		for (int i = 0; i < 20; i++)
//		{
//			temp[i] = '\0';
//		}
//		Read >> temp;
//		UserData->UserID = Helper::GetStringFromBuffer(temp);
//		for (int i = 0; i < 20; i++)
//		{
//			temp[i] = '\0';
//		}
//		Read >> temp;
//		UserData->UserFName = Helper::GetStringFromBuffer(temp);
//		for (int i = 0; i < 20; i++)
//		{
//			temp[i] = '\0';
//		}
//		Read >> temp;
//		UserData->UserLName = Helper::GetStringFromBuffer(temp);
//		for (int i = 0; i < 20; i++)
//		{
//			temp[i] = '\0';
//		}
//		Read >> temp;
//		UserData->UserFriends = new char* [20];
//		int i;
//		for (i = 0; temp[0] != '-' || temp[1] != '1'; i++)
//		{
//			UserData->UserFriends[i] = Helper::GetStringFromBuffer(temp);
//			Read >> temp;
//		}
//		UserData->NoofFriends = i;
//		for (int i = 0; i < 20; i++)
//		{
//			temp[i] = '\0';
//		}
//
//		UserData->LikedPagesList = new Pages * [10];
//		Read >> temp;
//		int j;
//		for (j = 0; temp[0] != '-' || temp[1] != '1'; j++)
//		{
//			//UserData->LikedPagesList[j] = new Pages;
//			UserData->LikedPagesList[j] = Pages::SetLikedPage(PageInfo, temp);
//			Read >> temp;
//		}
//		UserData->NoofLikedPages = j;
//	}
//
//	void ViewFriendList()
//	{
//		cout << " Command: View Friend List" << endl;
//		Helper::ShowLine();
//		cout << this->GetUserFName() << " " << this->GetUserLName() << " ->   Friend List" << endl << endl;
//		if (this->FriendList != NULL)
//		{
//			for (int i = 0; i < NoofFriends; i++)
//			{
//				cout << this->FriendList[i]->GetUserID() << "\t " << FriendList[i]->GetUserFName() << " " << FriendList[i]->GetUserLName() << endl;
//			}
//		}
//		else
//		{
//			cout << this->GetUserFName() << " " << this->GetUserLName() << " Has No Friends" << endl;
//		}
//	}
//
//	void ViewLikedPages()
//	{
//		cout << " Command: View Liked Pages" << endl;
//		Helper::ShowLine();
//		cout << this->GetUserFName() << " " << this->GetUserLName() << " ->   Liked Pages" << endl << endl;
//		for (int j = 0; j < this->NoofLikedPages; j++)
//		{
//			cout << this->LikedPagesList[j]->GetPageID() << "\t" << LikedPagesList[j]->GetPageName() << endl;
//		}
//	}
//	char* GetUserFName()
//	{
//		return this->UserFName;
//	}
//	char* GetUserLName()
//	{
//		return this->UserLName;
//	}
//	char* GetUserID()
//	{
//		return this->UserID;
//	}
//
//	int GetNoofFriends()
//	{
//		return this->NoofFriends;
//	}
//
//	int GetNoofLikedPages()
//	{
//		return this->NoofLikedPages;
//	}
//
//	void PrintName()
//	{
//		cout << UserFName << " " << UserLName;
//	}
//
//	static void SetFriends(Users** usersInfo, int TotalUsers)
//	{
//		char* ID;
//		for (int i = 0; i < TotalUsers; i++)
//		{
//			if (usersInfo[i]->NoofFriends != 0)
//			{
//				usersInfo[i]->FriendList = new Users * [usersInfo[i]->NoofFriends];
//				for (int j = 0; j < usersInfo[i]->NoofFriends; j++)
//				{
//					ID = usersInfo[i]->UserFriends[j];
//					for (int k = 0; k < TotalUsers; k++)
//					{
//						if (Helper::CompareString(usersInfo[k]->UserID, ID))
//						{
//							usersInfo[i]->FriendList[j] = new Users;
//							usersInfo[i]->FriendList[j] = usersInfo[k];
//							break;
//						}
//					}
//				}
//			}
//			else
//			{
//				usersInfo[i]->FriendList = NULL;
//			}
//		}
//	}
//
//	
//
//	void SetTimeline(Post*& P)
//	{
//		if (Timeline == NULL)
//		{
//			Timeline = new Post * [10];
//
//			for (int i = 0; i < 10; i++)
//			{
//				Timeline[i] = 0;
//			}
//		}
//		if (Helper::Possible(NoofPosts))
//		{
//			for (int i = 0; i < 10; i++)
//			{
//				if (Timeline[i] == NULL)
//				{
//					Timeline[i] = new Post;
//					Timeline[i]->SetID(P->GetID());
//					Timeline[i]->SetPostDescription(P->GetPostDescription());
//					Timeline[i]->SetSharedDate(P->GetSharedDate());
//					Timeline[i]->SetCommentCount(P->GetCommentCount());
//					Timeline[i]->SetCommentstoPost(P->GetComment());
//					Timeline[i]->SetShared(P->GetShared());
//					Timeline[i]->SetLikeCount(P->GetLikecount());
//					Timeline[i]->SetLikedUser(P->GetLikedBy());
//					//delete P;
//					P = Timeline[i];
//					NoofPosts++;
//					break;
//				}
//			}
//		 }
//	}
//
//};
//int Users::TotalUsers = 0;
//
////<<------------------------------- Date Class-------------------------------------- >>
//class Date
//{
//private:
//	int day;
//	int month;
//	int year;
//public:
//	Date()
//	{
//		day = 0;
//		month = 0;
//		year = 0;
//	}
//	Date(int _day,int _month,int _year)
//	{
//		day = _day;
//		month = _month;
//		year = _year;
//	}
//	void InputDate(ifstream & read)
//	{
//		read >> day >> month >> year;
//	}
//	void SetDate(int _day, int _month, int _year)
//	{
//		day = _day;
//		month = _month;
//		year = _year;
//	}
//	void PrintDate()
//	{
//		cout << "(";
//		if (day <= 9)
//		{
//			cout << '0' << day << '/';
//		}
//		else
//		{
//			cout << day << '/';
//		}
//		if (month <= 9)
//		{
//			cout << '0' << month << '/';
//		}
//		else
//		{
//			cout << month << '/';
//		}
//			cout << year<<")\n";
//	}
//	/*~Date()
//	{
//
//	}*/
//	void SetDate(Date post)
//	{
//		day = post.day;
//		month = post.month;
//		year = post.year;
//	}
//	int GetDay()
//	{
//		return day;
//	}
//};
//
////<<-------------------------------Activity Class-------------------------------------->>
//class Activity
//{
//private:
//	char* Value;
//	int TypeofActivity;
//public:
//
//	Activity()
//	{
//		Value = NULL;
//		TypeofActivity = 0;
//	}
//
//	void ReadData(ifstream& fin)
//	{
//		char temp[40] = { '\0' };
//		fin >> TypeofActivity;
//		fin >> temp;
//		Value =Helper::GetStringFromBuffer(temp);
//	}
//
//	void PrintMood()
//	{
//		if (TypeofActivity = 1)
//		{
//			cout << "Feeling " << Value;
//		}
//		if (TypeofActivity = 2)
//		{
//			cout << "Thinking About " << Value;
//		}
//		if (TypeofActivity = 3)
//		{
//			cout << "Making " << Value;
//		}
//		if (TypeofActivity = 4)
//		{
//			cout << "Celebrating " << Value;
//		}
//	}
//};
//
////<<-------------------------------Comment Class-------------------------------------->>
//
//class Comments :public Object
//{
//private:
//	/*char* CID;
//	char* PID;*/
//	char* Text;
//	char* CommentDescription;
//	Object* Commentator;
//public:
//	static int TotalComments;
//	Comments()
//	{
//		/*CID = NULL;
//		PID = NULL;*/
//		Text = NULL;
//		CommentDescription = NULL;
//		Commentator = NULL;
//	}
//
//	void SetCommentator(Object* U)
//	{
//		Commentator = U;
//	}
//
//	Object* GetCommentator()
//	{
//		return Commentator;
//	}
//
//
//	void SetText(char* buffer)
//	{
//		Text = Helper::GetStringFromBuffer(buffer);
//	}
//
//	char* GetText()
//	{
//		return Text;
//	}
//};
//int Comments::TotalComments = 0;
//
////<<-------------------------------Post Class-------------------------------------->>
//
//class Post :public Object
//{
//private:
//	int PostType;
//	char* PostID;
//	Date SharedDate;
//	Object* SharedBy;
//	Object** LikedBy;
//	Comments** comment;
//	Activity* Mood;
//	char* PostDescription;
//	char* ValueofActivity;
//	int CommentCount;
//	int LikeCount;
//	int SharedCount;
//public:
//	
//	static int TotalPosts;
//	Post() :SharedDate()
//	{
//		 PostType=0;
//		 PostID=0;
//		 SharedBy = NULL;
//		 LikedBy = NULL;
//		 PostDescription = NULL;
//		 ValueofActivity = NULL;
//		 comment = NULL;
//		 Mood = NULL;
//		 CommentCount = 0;
//		 LikeCount = 0;
//		 SharedCount = 0;
//	}
//	void ReadDataFromPostFile(ifstream& Read, Post* PostData)
//	{
//		char temp[100] = { '\0' };
//		Read >> PostData->PostType;
//		Read >> temp;
//		PostData->PostID = Helper::GetStringFromBuffer(temp);
//		for (int i = 0; i < 100; i++)
//		{
//			temp[i] = '\0';
//		}
//		PostData->SharedDate.InputDate(Read);
//		Read.ignore(1);
//		Read.getline(temp, 100);
//		PostData->PostDescription = Helper::GetStringFromBuffer(temp);
//		for (int i = 0; i < 100; i++)
//		{
//			temp[i] = '\0';
//		}
//		if (PostType == 2)
//		{
//			PostData->Mood = new Activity;      // Without This it was throwing Exception that this is NULLPTR
//			PostData->Mood->ReadData(Read);
//		}
//	}
//
//	void SetLiked(Object* LikingisFighting)
//	{
//		if (LikedBy == NULL)
//		{
//			LikedBy = new Object*[10];
//			for (int i = 0; i < 10; i++)
//			{
//				LikedBy[i] = NULL;
//			}
//		}
//		if (Helper::Possible(LikeCount))
//		{
//			for (int i = 0; i < 10; i++)
//			{
//				if (LikedBy[i] == NULL)
//				{
//					LikedBy[i] = LikingisFighting;
//					LikeCount++;
//					break;
//				}
//			}
//		}
//		else
//		{
//			cout << "YOU HAVE REACHED YOUR LIKE LIMIT\n";
//		}
//		
//	}
//	void SetLikedUser(Object** _liked)
//	{
//		if (LikedBy == NULL)
//		{
//			LikedBy = new Object * [10];
//			for (int i = 0; i < 10; i++)
//				LikedBy[i] = 0;
//		}
//
//		for (int i = 0; i < LikeCount; i++)
//		{
//			LikedBy[i] = _liked[i];
//		}
//	}
//
//	Object** GetLikedBy()
//	{
//		return LikedBy;
//	}
//	void AddComment(Comments*_Com)
//	{
//		if (comment == NULL)
//		{
//			comment = new Comments * [10];
//			for (int i = 0; i < 10; i++)
//			{
//				comment[i] = NULL;
//			}
//		}
//		int flag = 1;
//		if (Helper::Possible(CommentCount))
//		{
//			for (int i = 0; flag == 1; i++)
//			{
//				if (comment[i] == NULL)
//				{
//					comment[i] = new Comments;
//					comment[i]->SetID(_Com->GetID());
//					comment[i]->SetCommentator(_Com->GetCommentator());
//					comment[i]->SetText(_Com->GetText());
//					CommentCount++;
//					flag = 0;
//				}
//			}
//		}
//	}
//
//	void SetShared(Object* SharingisCaring)
//	{
//		if (SharedBy == NULL)
//		{
//			SharedBy = SharingisCaring;
//			SharedCount++;
//		}
//		else
//		{
//			cout << "Shared Max Limit is Reached" << endl;
//		}
//	}
//
//	void SetCommentstoPost(Comments **C)
//	{
//		if (C != NULL)
//		{
//			if (comment == NULL)
//			{
//				comment = new Comments * [10];
//				for (int i = 0; i < 10; i++)
//				{
//					comment[i] = 0;
//				}
//			}
//			for (int i = 0; i < CommentCount; i++)
//			{
//				comment[i] = new Comments;
//				comment[i]->SetCommentator(C[i]->GetCommentator());
//				comment[i]->SetText(C[i]->GetText());
//			}
//		}
//		else
//			comment = NULL;
//	}
//
//	void SetShared(Object* u)
//	{
//		if (Helper::Possible(SharedCount))
//		{
//			SharedBy = u;
//		}
//		else
//		{
//			cout << "MAXIMUM USERS HAVE SHARED\n";
//		}
//	}
//
//	int GetLikecount()
//	{
//		return LikeCount;
//	}
//
//	void SetLikeCount(int _count)
//	{
//		LikeCount = _count;
//	}
//
//	Object* GetShared()
//	{
//		return SharedBy;
//	}
//
//	Date GetSharedDate()
//	{
//		return SharedDate;
//	}
//	Comments** GetComment()
//	{
//		return comment;
//	}
//	void SetSharedDate(Date obj)
//	{
//		SharedDate = obj;
//	}
//
//	void SetCommentCount(int C)
//	{
//		CommentCount = C;
//	}
//
//	int GetCommentCount()
//	{
//		return CommentCount;
//	}
//
//	void SetPostDescription(char* post)
//	{
//		PostDescription = Helper::GetStringFromBuffer(post);
//	}
//
//	char* GetPostDescription()
//	{
//		return PostDescription;
//	}
//
//	void PrintName() {};
//};
//int Post::TotalPosts = 0;
//
////<<-------------------------------FaceBook Class-------------------------------------->>
//
//class Facebook :public Users
//{
//private:
//	Users** UserInfo;
//	Pages** PageInfo;
//	Post** PostInfo;
//	Users* CurrentUser;
//public:
//	static Date currentDate;
//	static int TotalComments;
//	static int TotalPosts;
//	static int TotalPages;
//	static int TotalUsers;
//	Facebook()
//	{
//		UserInfo = NULL;
//		PageInfo = NULL;
//		PostInfo = NULL;
//		CurrentUser = NULL;
//	}
//	/*~Facebook()
//	{
//		if (UserInfo != NULL)
//		{
//			for (int i = 0; i < TotalUsers; i++)
//				delete[]UserInfo[i];
//			delete[]UserInfo;
//			UserInfo = NULL;
//		}
//		if (PageInfo != NULL)
//		{
//			for (int i = 0; i < TotalPages; i++)
//				delete[]PageInfo[i];
//			delete[]PageInfo;
//			PageInfo = NULL;
//		}
//		delete[]CurrentUser;
//		CurrentUser = NULL;
//
//	}*/
//	void LoadData()
//	{
//		ifstream Read;
//		LoadPages(Read);
//		LoadUsers(Read);
// 		LoadPost(Read);
//		LoadComments(Read);
//
//	}
//
//	void LoadPost(ifstream &Read)
//	{
//		Read.open("Posts.txt");
//		char temp[100]={'\0'};
//		if (Read.is_open())
//		{
//			Read >> Post::TotalPosts;
// 			PostInfo = new Post * [Post::TotalPosts];
//			int i = 0;
//			while (!Read.eof() && i < Post::TotalPosts)
//			{
//				PostInfo[i] = new Post;
//				PostInfo[i]->ReadDataFromPostFile(Read,PostInfo[i]);
//
//				Read >> temp;    //  Reading Shared User/Page 
//				int index = Helper::returnIndex(temp);
//				if (temp[0] == 'u')
//				{
//					PostInfo[i]->SetShared(UserInfo[index]);
//				}
//				else if (temp[0] == 'p')
//				{
//					PostInfo[i]->SetShared(PageInfo[index]);
//				}
//				for (int i = 0; i < 100; i++)
//				{
//					temp[i] = '\0';
//				}
//				Read >> temp;
//				for (int j = 0; temp[0] != '-' || temp[1] != '1'; j++)
//				{
//					index = Helper::returnIndex(temp);
//					if (temp[0] == 'u')
//					{
//						PostInfo[i]->SetLiked(UserInfo[index]);
//					}
//					else if (temp[0] == 'p')
//					{
//						PostInfo[i]->SetLiked(PageInfo[index]);
//					}
//					Read >> temp;
//				}
//				i++; 
//			}
//			Read.close();
//		}
//		else
//		{
//			cout << "Post File was not Properly Opened" << endl;
//		}
//		
//	}
//
//	void LoadComments(ifstream& Read)
//	{
//		Read.open("Comments.txt");
//		if (Read.is_open())
//		{
//			char temp[100] = { '\0' };
//			Read >> Comments::TotalComments;
//			int i = 0;
//			while (!Read.eof() && i < Comments::TotalComments)
//			{
//				Read >> temp;
//				Comments* Comment = new Comments;
//				Comment->SetID(temp);
//				for (int i = 0; i < 100; i++)
//				{
//					temp[i] = '\0';
//				}
//				Read >> temp;
//				int PostIndex = Helper::returnIndex(temp);
//				for (int i = 0; i < 100; i++)
//				{
//					temp[i] = '\0';
//				}
//				Read >> temp;
//				int index = Helper::returnIndex(temp);
//				if (temp[0] == 'u')
//				{
//					Comment->SetCommentator(UserInfo[index]);
//				}
//				else
//				{
//					Comment->SetCommentator(PageInfo[index]);
//				}
//				for (int i = 0; i < 100; i++)
//				{
//					temp[i] = '\0';
//				}
//				Read.getline(temp, 100);
//				Comment->SetText(temp);
//				PostInfo[PostIndex]->AddComment(Comment);
//				i++;
//			}
//			Read.close();
//		}
//		else
//		{
//			cout << "Cooments File was not Properly Opened "<<endl;
//		}
//	}
//	void LoadPages(ifstream& Read)
//	{
//
//		Read.open("PagesData.txt");
//		if (Read.is_open())
//		{
//			Read >> Pages::TotalPages;
//			PageInfo = new Pages * [Pages::TotalPages];
//			int i = 0;
//			while (!Read.eof() && i < Pages::TotalPages)// 2nd Condition is for cases when it is still reading after end of file
//			{
//				PageInfo[i] = new Pages;
//				PageInfo[i]->ReadDataFromPageFile(Read);
//				i++;
//			}
//			Read.close();
//		}
//		else
//		{
//			cout << "Page File was not Properly Opened" << endl;
//		}
//	}
//
//	void LoadUsers(ifstream& Read)
//	{
//		Read.open("StudentRecord.txt");
//		if (Read.is_open())
//		{
//			Read >> Users::TotalUsers;
//			UserInfo = new Users * [Users::TotalUsers];
//			int i = 0;
//			while (!Read.eof() && i < Users::TotalUsers)// 2nd Condition is for cases when it is still reading after end of file
//			{
//				UserInfo[i] = new Users;
//				UserInfo[i]->ReadDataFromUserFile(Read, PageInfo, Pages::TotalPages, UserInfo[i]);
//				i++;
//			}
//			Users::SetFriends(UserInfo, Users::TotalUsers);
//			Read.close();
//		}
//		else
//		{
//			cout << "User File was not properly opened" << endl;
//		}
//	}
//
//
//	Users* SetCurrentUser(Users** Users, char* SearchUser)  //This Function Searches Given ID
//	{
//		for (int i = 0; i < 1; i++)
//		{
//			for (int j = 0; j < 20; j++)
//			{
//				char* UserID = Users[j][i].GetUserID();
//				if (Helper::CompareString(UserID, SearchUser))
//				{
//					return Users[j];
//				}
//			}
//		}
//		cout << "You Have Entered Wrong ID" << endl;
//		return NULL;
//	}
//
//	void Run()
//	{
//		char temp[10] = { 'u','2','0'};
//		cout << "Command:\tSet current user to " << temp << endl;
//		CurrentUser = SetCurrentUser(UserInfo, temp);
//		if (CurrentUser != NULL)
//		{
//			cout << CurrentUser->GetUserFName() << " " << CurrentUser->GetUserLName() << "  Successfully set as Current User " << endl << endl;
//			Helper::ShowLine();
//			CurrentUser->ViewFriendList();
//			cout << endl;
//			Helper::ShowLine();
//			CurrentUser->ViewLikedPages();
//			cout << endl;
//			Helper::ShowLine();
//			
//		}
//	}
//};
//Date Facebook::currentDate;
//int Facebook::TotalComments = 0;
//int Facebook::TotalPosts = 0;
//int Facebook::TotalUsers = 0;
//int Facebook::TotalPages = 0;
//int main()
//{
//	{
//		Helper::ShowTitle();
//		Facebook fb;
//		fb.LoadData();
//		fb.Run();
//	}
//	system("color 70");
//	cout << endl << endl << endl << endl << endl;
//	return 0;
//}
