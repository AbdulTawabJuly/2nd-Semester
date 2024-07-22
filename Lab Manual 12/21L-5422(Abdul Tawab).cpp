#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class Animal
{
	char sound[50];
public:
	Animal();
	virtual const char* Speak();
	virtual~Animal();
};
Animal::Animal()
{	
	strcpy_s(sound, "");
}
const char* Animal::Speak()
{
	/*strcpy_s(sound, "Speak() Called");
	return sound;*/
	return "speak() called.";

}
Animal::~Animal()
{
	cout << "~Animal() called." << endl;
}
class Dog :public Animal
{
	char sound[50];
public:
	Dog();
	const char* Speak();
	~Dog();
};
Dog::Dog()
{
	strcpy_s(sound, "");
}
const char* Dog::Speak()
{
	/*strcpy_s(sound,"WOOF");
	return sound;*/
	return "WOOF";
}
Dog::~Dog()
{
	cout << "~Dog() called." << endl;
}
class Cat :public Animal
{
public:
	const char* Speak();
	~Cat();
};
const char* Cat::Speak()
{
	return "MEOW";
}

Cat::~Cat()
{
	cout << "~Cat() called." << endl;
}
class Sheep:public Animal
{
public:
	const char* Speak();
	~Sheep();
};
const char* Sheep::Speak()
{
	return "BLEAT";
}
Sheep::~Sheep()
{
	cout << "~Sheep() called." << endl;
}
class Cow:public Animal
{
public:
	const char* Speak();
	~Cow();
};
const char* Cow::Speak()
{
	return "BLEAT";
}
Cow::~Cow()
{
	cout << "~Cow() called." << endl;
}
class Horse:public Animal
{
public:
	const char* Speak();
	~Horse();
};
const char* Horse::Speak()
{
	return "BLEAT";
}
Horse::~Horse()
{
	cout << "~Horse() called." << endl;
}
int main()
{


	/*Animal objAnimal;
	Dog objDog;
	Animal* ptrAnimal = &objDog;
	Dog* ptrDog = &objDog;
	cout << objAnimal.Speak() << endl;
	cout << objDog.Speak() << endl;
	cout << ptrAnimal->Speak() << endl;
	cout << ptrDog->Speak() << endl<<endl;
	cout << "=======================================" << endl;
	cout<<ptrDog->Animal::Speak();
	cout << endl;
	cout << "=======================================" << endl;*/

	////===============================================
	/*ptrAnimal = &objDog;
	cout << ptrAnimal->Speak() << endl;*/
	//ptrDog = &objAnimal;
	////===============================================

	/*Dog lassie;
	Animal* myPet = &lassie;
	cout << myPet->Speak() << endl;
	cout << endl;*/
	//cout << "=======================================" << endl;
	//

	/*const int size = 2;
	Animal* myPets[size];
	Cat whiskers;
	Dog mutley;
	myPets[0] = &whiskers;
	myPets[1] = &mutley;
	for (int i = 0; i < size; i++)
		cout << myPets[i]->Speak() << endl;*/
	//cout << "=======================================" << endl;

	/*const int size2 = 5;
	Animal* myPets2[size2];
	int i = 0;
	while (i < size2)
	{
		cout << "Press 1 for a Dog and 2 for a Cat." << endl;
		switch (_getch())
		{
		case '1':
			myPets2[i] = new Dog;
			cout << "Dog added at position " << i << endl << endl;
			i++;
			break;
		case '2':
			myPets2[i] = new Cat;
			cout << "Cat added at position " << i << endl << endl;
			i++;
			break;
		default:
			cout << "Invalid input. Enter again." << endl << endl;
			break;
		}
	}
	for (int i = 0; i < size2; i++)
	{
		cout<<myPets2[i]->Speak()<<endl;
	}
	for (int i = 0; i < size2; i++)
	{
		delete myPets2[i];
	}*/
	//==============================================================================
	const int size3 = 5;
	Animal* myPets3[size3];
	//cout << "=======================================================" << endl;
	int j = 0;
	while (j < size3)
	{
		cout << "Press 1 for a Dog 2 for a Cat , 3 for Sheep , 4 for Cow , 5 for Horse" << endl;
		switch (_getch())
		{
		case '1':
			myPets3[j] = new Dog;
			cout << "Dog added at position " << j << endl << endl;
			j++;
			break;
		case '2':
			myPets3[j] = new Cat;
			cout << "Cat added at position " << j << endl << endl;
		     j++;
			break;
		case '3':
			myPets3[j] = new Sheep;
			cout << "Sheep added at position " << j << endl << endl;
			j++;
			break;
		case '4':
			myPets3[j] = new Cow;
			cout << "Cow added at position " << j << endl << endl;
			j++;
			break;
		case '5':
			myPets3[j] = new Horse;
			cout << "Horse added at position " << j << endl << endl;
			j++;
			break;
		default:
			cout << "Invalid input. Enter again." << endl << endl;
			break;
		}
	}

	for (int k = 0; k < size3; k++)
	{
		delete myPets3[k];
	}
}