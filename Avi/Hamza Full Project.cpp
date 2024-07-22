#include<iostream>
#include<fstream>
using namespace std;


class User;
class Page;
class Activity;
class Date;
class Post;
class Comment;
class Facebook;
class Memory;

class Helper
{
public:
	static int StringLength(char* arr)
	{
		int i = 0;
		while (arr[i] != '\0')
		{
			i++;
		}
		return i;
	}
	static void StringCopy(char*& arr1, char* arr2)
	{
		int i = 0;
		while (arr2[i] != '\0')
		{
			arr1[i] = arr2[i];
			i++;
		}
		arr1[i] = '\0';
	}
	static char* GetStringFromBuffer(char* arr1)
	{
		int length;
		length = StringLength(arr1);
		char* arr = new char[length + 1];
		StringCopy(arr, arr1);
		return arr;
	}
	static int NumOfFriends(char** arr)
	{
		int count = 0;
		for (int i = 0; i < 10; i++)
		{
			if (arr[i] == 0)
			{

			}
			else {
				count++;
			}
		}
		return count;
	}
};

template<class T>
class deAllocation
{
public:
	static void DeallocateMemory(T*& ptr)
	{
		if (ptr != NULL)
		{
			delete[] ptr;
			ptr = NULL;
		}
	}
	static void Deallocate2DMemory(T**& ptr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] != NULL)
			{
				delete ptr[i];
				ptr[i] = NULL;
			}
		}
		delete[] ptr;
		ptr = NULL;
	}
};

class Object		// Base Class
{
	char* ID;
public:
	Object();
	~Object();
	void LoadID(ifstream& fin);
	virtual char* GetID()
	{
		return ID;
	}
	virtual void AddPostToTimeline(Post*) {};
	virtual void PrintName() {};
	virtual char* GetName() = 0;
};

class Comment
{
	char* ID;
	char* commentText;
	Object* commentBy;
public:
	~Comment();
	void setComments(char*, char*, Object*);
	void PrintComments()
	{
		commentBy->PrintName();
		cout << " wrote: " << commentText << endl;
	}
	void SetNewComment(char* txt, Object* comBy)
	{
		commentText = txt;
		commentBy = comBy;
	}
};

Comment::~Comment()
{
	deAllocation<char>::DeallocateMemory(ID);
	deAllocation<char>::DeallocateMemory(commentText);
	commentBy = NULL;
}

class Activity
{
	int activityType;
	char* activityText;
public:
	Activity();
	~Activity()
	{
		delete[] activityText;
	}
	//friend class Post;
	void ReadActivityFromFile(ifstream& fin);
	void PrintActivity()
	{
		if (activityType == 1)
		{
			cout << "is feeling " << activityText << endl;
		}
		if (activityType == 2)
		{
			cout << "is talking about " << activityText << endl;
		}
		if (activityType == 3)
		{
			cout << "is making " << activityText << endl;
		}
		if (activityType == 4)
		{
			cout << "is celebrating " << activityText << endl;
		}
	}
};


