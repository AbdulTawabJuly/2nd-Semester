#include<iostream>
#include<fstream>
using namespace std;
class helper
{
public:
	static void printlins(const char* asdf)
	{
		for (int i = 0; i < 120; i++)
			cout << "_";
		cout << "\ncommand\t\t\t\t\t\t" << asdf << "\n";
		for (int i = 0; i < 120; i++)
			cout << "_";
		cout << endl;
	}
	template<class a>
	static a** resize(a** asdf, a* u)
	{
		int t;
		for (t = 0; asdf[t] != NULL; t++)
		{
		}

		a** xtend = new a * [t + 2];
		xtend[0] = u;
		int l = 1;
		for (int i = 0; i < t; i++, l++)
		{
			xtend[l] = asdf[i];
		}
		xtend[t + 1] = NULL;
		delete[] asdf;
		return xtend;
	}
	static char* concat(char* asd, char* dfg)
	{
		int i = 0;
		while (asd[i] != '\0')
		{
			i++;
		}
		int k = 0;
		while (dfg[k] != '\0')
		{
			k++;
		}
		char* con = new char[i + k + 2];
		int y = 0, o = 0;
		for (int l = 0; l < i + k + 1; l++)
		{
			if (l < i)
			{
				con[l] = asd[y];
				y++;
			}
			else if (l > i)
			{
				con[l] = dfg[o];
				o++;
			}
			else con[l] = ' ';
		}
		con[i + k + 1] = '\0';
		return con;
	}
	static char* concatpost(char* asd, char* dfg)
	{
		int i = 0;
		while (asd[i] != '\0')
		{
			i++;
		}
		int k = 0;
		while (dfg[k] != '\0')
		{
			k++;
		}
		char* con = new char[i + k + 4];
		int y = 0, o = 0;
		con[y] = '\t';
		y++;
		for (int l = 0; l < i; l++)
		{
			con[y] = asd[l];
			y++;
		}
		con[y] = '\n';
		y++;
		for (int l = 0; l < k; l++)
		{
			con[y] = dfg[l];
			y++;
		}
		con[i + k + 1] = '\0';
		return con;
	}
	//this function delete a 3d character pointer
	static void deleteptr(char*** asd, int a, int b)
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
				if (asd[i][j] != NULL)
					delete[] asd[i][j];
		}
		delete[] asd;
		asd = NULL;
	}
	template<class a, class b>
	static void settimeline(a**, b*, char*);
	// this function is to return string form buffer after creating dynamic char* array of exact stirng length
	static char* getStringfromBuffer(char* str)
	{
		//count is length of the stirng
		int count = 0;
		while (str[count] != '\0')
		{
			count++;
		}
		//creating char* of length count
		char* ptr = new char[count + 1];
		int i = 0;
		while (i < count)
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[count] = '\0';
		return ptr;
	}
	// this function return char* from const char* 
	static char* getStringfromBuffer(const char* str)
	{
		//count is length of the stirng
		int count = 0;
		while (str[count] != '\0')
		{
			count++;
		}
		//creating char* of length count
		char* ptr = new char[count + 1];
		int i = 0;
		while (i < count)
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[count] = '\0';
		return ptr;
	}
	//this function compare two sting that are sent as arugument
	static bool compare(char* asd, char* jkl)
	{
		int counta = 0;
		while (asd[counta] != '\0')
		{
			counta++;
		}
		int countb = 0;
		while (jkl[countb] != '\0')
		{
			countb++;
		}
		if (counta == countb)
		{
			for (int i = 0; i < countb; i++)
			{
				if (asd[i] != jkl[i])
				{
					break;
				}
				else
					if (i == countb - 1)
					{
						return true;
					}
			}
			return false;
		}
		return false;
	}
};
class obj
{
public:
	void  showtimeline()
	{
	}
	template<class a>
	static a change(obj** asd)
	{
		a AA = *asd[0];
		return AA;
	}
	virtual void set(char* akl)
	{

	}
	virtual char* getID()
	{
		return NULL;
	}
	virtual void postprint()
	{

	}
	virtual char* getname()
	{
		return NULL;
	}
};
class coment
{
	char* ID;
	char* Text;
	char* post_ID;
	obj* comentby;
public:
	~coment()
	{
		delete[] ID;
		delete[] Text;
		post_ID = NULL;
		obj* comentby = NULL;
	}
	template<class a>
	static 	coment** add_coment(coment** com, a* asd, const char* asdf)
	{
		cout << "adding comment on  post[8]";

		coment* com2 = new coment;
		cout << "\nadd your commert here\n";
		com2->Text = helper::getStringfromBuffer(asdf);
		com2->comentby = asd;
		com2->post_ID = helper::getStringfromBuffer(com[0]->post_ID);
		char hat[4] = "c14";
		com2->ID = helper::getStringfromBuffer(hat);
		coment** com3 = helper::resize(com, com2);
		return com3;
	}
	void setcom(char* id, char* text, char* postid, obj* asd)
	{
		this->comentby = asd;
		this->ID = id;
		this->post_ID = postid;
		this->Text = text;
	}
	char* getID()
	{
		return post_ID;
	}
	void printcoment()
	{
		obj* asd = this->comentby;
		cout << asd->getname() << " wrote ";
		cout << "\"" << this->Text << "\"" << endl;
	}
	static coment** numofComent(char* id, coment** com)
	{
		int l = 0;
		int i = 0;
		while (com[i] != NULL)
		{
			if (helper::compare(id, com[i]->post_ID))
			{
				l++;
			}
			i++;
		}
		if (l > 0)
		{

			coment** coma = new coment * [l + 1];
			int k = 0;
			for (int i = 0; com[i] != NULL; i++)
			{
				if (helper::compare(id, com[i]->post_ID))
				{
					coma[k] = com[i];
					k++;
				}
			}
			coma[l] = NULL;
			return coma;
		}
		else
		{
			return NULL;
		}
	}
};
class activity
{
	char* value;
	int type;
public:
	~activity()
	{
		delete[] value;
	}
	void set(int val, char* asd)
	{
		value = helper::getStringfromBuffer(asd);
		type = val;
	}
	void printactivity()
	{
		if (type == 1)
			cout << "is feeling ";
		else if (type == 2)
			cout << " is thinking about ";
		else if (type == 3)
			cout << " is Making ";
		else if (type == 4)
			cout << " is celebrating ";
		cout << value;
	}
};
class date_time
{
	int day;
	int month;
	int year;
	static date_time current_date;
public:
	date_time()
	{
		day = 0; month = 0; year = 0;
	}
	static date_time get_current_date()
	{
		return current_date;
	}
	static void setcurrentdate(int d, int m, int y)
	{
		current_date.set(d, m, y);
	}
	void set(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	int years()
	{
		return year;
	}
	bool operator==(date_time asd)
	{
		if (this->year == asd.year)
		{
			if (this->month == asd.month)
			{
				if (this->day == asd.day)
					return true;
			}
		}
		return false;
	}
	void print()
	{
		cout << " " << this->day << "- ";
		switch (this->month)
		{
		case 1:
			cout << "january";
			break;
		case 2:
			cout << "febuary";
			break;
		case 3:
			cout << "march";
			break;
		case 4:
			cout << "april";
			break;
		case 5:
			cout << "may";
			break;
		case 6:
			cout << "june";
			break;
		case 7:
			cout << "july";
			break;
		case 8:
			cout << "august";
			break;
		case 9:
			cout << "september";
			break;
		case 11:
			cout << "November";
			break;
		case 12:
			cout << "december";
			break;
		case 10:
			cout << "octuber";
			break;
		default:
			break;
		}
		cout << "- " << this->year;
	}
	date_time operator-(int i)
	{
		date_time asd;
		asd.set((this->day - i), this->month, this->year);
		return asd;
	}
	bool checkmemory()
	{
		if ((current_date.day == this->day) && (current_date.month == this->month) && (current_date.year > this->year))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
date_time date_time::current_date;
class post
{
	bool swit = true;
	char* ID;
	char* Text;
	obj* sharedBY;
	date_time shared_date;
	activity* akl = NULL;
	coment** comments;
	obj** liked_by;
public:
	post(char* text, obj* sharby)
	{
		Text = text;
		sharedBY = sharby;
	}
	post()
	{

	}
	~post()
	{
		delete[] ID;
		delete[] Text;
		if (comments != NULL)
			for (int i = 0; comments[i] != NULL; i++)
				delete comments[i];
		if (liked_by != NULL)
			delete[] liked_by;
		if (akl != NULL)
			delete akl;
	}
	void setcoment(coment** as)
	{
		comments = as;
	}
	char* getText()
	{
		return Text;
	}
	template <class a>
	static void likePost(post* asdf, a* user)
	{
		asdf->liked_by = helper::resize<obj>(asdf->liked_by, user);
	}
	void printlikes()
	{
		cout << this->ID << " by " << this->sharedBY->getname() << endl;
		if (this->liked_by != NULL)
		{
			for (int i = 0; this->liked_by[i] != NULL; i++)
				cout << "liked by " << this->liked_by[i]->getname() << endl;
		}
		else
		{
			cout << "\n no likes on this post yet\n";
		}
	}
	void printCOmnet()
	{
		if (this->comments != NULL) {
			for (int i = 0; this->comments[i] != NULL; i++)
			{
				this->comments[i]->printcoment();
			}
		}
		else
		{
			cout << this->ID << " by " << this->sharedBY->getname() << " has no coments yet" << endl;
		}
	}
	template<class a>
	void addcom(a* asd, const char* com)
	{

		this->comments = coment::add_coment<a>(comments, asd, com);
	}
	void setpost(char* id, char* text, obj* share, obj** asd, date_time& as, activity* al = NULL)
	{
		this->ID = id;
		this->akl = al;
		this->liked_by = asd;
		this->shared_date = as;
		this->sharedBY = share;
		this->Text = text;
	}
	obj* getSharedBy()
	{
		return sharedBY;
	}
	bool getswit()
	{
		return swit;
	}
	static post** memory(date_time& current, post** posts)
	{
		if (posts != NULL)
		{
			int l = 0;
			for (int i = 0; posts[i] != NULL; i++)
			{
				if (posts[i]->shared_date.years() < current.years())
				{
					posts[i]->swit = true;
					l++;
				}
			}
			post** memory = new post * [l + 1];
			int a = 0;
			for (int i = 0; posts[i] != NULL; i++)
			{
				if (posts[i]->shared_date.years() < current.years())
				{
					memory[a] = posts[i];
					a++;
				}
			}
			memory[l] = NULL;
			return memory;
		}
		else
			return NULL;
	}
	char* getID()
	{
		return ID;
	}
	date_time getdate()
	{
		return shared_date;
	}
	virtual	void printPost()
	{
		cout << sharedBY->getname();
		if (akl != NULL)
		{
			akl->printactivity();
		}
		cout << "\"" << Text << "\"" << endl;
		if (liked_by != NULL)
		{
			for (int i = 0; liked_by[i] != NULL; i++)
			{
				cout << "liked by  " << liked_by[i]->getname() << endl;
			}
		}
		else
		{
			cout << "not liked yet\t\t\t";
		}
		if (comments != NULL) {
			for (int i = 0; comments[i] != NULL; i++)
			{
				comments[i]->printcoment();
			}
		}
		else
		{
			cout << "0 coment\n";
		}
	}
	static post** settimeline(post** asdf, obj* usd)
	{
		int l = 0;
		for (int i = 0; asdf[i] != NULL; i++)
		{
			if (helper::compare(asdf[i]->sharedBY->getID(), usd->getID()))
			{
				l++;
			}
		}
		post** timeline = new post * [l + 1];
		int kl = 0;
		for (int i = 0; asdf[i] != NULL; i++)
		{
			if (helper::compare(asdf[i]->sharedBY->getID(), usd->getID()))
			{
				timeline[kl] = asdf[i];
				asdf[i]->swit = false;
				kl++;
			}
		}
		timeline[l] = NULL;
		return timeline;
	}
};
class Pages :public obj
{
	char* ID;
	char* title;
	post** timeline = NULL;
public:
	// search pages out of 2d array of all pages
	static Pages* searchpage(Pages**, char*);
	// get pages load data from file in pages and return 2d pointer 
	void setpages(char*& id, char*& tirle)
	{
		ID = helper::getStringfromBuffer(id);
		this->title = helper::getStringfromBuffer(tirle);
	}
	//
	void  showtimeline()
	{
		if (this->timeline != NULL) {
			for (int i = 0; this->timeline[i] != NULL; i++)
			{
				this->timeline[i]->printPost();
				date_time asd = this->timeline[i]->getdate();
				asd.print();
				cout << endl << endl << endl;
			}
		}
		else
		{
			cout << "Nothing posted yet";
		}
	}
	//
	char* getname()
	{
		return title;
	}
	static void settimeline(post** asd, Pages& page)
	{
		page.timeline = asd;
	}
	char* getID()
	{
		return ID;
	}
	// return ID of page
	char* getter()
	{
		return ID;
	}
	// assignment operator
	void operator=(const Pages& asd)
	{
		this->ID = asd.ID;
		this->title = asd.title;
	}
	//print id and  name of page 
	void showpages()
	{
		cout << ID << '\t' << title << endl;
	}
	//print post;
	void postprint()
	{
		date_time current;
		current.set(17, 11, 2017);
		if (this->timeline != NULL)
		{
			for (int i = 0; this->timeline[i] != NULL; i++)
			{
				if ((this->timeline[i]->getdate() == date_time::get_current_date()) || (this->timeline[i]->getdate() == date_time::get_current_date() - 1))
				{
					cout << this->getname();
					this->timeline[i]->printPost();
					cout << endl << endl << endl;
				}
			}
		}
	}
	// set page id 
	void set(char* id)
	{
		ID = helper::getStringfromBuffer(id);
	}
	//distructor of pages
	~Pages()
	{
		cout << "page distructor called";
		delete[] ID;
		delete[] title;
		if (timeline != NULL)
			for (int i = 0; timeline[i] != NULL; i++)
				delete timeline[i];
		delete[] timeline;
	}
};
class memories :public post
{
	post* shared_post;
public:
	~memories()
	{
	}
	memories(post* ptr, char* Text, obj* CurrentUser) :post(Text, CurrentUser)//overlaoded constructor
	{
		shared_post = ptr;
	}
	void printPost()//printing memory
	{
		cout << "~~~" << shared_post->getSharedBy()->getname() << " shared a memory~~~";
		cout << "...";
		shared_post->getdate().print();
		cout << "\n\"" << this->getText() << "\"\n";
		cout << "\t\t(" << date_time::get_current_date().years() - shared_post->getdate().years() << " Years Ago)\n";
		shared_post->printPost();
	}

};
class User :public obj
{
	char* id = NULL;
	User** friendList = NULL;
	int friendnumber = 0;
	char* first_Name = NULL;
	char* second_Name = NULL;
	int pagesnumber = 0;
	Pages** liked_pages = NULL;
	post** timeline = NULL;
public:
	void setfrilist(User** asd)
	{
		this->friendList = asd;
	}
	void setpage(Pages** asd)
	{
		this->liked_pages = asd;
	}
	//
	void  setuser(char*& fname, char*& lname, char*& i, int& pageno, int& friendNumebr)
	{
		this->id = helper::getStringfromBuffer(i);
		this->first_Name = helper::getStringfromBuffer(fname);
		this->second_Name = helper::getStringfromBuffer(lname);
		this->pagesnumber = pageno;
		this->friendnumber = friendNumebr;
	}
	//
	void sharememory(post* pos, const char* asd)
	{
		char* tex = helper::getStringfromBuffer(asd);
		post* mem = new memories(pos, tex, pos->getSharedBy());
		this->timeline = helper::resize<post>(timeline, mem);
	}
	//like post
	void likePost(post* asdf)
	{
		post::likePost(asdf, this);
	}
	//get timeline of a function
	post** gettimeline()
	{
		return this->timeline;
	}
	//
	post* checkMemory()
	{
		for (int i = 0; timeline[i] != NULL; i++)
		{
			if (this->timeline[i]->getdate().checkmemory())
			{
				return timeline[i];
			}
		}
		return NULL;
	}
	// this function searchb selecte user from 2d array of users
	static User* searchusers(User**, char*);
	// set timeline
	static void settimeline(post** asd, User& user)
	{
		user.timeline = asd;
	}
	//get ID of user
	char* getID()
	{
		return id;
	}
	// get name from user
	char* getname()
	{
		char* name = helper::concat(first_Name, second_Name);
		return name;
	}
	// show timeline of user
	void  showtimeline()
	{
		if (this->timeline != NULL) {
			for (int i = 0; this->timeline[i] != NULL; i++)
			{
				if (!this->timeline[i]->getswit())
				{
					this->timeline[i]->printPost();
					date_time asd = this->timeline[i]->getdate();
					asd.print();
					cout << endl << endl << endl;
				}
				else
				{
					timeline[i]->getdate().print();
					this->timeline[i]->printPost();
					date_time::get_current_date().print();
					cout << endl << endl << endl;
				}
			}
		}
		else
		{
			cout << "Nothing posted yet";
		}
	}
	//

	// this function load data of user from file eg name id first name last name liked pages and friend list
	//also return 2d user pointer
	char* getter()
	{
		return this->id;
	}
	friend ofstream& operator<<(ofstream& ost, User* us)
	{
		ost << us->first_Name << " " << us->second_Name;
		return ost;
	}
	void operator=(const User& asd)
	{
		this->first_Name = asd.first_Name;
		this->id = asd.id;
		this->second_Name = asd.second_Name;
	}
	char* getfirstname()
	{
		return first_Name;
	}
	char* getsecondname()
	{
		return second_Name;
	}
	// show curretn users friend
	void showUser()
	{
		cout << " User ID :\t" << this->id << "\t" << this->first_Name << " " << this->second_Name << endl;
	}
	//print detailed current user of fb
	void showdetailedUser()
	{

		cout << " User ID :\t\t\t\t" << this->first_Name << " " << this->second_Name << endl;
		for (int i = 0; i < 120; i++)
			cout << "_";
		cout << endl;
		if (friendList != NULL)
		{
			cout << "Command\t\t\t\t\tShow current user's Friend list" << "\n";
			for (int i = 0; i < 120; i++)
				cout << "_";
			cout << endl << endl << endl;
			cout << "\t\t\t\t\t\t\tFriend List\n";
			for (int i = 0; i < 120; i++)
				cout << "_";
			cout << endl;
			if (friendnumber > 0) {
				for (int i = 0; i < friendnumber; i++)
				{
					cout << "F" << i + 1 << ":\t";
					friendList[i]->showUser();
				}
			}
			else
			{
				cout << "No Friend at the moment\n";
			}
		}
		for (int i = 0; i < 120; i++)
			cout << "_";
		cout << endl << endl;
		cout << "Command\t\t\t\t\tShow current user's Liked pages" << "\n";
		for (int i = 0; i < 120; i++)
			cout << "_";
		cout << endl << endl << endl;
		cout << "\t\t\t\t\t\t\tPages Liked\n";
		for (int i = 0; i < 120; i++)
			cout << "_";
		cout << endl;
		if (pagesnumber > 0)
		{
			for (int i = 0; i < pagesnumber; i++)
				liked_pages[i]->Pages::showpages();
		}
		else
		{
			cout << "no Page liked yet\n";
		}
	}
	void set(char* ID)
	{
		id = helper::getStringfromBuffer(ID);
	}
	//distructor of users
	~User()
	{
		if (this != NULL)
		{
			cout << "user distructor called\n";
			delete[] first_Name;
			delete[] second_Name;
			delete[] id;
			if (friendList != NULL)
				delete[] friendList;
			if (liked_pages != NULL)
				delete[] liked_pages;
			if (timeline != NULL)
				for (int i = 0; timeline[i] != NULL; i++)
					delete timeline[i];
			delete[] timeline;
		}
	}
	//home screen
	void homescreen()
	{
		for (int i = 0; i < this->friendnumber; i++)
		{
			this->friendList[i]->postprint();
		}
		for (int i = 0; i < this->pagesnumber; i++)
		{
			this->liked_pages[i]->postprint();
		}
	}
	void postprint()
	{
		if (this->timeline != NULL)
		{
			for (int i = 0; this->timeline[i] != NULL; i++)
			{
				if ((this->timeline[i]->getdate() == date_time::get_current_date()) || (this->timeline[i]->getdate() == date_time::get_current_date() - 1))
				{
					cout << this->timeline[i]->getSharedBy()->getname();
					this->timeline[i]->printPost();
					cout << endl << endl << endl;
				}
			}
		}
	}
};
Pages* Pages::searchpage(Pages** asdf, char* id)
{
	for (int i = 0; asdf[i] != NULL; i++)
	{
		if (helper::compare(asdf[i]->getter(), id))
		{
			return asdf[i];
		}
	}
}
User* User::searchusers(User** asdf, char* id)
{
	for (int i = 0; asdf[i] != NULL; i++)
	{
		if (helper::compare(asdf[i]->getter(), id))
		{
			return asdf[i];
		}
	}
}

class Facebook
{
	Pages** page;
	User** user;
	post** posts;
	coment** coments;
	void loadUser(const char* asd, int totalpages)
	{
		ifstream fin(asd);
		if (fin.is_open())
		{
			int totaluser;
			fin >> totaluser;
			char buffer[100] = "\0";
			user = new User * [totaluser + 1];
			char* fname = NULL;
			char* sname = NULL;
			char* id = NULL;
			int* frinum = new int[totaluser];
			int* pagenum = new int[totaluser];
			// extra char* pointer to store id for time t
			char*** temp = new char** [totaluser];
			char*** temptr = new char** [totaluser];
			for (int i = 0; i < totaluser; i++)
			{
				frinum[i] = 0;
				pagenum[i] = 0;
				user[i] = new  User;
				fin >> buffer;
				id = helper::getStringfromBuffer(buffer);
				fin >> buffer;
				fname = helper::getStringfromBuffer(buffer);
				fin >> buffer;
				sname = helper::getStringfromBuffer(buffer);
				fin >> buffer;
				temp[i] = new char* [10];
				temptr[i] = new char* [10];
				for (int j = 0; j < 10; j++)
				{
					temp[i][j] = NULL;
					temptr[i][j] = NULL;
				}
				while (buffer != "-1")
				{
					int p = 0;
					if (buffer[p] == '-')
					{
						if (buffer[p + 1] == '1')
						{
							break;
						}
					}
					else
					{
						temp[i][frinum[i]] = helper::getStringfromBuffer(buffer);
						frinum[i]++;
						fin >> buffer;
					}
				}
				fin >> buffer;
				while (buffer != "-1")
				{
					int p = 0;
					if (buffer[p] == '-')
					{
						if (buffer[p + 1] == '1')
						{
							break;
						}
					}
					else
					{
						temptr[i][pagenum[i]] = helper::getStringfromBuffer(buffer);
						pagenum[i]++;
						fin >> buffer;
					}
				}
				user[i]->setuser(fname, sname, id, pagenum[i], frinum[i]);
			}
			user[totaluser] = NULL;
			for (int i = 0; i < totaluser; i++)
			{
				if (frinum[i] == 0)
				{
					User** asd = NULL;
					user[i]->setfrilist(asd);
				}
				User** asd = new User * [frinum[i] + 1];

				for (int j = 0; j < frinum[i]; j++)
				{
					for (int t = 0; t < totaluser; t++)
					{
						char* id = user[t]->getID();
						if (helper::compare(temp[i][j], id))
						{
							asd[j] = user[t];
							break;
						}
					}
				}
				asd[frinum[i]] == NULL;
				user[i]->setfrilist(asd);

				/////// add exception here
				//make dynamic liked pages and give them value ID and corrsponding name
				Pages** fut = new Pages * [pagenum[i] + 1];
				for (int j = 0; j < pagenum[i]; j++)
				{
					for (int t = 0; t < totalpages; t++)
					{
						char* id = page[t]->getter();
						if (helper::compare(temptr[i][j], id))
						{
							fut[j] = page[t];
							break;
						}
					}

				}
				fut[pagenum[i]] = NULL;
				user[i]->setpage(fut);
			}
			helper::deleteptr(temp, totaluser, 10);
			helper::deleteptr(temptr, totaluser, 10);
		}
		else
		{
			cout << "file didents open";
		}
	}
	void loadpages(const char* asd, int& totalpages)
	{
		ifstream fin(asd);
		if (fin.is_open()) {
			fin >> totalpages;
			page = new Pages * [totalpages + 1];
			char* id;
			char* title;
			for (int i = 0; i < totalpages; i++)
			{
				page[i] = new Pages;
				char buffer[100] = "";
				fin >> buffer;
				id = helper::getStringfromBuffer(buffer);
				fin.getline(buffer, 100);
				title = helper::getStringfromBuffer(buffer);
				page[i]->setpages(id, title);
			}
			page[totalpages] = NULL;
		}
		else
		{
			cout << "file didnt found";
		}
	}
	void loadcoments(const char* fun, User** user, Pages** pages)
	{
		ifstream fin(fun);
		if (fin.is_open())
		{
			int total_coment;
			fin >> total_coment;
			coments = new coment * [total_coment + 1];
			char buffer[100] = "";
			char* id;
			char* post_id;
			obj* comby = NULL;
			char* Text;
			for (int i = 0; i < total_coment; i++)
			{
				coments[i] = new coment;
				fin >> buffer;
				id = helper::getStringfromBuffer(buffer);
				fin >> buffer;
				post_id = helper::getStringfromBuffer(buffer);
				fin >> buffer;
				if (buffer[0] == 'u')
				{
					comby = User::searchusers(user, buffer);
				}
				if (buffer[0] == 'p')
				{
					comby = Pages::searchpage(pages, buffer);
				}
				fin.getline(buffer, 100);
				Text = helper::getStringfromBuffer(buffer);
				coments[i]->setcom(id, Text, post_id, comby);
			}
			coments[total_coment] = NULL;
		}
		else
		{
			cout << "file didn't opened";
		}
	}
	void loadposts(const char* fun, User** users, Pages** pages, coment** coments)
	{
		ifstream fin(fun);
		if (fin.is_open())
		{
			int total_post;
			fin >> total_post;
			posts = new post * [total_post + 1];
			for (int i = 0; i < total_post; i++)
			{
				posts[i] = new post;
				char buffer[100] = "";
				char* id = NULL;
				date_time asd;
				char* Text = NULL;
				obj* sharby = NULL;
				obj** likeby = NULL;
				int check;
				fin >> check;
				if (check == 1)
				{
					fin >> buffer;
					id = helper::getStringfromBuffer(buffer);
					int d, m, y;
					fin >> d >> m >> y;
					asd.set(d, m, y);
					fin.getline(buffer, 100);
					Text = helper::getStringfromBuffer(buffer);
					fin >> buffer;
					if (buffer[0] == 'u')
					{
						sharby = User::searchusers(users, buffer);
					}
					if (buffer[0] == 'p')
					{
						sharby = Pages::searchpage(pages, buffer);
					}
					char** akl;
					akl = new char* [10];
					char r[3] = { '-','1','\0' };
					int l = 0;
					fin >> buffer;
					while (!(helper::compare(buffer, r)))
					{
						akl[l] = helper::getStringfromBuffer(buffer);
						l++;
						fin >> buffer;
					}
					if (l > 0)
					{
						likeby = new obj * [l + 1];
						int k = 0;
						for (int p = 0; p < l; p++)
						{
							if (akl[p][0] == 'u')
							{
								likeby[k] = User::searchusers(users, akl[p]);
							}
							if (akl[p][0] == 'p')
							{
								likeby[k] = Pages::searchpage(pages, akl[p]);
							}
							k++;
						}
						likeby[l] = NULL;
					}
					else
					{
						likeby = NULL;
					}
					posts[i]->setpost(id, Text, sharby, likeby, asd);
				}
				if (check == 2)
				{
					activity* akl = new activity;

					fin >> buffer;
					id = helper::getStringfromBuffer(buffer);
					int d, m, y;
					fin >> d >> m >> y;
					asd.set(d, m, y);
					fin.getline(buffer, 100);
					Text = helper::getStringfromBuffer(buffer);
					int val;
					fin >> val;
					fin.getline(buffer, 100);
					akl->set(val, buffer);
					fin >> buffer;
					if (buffer[0] == 'u')
					{
						sharby = User::searchusers(users, buffer);
					}
					if (buffer[0] == 'p')
					{
						sharby = Pages::searchpage(pages, buffer);
					}
					char** akt;
					akt = new char* [10];
					char r[3] = "-1";
					int l = 0;
					fin >> buffer;
					while (!(helper::compare(buffer, r)))
					{
						akt[l] = helper::getStringfromBuffer(buffer);
						l++;
						fin >> buffer;
					}
					if (l > 0)
					{
						likeby = new obj * [l + 1];
						for (int p = 0; p < l; p++)
						{
							if (akt[p][0] == 'u')
							{
								likeby[p] = User::searchusers(users, akt[p]);
							}
							if (akt[p][0] == 'p')
							{
								likeby[p] = Pages::searchpage(pages, akt[p]);
							}
						}
						likeby[l] = NULL;
					}
					else
					{
						likeby = NULL;
					}
					posts[i]->setpost(id, Text, sharby, likeby, asd, akl);
				}
			}
			posts[total_post] = NULL;
			int t = 0;
			for (t = 0; posts[t] != NULL; t++)
			{
				coment** comments = coment::numofComent(posts[t]->getID(), coments);
				posts[t]->setcoment(comments);
			}
			posts[t] = NULL;
		}
		else
		{
			cout << "Error: file didn't found";
		}
	}
public:
	//

	//load data from txt files
	void load(const char* use, const char* pag)
	{
		int totalpages = 0;
		this->loadpages(pag, totalpages);
		this->loadUser(use, totalpages);
		this->loadcoments("coment.txt", user, page);
		this->loadposts("posts.txt", user, page, coments);
		User* users = NULL;
		Pages* pages = NULL;
		obj** asdf = new obj*;
		for (int i = 0; posts[i] != NULL; i++)
		{
			if (posts[i]->getswit())
			{
				char* id = posts[i]->getSharedBy()->getID();
				if (id[0] == 'u')
				{
					users = User::searchusers(user, id);
					*asdf = users;
				}
				else if (id[0] == 'p')
				{
					pages = Pages::searchpage(page, id);
					*asdf = pages;
				}
				post** timeline = post::settimeline(posts, *asdf);
				if (id[0] == 'u')
					User::settimeline(timeline, *users);
				else if (id[0] == 'p')
					Pages::settimeline(timeline, *pages);
			}
		}
	}
	//run FB for spessific user
	void run()
	{
		date_time::setcurrentdate(15, 11, 2017);
		int i = 7;
		helper::printlins(" set user ID u7 as current user ");
		cout << "\t\t\t\t" << this->user[i - 1]->getfirstname() << this->user[i - 1]->getsecondname() << " is successfully set as current user\n";
		helper::printlins("details about u7");
		user[i - 1]->showdetailedUser();
		helper::printlins("show home screen");
		cout << user[i - 1]->getname() << "'s  homescreen\n" << endl;
		user[i - 1]->homescreen();
		helper::printlins("show timLine of u7");
		user[i - 1]->showtimeline();
		helper::printlins("print coments of post[4]");
		posts[4]->printCOmnet();
		helper::printlins("print likes of post[4]");
		posts[4]->printlikes();
		for (int i = 0; i < 120; i++)
			cout << "_";
		helper::printlins("like post[8]");
		user[i - 1]->likePost(posts[8]);
		helper::printlins("print post[8]");
		posts[8]->printPost();
		helper::printlins("add coment at post[8]");
		posts[8]->addcom<User>(user[i - 1], "Thanks for the wishes");
		helper::printlins("print post[8]");
		posts[8]->printPost();
		post* memory_of_today = user[i - 1]->checkMemory();
		helper::printlins("share memory");
		user[i - 1]->sharememory(memory_of_today, "Never thought i would be specialist in this field");
		cout << "Post shared\n";
		helper::printlins("show timeline");
		user[i - 1]->showtimeline();
		helper::printlins("show timeline of page id p2");
		page[1]->showtimeline();
	}
	//distructor of FB
	~Facebook()
	{
		cout << "FB distructor called";
		for (int i = 0; user[i] != NULL; i++)
			delete user[i];
		for (int i = 0; page[i] != NULL; i++)
			delete page[i];
		delete[] user;
		delete[] coments;
		delete[] posts;
		delete[] page;
	}
};
void main()
{
	Facebook Fb;
	Fb.load("Users.txt", "pages.txt");
	Fb.run();
	system("pause");
}