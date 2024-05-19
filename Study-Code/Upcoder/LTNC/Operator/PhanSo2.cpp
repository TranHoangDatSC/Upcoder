#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;  
    void operator = (int x)
    {
        tu = x;
        mau = 1;
    }
};

istream& operator >> (istream& is, PhanSo& p)
{
    is >> p.tu >> p.mau;
    return is;
}
ostream& operator << (ostream& os, PhanSo p)
{
    os << p.tu << "/" << p.mau << "\n";
    return os;
}

int Find_GCD(int a,int b)
{
    if (b==0) return a;
    return Find_GCD(b,a%b);
}
PhanSo RutGon(PhanSo p)
{
    int a = Find_GCD(p.tu, p.mau);
    p.tu /= a;
    p.mau /= a;
    return p;
}
PhanSo operator + (PhanSo a, PhanSo b)
{
    PhanSo tong;
    tong.tu = a.tu * b.mau + a.mau * b.tu;
    tong.mau = a.mau * b.mau;
    return RutGon(tong);
}
bool operator == (PhanSo a, PhanSo b)
{
    return ((a.tu*b.mau) == (b.tu*a.mau));
}
bool operator != (PhanSo a, PhanSo b)
{
    return !(a==b);
}
template<typename T>
struct Mang
{
    int size;
    Mang()
    {
        size = 0;
    }
    
    T a[100];
    T& operator[] (int index) 
    {
        return a[index];
    } 
};
template<typename T>
istream& operator >> (istream& is, Mang<T>& p)
{
    p.size = 0;
	while (is >> p[p.size]) p.size++;
    return is;
}
template<typename T>
ostream& operator << (ostream& os, Mang<T> p)
{
    for(int i=0;i<p.size;i++)
    {
        os << p[i] << "\n";
    }
    return os;
}

template<typename T>
T Sum(Mang<T> p)
{
    T sum;
    sum=0;
    for (int i=0;i<p.size;i++) 
    {
        sum=sum+p[i];
    }
    return sum;
}

int main()
{
    Mang<PhanSo> arr;
    cin >> arr;
    cout << Sum<PhanSo>(arr) << "\n";
    return 0;
}
