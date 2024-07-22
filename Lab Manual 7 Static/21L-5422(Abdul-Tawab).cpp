//#include<iostream>
//#include<fstream>
//using namespace std;
//class Helper
//{
//public:
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
//		//Write Yourself
//		// This function should return lenght of str
//	}
//	static void StringCopy(char*& dest, char*& src) {
//		int length = StringLength(src);
//		int i = 0;
//		while (i < length)
//		{
//			dest[i] = src[i];
//		}
//		//Deep Copies src into dest.
//	}
//	static char* GetStringFromBuffer(char *str)
//	{
//		int length = StringLength(str);
//		char* dest = new char[length];
//		StringCopy(dest,str);
//		return dest;
//		//Write Yourself
//		//This function should allocate required memory on heap,
//		//copy string in this memory using StringCopy and return newly created
//		//cstring.
//	}
//};
//class Car
//{
//private:
//	int totalCars; // initialize it to zero yourself
//	int model;
//	char* make;
//	char* name;
//	char* color;
//public:
//	Car()
//	{
//		model = 0;
//		color = make = name = 0;
//		totalCars++;
//	}
//	//Write Getter of totalCars yourself
//	 int GetTotalCars()
//	{
//		return totalCars;
//	}
//	void ReadDataFromFile(ifstream& fin)
//	{
//		char temp[20];
//		fin >> model;
//		fin >> temp;
//		//This is how we call static functions without object
//		make = Helper::GetStringFromBuffer(temp);
//		//Set rest of the values yourself.
//	}
//	void PrintListView()
//	{
//		cout << model << make << name << color;
//		//Write yourself
//	}
//	void PrintDetailView()
//	{
//		cout << "Enter Car Information" << endl;
//		Input();
//		cout << "Car Information" << endl;
//		cout << "Model: " << model;
//		cout << "Make: " << make;
//		cout << "Name: " << name;
//		cout << "Color: " << color;
//
//		
//		//Write yourself
//	}
//	~Car()
//	{
//		cout << "Destroying ";
//		PrintListView();
//		//Deallocate memory yourself
//	}
//	void Input()
//	{
//		cout << "Enter Model ";
//		cin >> model;
//		cout << "Enter Make ";
//		cin >> make;
//		cout << "Enter Name ";
//		cin >> name;
//		cout << "Enter Color ";
//		cin >> color;
//		//Do not consume one extra byte on heap
//		//Use only one temp buffer
//	}
//};
//Car* ReadDataFromFile(char* fileName)
//{
//	ifstream Read;
//	int totalCars = 0;
//	char buffer[80];
//	Read.open("CarsData.txt");
//		if (Read.is_open())
//		{
//			Read >> totalCars;
//			//cout << totalCars;
//			Read.getline(buffer, 80, '\n'); //We are not saving comment
//			//cout << buffer << endl;
//			Car* carsList = new Car[totalCars];
//			int i = 0;
//			while (!Read.eof())
//			{
//				carsList[i].ReadDataFromFile(Read);
//				i++;
//			}
//			return carsList;
//		}
//		else
//		{
//			return 0;
//		}
//}
//int main()
//{
//	//Comment all the code. Then uncomment it line by line.
//	//Implement/add functionality for uncommented line.
//	//Execute and verify result with output.
//	char Read[] = "CarsData.txt";
//	Car* carsList = ReadDataFromFile(Read);
//	int count = 0;
//	if (carsList != 0)
//	{
//		count = Car::GetTotalCars(); //Calling static function
//		cout << "Total Number of Cars in System:\t" << count << endl;
//		//Test one Print at a time.
//		cout << "\nCars List:\n\n";
//		{
//			for (int i = 0; i < count; i++)
//			{
//				carsList[i].PrintListView();
//			}
//		}
//		//Comment above printing and Test Printing 2
//		cout << "\nCars List:\n\n";
//		{
//			Car temp = carsList[0];
//			temp.PrintListView();
//			for (int i = 1; i < count; i++)
//			{
//				temp = carsList[i];
//				temp.PrintListView();
//			}
//		}
//		if (carsList)
//			delete[] carsList;
//	}
//	cout << "Total Number of Cars in System:\t" << Car::GetTotalCars() << endl << endl
//		<< endl;
//	Car testCar;
//	testCar.Input(); // Take car data from user
//	testCar.PrintDetailView();
//	cout << "Total Number of Cars in System:\t" << testCar.GetTotalCars() << endl <<
//		endl << endl;
//
//	return 0;
//}
