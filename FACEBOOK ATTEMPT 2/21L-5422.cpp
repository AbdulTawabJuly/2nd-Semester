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
class PageInfo
{
private:
	char* PageID;
	char* PageName;
public:
	void ReadDataFromPageFile(ifstream &Read)
	{
		char temp[20] = { '\0' };
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		PageID = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read.getline(temp, 40);
		PageName = Helper::GetStringFromBuffer(temp);
	}
	static PageInfo* SearchPage(PageInfo* Pages, char* pageID)  //This Function Search Given Page by ID
	{
		for (int i = 0; i < 20; i++)
		{
			char* PID = Pages[i].GetPageID();
			if (Helper::CompareString(PID, pageID))
			{
				return (Pages + i);
			}
		}
		return NULL;
	}
	char* GetPageID()
	{
		return this->PageID;
	}
};
PageInfo* ReadDataFromPageFile(const char* file)
{
	ifstream Read;
	int TotalPages;
	Read.open(file);
	if (Read.is_open())
	{
		Read >> TotalPages;

		PageInfo* PageList = new PageInfo[TotalPages];
		int i = 0;
		while (!Read.eof())
		{
			PageList[i].ReadDataFromPageFile(Read);
			i++;
		}
		return PageList;
	}
	else
	{
		cout << "Page File was not properly opened" << endl;
		return 0;
	}
}
class UserInfo
{
	
	char* UserID;
	char* UserFName;
	char* UserLName;
public:
	void ReadDataFromUserFile(ifstream& Read)
	{
		PageInfo* PList = ReadDataFromPageFile("PagesData");

		char temp[20]={'\0'};
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		UserID = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		UserFName = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		UserLName = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		char*** UserInfo = new char** [20];
		PageInfo*** LikedPages = new PageInfo ** [20];
		char* PageID=NULL;//<<<<<<-----------------------------
		int j = 0;
		for (int i = 0; i < 20; i++)
		{
			UserInfo[i] = new char* [10];
			LikedPages[i] = new PageInfo* [10];
			while (temp[j] != '-')
			{
				Read >> temp;
				UserInfo[i][j] = Helper::GetStringFromBuffer(temp);
				
			}
			while (PageID[j] != '-')//<<<<---------------------
			{
				Read >> PageID;
				LikedPages[i][j] = PageInfo::SearchPage(PList, PageID);
			}
			j++;
		}
	}
	char* GetUserID()
	{
		return this->UserID;
	}
	static UserInfo* SearchUserByID(UserInfo* List, char* SearchUser)  //This Function Search Given Page by ID
	{
		for (int i = 0; i < 20; i++)
		{
			char* UID = List[i].GetUserID();
			if (Helper::CompareString(UID, SearchUser))
			{
				return (List + i);
			}
		}
		return NULL;
	}

	void ViewFriendList()
	{
		cout << "Command :   View Friend List" << endl<<endl;
		cout << this->UserFName << " " << this->UserLName << " FRIEND LIST" << endl;
		


	}
	void ViewLikedPages()
	{
		cout << "Command :   View Liked Pages" << endl<<endl;
		cout << this->UserFName << " " << this->UserLName << " LIKED PAGES" << endl;



	}
};
UserInfo* ReadDataFromUserFile(const char* file2)
{
	ifstream Read2;
	Read2.open(file2);
	int TotalUsers;
	if (Read2.is_open())
	{
		Read2 >> TotalUsers;
		UserInfo* UserList = new UserInfo[TotalUsers];
		int i = 0;
		while (Read2.eof())
		{
			UserList[i].ReadDataFromUserFile(Read2);
			i++;
		}
		return UserList;
	}
	else
	{
		cout << "User File was not properly opened" << endl;
		return 0;
	}
}
class FaceBook
{
private:
	PageInfo** Pages;
	UserInfo** Users;
public:
	void LoadAllPages()
	{
		PageInfo* PagesList = ReadDataFromPageFile("PagesData");
	}
	void LoadAllUsers()
	{
		UserInfo* Users = ReadDataFromUserFile("StudentRecord");
	}
	void Run(char *ID)
	{/*
		UserInfo* CurrentUser = UserInfo::SearchUserByID(Users,ID);
		CurrentUser->ViewFriendList();
		cout << "------------------------------------------------------------------------------------------" << endl;
		CurrentUser->ViewLikedPages();
		cout << endl;*/
	}
};
int main()
{
	cout << "\t\t\t********  ********  ********  ********  ********    ********  ********  *      *      " << endl;
	cout << "\t\t\t*         *      *  *         *         *      *    *      *  *      *  *    *        " << endl;
	cout << "\t\t\t*         *      *  *         *         *      *    *      *  *      *  *  *          " << endl;
	cout << "\t\t\t********  ********  *         ********  **********  *      *  *      *  **            " << endl;
	cout << "\t\t\t*         *      *  *         *         *        *  *      *  *      *  *  *          " << endl;
	cout << "\t\t\t*         *      *  *         *         *        *  *      *  *      *  *    *        " << endl;
	cout << "\t\t\t*         *      *  ********  ********  **********  ********  ********  *      *       " << endl;
	cout << endl << endl << endl;
	//FaceBook fb;

	return 0;
}
