#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct SoMoi
{
	int ChuSo;

	friend istream& operator >> (istream& is, SoMoi& p)
	{
		is >> p.ChuSo;
		return is;
	}
	friend ostream& operator << (ostream& os, SoMoi p)
	{
		os << "[SoMoi] " << p.ChuSo ;
		return os;
	}

	int TongChuSo(int other)
	{
		if(other < 10) return other;
		return other % 10 + TongChuSo(other / 10);
	}
    
    bool operator == (SoMoi other)
    {
        return this->ChuSo == other.ChuSo;
    }
    
	bool operator > (SoMoi s)
	{
		return TongChuSo(this->ChuSo) > TongChuSo(s.ChuSo);
	}

	SoMoi operator + (SoMoi s)
	{
		SoMoi sum;
		sum.ChuSo = TongChuSo(this->ChuSo) + TongChuSo(s.ChuSo);
		return sum;
	}

};


template <typename T>
struct Mang
{
	int size;
	T values[1000];

	void operator = (T a)
	{
		size = a.size;
		for (int i = 0; i < size; i++)
		{
			values[i] = a.values[i];
		}
	}

	T& operator [](int index)
	{
		return values[index];
	}

	friend istream& operator >> (istream& is, Mang& p)
	{
		T n;
		while (is >> n)
		{
			p.values[p.size++] = n;
		}
		return is;
	}
	friend ostream& operator << (ostream& os, Mang p)
	{
		T max = p.values[0];
		int count = 1;
		for (int i = 1; i < p.size; i++)
		{
		    if(max == p.values[i])
		    {
		        count += 1;
		    }
			if (p.values[i] > max)
			{
				max = p.values[i];
				count=1;
			}
		}
		cout << max << "\n" << count << "\n";
		return os;
	}

	T Sum()
	{
		T sum = T();
		for (int i = 0; i < this->size; i++)
		{
			sum = sum + this->values[i];
		}
		return sum;
	}
};

int main()
{
	char type;
	Mang<int> a;
	Mang<SoMoi> b;

	cin >> type;
	
	switch(type)
	{
		case'N':
		{
			cin >> a;
			cout << a;
		    cout <<	a.Sum();
		    break;
		}
		case'M':
		{
			cin >> b;
			cout << b;
		    cout <<	b.Sum();
		    break;
		}
	}


	return 0;
}
