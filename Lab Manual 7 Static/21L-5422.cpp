#include<iostream>
#include<fstream>
using namespace std;
class Helper
{
public:
	static int StringLength(char* str)
	{
		int i = 0;
		int count = 0;
		while (str[i] != '\0')
		{
			i++;
			count++;
		}
		return count;
	
	}
	static void StringCopy(char*& dest, char*& src) {
		int i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';

	}
	static char* GetStringFromBuffer(char* str)
	{
		int length = StringLength(str);
		char* dest = new char[length+1];
		StringCopy(dest, str);
		return dest;
		
	}
};
class Car
{
private:
	static int totalCars; 
	int model;
	char* make;
	char* name;
	char* color;
public:
	Car()
	{
		model = 0;
		color = make = name = 0;
		totalCars++;
	}
	
	static int GetTotalCars()
	{
		return totalCars;
	}
	void ReadDataFromFile(ifstream& fin)
	{
		char temp[20];
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		fin >> model;
		fin >> temp;
		make = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		fin >> temp;
		name = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		fin >> temp;
		color = Helper::GetStringFromBuffer(temp);
	}
	void PrintListView()
	{
		cout << model<<" " << make<<" " << name<<" " << color << endl;;
		
	}
	void PrintDetailView()
	{
		cout << "Car Information" << endl;
		cout << "Model: " << model<<endl;
		cout << "Make: " << make<<endl;
		cout << "Name: " << name<<endl;
		cout << "Color: " << color<<endl;
	}
	~Car()
	{
		cout << "Destroying ";
		
		PrintListView();
		delete[]make;
		delete[]name;
		delete[]color;
	}
	void Input()
	{
		char temp[20];
		cout << "Enter Model ";
		cin >> model;
		cout << "Enter Make ";
		cin >> temp;
		make = Helper::GetStringFromBuffer(temp);
		cout << "Enter Name ";
		cin >> temp;
		name = Helper::GetStringFromBuffer(temp);
		cout << "Enter Color ";
		cin >> temp;
		color = Helper::GetStringFromBuffer(temp);
		
	}
};
int Car::totalCars = 0;
Car* ReadDataFromFile(const char* fileName)

{
	ifstream Read;
	int totalCars = 0;
	char buffer[80];
	Read.open("CarsData.txt");
	if (Read.is_open())
	{
		Read >> totalCars;
		Car* carsList = new Car[totalCars];
		int i = 0;
		while (!Read.eof())
		{
			carsList[i].ReadDataFromFile(Read);
			i++;
		}
		return carsList;
	}
	else
	{
		return 0;
	}
}
int main()
{
	Car* carsList = ReadDataFromFile("CarsData.txt");
	int count = 0;
	if (carsList != 0)
	{
		count = Car::GetTotalCars(); //Calling static function
		cout << "Total Number of Cars in System:\t" << count << endl;
		
		cout << "\nCars List:\n\n";
		{
			for (int i = 0; i < count; i++)
			{
				carsList[i].PrintListView();
			}
		}
		//Comment above printing and Test Printing 2
		/*cout << "\nCars List	:\n\n";
		{
			Car temp = carsList[0];
			temp.PrintListView();
			for (int i = 1; i < count; i++)
			{
				temp = carsList[i];
				temp.PrintListView();
			}
		}*/
		if (carsList)
			delete[] carsList;
	}
	cout << "Total Number of Cars in System:\t" << Car::GetTotalCars() << endl << endl
		<< endl;
	Car testCar;
	cout << "Enter Car Information" << endl;
	testCar.Input(); // Take car data from user
	testCar.PrintDetailView();
	cout << "Total Number of Cars in System:\t" << testCar.GetTotalCars() << endl <<
		endl << endl;

	return 0;
}