class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	void ReadDateFromFile(ifstream& fin);
	static Date currentDate;
	void SetCurrentDate(int, int, int);
	bool CheckLatest()
	{
		if (currentDate.day == day || currentDate.day - 1 == day && currentDate.month == month && currentDate.year == year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend ostream& operator<<(ostream&, Date&);
	int GetDay()
	{
		return day;
	}
	int GetMonth()
	{
		return month;
	}
	int GetYear()
	{
		return year;
	}

};


Date Date::currentDate;

void Date::SetCurrentDate(int d, int m, int y)
{
	currentDate.day = d;
	currentDate.month = m;
	currentDate.year = y;
}

ostream& operator<< (ostream& out, Date& date)
{
	out << "(" << date.day << "," << date.month << "," << date.year << ")";
	return out;
}

Object::Object()
{
	ID = 0;
}

Object::~Object()
{
	delete ID;
	ID = NULL;
}

void Object::LoadID(ifstream& fin)
{
	char temp[100];
	fin >> temp;
	ID = Helper::GetStringFromBuffer(temp);
}

class Post // : public Date, Activity
{
	Comment** Comments{ new Comment * [10]{0,0,0,0,0,0,0,0,0,0} };
	int numberOfLikes;
	char* postID;
	char* text;				// getline the text
	Date sharedDate;
	char** comments;
	Activity* activity;
	int isActivity;
	Object* sharedBy;
	Object** likedBy{ new Object * [10] {0,0,0,0,0,0,0,0,0,0} };
	int numberOfComments;


public:
	Post();
	~Post();
	void ReadPostFromFile(ifstream& fin);
	void SetSharedBy(Object* ptr);
	void SetLikedBy(Object* ptr);
	char* GetPostID();
	void addComment(Comment* ptr);
	Date& GetDate()
	{
		return sharedDate;
	}
	void PrintLatestPost()
	{
		if (sharedDate.CheckLatest())
		{
			if (activity != NULL)
			{
				sharedBy->PrintName();
				activity->PrintActivity();
				cout << text << endl;		// post text
				for (int i = 0; i < numberOfComments; i++)
				{
					Comments[i]->PrintComments();
				}
			}
			else
			{
				sharedBy->PrintName();
				cout << text << endl;		// post text
				for (int i = 0; i < numberOfComments; i++)
				{
					Comments[i]->PrintComments();
				}
			}
		}
	}
	virtual void PrintPost()
	{
		if (activity != NULL)
		{
			sharedBy->PrintName();
			activity->PrintActivity();
			cout << " " << text << "" << sharedDate << endl;
			for (int i = 0; i < numberOfComments; i++)
			{
				Comments[i]->PrintComments();
			}
		}
		else
		{
			sharedBy->PrintName();
			cout << " " << text << "" << sharedDate << endl;
			for (int i = 0; i < numberOfComments; i++)
			{
				Comments[i]->PrintComments();
			}
		}
	}
	void printLikedBy()
	{
		cout << " \n-------------------------------------------\n ";
		cout << "Command: \t\t" << "ViewLikedList : " << GetPostID();
		cout << "\n\nPost Liked By : \n";
		for (int i = 0; i < numberOfLikes; i++)
		{
			cout << likedBy[i]->GetID() << "\t";
			likedBy[i]->PrintName();
			cout << endl;
		}
	}
	void AddLikedBy(Object* ptr)
	{
		likedBy[numberOfLikes] = ptr;
		++numberOfLikes;
	}
	void AddingNewComment(char* text, Object* ptr)
	{
		Comments[numberOfComments] = new Comment;
		Comments[numberOfComments]->SetNewComment(text, ptr);
		++numberOfComments;
	}
	bool CheckMemories()
	{
		if (sharedDate.GetDay() == Date::currentDate.GetDay() && sharedDate.GetMonth() == Date::currentDate.GetMonth() && sharedDate.GetYear() != Date::currentDate.GetYear())
		{
			return true;
		}
		else
			return false;
	}
	void SetCurrentDate(Date& obj)
	{
		sharedDate = obj;
	}
	char* getSharedByName()
	{
		return sharedBy->GetName();
	}
};


class Page : public Object		// Derived class
{
	static int totalPages;
	char* pageID;
	char* pageTitle;
	Post** timeLine{ new Post * [10]{0,0,0,0,0,0,0,0,0,0} };
	int timelineCount;
public:
	Page();
	~Page();
	void ReadPageFromFile(ifstream& fin);
	char* GetPageID();
	void PrintLikedPages();
	void AddPostToTimeline(Post*);
	void PrintName()
	{
		cout << pageTitle;
	};
	char* GetID()
	{
		return pageID;
	}
	char* GetName()
	{
		return pageTitle;
	}
	void PrintFullPage()
	{
		cout << pageID << " - " << pageTitle << endl;
		for (int i = 0; i < timelineCount; i++)
		{
			timeLine[i]->PrintPost();
			cout << endl << endl;
		}
	}
	void printPage()
	{
		cout << pageID << " - " << pageTitle << endl;
	}
};
int Page::totalPages = 0;

class Memory : public Post
{
	Post* originalPost{ NULL };
	char* shareText{ NULL };

public:

	Memory(Post* p, char* txt, Object* sharedBy)
	{
		originalPost = p;
		shareText = txt;
		SetSharedBy(sharedBy);
		SetCurrentDate(Date::currentDate);
	}
	~Memory()
	{
		originalPost = NULL;
		delete[] shareText;
		shareText = NULL;
	}
	void PrintPost()
	{
		cout << "~~~" << getSharedByName() << " shared a memory ~~~";
		cout << GetDate();
		cout << endl << '"' << shareText << '"' << endl;
		cout << "\t\t(" << (this->GetDate(), originalPost->GetDate()) << " Years Ago)\n\n";
		originalPost->PrintPost();
	}
};



Post::~Post()
{
	deAllocation<char>::DeallocateMemory(postID);
	deAllocation<char>::DeallocateMemory(text);

	delete activity;
	activity = 0;
	delete[] likedBy;
	likedBy = 0;

	deAllocation<Comment>::Deallocate2DMemory(Comments, numberOfComments);
}


class User : public Object		// Derived class
{
	int noOfFriends;
	int totalPagesLiked;
	char* userID;
	char* fName;
	char* lName;
	User** friendList;
	Page** likedPagesList;
	Post** timeLine{ new Post * [10]{0,0,0,0,0,0,0,0,0,0} };
	int timelineCount;

public:
	User();
	~User();
	void ReadUserFromFile(ifstream& fin);
	char* GetUserID();
	void AddLikedPage(Page*);
	void AddFriend(User*);///declaration same as Like page
	int GetNumberOfFriends();
	void PrintUserInfo();
	void AddPostToTimeline(Post*);
	void PrintLatestPost();
	void PrintName()
	{
		cout << fName << " " << lName;
	};
	void PrintHomePage();
	char* GetName()
	{
		return fName;
	}
	void PrintTimeline()
	{
		cout << "-------------------------------------------------------" << endl;		//printing timeline
		this->PrintName(); cout << "- Timeline" << endl;
		for (int i = 0; i < timelineCount; i++)
		{
			timeLine[i]->PrintPost();
		}
	}
	char* GetID()
	{
		return userID;
	}

	void LikeAPost(Post* postID)
	{
		timeLine[timelineCount] = postID;
		++timelineCount;
		postID->AddLikedBy(this);
	}
	void ViewYourMemories()
	{
		cout << "We hope you enjoy looking back and sharing your memories of Facebook, from the most recent to those long ago" << endl;
		cout << "On this day" << endl;
		for (int i = 0; i < timelineCount; i++)
		{
			if (timeLine[i]->CheckMemories())
			{
				timeLine[i]->PrintPost();
			}
		}
	}

	void ShareMemory(char* txt, Post* p)
	{
		Memory* mem = new Memory{ p,txt,this };			// this has post ka pointer
		AddPostToTimeline(mem);
	}
	void printUser()
	{
		cout << "\nCommand : \tView Friend List\n\n";
		cout << "--------------------------------------------------------------------------------------\n\n";
		cout << fName << " " << lName << " -- Friend List\n\n";
		for (int i = 0; i < this->noOfFriends; i++)
		{
			friendList[i]->PrintSingleUser();
		}
		cout << "\n--------------------------------------------------------------------------------------\n\n";
		cout << "Command : \tView Liked Pages\n\n";
		cout << "--------------------------------------------------------------------------------------\n\n";
		cout << fName << " " << lName << " -- Liked Pages\n\n";
		for (int i = 0; i < this->totalPagesLiked; i++)
		{
			likedPagesList[i]->printPage();
		}
	}
	void PrintSingleUser()
	{
		cout << userID << " - " << fName << " " << lName << endl;
	}
};


class Facebook
{
	Post** Posts;
	Page** Pages;
	User** Users;
	static int totalPages;
	static int totalUsers;
	static int totalPosts;
	static int totalComments;
public:
	Facebook();
	~Facebook();
	void LoadData();
	void LoadUsers(ifstream& fin);
	void LoadPages(ifstream& fin);
	User* SearchUserByID(char*);
	Page* SearchPageByID(char*);
	void Run();
	void LoadPosts(ifstream& fin);
	void LoadComments(ifstream& fin);
	Post* SearchPostByID(char*);

};


void User::PrintHomePage()
{
	for (int i = 0; i < noOfFriends; i++)
	{
		friendList[i]->PrintLatestPost();
	}
}


void User::PrintLatestPost()
{
	for (int i = 0; i < timelineCount; i++)
	{
		timeLine[i]->PrintLatestPost();
	}
}


int Facebook::totalPages = 0;
int Facebook::totalUsers = 0;
int Facebook::totalPosts = 0;
int Facebook::totalComments = 0;

Page::Page()
{
	pageID = 0;
	pageTitle = 0;
}



Page::~Page()
{
	deAllocation<char>::DeallocateMemory(pageID);
	deAllocation<char>::DeallocateMemory(pageTitle);
	for (int i = 0; i < totalPages; i++)
	{
		delete timeLine[i];
	}
	delete[] timeLine;
	timeLine = NULL;
}

Facebook::Facebook()
{
	totalPages = 0;
	Pages = 0;
	Users = 0;
}


Facebook::~Facebook()
{

	deAllocation<Page>::Deallocate2DMemory(Pages, Facebook::totalPages);
	deAllocation<User>::Deallocate2DMemory(Users, Facebook::totalUsers);

	delete[] Posts;
	Posts = 0;
}

int User::GetNumberOfFriends()
{
	return noOfFriends;
}

User::User()
{
	userID = 0;
	fName = 0;
	lName = 0;
	friendList = new User * [10]{ 0,0,0,0,0,0,0,0,0,0 };
	likedPagesList = new Page * [10]{ 0,0,0,0,0,0,0,0,0,0 };
	totalPagesLiked = 0;
	noOfFriends = 0;
}

User::~User()
{
	deAllocation<char>::DeallocateMemory(userID);
	deAllocation<char>::DeallocateMemory(fName);
	deAllocation<char>::DeallocateMemory(lName);

	delete[] friendList;
	friendList = 0;
	delete[] likedPagesList;
	likedPagesList = 0;

	deAllocation<Post>::Deallocate2DMemory(timeLine, timelineCount);
}


void User::AddLikedPage(Page* ptr)
{
	likedPagesList[totalPagesLiked] = ptr;
	totalPagesLiked++;
}

void User::AddFriend(User* ptr)
{
	friendList[noOfFriends] = ptr;
	noOfFriends++;
}




char* Post::GetPostID()
{
	return postID;
}

void Facebook::LoadPosts(ifstream& fin)
{
	fin >> totalPosts;

	Posts = new Post * [totalPosts];


	for (int i = 0; i < totalPosts; i++)
	{
		Posts[i] = new Post;
		Posts[i]->ReadPostFromFile(fin);

		char temp[100];
		fin >> temp;						// Junk won't be on 0th index so this will work properly


		if (temp[0] == 'u')
		{
			char* ID = Helper::GetStringFromBuffer(temp);
			Object* sharedByPtr = SearchUserByID(temp);
			Posts[i]->SetSharedBy(sharedByPtr);
			sharedByPtr->AddPostToTimeline(Posts[i]);
		}
		else if (temp[0] == 'p')
		{
			char* ID = Helper::GetStringFromBuffer(temp);
			Object* sharedByPtr = SearchPageByID(temp);
			Posts[i]->SetSharedBy(sharedByPtr);
			sharedByPtr->AddPostToTimeline(Posts[i]);
		}



		fin >> temp;

		while (temp[0] != '-')
		{
			if (temp[0] == 'u')
			{
				char* ID = Helper::GetStringFromBuffer(temp);
				Object* likedByPtr = SearchUserByID(temp);
				Posts[i]->SetLikedBy(likedByPtr);
				fin >> temp;

			}
			else if (temp[0] == 'p')
			{
				char* ID = Helper::GetStringFromBuffer(temp);
				Object* likedByPtr = SearchPageByID(temp);
				Posts[i]->SetLikedBy(likedByPtr);
				fin >> temp;
			}
		}

	}
}

void User::AddPostToTimeline(Post* ptr)
{
	timeLine[timelineCount] = ptr;
	timelineCount++;
}

void Page::AddPostToTimeline(Post* ptr)
{
	timeLine[timelineCount] = ptr;
	timelineCount++;
}

void Post::SetLikedBy(Object* ptr)
{
	likedBy[numberOfLikes] = ptr;
	numberOfLikes++;
}

void Post::ReadPostFromFile(ifstream& fin)
{
	fin >> isActivity;

	char temp[100];

	fin >> temp;
	postID = Helper::GetStringFromBuffer(temp);

	sharedDate.ReadDateFromFile(fin);
	fin.ignore();
	fin.getline(temp, 100);
	text = Helper::GetStringFromBuffer(temp);

	if (isActivity == 2)
	{
		activity = new Activity;
		activity->ReadActivityFromFile(fin);
	}

}


Post::Post()
{
	postID = 0;
	text = 0;
	comments = 0;
	isActivity = 0;
}



void Post::SetSharedBy(Object* ptr)
{
	sharedBy = ptr;
}


Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}



