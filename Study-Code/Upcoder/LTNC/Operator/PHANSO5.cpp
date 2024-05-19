#include <iostream>
#include <string>
using namespace std;

struct PhanSo
{
    int tu;
    int mau;
    
    void operator = (int t)
    {
        tu = t;
        mau = 1;
    }
    
    friend istream& operator >> (istream& is, PhanSo& p);
    friend ostream& operator << (ostream& os, PhanSo p);

    PhanSo operator ++ (int );

    PhanSo operator -- (int );
};

int main()
{
    PhanSo a;
    string type;
    
    cin >> a >> type;
    
    cout << a << "\n";
    
    if (type == "++")
    {
        a++;
        cout << (a) << "\n";
    }
    if (type == "--")
    {
        a--;
        cout << (a) << "\n";
    }
    return 0;
}

istream& operator >> (istream& is, PhanSo& p)
{
    is >> p.tu >> p.mau;
    return is;
}
ostream& operator << (ostream& os, PhanSo p)
{
    os << p.tu << "/" << p.mau;
    return os;
}

PhanSo PhanSo::operator ++ (int )
{
    PhanSo tmp = *this;
    this->tu = this->tu + 1;
    return tmp;
}

PhanSo PhanSo::operator -- (int )
{
    PhanSo tmp = *this;
    this->tu = this->tu - 1;
    return tmp;
}

