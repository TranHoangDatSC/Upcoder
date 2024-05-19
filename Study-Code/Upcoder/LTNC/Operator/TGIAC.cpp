#include <iostream>
#include <cmath>
using namespace std;

struct Diem
{
    int x,y;
    
    friend istream& operator >> (istream& is, Diem& p)
    {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream& os, Diem p)
    {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
    double Range(Diem other)
    {
        return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
    }
    bool operator == (Diem other)
    {
        return ((this->x == other.x) && (this->y == other.y));
    }
};

struct TamGiac
{
    Diem a,b,c;
    
    friend istream& operator >> (istream& is, TamGiac& p)
    {
        is >> p.a >> p.b >> p.c;
        return is;
    }
    friend ostream& operator << (ostream& os, TamGiac p)
    {
        os << p.a << " " << p.b << " " << p.c;
        return os;
    }
    
    double ChuVi()
    {
        return a.Range(b) + b.Range(c) + a.Range(c);
    }
    double operator + (TamGiac other)
    {
        return this->ChuVi() + other.ChuVi();
    }
    bool operator < (TamGiac other)
    {
        return this->ChuVi() < other.ChuVi();
    }
    bool operator == (TamGiac other)
    {
        if((this->a==other.a || this->a==other.b|| this->a==other.c) &&
        (this->b==other.b || this->b==other.c|| this->b==other.a) &&
        (this->c==other.c|| this->c==other.b|| this->c==other.a))
            return true;
        return false;
    }
};

int main()
{
    TamGiac tg1,tg2;
    cin>>tg1>>tg2;
    
    cout << tg1 << "\n";
    cout << tg2 << "\n";
    
    cout << ((tg1 < tg2) ? "TRUE" : "FALSE" );
    cout << "\n" << ((tg1 == tg2) ? "TRUE" : "FALSE" );
    return 0;
}
