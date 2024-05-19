#include <iostream>
#include <string>
using namespace std;

struct SoChan
{
	string ChuSo;

	friend istream& operator >> (istream& is, SoChan& c)
	{
		is >> c.ChuSo;
		return is;
	}
	friend ostream& operator << (ostream& os, SoChan c)
	{
		os << c.Chan();
		return os;
	}

	int Chan()
	{
		int kq = 0;
		for (int i = 0; i < ChuSo.size(); i+=2)
		{
			kq = kq * 10 + (this->ChuSo[i] - 48);
		}
		return kq;
	}

	int Le()
	{
		int kq = 0;
		for (int i = 1; i < ChuSo.size(); i += 2)
		{
			kq = kq * 10 + (this->ChuSo[i] - 48);
		}
		return kq;
	}

	bool operator < (SoChan other)
	{
		return this->Chan() < other.Chan();
	}
};

int tongThanhPhan(SoChan number,int parameter = 0)
{
	int kqChan = 0;
	int kqLe = 0;

	for (int i = 0; i < number.ChuSo.size(); i++)
	{
		if (i % 2 == 0) kqChan += (number.ChuSo[i] - 48);

		else kqLe += (number.ChuSo[i] - 48);
	}
	if (parameter == 0) return kqChan;
	else return kqLe;
}

int main()
{
	SoChan a, b;
	int parameter;
	cin >> a >> b >> parameter;

	cout << a << "\n" << b << "\n";

	cout << (a < b ? "true" : "false") << "\n";

	cout << tongThanhPhan(a, parameter) << "\n";
	cout << tongThanhPhan(b, parameter);

	return 0;
}