Activity::Activity()
{
	activityType = 0;
	activityText = 0;
}






void Date::ReadDateFromFile(ifstream& fin)
{
	fin >> day;
	fin >> month;
	fin >> year;
}

void Activity::ReadActivityFromFile(ifstream& fin)
{
	char temp[100];
	fin >> activityType;

	fin.getline(temp, 100);
	activityText = Helper::GetStringFromBuffer(temp);
}

void Page::PrintLikedPages()
{
	cout << pageID << " - " << pageTitle << endl;
}

char* User::GetUserID()
{
	return userID;
}

char* Page::GetPageID()
{
	return pageID;
}

void User::PrintUserInfo()
{
	cout << fName << " " << lName << " successfully set as Current User" << endl << endl;
	cout << "Command:				View Friend List" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << fName << " " << lName << " - Friend List" << endl << endl;

	for (int i = 0; i < noOfFriends; i++)
	{
		cout << friendList[i]->userID << " - " << friendList[i]->fName << " " << friendList[i]->lName << endl;
	}

	cout << "---------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "Command:				View Liked Pages" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << fName << " " << lName << " - Liked Pages" << endl << endl;

	for (int i = 0; i < totalPagesLiked; i++)
	{
		likedPagesList[i]->PrintLikedPages();
		cout << endl;
	}
}

