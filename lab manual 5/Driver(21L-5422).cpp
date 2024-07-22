#include"Date(21L-5422).h"
int main()
{
	Date obj;
	/*obj.Print();*/

	/*cout << "Independance Date" << endl;
	Date independence(14, 8, 1947);
	independence.Print();*/

	cout << "Input Your Own Date" << endl;
	obj.Input();
	obj.Print();

	/*Date In;
	In=obj.DateIncreament();
	In.Print();*/

	Date Com;
	Com.Input();
	cout<< Com.Compare(obj);
	system("pause");
}