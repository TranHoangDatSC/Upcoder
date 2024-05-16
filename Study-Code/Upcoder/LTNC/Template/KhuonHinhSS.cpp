#include <iostream>
using namespace std;

struct PhanSo
{
	int tu, mau;
	
	friend istream& operator >> (istream& is, PhanSo& p)
	{
		is >> p.tu >> p.mau;
		return is;
	}
	friend ostream& operator << (ostream& os, PhanSo p)
	{
		os << p.tu << "/" << p.tu;
		return os;
	}

	bool operator == (PhanSo p)
	{
		return (this->tu * p.mau == p.tu * this->mau);
	}
};

template<typename T>
bool Test(T a, T b)
{
	return a == b;
}

int main()
{
	char type;
	cin >> type;
	switch (type)
	{
		case 'a':
		{
			int a, b;
        	cin >> a >> b;
        	if (Test(a, b) == true)
        		cout << "true";
        	else
        		cout << "false";
			break;
		}
		case 'b':
			float a, b;
        	cin >> a >> b;
        	if (Test(a, b) == true)
        		cout << "true";
        	else
        		cout << "false";
			break;
		case 'c':
		{
			PhanSo a, b;
        	cin >> a >> b;
        	if (Test(a, b) == true)
        		cout << "true";
        	else
        		cout << "false";
			break;
		}
		default: "khong co";
	}
	return 0;
}
