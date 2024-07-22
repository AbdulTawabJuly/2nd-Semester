#include <iostream> 
#include <fstream>
#include <cstring>
using namespace std;
class Helper;
class Object;
class User;
class Page;
class Post;
class Comment;
class Date;
class Facebook;
// HELPER CLASS 
class Helper
{
public:
    static char* strCopy(const char*);
    static int strLength(const char*);
    static int returnIndex(const char*);
    static void showAppTitle();
    static void showLine();
    static char* intToStr(int num)
    {
        int rem = 10;
        int i = 0;
        int div = num;
        while (div != 0)
        {
            rem = div % 10;
            div = div / 10;
            i++;
        }
        char* temp = new char[i];
        int j = i - 1;
        while (num != 0)
        {
            rem = num % 10;
            temp[j] = (char)rem + 48;
            num = num / 10;
            j--;
        }
        temp[i] = '\0';
        return temp;
    }
    static bool can(int like)
    {
        if (like <= 10)
            return true;
        return false;
    }
};
// ID CLASS 
class Object
{
private:
char* ID; public:
    Object();
    Object(char*);
    ~Object();
    void printID();
    void setID(char* str)
    {
        ID = Helper::strCopy(str);
    }
    char* getID()
    {
        return ID;
    }
    virtual void printName()
    {
        printID();
    };
    virtual void printListView()
    {
        cout << ID;
    }
};
// USER CLASS
class User : public Object
{
private:
    char* firstName;
    char* lastName;
    User** friendList;
    Page** likedPages;
    Post** timeLine;
    int noOfFriends;
    int noOfLikedPages;
    int noOfPosts;
    char** tempID; 
public:
    User();
    ~User();
    void InputData(ifstream&);
    void printName();
    void printListView();
    void viewFriendList();
    void viewLikedPages();
    int getnoOfFriends()
    {
        return noOfFriends;
    }
    void incNoOfLikedPages()
    {
        noOfLikedPages++;
    }
    char** getTempID()
    {
        return tempID;
    }
    void setFriendList(User*&);
    void setLikedPages(Page*&);
    void addPost(Post*&);
    void viewTimeLine();
    void viewHome();
    void printDetailedView();
    void addAPost(Post*&);
    char* getFName()
    {
        return firstName;
    }
    char* getLName()
    {
        return lastName;
    }
};
// PAGE CLASS 
class Page : public Object
{
private:
    char* title;
    int likeCount;
    User** likingUser;
    Post** timeLine;
    int noOfPost;
public:
    Page();
    ~Page();
    void printName()
    {
        cout << title;
    }
    void incNoOfLikes()
    {
        likeCount++;
    }
    void setTitle(char* str)
    {
        title = Helper::strCopy(str);
    }
    char* getTitle()
    {
        return title;
    }
    void InputData(ifstream&);
    void printListView();
    void printDetailedView();
    void setLikingUser(User*&);
    void addPost(Post*&);       
    void viewTimeLine();
    void viewPosts();
};
// DATE CLASS
class Date
{
private:
    int day;
    int month;
int year; 
public:
    Date();
    Date(int, int, int);
    ~Date();
    void InputData(ifstream&);
    void setDate(int, int, int);
    void printDate();
    int getDay()
    {
        return day;
    }
    void setDate(Date);
};
// COMMENT CLASS
class Comment : public Object
{
private:
    char* text;
    Object* commentator;
public:
    Comment();
    Comment(const char*, Object*);
    ~Comment();
    void printListView();
    void setText(char*);
    void setCommentator(Object*);
    char* getText() { return text; }
    Object* getCommentator()
    {
        return commentator;
    }
    void printName() {};
};
// POST CLASS 
class Post : public Object
{
private:
    char* description;
    Date postedDate;
    Object* shared;
    Object** liked;
    Comment** comments;
    int commentCount;
    int likeCount;
    int shareCount;
public:
    Post();
    ~Post();
    void addAComment(Comment*);
    void InputData(ifstream&);
    void setShared(Object*);
    void setLiked(Object*);
    void printListView();
    void printName() {};
    void printDetailedView();
    void addComment(Comment* _comment);
    void setDescription(char* des)
    {
        description = Helper::strCopy(des);
    }
    char* getDescription()
    {
        return description;
    }
    void setDate(Date date)
    {
        postedDate = date;
    }
    Date getDate()
    {
        return postedDate;
    }
    Comment** getComment()
    {
        return comments;
    }
    int getCommentCount()
    {
        return commentCount;
    }
    int postedDay()
    {
        return postedDate.getDay();
    }
    void setComment(Comment**);
    void setCommentCount(int a)
    {
        commentCount = a;
    }
    Object* getShared()
    {
        return shared;
    }
    int getSharedCount()
    {
        return shareCount;
    }
    void showLiked();
    int getLikecount()
    {
        return likeCount;
    }
    void setLikeCount(int _count)
    {
        likeCount = _count;
    }
    void setLikedUser(Object** _liked)
    {
        if (liked == NULL)
        {
            liked = new Object * [10];
            for (int i = 0; i < 10; i++)
                liked[i] = 0;
        }
        for (int i = 0; i < likeCount; i++)
        {
            liked[i] = _liked[i];
        }
    }
    Object** getLiked()
    {
        return liked;
    }
    void viewAPost();
};
// FACEBOOK CLASS
class Facebook
{
private:
    User** allUsers;
    User* currentUser;
    Page** allPages;
    Post** allPosts;
public:
    static Date currentDate;
    static int totalUsers;
    static int totalPages;
    static int totalPosts;
    static int totalComments;
    Facebook();
    ~Facebook();
    void LoadData();
    void setCurrentUser(const char*);
    void setCurrentDate(int, int, int);
    void Run();
    void LoadPages(ifstream&);
    void LoadPosts(ifstream&);
    void LoadUsers(ifstream&);
    void LoadComments(ifstream& inp);
    static int getCurrentDay()
    {
        return currentDate.getDay();
    };
    void Search(const char*);
};
Date Facebook::currentDate;
int Facebook::totalUsers = 0;
int Facebook::totalPages = 0;
int Facebook::totalPosts = 0;
int Facebook::totalComments = 0;
int main()
{
    {
        Helper::showAppTitle();
        Facebook fb;
        fb.LoadData();
        fb.Run();
    }
    system("pause");
    return 0;
}
// HELPER CLASS METHODS IMPLEMENTATION 
char* Helper::strCopy(const char* str)
{
    int len = strLength(str);
    char* temp = new char[len + 1];
    for (int i = 0; i <= len; i++)
    {
        temp[i] = str[i];
    }
    return temp;
}
int Helper::strLength(const char* str)
{
    int i = 0;
    if (str == NULL)
        return i;
    else
    {
        while (str[++i] != '\0');
        return i;
    }
}
void Helper::showAppTitle()
{
    for (int i = 0; i < 118; i++)
    {
        cout << '|';
    }
    cout << endl;
    for (int i = 0; i < 54; i++)
    {
        cout << '|';
    }
    cout << " FACEBOOK ";
    for (int i = 0; i < 54; i++)
    {
        cout << '|';
    }
    cout << endl;
    for (int i = 0; i < 118; i++)
    {
        cout << '|';
    }
    cout << endl << endl;
}
void Helper::showLine()
{
    for (int i = 0; i < 117; i++)
    {
        cout << "-";
    }
    cout << endl;
}
int Helper::returnIndex(const char* str)
{
    int index, len = Helper::strLength(str);
    if (len == 2)
    {
        index = (int)str[1] - 49;
    }
    else if (len == 3)
    {
        index = ((int)str[1] - 48) * 10 + ((int)str[2] - 49);
    }
    else if (len == 5)
    {
        index = (int)str[4] - 49;
    }
    else
    {
        index = ((int)str[4] - 48) * 10 + ((int)str[5] - 49);
    }
    return index;
}
// OBJECT CLASS METHODS IMPLEMENTATION   
Object::Object() :ID(0) {}
Object::Object(char* _ID)
{
    if (_ID == NULL)
        ID = 0;
    else
        ID = Helper::strCopy(_ID);
}
Object::~Object()
{
    if (ID != NULL)
    {
        delete[] ID;
        ID = 0;
    }
}
void Object::printID()
{
    cout << ID;
}
// USER CLASS METHODS IMPLEMENTATION
User::User()
    :Object(NULL),
    firstName(NULL), lastName(NULL), noOfFriends(0), noOfLikedPages(0), timeLine(0), noOfPosts(0), friendList(0), likedPages(0) {}
