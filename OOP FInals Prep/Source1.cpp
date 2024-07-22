#include<iostream>
using namespace std;
class Helper
{
public:
	static int StringLength(const char* str)
	{
		int i = 0;
		while (str[i] != 0)
		{
			i++;
		}
		return i;
	}
	static void StringCopy(const char*& src, char*& dest)
	{
		int i = 0;
		while (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	static char* GetStringFromBuffer(const char*& str)
	{
		int length = StringLength(str);
		char* temp = new char[length + 1];
		StringCopy(str, temp);
		return temp;
	}
};
class Date
{
private:
	int date;
	int month;
	int year;
	static Date currentDate;
public:
	Date(int d = 0, int m = 0, int y = 0)
	{
		date = d;
		month = m;
		year = y;
	}
	void SetDate(int d, int m, int y)
	{
		date = d;
		month = m;
		year = y;
	}
	static Date GetCurrentDate()
	{
		return currentDate;
	}
	int countLeapYears(Date d)
	{
		int years = d.year;
		if (d.month <= 2)
			years--;
		return years / 4 - years / 100 + years / 400;
	}

	int operator-(const Date& dt2)
	{
		const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		long int n1 = year * 365 + date;

		for (int i = 0; i < month - 1; i++)
			n1 += monthDays[i];
		n1 += countLeapYears(*this);
		long int n2 = dt2.year * 365 + dt2.date;
		for (int i = 0; i < dt2.month - 1; i++)
			n2 += monthDays[i];
		n2 += countLeapYears(dt2);
		return (n1 - n2);
	}

	void Print()
	{
		cout << date << "/" << month << "/" << year << endl;
	}
};
Date Date::currentDate(14, 12, 2017);
class Item
{
private:
	char* name;
	float originalprice;
public:
	Item(const char* na, float price)
	{
		name = Helper::GetStringFromBuffer(na);
		originalprice = price;
	}
	virtual void DisplayItem()
	{

	}
	char* GetName()
	{
		return name;
	}
	float GetPrice()
	{
		return originalprice;

	}
	virtual ~Item()
	{
		delete[] name;
	}
};
class Perishable :public Item
{
private:
	Date ExpiryDate;
	int Quantity;
public:
	Perishable(const char* name, float price, int date, int month, int year, int amount) :Item(name, price)
	{
		ExpiryDate.SetDate(date, month, year);
		Quantity = amount;
	}
	void DisplayItem()
	{
		cout << "Item Type = Perishable" << endl;
		cout << "Item Name = " << GetName() << endl;
		cout << "Quantity = " << Quantity << endl;
		cout << " Expiry Date = ";
		ExpiryDate.Print();
		if ((Date::GetCurrentDate() - ExpiryDate) <= 0)
		{
			cout << "Price = 0" << endl;
		}
		else
		{
			cout << " Price = " << GetPrice() << endl << endl;
		}
		cout << "-----------------------------------------------------------------------------------------" << endl;

	}
	~Perishable()
	{

	}
};
class Permanent :public Item
{
private:
	Date EntryDate;
	int age;
public:
	Permanent(const char* name, float price, int date, int month, int year) :Item(name, price)
	{
		EntryDate.SetDate(date, month, year);
		age = Date::GetCurrentDate() - EntryDate;
	}
	virtual void DisplayItem()
	{
		cout << "Item Type = Permanent" << endl;
		cout << "Item Name = " << GetName() << endl;
		cout << " Entry Date = ";
		EntryDate.Print();
		cout << "Age = " << age << endl;
		cout << "Price = " << GetPrice() - (age * ((0.02 / 100.0) * GetPrice())) << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
	}
	int GetAge()
	{
		return age;
	}
	Date GetEntryDate()
	{
		return EntryDate;
	}
	virtual ~Permanent()
	{

	}
};
class Bulk_Item :public Permanent
{
private:
	char* description;
	bool set;
public:
	Bulk_Item(const char* name, float price, int date, int month, int year, const char* desc, bool check) :Permanent(name, price, date, month, year)
	{
		description = Helper::GetStringFromBuffer(desc);
		set = check;
	}
	virtual void DisplayItem()
	{
		cout << "Item Type = Bulk" << endl;
		cout << "Item Name = " << GetName() << endl;
		cout << " Entry Date = ";
		GetEntryDate().Print();
		cout << "Description : " << description << endl;
		cout << "Age = " << GetAge() << endl;
		if (set != true)
		{
			cout << "Price = " << GetPrice() - (GetAge() * ((0.02 / 100.0) * GetPrice())) << endl;
		}
		else
		{
			cout << "Price = " << GetPrice() << endl;
		}

		cout << "-----------------------------------------------------------------------------------------" << endl;
	}
	~Bulk_Item()
	{
		delete[]description;
	}
};
class Pharmacy
{
private:
	Item** item;
	int Itemcount;
public:
	Pharmacy(int count)
	{
		Itemcount = count;
		item = 0;
	}
	~Pharmacy()
	{
		for (int i = 0; i < Itemcount; i++)
		{
			delete item[i];
		}
		delete[]item;
	}
	void AddItem(Item* ptr)
	{
		if (item == 0)
		{
			item = new Item * [Itemcount];
			for (int i = 0; i < Itemcount; i++)
			{
				item[i] = 0;
			}
		}
		int i = 0;
		while (item[i] != 0)
		{
			if (i == Itemcount)
			{
				break;
			}
			i++;
		}
		item[i] = ptr;

	}
	void DisplayItems()
	{
		for (int i = 0; i < Itemcount; i++)
		{
			item[i]->DisplayItem();
		}
	}


};

int main()
{
	int itemCount = 4;
	Pharmacy ph(itemCount); //ph has a list of 4 items here
	Item* iptr = new Permanent("glucometer", 5000, 15, 11, 2016);
	// a glucometer of price 5000 and entry date 15 Nov 2016
	ph.AddItem(iptr);
	iptr = new Perishable("Panadol", 20, 16, 11, 2018, 500);
	// 500mg Panadol tablet of price 20, expiry date 16 Nov 2018
	ph.AddItem(iptr);
	iptr = new Bulk_Item("Gloves", 500, 12, 10, 2016, "Glove box for doctors", true);
	// glovesbox of cost 500 Rs. With entry date 12 Oct 2016
	ph.AddItem(iptr);
	iptr = new Bulk_Item("5CC Syringe", 90, 15, 7, 2017, "For Injections only", false);
	// Syring of cost 90 Rs. each with entry date 15 July 2017
	ph.AddItem(iptr);
	ph.DisplayItems();
	// this function should print complete information of items in list
	return 0;
}