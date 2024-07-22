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
class FaceBook
{
private:
	int TotalPages;
	char *PageID;
	char* PageName;
	int TotalUsers;
	char *UserID;
	char* UserFName;
	char* UserLName;
public:
	FaceBook()
	{
		TotalPages = 0;
		PageID = 0;
		PageName = '\0';
	}
	void ReadDataFromPageFile(ifstream Read)
	{
		Read >> TotalPages;
		char temp[20] = { '\0' };
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read>>temp;
		PageID = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read.getline(temp, 40);
		PageName = Helper::GetStringFromBuffer(temp);
	}
	void ReadDataFromUserFile(ifstream Read)
	{
		Read >>TotalUsers;
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
		Read>>temp;
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
		char ***UserInfo=new char**[TotalUsers];
		for (int i = 0; i < TotalUsers; i++)
		{
			UserInfo[i] = new char* [10];
			int j = 0;
			while (temp[j] != '-')
			{ 
				Read.getline(temp, 40);
				UserInfo[i][j] = Helper::GetStringFromBuffer(temp);
			}
			j++;
		}
		char pageID[10] = {'\0'};
		int k = 0;
		while (pageID[k] != '-')
		{
			Read >> pageID;
			if (pageID[k] == '-')
			{

			}
			k++;
		
		}
	}
};

int main()
{
	cout << "\t\t\t\t\tWELCOME TO FACEBOOK\t\t\t\t\t" << endl;
	//throw exception("Now get lost");
	
}