void User::InputData(ifstream& inp)
{
    char buffer[80];
    inp >> buffer;
    setID(buffer);
    inp >> buffer;
    firstName = Helper::strCopy(buffer);
    inp >> buffer;
    lastName = Helper::strCopy(buffer);
    int i;
    tempID = new char* [10];
    inp >> buffer;
    for (i = 0; buffer[0] != '-' || buffer[1] != '1'; i++)
    {
        tempID[i] = Helper::strCopy(buffer);
        inp >> buffer;
    }
    noOfFriends = i;
}
User::~User()
{
    if (firstName != NULL)
    {
        delete[] firstName;
        firstName = 0;
    }
    if (lastName != NULL)
    {
        delete[] lastName;
        lastName = 0;
    }
    if (friendList != NULL)
    {
        delete[] friendList;
    }
    if (likedPages != NULL)
    {
        delete[] likedPages;
    }
    if (timeLine != 0)
    {
        for (int i = 0; i < noOfPosts; i++)
            delete timeLine[i];
        delete timeLine;
    }
}
void User::setLikedPages(Page*& aPage)
{
    if (likedPages == NULL)
    {
        likedPages = new Page * [10];
        for (int i = 0; i < 10; i++)
            likedPages[i] = 0;
    }
    if (Helper::can(noOfLikedPages))
    {
        for (int i = 0; i < noOfLikedPages; i++)
        {
            if (likedPages[i] == NULL)
            {
                likedPages[i] = aPage;
                break;
            }
        }
    }
    else
    {
        cout << "MAXIMUM LIKED PAGES LIMIT REACHED\n";
    }
}
void User::viewFriendList()
{
    printName();
    cout << " " << (char)196 << " Friend List\n\n";
    for (int i = 0; i < noOfFriends; i++)
    {
        friendList[i]->printListView();
    }
}
void User::viewLikedPages()
{
    printName();
    cout << " " << (char)196 << " Liked Pages\n\n";
    for (int i = 0; likedPages[i] != 0; i++)
    {
        likedPages[i]->printListView();
    }
}
void User::printListView()
{
    printID();
    cout << '-';
    cout << firstName << ' ' << lastName << endl;
}
void User::setFriendList(User*& userFriend)
{
    if (friendList == NULL)
    {
        friendList = new User * [10];
        for (int i = 0; i < 10; i++)
            friendList[i] = 0;
    }
    if (Helper::can(noOfFriends))
    {
        for (int i = 0; i < noOfFriends; i++)
        {
            if (friendList[i] == NULL)
            {
                friendList[i] = userFriend;
                break;
            }
        }
    }
    else
    {
        cout << "MAXIMUM NO. OF FRIENDS REACHED\n";
    }
}
void User::printName()
{
    cout << firstName << " " << lastName;
}
void User::addPost(Post*& rhs)
{
    if (timeLine == NULL)
    {
        timeLine = new Post * [10];
        for (int i = 0; i < 10; i++)
        {
            timeLine[i] = 0;
        }
    }
    if (Helper::can(noOfPosts))
    {
        for (int i = 0; i < 10; i++)
        {
            if (timeLine[i] == NULL)
            {
                timeLine[i] = new Post;
                timeLine[i]->setID(rhs->getID());
                timeLine[i]->setDescription(rhs->getDescription());
                timeLine[i]->setDate(rhs->getDate());
                timeLine[i]->setCommentCount(rhs->getCommentCount());
                timeLine[i]->setComment(rhs->getComment());
                timeLine[i]->setShared(rhs->getShared());
                timeLine[i]->setLikeCount(rhs->getLikecount());
                timeLine[i]->setLikedUser(rhs->getLiked());
                delete rhs;
                rhs = timeLine[i];
                noOfPosts++;
                break;
            }
        }
    }
    else
    {
        cout << "MAXIMUM LIMIT OF POSTS REACHED\n";
    }
}
void User::addAPost(Post*& rhs)
{
    if (timeLine == NULL)
    {
        timeLine = new Post * [10];
        for (int i = 0; i < 10; i++)
        {
            timeLine[i] = 0;
        }
    }
    if (Helper::can(noOfPosts))
    {
        for (int i = 0; i < 10; i++)
        {
            if (timeLine[i] == NULL)
            {
                timeLine[i] = new Post;
                char ID[10] = "post";
                Facebook::totalPosts++;
                char* temp = Helper::intToStr(Facebook::totalPosts);
                strcat_s(ID, 10, temp);
                timeLine[i]->setID(ID);
                timeLine[i]->setDescription(rhs->getDescription());
                timeLine[i]->setShared(rhs->getShared());
                timeLine[i]->setDate(Facebook::currentDate);
                noOfPosts++;
                break;
            }
        }
    }
    else
    {
        cout << "MAXIMUM NO. OF POSTS HAVE REACHED\n";
    }
}
void User::viewTimeLine()
{
    printName();
    cout << (char)196 << "Time Line\n\n";
    for (int i = 0; i < noOfPosts; i++)
    {
        cout << (char)196;
        timeLine[i]->printDetailedView();
    }
}
void User::printDetailedView()
{
    for (int i = 0; i < noOfPosts; i++)
    {
        int currentDay = Facebook::getCurrentDay();
        int postedDay = timeLine[i]->postedDay();
        if (currentDay - postedDay == 1 || currentDay - postedDay == 0)
            timeLine[i]->printDetailedView();
    }
}
void User::viewHome()
{
    printName();
    cout << (char)196 << "Home Page\n\n";
    for (int i = 0; i < noOfFriends; i++)
    {
        friendList[i]->printDetailedView();
    }
    for (int i = 0; i < noOfLikedPages; i++)
    {
        likedPages[i]->viewPosts();
    }
}
// PAGE CLASS METHODS IMPLEMENTATION
Page::Page() :Object(0), title(0), likeCount(0), timeLine(0), noOfPost(0), likingUser(0) {}
Page::~Page()
{
    if (title != NULL)
        delete[] title;
    if (likingUser != 0)
    {
        delete[] likingUser;
    }
    if (timeLine != 0)
    {
        for (int i = 0; i < noOfPost; i++)
        {
            if (timeLine[i] != 0)
                delete timeLine[i];
        }
        delete[] timeLine;
    }
}
void Page::printListView()
{
    printID();
    cout << '-';
    cout << title << endl;
}
void Page::printDetailedView()
{
    Helper::showLine();
    cout << "              " << title << endl;
    Helper::showLine();
    cout << "               LIKED USERS LIST\n";        
    Helper::showLine();
    for (int i = 0; i < likeCount; i++)
    {
        likingUser[i]->printListView();
    }
}
void Page::InputData(ifstream& inp)
{
    char buffer[80];
    inp >> buffer;
    setID(Helper::strCopy(buffer));
    inp.ignore(1);
    inp.getline(buffer, 80);
    title = Helper::strCopy(buffer);
}
void Page::setLikingUser(User*& aUser)
{
    if (likingUser == NULL)
    {
        likingUser = new User * [10];
        for (int i = 0; i < 10; i++)
        {
            likingUser[i] = 0;
        }
    }
    if (Helper::can(likeCount))
    {
        for (int i = 0; i < likeCount; i++)
        {
            if (likingUser[i] == NULL)
            {
                likingUser[i] = aUser;
                break;
            }
        }
    }
    else
    {
        cout << "MAXIMUM USERS HAVE LIKED\n";
    }
}
void Page::addPost(Post*& rhs)
{
    if (timeLine == NULL)
    {
        timeLine = new Post * [10];
        for (int i = 0; i < 10; i++)
        {
            timeLine[i] = 0;
        }
    }
    if (Helper::can(noOfPost))
    {
        for (int i = 0; i < 10; i++)
        {
            if (timeLine[i] == NULL)
            {
                timeLine[i] = new Post;
                timeLine[i]->setID(rhs->getID());
                timeLine[i]->setDescription(rhs->getDescription());
                timeLine[i]->setDate(rhs->getDate());
                timeLine[i]->setCommentCount(rhs->getCommentCount());
                timeLine[i]->setComment(rhs->getComment());
                noOfPost++;
                break;
            }
        }
    }
    else
    {
        cout << "MAXIMUM NO. OF POSTS HAVE REACHED\n";
    }
}
void Page::viewTimeLine()
{
    for (int i = 0; i < noOfPost; i++)
    {
        cout << (char)196;
        timeLine[i]->printDetailedView();
    }
}
void Page::viewPosts()
{
    for (int i = 0; i < noOfPost; i++)
    {
        int currentDay = Facebook::getCurrentDay();
        int postedDay = timeLine[i]->postedDay();
        if (currentDay - postedDay == 1 || currentDay - postedDay == 0)
            timeLine[i]->printDetailedView();
    }
}
// POST CLASS METHODS IMPLEMENTATION
Post::Post() :Object(0), description(0), commentCount(0), likeCount(0), shareCount(0), liked(0), shared(0), comments(0) {}
Post::~Post()
{
    if (description != NULL)
    {
        delete[] description;
    }
    if (liked != NULL)
    {
        delete[] liked;
    }
    if (comments != NULL)
    {
        for (int i = 0; i < commentCount; i++)
        {
            delete comments[i];
        }
        delete[] comments;
    }
}
void Post::setLiked(Object* user)
{
    if (liked == NULL)
    {
        liked = new Object * [10];
        for (int i = 0; i < 10; i++)
            liked[i] = 0;
    }
    if (Helper::can(likeCount))
    {
        for (int i = 0; i < 10; i++)
        {
            if (liked[i] == NULL)
            {
                liked[i] = user;
                likeCount++;
                break;
            }
        }
    }
    else
        cout << "YOU HAVE REACHED YOUR LIKE LIMIT\n";
}
void Post::setShared(Object* user)
{
    if (Helper::can(shareCount))
    {
        shared = user;
    }
    else
    {
        cout << "MAXIMUM USERS HAVE SHARED\n";
    }
}
void Post::InputData(ifstream& inp)
{
    char buffer[120];
    inp >> buffer;
    setID(buffer);
    postedDate.InputData(inp);
    inp.ignore(1);
    inp.getline(buffer, 80);
    description = Helper::strCopy(buffer);

}
void Post::printDetailedView()
{
    if (shared != NULL)
    {
        shared->printName();
        cout << "shared :";
    }
    cout << "\"" << description << "\"" << "...";
    postedDate.printDate();
    if (comments != NULL)
    {
        for (int i = 0; i < commentCount; i++)
            comments[i]->printListView();
    }
}
void Post::printListView()
{
    cout << "\"" << description << "\"" << "...";
    postedDate.printDate();
}
void Post::addComment(Comment* _comment)
{
    if (comments == NULL)
    {
        comments = new Comment * [10];
        for (int i = 0; i < 10; i++)
        {
            comments[i] = 0;
        }
    }
    int flag = 1;
    if (Helper::can(commentCount))
    {
        for (int i = 0; flag == 1; i++)
        {
            if (comments[i] == NULL)
            {
                comments[i] = new Comment;
                comments[i]->setID(_comment->getID());
                comments[i]->setCommentator(_comment->getCommentator());
                comments[i]->setText(_comment->getText());
                commentCount++;
                flag = 0;
            }
        }
    }
    else
    {
        cout << "MAXIMUM COMMENTS REACHED\n";
    }
}
void Post::addAComment(Comment* _comment)
{
    if (comments == NULL)
    {
        comments = new Comment * [10];
        for (int i = 0; i < 10; i++)
        {
            comments[i] = 0;
        }
    }
    int flag = 1;
    if (Helper::can(commentCount))
    {
        for (int i = 0; flag == 1; i++)
        {
            if (comments[i] == NULL)
            {
                comments[i] = new Comment;
                char ID[5] = "c";
                Facebook::totalComments++;
                char* temp = Helper::intToStr(Facebook::totalComments);
                strcat_s(ID, 5, temp);
                comments[i]->setID(ID);
                comments[i]->setCommentator(_comment->getCommentator());
                comments[i]->setText(_comment->getText());
                commentCount++;
                flag = 0;
            }
        }
    }
    else
    {
        cout << "MAXIMUM COMMENTS REACHED\n";
    }
}
void Post::showLiked()
{
    cout << "\n\nPost Liked By:\n";
    for (int i = 0; i < likeCount; i++)
    {
        liked[i]->printListView();
    }
}
void Post::setComment(Comment** com)
{
    if (com != NULL)
    {
        if (comments == NULL)
        {
            comments = new Comment * [10];
            for (int i = 0; i < 10; i++)
            {
                comments[i] = 0;
            }
        }
        for (int i = 0; i < commentCount; i++)
        {
            comments[i] = new Comment;
            comments[i]->setCommentator(com[i]->getCommentator());
            comments[i]->setText(com[i]->getText());
        }
    }
    else
        comments = NULL;
}
void Post::viewAPost()
{
    shared->printName();
    cout << " shared : ";
    printListView();
}
// COMMENT CLASS METHODS IMPLEMENTATION 
Comment::Comment() :Object(0), text(0), commentator(0) {}
Comment::Comment(const char* _text, Object* _commentator)
{
    text = Helper::strCopy(_text);
    commentator = _commentator;
}
void Comment::setCommentator(Object* user)
{
    commentator = user;
}
void Comment::setText(char* str)
{
    text = Helper::strCopy(str);
}

