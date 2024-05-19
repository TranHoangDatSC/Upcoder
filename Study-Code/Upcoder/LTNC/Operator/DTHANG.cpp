#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct DT
{
	int a, b,c;
	friend istream& operator >> (istream& is, DT& d)
	{
		is >> d.a >> d.b >> d.c;
		return is;
	}

	friend ostream& operator << (ostream& os, DT d)
	{
		if (d.a != 0)
		{
			if (d.a < 0) os << "- ";
			if (abs(d.a) != 1) os << abs(d.a);
			os << "x ";
		}

		if (d.b != 0)
		{
			if (d.b > 0 && d.a == 0) os << "";
			if (d.b > 0 && d.a != 0) os << "+ ";
			if (d.b < 0 && d.a!=0) os << "- ";
			if (d.b < 0 && d.a == 0) os << "- ";
			if (abs(d.b) != 1) os << abs(d.b);
			os << "y ";
		}
		if (d.c != 0)
		{
			if(d.c>0)os << "+ ";
			if (d.c < 0)os << "- ";
			os << abs(d.c);
		}

		os << " = 0";
		
		return os;
	}

	bool operator == (DT other)
	{
		return this->a == other.a && this->b == other.b && this->c == other.c;
	}
};

struct PhanSo 
{
	int tu, mau;

	int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a % b);
	}

	friend istream& operator >> (istream& is, PhanSo& p)
	{
		is >> p.tu >> p.mau;
		return is;
	}
	friend ostream& operator << (ostream& os, PhanSo p)
	{
		os << p.tu << "/" << p.mau;
		return os;
	}

	void RutGon()
	{
		int d = gcd(this->tu, this->mau);
		this->tu /= d;
		this->mau /= d;

		if (this->mau < 0)
		{
			this->mau = -this->mau;
			this->tu = -this->tu;
		}
	}

	double operator * (int x)
	{
		return (double)this->tu * x / this->mau;
	}

};

char vitriTuongDoi(int D, int Dx, int Dy, int Dv)
{
	// song song thi a = a', b != b'
	// trung thi a = a' , b = b'
	// vuong thi tich vo huong = 0
	// cat thi a != a'

	if (Dv == 0) return 'V';
	if (D != 0) return 'C';

	else
	{
		if (Dx == Dy && Dy == 0) return 'T';
		if (Dx != 0 && Dy != 0) return 'S';
	}
}

void xuat(DT dt1, DT dt2)
{
	dt1.c = -dt1.c;
	dt2.c = -dt2.c;

	int D = dt1.a * dt2.b - dt2.a * dt1.b;
	int Dx = dt1.c * dt2.b - dt2.c * dt1.b;
	int Dy = dt1.a * dt2.c - dt2.a * dt1.c;
	int Dv = dt1.a * dt2.a + dt1.b * dt2.b;

	char position = vitriTuongDoi(D, Dx, Dy, Dv);

	cout << position << "\n";

	if (position == 'C' || position == 'V')
	{
		PhanSo x, y;
		x.tu = Dx;
		x.mau = D;
		x.RutGon();

		y.tu = Dy;
		y.mau = D;
		y.RutGon();

		cout << "(";
		if (x.tu % x.mau == 0)
			cout << x.tu / x.mau;
		else cout << x;
		cout << ", ";

		if (y.tu % y.mau == 0)
			cout << y.tu / y.mau;
		else cout << y;

		cout << ")";
	}
	else if (position == 'S')
	{
		int x = 1;
		double y = (double)(-dt2.c - dt2.a * x) / dt2.b;
		double range = abs(dt1.a * x + dt1.b * y + dt1.c) / sqrt(dt1.a * dt1.a + dt1.b * dt1.b);
		cout << roundf(range * 1000) / 1000;
	}
	else if (position == 'T') cout << 0;
}
int main()
{
	DT dt1, dt2;
	cin >> dt1 >> dt2;

	cout << dt1 << "\n";
	cout << dt2 << "\n";

	xuat(dt1, dt2);

	return 0;
}
