#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct PhanSo
{
	int tu, mau;

	friend istream& operator >> (istream& is, PhanSo& p)
	{
		is >> p.tu >> p.mau;
		return is;
	}
	friend ostream & operator << (ostream& os, PhanSo p)
	{
		os << p.tu << "/" << p.mau;
		return os;
	}

	bool operator != (PhanSo p)
	{
		return (this->tu != p.tu || this->mau != p.mau);
	}
};

PhanSo RutGonPS(PhanSo& p)
{
	int d = gcd(p.tu, p.mau);
	p.tu /= d;
	p.mau /= d;
	return p;
}

struct HonSo
{
	int nguyen;
	PhanSo ps;

	friend istream& operator >> (istream& is, HonSo& hs)
	{
		is >> hs.nguyen >> hs.ps.tu >> hs.ps.mau;
		return is;
	}
	friend ostream& operator << (ostream& os, HonSo hs)
	{
		os << hs.nguyen << " " << hs.ps;
		return os;
	}

	int TongCacThanhPhan()
	{
		return this->nguyen + this->ps.tu + this->ps.mau;
	}

	bool operator != (HonSo hs)
	{
		return (this->nguyen != hs.nguyen || this->ps.tu != hs.ps.tu || this->ps.mau != hs.ps.mau);
	}

	bool operator > (HonSo hs)
	{
		return (this->TongCacThanhPhan() > hs.TongCacThanhPhan());
	}

};

PhanSo RutGonHS(HonSo& hs)
{
	int tmpTu = hs.nguyen * hs.ps.mau + hs.ps.tu;
	hs.nguyen = tmpTu / hs.ps.mau;
	hs.ps.tu = tmpTu % hs.ps.mau;
	return RutGonPS(hs.ps);
}

PhanSo DoiHSPS(HonSo hs)
{
	PhanSo p;
	p.tu = hs.nguyen * hs.ps.mau + hs.ps.tu;
	p.mau = hs.ps.mau;
	return p;
}

HonSo DoiPSHS(PhanSo p)
{
	HonSo hs;
	hs.nguyen = p.tu / p.mau;
	hs.ps.tu = p.tu % p.mau;
	hs.ps.mau = p.mau;
	return hs;
}



int main()
{
	HonSo hs1, hs2;
	PhanSo p1, p2;

	string type;

	cin >> hs1 >> hs2 >> type;

	cout << (hs1 != hs2 ? "TRUE" : "FALSE") << "\n";
	cout << (hs1 > hs2 ? "TRUE" : "FALSE") << "\n";

	if (type == "true")
	{
	    RutGonHS(hs1);
	    RutGonHS(hs2);
		cout << hs1 << "\n" << hs2;
	}
	else if (type == "false")
	{
		p1 = DoiHSPS(hs1);
		RutGonPS(p1);

		p2 = DoiHSPS(hs2);
		RutGonPS(p2);

		cout << p1 << "\n" << p2;
	}
	return 0;
}