void Comment::printListView()
{
    cout << "           ";
    commentator->printName();
    cout << " wrote:" << '"';
    cout << text << '"' << endl << endl;
}
Comment::~Comment()
{
    if (text != NULL)
    {
        delete[] text;
    }
}
// DATE CLASS METHODS IMPLEMENTATION 
Date::Date() :day(1), month(1), year(1999) {}
Date::Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}
Date::~Date() {}
void Date::InputData(ifstream& inp)
{
    inp >> day >> month >> year;
}
void Date::printDate()
{
    cout << "(";
    if (day <= 9)
        cout << '0' << day << '/';
    else
        cout << day << '/';
    if (month <= 9)
        cout << '0' << month << '/';
    else
        cout << month << '/';
    cout << year;
    cout << ")\n";
}
void Date::setDate(int _day, int _month, int _year)
{
    day = _day;
    month = _month;
    year = _year;
}
void Date::setDate(Date _post)
{
    day = _post.day;
    month = _post.month;
    year = _post.year;
}
// FACEBOOK CLASS METHODS IMPLEMENTATION 
Facebook::Facebook() :allUsers(0), currentUser(0), allPages(0), allPosts(0) {}
Facebook::~Facebook()
{
    if (allUsers != NULL)
    {
        for (int i = 0; i < totalUsers; i++)
            delete allUsers[i];
        delete[] allUsers;
    }
    if (allPages != NULL)
    {
        for (int i = 0; i < totalPages; i++)
            delete allPages[i];
        delete[] allPages;
    }
    if (allPosts != NULL)
    {
        delete[] allPosts;
    }
}
void Facebook::LoadData()
{
    ifstream inp;
    LoadPages(inp);
    LoadUsers(inp);
    LoadPosts(inp);
    LoadComments(inp);
}
void Facebook::LoadPages(ifstream& inp)
{
    char buffer[80];
    inp.open("Pages.txt");
    if (!inp)
        cout << "ERROR IN FILE OPENING\n";
    else {
        inp >> totalPages;
        inp.getline(buffer, 80);
        allPages = new Page * [totalPages];
        for (int i = 0; i < totalPages; i++)
        {
            allPages[i] = new Page();
            allPages[i]->InputData(inp);
        }
        inp.close();
    }
}
void Facebook::LoadPosts(ifstream& inp)
{
    char buffer[120];
    inp.open("Posts.txt");
    if (!inp)
        cout << "ERROR IN FILE OPENING\n";
    else
    {
        inp >> totalPosts;
        for (int i = 0; i < 8; i++)
            inp.getline(buffer, 120);
        allPosts = new Post * [totalPosts];
        for (int i = 0; i < totalPosts; i++)
        {
            allPosts[i] = new Post();
            allPosts[i]->InputData(inp);
            inp >> buffer;
            int index = Helper::returnIndex(buffer);
            if (buffer[0] == 'u')
            {
                allPosts[i]->setShared(allUsers[index]);
            }
            else if (buffer[0] == 'p' && buffer[1] != 'o')
            {
                allPosts[i]->setShared(allPages[index]);
            }
            inp >> buffer;
            for (int j = 0; buffer[0] != '-' || buffer[1] != '1'; j++)
            {
                index = Helper::returnIndex(buffer);
                if (buffer[0] == 'u') {
                    allPosts[i]->setLiked(allUsers[index]);
                }
                else if (buffer[0] == 'p' && buffer[1] != 'o')
                {
                    allPosts[i]->setLiked(allPages[index]);
                }
                inp >> buffer;
            }
            inp.ignore(1);
            inp.getline(buffer, 120);
        }
        inp.close();
    }
}
void Facebook::LoadUsers(ifstream& inp)
{
    char buffer[80];
    inp.open("Users.txt");
    if (!inp)
        cout << "ERROR IN FILE OPENING\n";
    else
    {
        inp >> totalUsers;
        inp.getline(buffer, 80);
        allUsers = new User * [totalUsers];
        for (int i = 0; i < totalUsers; i++) {
            allUsers[i] = new User();
            allUsers[i]->InputData(inp);
            inp >> buffer;
            int j;
            for (j = 0; buffer[0] != '-' || buffer[1] != '1'; j++)
            {
                allUsers[i]->incNoOfLikedPages();
                int index = Helper::returnIndex(buffer);
                allUsers[i]->setLikedPages(allPages[index]);
                allPages[index]->incNoOfLikes();
                allPages[index]->setLikingUser(allUsers[i]);
                inp >> buffer;
            }
        }

        for (int i = 0; i < totalUsers; i++)
        {
            for (int j = 0; j < allUsers[i]->getnoOfFriends(); j++)
            {
                int index = Helper::returnIndex(allUsers[i]->getTempID()[j]);
                allUsers[i]->setFriendList(allUsers[index]);
                delete[] allUsers[i]->getTempID()[j];
            }
            delete[] allUsers[i]->getTempID();
        }
        inp.close();
    }
}
void Facebook::LoadComments(ifstream& inp)
{
    char buffer[180];
    inp.open("Comments.txt");
    if (!inp)
        cout << "ERROR IN FILE OPENING\n";
    else
    {
        inp >> totalComments;
        inp.getline(buffer, 180);
        inp.getline(buffer, 180);
        inp.getline(buffer, 180);
        while (!inp.eof())
        {
            inp >> buffer;
            Comment* comment = new Comment;
            comment->setID(buffer);
            inp >> buffer;
            int postIndex = Helper::returnIndex(buffer);
            inp >> buffer;
            int index = Helper::returnIndex(buffer);
            if (buffer[0] == 'u')
            {
                comment->setCommentator(allUsers[index]);
            }
            else
            {
                comment->setCommentator(allPages[index]);
            }
            inp.ignore(1);
            inp.getline(buffer, 180);
            comment->setText(buffer);
            allPosts[postIndex]->addComment(comment);
            delete comment;  // <---------------------------------------------------
        }
        inp.close();
        for (int i = 0; i < totalPosts; i++)
        {
            int index = Helper::returnIndex(allPosts[i]->getShared()->getID());
            if (allPosts[i]->getShared()->getID()[0] == 'u')
            {
                allUsers[index]->addPost(allPosts[i]);
            }
            else
            {
                allPages[index]->addPost(allPosts[i]);
            }
        }
    }
}
void Facebook::setCurrentUser(const char* ID)
{
    int flag = 0;
    int index = Helper::returnIndex(ID);
    if (index >= 0 && index < totalUsers)
    {
        currentUser = allUsers[index];
        flag = 1;
    }
    if (flag == 0)
        cout << "Oops , you forgot your ID\n", currentUser = NULL;
    else {
        currentUser->printName();
        cout << " successfully set as Current User\n\n";
    }
}
void Facebook::setCurrentDate(int _day, int _month, int _year)
{
    currentDate.setDate(_day, _month, _year);
}
void Facebook::Run()
{
    const char* temp = "u7";
    cout << "Command:\tSet current user " << '"' << temp << '"' << endl;
    setCurrentUser(temp);
    cout << "Command:\tSet current System Date 15 11 2017\n";
    currentDate.setDate(15, 11, 2017);
    cout << "System Date:\t";
    currentDate.printDate();
    cout << endl;
    if (currentUser != NULL)
    {
        cout << "Command:\tView Friend List\n";
        Helper::showLine();
        currentUser->viewFriendList();
        Helper::showLine();
        cout << endl;
        cout << "Command:\tView Liked Pages\n";
        Helper::showLine();
        currentUser->viewLikedPages();
        Helper::showLine();
        cout << endl;
        cout << "Command:\tView Home\n";
        Helper::showLine();
        currentUser->viewHome();
        Helper::showLine();
        cout << endl;
        cout << "Command:\tView Time Line\n";
        Helper::showLine();
        currentUser->viewTimeLine();
        Helper::showLine();
        cout << endl;
        int index;
        cout << "Command:\tView LikedList(Post 5)\n";
        index = Helper::returnIndex("post5");
        allPosts[index]->showLiked();
        Helper::showLine();
        cout << endl;
        cout << "Command:\tLike Post(Post 5)\n";
        allPosts[index]->setLiked(currentUser);
        cout << "Command:\tView LikedList(Post 5)\n";
        allPosts[index]->showLiked();
        Helper::showLine();
        cout << endl;
        cout << "Command:\tPostComment(Post 4, Good Luck for your Result)\n";
        Comment* comment = new Comment("Good Luck for your Result", currentUser);
        index = Helper::returnIndex("post4");
        allPosts[index]->addAComment(comment);
        delete comment;
        cout << "Command:\tView Post(Post 4)\n";
        allPosts[index]->printDetailedView();
        Helper::showLine();
        cout << endl;
        cout << "Command:\tPostComment(Post 8, Thanks for the wishes)\n";
        comment = new Comment("Thanks for the wishes", currentUser);
        index = Helper::returnIndex("post8");
        allPosts[index]->addAComment(comment);
        delete comment;
        cout << "Command:\tView Post(Post 8)\n";
        allPosts[index]->printDetailedView();
        Helper::showLine();
        cout << endl;
        cout << "Command:\tShare Post(Post 5)\n";
        index = Helper::returnIndex("post5");
        currentUser->addAPost(allPosts[index]);
        cout << "Command:\tView TimeLine\n\n";
        currentUser->viewTimeLine();
        Helper::showLine();
        cout << endl;
        cout << "Command:\tView Page(p1)\n\n";
        index = Helper::returnIndex("p1");
        allPages[index]->viewTimeLine();
        Helper::showLine();
        cout << endl;
        cout << "Command:\tSearch(\"Birthday\")\n";
        Search("Birthday");
        Helper::showLine();
        cout << endl;
        cout << "Command:\tSearch(\"Ali\")\n";
        Search("Ali");
        Helper::showLine();
        cout << endl;
    }
}
void Facebook::Search(const char* str)
{

    int flag = 0;
    for (int i = 0; i < totalUsers; i++)
    {
        char* first = allUsers[i]->getFName();
        char* last = allUsers[i]->getLName();
        char* found1 = NULL, * found2 = NULL;
        found1 = strstr(first, str), found2 = strstr(last, str);
        if ((found1 || found2) && flag == 0)
        {
            cout << "\nUsers:\n";
            cout << "---";
            allUsers[i]->printListView();
            flag = 1;
        }
        else if (found1 || found2)
        {
            cout << "---";
            allUsers[i]->printListView();
        }
    }
    for (int i = 0; i < 11; i++)
        // I have hard coded 11 because the value of totalPosts gets updated and as Ma'am you have said that     
    {   // we don't need to link the newly shared post to Facebook so , I have to do this. 
        char* desc = allPosts[i]->getDescription();
        char* found = NULL;
        found = strstr(desc, str);
        if (found && flag == 1)
        {
            cout << "\nPosts:\n";
            cout << "---";
            allPosts[i]->printID();
            cout << '-';
            allPosts[i]->viewAPost();
            flag = 0;
        }
        else if (found)
        {
            cout << "---";
            allPosts[i]->printID();
            cout << '-';
            allPosts[i]->viewAPost();
        }
    }
    for (int i = 0; i < totalPages; i++)
    {
        char* title = allPages[i]->getTitle();
        char* found = NULL;
        found = strstr(title, str);
        if (found && flag == 0)
        {
            cout << "\nPages:\n";
            cout << "---";
            allPages[i]->printListView();
            flag = 1;
        }
        else if (found)
        {
            cout << "---";
            allPages[i]->printListView();
        }
    }
}
