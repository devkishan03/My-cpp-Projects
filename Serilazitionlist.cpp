#include <iostream>
#include <fstream>
using namespace std;

class Iteam
{
public:
	string name;
	int Quantity;
	int price;
	Iteam() {}
	Iteam(string name, int Quantity, int price)
	{
		this->name = name;
		this->Quantity = Quantity;
		this->price = price;
	}
	// friend ofstream &operator<<(ofstream &ofs, Iteam &its);
	// friend ifstream &operator>>(ifstream &ofs, Iteam &it);
	// friend ostream &operator<<(ostream &os, Iteam &it);
};

ofstream &operator<<(ofstream &ofs, Iteam &its)
{
	ofs << its.name << endl;
	ofs << its.Quantity << endl;
	ofs << its.price << endl;
	return ofs;
}
ifstream &operator>>(ifstream &ofs, Iteam &it)
{
	ofs >> it.name;
	ofs >> it.Quantity;
	ofs >> it.price;
	return ofs;
}
ostream &operator<<(ostream &os, Iteam &it)
{
	os << "name-" << it.name << endl;
	os << "Quantity-" << it.Quantity << endl;
	os << "price-" << it.price << endl;
	return os;
}

int main()
{
	cout << "Enter the number of list" << endl;
	int n;
	cin >> n;
	string name;
	int qty;
	int price;

	Iteam *list[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the name,quantity,price of iteam " << i + 1 << ":" << endl;
		cin >> name;
		cin >> qty;
		cin >> price;
		list[i] = new Iteam(name, qty, price);
	}

	ofstream off("Iteams.txt");
	for (int i = 0; i < n; i++)
	{
		off << *list[i];
	}
	off.close();
	ifstream iff("Iteams.txt");
	Iteam list2;
	for (int i = 0; i < n; i++)
	{
		iff >> list2;
		cout << "iteam " << i + 1 << "\n"
			 << list2 << endl;
	}

	return 0;
}
