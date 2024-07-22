#include<iostream>
#include<windows.h>
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
		if (i < 10)  // Max 10 Friends
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

class Facebook;
//<<-----------------------------------Page Class------------------------------->>

class Pages
{
private:
	
	char* PageID;
	char* PageName;
public:
	static int TotalPages;
	Pages()
	{
		PageID = NULL;
		PageName = NULL;
	}

	void ReadDataFromPageFile(ifstream& Read)
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
	 
	static Pages* SetLikedPage(Pages** Pages, char* ID)
	{
		int i;
		for (i = 0; i <Pages::TotalPages; i++) 
		{
			if (Helper::CompareString(Pages[i]->PageID, ID)) 
			{
				return Pages[i];
				//break;
			}
		}
	}

	char* GetPageID()
	{
		return this->PageID;
	}

	char* GetPageName()
	{
		return this->PageName;
	}
};
int Pages::TotalPages = 0;
//<<----------------------------User Class----------------------------->>

class Users
{

	char* UserID;
	char* UserFName;
	char* UserLName;
	char** UserFriends;
	Pages** LikedPagesList;
	Users** FriendList;
	int NoofFriends;
	int NoofLikedPages;
public:
	static int TotalUsers;
	Users()
	{
		UserID = NULL;
		UserFName = NULL;
		UserLName = NULL;
		UserFriends = NULL;
		FriendList = NULL;
		LikedPagesList = NULL;
		NoofFriends = 0;
		NoofLikedPages = 0;
	}
	void ReadDataFromUserFile(ifstream& Read,Pages ** PageInfo, int tPages,Users *UserData)
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

		UserData->LikedPagesList = new Pages* [10];
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

	void ViewFriendList()
	{
		cout << " Command: View Friend List" << endl;
		Helper::ShowLine();
		cout << this->GetUserFName() << " " << this->GetUserLName() << " ->   Friend List" << endl << endl;
		for (int i = 0; i < NoofFriends; i++)
		{
			cout << this->FriendList[i]->GetUserID()<<"\t "<<FriendList[i]->GetUserFName()<<" "<<FriendList[i]->GetUserLName() << endl;
		}
	}

	void ViewLikedPages()
	{
		cout << " Command: View Liked Pages" << endl;
		Helper::ShowLine();
		cout << this->GetUserFName() << " " << this->GetUserLName() << " ->   Liked Pages" << endl << endl;
		for (int j = 0; j <this->NoofLikedPages; j++)
		{
			cout << this->LikedPagesList[j] ->GetPageID() << "\t" << LikedPagesList[j]->GetPageName() << endl;
		}
	}
	char* GetUserFName()
	{
		return this->UserFName;
	}
	char* GetUserLName()
	{
		return this->UserLName;
	}
	char* GetUserID()
	{
		return this->UserID;
	}

	int GetNoofFriends()
	{
		return this->NoofFriends;
	}

	int GetNoofLikedPages()
	{
		return this->NoofLikedPages;
	}

	static void SetFriends(Users** usersInfo, int TotalUsers) 
	{
		char* ID;
		for (int i = 0; i < TotalUsers; i++) 
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
	}
};
int Users::TotalUsers = 0;

//<<-------------------------------FaceBook Class-------------------------------------->>

class Facebook :public Users
{
private:
	Users** UserInfo = NULL;
	Pages** PageInfo = NULL;
	Users* CurrentUser = NULL;
public:
	Facebook()
	{
		UserInfo = NULL;
		PageInfo = NULL;
		CurrentUser = NULL;
	}
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
	void LoadData()
	{
		ifstream Read;
		LoadPages(Read);
		LoadUsers(Read);
		
	}
	
	void LoadPages(ifstream& Read)
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

	void LoadUsers(ifstream& Read)
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
				UserInfo[i]->ReadDataFromUserFile(Read, PageInfo,Pages::TotalPages,UserInfo[i]);
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


	Users* SearchUserByID(Users** Users, char* SearchUser)  //This Function Searches Given ID
	{
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				char* UID = Users[j][i].GetUserID();
				if (Helper::CompareString(UID, SearchUser))
				{
					return Users[j];
				}
			}
		}

		cout << "You Have Entered Wrong ID" << endl;
		return NULL;
	}

	void Run()
	{
		char temp[10] = { 'u','1','1'};
		cout << "Command:\tSet current user to " << temp << endl;

		CurrentUser = SearchUserByID(UserInfo, temp);
		if (CurrentUser != NULL)
		{
			cout << CurrentUser->GetUserFName() << " " << CurrentUser->GetUserLName() << "  Successfully set as Current User " << endl << endl;
			CurrentUser->ViewFriendList();
			Helper::ShowLine();
			CurrentUser->ViewLikedPages();
		}
	}

};
int main()
{
	{
		Helper::ShowTitle();
		Facebook fb;
		fb.LoadData();
		fb.Run();
	}
	system("color 74");
	cout << endl << endl << endl << endl;
	return 0;
}