#include <iostream>
#include <cmath>
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
		if (p.tu < 0)
		{
			os << "-";
		}

		os << abs(p.tu) << "/" << p.mau;

		return os;
	}

	int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a % b);
	}

	void RutGon()
	{
		int kq = gcd(this->tu, this->mau);
		this->tu /= kq;
		this->mau /= kq;

		if (this->mau < 0)
		{
			this->tu = -this->tu;
			this->mau = abs(this->mau);
		}
		return;
	}

	PhanSo operator + (PhanSo p)
	{
		PhanSo kq;
		kq.tu = this->tu * p.mau + this->mau * p.tu;
		kq.mau = this->mau * p.mau;
		return kq;
	}
};

struct SoPhuc
{
	int thuc, ao;

	friend istream& operator >> (istream& is, SoPhuc& sp)
	{
		is >> sp.thuc >> sp.ao;
		return is;
	}

	friend ostream& operator << (ostream& os, SoPhuc sp)
	{
		if (sp.thuc != 0) os << sp.thuc;

		if (sp.ao != 0)
		{
			if (sp.ao > 0 && sp.thuc != 0) os << "+";
			if (sp.ao < 0 && sp.thuc != 0) os << "-";
			if (sp.ao < 0 && sp.thuc == 0) os << "-";
			if (sp.ao > 0 && sp.thuc == 0) os << "";
			if (abs(sp.ao) != 1) os << abs(sp.ao);

			os <<"i";
		}

		if (sp.thuc == 0 && sp.ao == 0)
		{
			os << 0;
		}
		return os;
	}
	SoPhuc operator + (SoPhuc sp)
	{
		SoPhuc kq;
		kq.thuc = this->thuc + sp.thuc;
		kq.ao = this->ao + sp.ao;
		return kq;
	}
	SoPhuc operator + (int p)
	{
		SoPhuc kq;
		kq.thuc = this->thuc + p;
		kq.ao = this->ao;
		return kq;
	}
	SoPhuc operator + (PhanSo p)
	{
		SoPhuc kq;
		kq.thuc = this->thuc + p.tu;
		kq.ao = this->ao + p.mau;
		return kq;
	}
};

int main()
{
	SoPhuc sp;
	char type;

	int i;
	SoPhuc z;
	PhanSo p;

	cin >> sp >> type;

	cout << sp << "\n";

	if (type == 'i')
	{
		cin >> i;
		cout << i << "\n" << sp + i;
	}
	else if (type == 'z')
	{
		cin >> z;
		cout << z << "\n" << sp + z;
	}
	else if (type == 'p')
	{
		cin >> p;
		p.RutGon();
		cout << p << "\n" << sp + p;
	}
	return 0;
}