bool CompareString(char* arr1, char* arr2)
{
	int l1, l2;
	l1 = Helper::StringLength(arr1);
	l2 = Helper::StringLength(arr2);
	if (l1 == l2)
	{
		for (int i = 0; i < l1; i++)
		{
			if (arr1[i] == arr2[i])
			{
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}


void Facebook::LoadComments(ifstream& fin)
{
	int totalComments = 0;
	fin >> totalComments;

	Comment** tempComments = new Comment * [totalComments];

	for (int i = 0; i < totalComments; i++)
	{
		tempComments[i] = new Comment;
		char* id, * postid, * userid, * text;
		char buffer[100];
		fin >> buffer;
		id = Helper::GetStringFromBuffer(buffer);
		fin >> buffer;
		postid = Helper::GetStringFromBuffer(buffer);
		fin >> buffer;
		userid = Helper::GetStringFromBuffer(buffer); // comment by
		fin.getline(buffer, 100, '\n');
		text = Helper::GetStringFromBuffer(buffer);

		if (userid[0] == 'u')
		{
			Object* obj = SearchUserByID(userid);
			tempComments[i]->setComments(id, text, obj);
		}
		if (userid[0] == 'p')
		{
			Object* obj = SearchPageByID(userid);
			tempComments[i]->setComments(id, text, obj);
		}

		Post* post = SearchPostByID(postid);
		post->addComment(tempComments[i]);
	}
	//deallocation of tempcomments left.
}

void Comment::setComments(char* id, char* text, Object* commentedBy)
{
	ID = id;
	commentText = text;
	commentBy = commentedBy;
}

void Post::addComment(Comment* ptr)
{
	Comments[numberOfComments] = ptr;
	numberOfComments++;
}

User* Facebook::SearchUserByID(char* searchUserID)
{
	char* temp;
	for (int i = 0; i < 20; i++)
	{
		temp = Users[i]->GetUserID();
		if (CompareString(temp, searchUserID))
		{
			return Users[i];
		}
	}
}

Post* Facebook::SearchPostByID(char* searchPostID)
{
	char* temp;
	for (int i = 0; i < totalPosts; i++)
	{
		temp = Posts[i]->GetPostID();
		if (CompareString(temp, searchPostID))
		{
			return Posts[i];
		}
	}
}


void Facebook::LoadUsers(ifstream& fin)
{
	fin >> totalUsers;

	Users = new User * [totalUsers];
	char temp[50] = { '\0' };
	char** tempFriends = new char* [totalUsers];



	for (int i = 0; i < totalUsers; i++)
	{
		Users[i] = new User;
		Users[i]->ReadUserFromFile(fin);


		int j = 0;
		tempFriends[i] = new char* [10];

		for (int k = 0; k < 10; k++)
		{
			tempFriends[i][k] = new char;
			tempFriends[i][k] = 0;
		}

		fin >> temp;
		while (temp[0] != '-')				// Inputting list of friends
		{
			// Friend ID input
			tempFriends[i][j] = Helper::GetStringFromBuffer(temp);	// Friend ID stored in respective user on different indexes 
			fin >> temp;
			j++;
		}

		fin >> temp;

		while (temp[0] != '-')
		{													// Same logic for inputting liked pages I
			Page* ptr = SearchPageByID(temp);		// Liked page input from file, compared in function and it's respective page returned and stored in ptr	
			Users[i]->AddLikedPage(ptr);			// Pointer of page stored in User		 
			fin >> temp;
		}
	}

	// Add friend
	for (int i = 0; i < totalUsers; i++)
	{
		int j = Helper::NumOfFriends(tempFriends[i]);				// User specified not friends
		for (int k = 0; k < j; k++)
		{
			User* userPtr = SearchUserByID(tempFriends[i][k]);		// Friends of user specified
			Users[i]->AddFriend(userPtr);
		}

	}

}

void User::ReadUserFromFile(ifstream& fin)
{
	char temp[50];

	fin >> temp;		// User ID

	userID = Helper::GetStringFromBuffer(temp);		// User ID

	fin >> temp;								// First Name
	fName = Helper::GetStringFromBuffer(temp);			// First Name

	fin >> temp;								// Last Name
	lName = Helper::GetStringFromBuffer(temp);		// Last Name

}

void Facebook::LoadPages(ifstream& fin)
{
	fin >> totalPages;
	Pages = new Page * [totalPages];
	for (int i = 0; i < totalPages; i++)
	{
		Pages[i] = new Page;
		Pages[i]->ReadPageFromFile(fin);
	}
}

void Page::ReadPageFromFile(ifstream& fin)
{
	char temp[100];

	fin >> temp;
	pageID = Helper::GetStringFromBuffer(temp);

	fin.getline(temp, 100);
	pageTitle = Helper::GetStringFromBuffer(temp);
}




Page* Facebook::SearchPageByID(char* searchPageID)
{
	char* temp;
	for (int i = 0; i < 12; i++)
	{
		temp = Pages[i]->GetPageID();
		if (CompareString(temp, searchPageID))
		{
			return Pages[i];
		}
	}
}


void Facebook::Run()
{
	char* ID = new char[4]{ "u7" };
	User* currentUser = SearchUserByID(ID);
	currentUser->PrintUserInfo();

	Date::currentDate.SetCurrentDate(15, 11, 2017);
	currentUser->PrintHomePage();

	cout << endl << endl;
	char* postID = new char[6]{ "post5" };
	Post* post = SearchPostByID(postID);
	post->PrintPost();
	cout << endl;

	post->printLikedBy();
	currentUser->LikeAPost(post);
	post->printLikedBy();

	cout << "---------------------------------------------------------------------------------------" << endl << endl;

	char post2[6] = "post4";
	char* text = new char[50]{ "Good Luck for your Result (2)" };

	cout << "Command: \tPost Comment(" << post2 << ", " << text << ")\n";
	Post* addComment = SearchPostByID(post2);
	addComment->AddingNewComment(text, currentUser);
	cout << "Command: \tView Post(" << post2 << ")\n\n";
	addComment->PrintPost();
	cout << "--------------------------------------------------------------------------------------\n";

	char post3[6] = "post8";
	char* text2 = new char[50]{ "Thanks for the wishes" };
	cout << "Command: \tPost Comment(" << post3 << ", " << text2 << ")\n";
	Post* addComment2 = SearchPostByID(post3);
	addComment2->AddingNewComment(text2, currentUser);
	cout << "Command: \tView Post(" << post3 << ")\n\n";
	addComment2->PrintPost();
	cout << "--------------------------------------------------------------------------------------\n";

	// Memories
	cout << "Command: \tSeeYourMemories()\n";
	currentUser->ViewYourMemories();
	cout << "--------------------------------------------------------------------------------------\n";


	char memoryPost[7] = "post10";
	Post* currentPost = SearchPostByID(memoryPost);
	char shareText[70] = "Never thought I will be specialist in this field...";
	cout << "Command: \tShareMemory(" << memoryPost << ",\"" << shareText << "\")\n";
	currentUser->ShareMemory(shareText, currentPost);
	cout << "\nCommand: \tView timeline\n";
	currentUser->PrintName();
	cout << "-Timeline:\n\n";
	currentUser->PrintTimeline();
	cout << "--------------------------------------------------------------------------------------\n";



	// View page
	char viewPage[] = "p1";
	Page* pagePtr = SearchPageByID(viewPage);
	cout << "Command :\tViewPage(" << viewPage << ")\n\n";
	pagePtr->PrintFullPage();


	cout << "--------------------------------------------------------------------------------------\n";

}



void Facebook::LoadData()
{
	ifstream fin;

	fin.open("Pages.txt");
	{
		LoadPages(fin);
	}
	fin.close();

	fin.open("Users.txt");
	{
		LoadUsers(fin);
	}
	fin.close();

	fin.open("Posts.txt");
	{
		LoadPosts(fin);
	}
	fin.close();
	fin.open("Comments.txt");
	{
		LoadComments(fin);
	}
	fin.close();
}

int main()
{
	Facebook fb;
	fb.LoadData();
	fb.Run();
	return 0;
}