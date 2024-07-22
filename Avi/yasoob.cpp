//#include <iostream>
//#include <fstream>
//using namespace std;
//
//class Helper
//{
//public:
//
//	static int StringLength(char* str)
//	{
//		int i = 0;
//		int count = 0;
//		while (str[i] != '\0')
//		{
//			i++;
//			count++;
//		}
//		return count;
//
//	}
//
//	static int StringLength(const char* str)
//	{
//		int i = 0;
//		int count = 0;
//		while (str[i] != '\0')
//		{
//			i++;
//			count++;
//		}
//		return count;
//
//	}
//
//	static bool compareString(char* str1, char* str2) {
//		if (StringLength(str1) != StringLength(str2)) return false;
//		else {
//			int flag = 0;
//			for (int i = 0; i < StringLength(str1); i++) {
//				if (str1[i] != str2[i]) {
//					flag++;
//				}
//			}
//			if (flag == 0) return true;
//			else return false;
//		}
//	}
//
//	static bool compareString(char* str1, const char* str2) {
//		if (StringLength(str1) != StringLength(str2)) return false;
//		else {
//			int flag = 0;
//			for (int i = 0; i < StringLength(str1); i++) {
//				if (str1[i] != str2[i]) {
//					flag++;
//				}
//			}
//			if (flag == 0) return true;
//			else return false;
//		}
//	}
//
//
//	static void StringCopy(char*& dest, char*& src) {
//		int i = 0;
//		while (src[i] != '\0')
//		{
//			dest[i] = src[i];
//			i++;
//		}
//		dest[i] = '\0';
//
//	}
//	static char* GetStringFromBuffer(char* str)
//	{
//		int length = StringLength(str);
//		char* dest = new char[length + 1];
//		StringCopy(dest, str);
//		return dest;
//
//	}
//};
//
//
//class Page {
//private:
//	char* ID;
//	char* Title;
//public:
//	static int TotalPages;
//	Page() {
//		ID = nullptr;
//		Title = nullptr;
//	}
//	static Page* getPages(ifstream& fin, Page* p) {
//		p = new Page;
//		char temp[45];
//		fin >> temp;
//		p->ID = Helper::GetStringFromBuffer(temp);
//		fin.getline(temp, 45);
//		p->Title = Helper::GetStringFromBuffer(temp);
//
//		return p;
//	}
//
//	static Page* ReturnPage(Page** pages, char* id) {
//		int i;
//
//		for (i = 0; i < Page::TotalPages; i++) {
//			if (Helper::compareString(pages[i]->ID, id)) {
//				return pages[i];
//				break;
//			}
//		}
//	}
//
//	void PrintPage();
//};
//
//int Page::TotalPages = 0;
//
//void Page::PrintPage() {
//	cout << this->ID << " - " << this->Title << endl;
//}
//
//
//class User {
//private:
//	char* ID;
//	char* FirstName;
//	char* LastName;
//	char** Friends;
//	User** Friendlist;
//	int tFriends;
//	Page** Linkedpages;
//	int tPages;
//public:
//	static int TotalUsers;
//
//	User() {
//		ID = nullptr;
//		FirstName = nullptr;
//		LastName = nullptr;
//		Friends = nullptr;
//		Friendlist = nullptr;
//		tFriends = 0;
//		Linkedpages = nullptr;
//		tPages = 0;
//
//	}
//
//	static User* getUser(ifstream& fin, User* u, Page** pages) {
//		u = new User;
//		char temp[20];
//
//		fin >> temp;
//		u->ID = Helper::GetStringFromBuffer(temp);
//
//		fin >> temp;
//		u->FirstName = Helper::GetStringFromBuffer(temp);
//
//		fin >> temp;
//		u->LastName = Helper::GetStringFromBuffer(temp);
//
//
//		u->tFriends = 0;
//		u->Friends = new char* [10];
//
//		for (int i = 0; i < 10; i++) {
//			fin >> temp;
//			if (temp[0] == '-') break;
//			u->tFriends++;
//			u->Friends[i] = Helper::GetStringFromBuffer(temp);
//		}
//
//
//
//		u->tPages = 0;
//		u->Linkedpages = new Page * [10];
//		for (int i = 0; i < 10; i++) {
//			fin >> temp;
//			if (temp[0] == '-') break;
//			u->Linkedpages[i] = new Page;
//			u->Linkedpages[i] = Page::ReturnPage(pages, temp);
//			u->tPages++;
//		}
//
//		return u;
//	}
//
//
//	static void LinkFriends(User** users) {
//
//		int flag = 0;
//		char* id;
//
//		for (int i = 0; i < User::TotalUsers; i++) {
//			users[i]->Friendlist = new User * [users[i]->tFriends];
//			for (int j = 0; j < users[i]->tFriends; j++) {
//				id = users[i]->Friends[j];
//				for (int k = 0; k < User::TotalUsers; k++) {
//					if (Helper::compareString(users[k]->ID, id)) {
//						users[i]->Friendlist[j] = new User;
//						users[i]->Friendlist[j] = users[k];
//						break;
//					}
//				}
//			}
//		}
//	}
//
//
//	static void PrintUserDetail(User** users, const char* u) {
//		int i;
//
//		for (i = 0; i < User::TotalUsers; i++) {
//
//			if (Helper::compareString(users[i]->ID, u)) {
//				cout << users[i]->ID << " - " << " successfully set as Current User." << endl << endl;
//				break;
//			}
//		}
//		if (i >= User::TotalUsers) cout << "user not found. " << endl;
//		else {
//			users[i]->PrintFriendList();
//			users[i]->PrintLikedPages();
//
//		}
//	}
//
//	void Print();
//	void PrintLikedPages();
//	void PrintFriendList();
//
//};
//
//int User::TotalUsers = 0;
//
//void User::Print() {
//	cout << this->ID << " - " << this->FirstName << " " << this->LastName << endl;
//}
//
//void User::PrintLikedPages() {
//	cout << this->FirstName << " " << this->LastName << " - " << "Liked Pages" << endl;
//	for (int i = 0; i < this->tPages; i++) {
//		this->Linkedpages[i]->PrintPage();
//	}
//	cout << ".." << endl;
//}
//
//void User::PrintFriendList() {
//	cout << this->FirstName << " " << this->LastName << " - " << "Friend List" << endl;
//	for (int i = 0; i < this->tFriends; i++) {
//		this->Friendlist[i]->Print();
//	}
//	cout << ".." << endl;
//}
//
//class Facebook {
//private:
//	Page** pages;
//	User** users;
//public:
//	Facebook();
//	void getData() {
//		ifstream fin;
//		fin.open("pages.txt");
//		fin >> Page::TotalPages;
//		pages = new Page * [Page::TotalPages];
//		for (int i = 0; i < Page::TotalPages; i++) {
//			pages[i] = Page::getPages(fin, pages[i]);
//		}
//
//		fin.close();
//
//		fin.open("users.txt");
//		fin >> User::TotalUsers;
//		users = new User * [User::TotalUsers];
//		for (int i = 0; i < User::TotalUsers; i++) {
//			users[i] = User::getUser(fin, users[i], pages);
//		}
//
//		fin.close();
//
//		User::LinkFriends(users);
//
//	}
//
//	void Run(const char*);
//
//
//};
//
//Facebook::Facebook() {
//	pages = nullptr;
//	users = nullptr;
//}
//
//void Facebook::Run(const char* u) {
//	User::PrintUserDetail(users, u);
//}
//
//
//int main() {
//
//	Facebook fb;
//	fb.getData();
//	fb.Run("u2");
//
//	//system("pause");
//	return 0;
//}