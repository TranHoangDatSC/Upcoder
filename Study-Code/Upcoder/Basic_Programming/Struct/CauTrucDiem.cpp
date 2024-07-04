#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct ToaDoDiem
{
    int x,y;
    
    friend istream& operator >> (istream& is, ToaDoDiem& td)
    {
        is >> td.x >> td.y;
        return is;
    }
    friend ostream& operator << (ostream& os, ToaDoDiem& td)
    {
        os << "(" << td.x << "," << td.y << ") ";
        return os;
    }
    
    double Range(ToaDoDiem other)
    {
        return (double) sqrt(pow(other.x - this->x,2) + pow(other.y - this->y,2));
    }
};
double DienTich(ToaDoDiem a, ToaDoDiem b, ToaDoDiem c)
{
    double p = (a.Range(b) + b.Range(c) + c.Range(a)) / 2;
    double S = sqrt(p*(p - a.Range(b))*(p - b.Range(c))*(p - c.Range(a)));
    return S;
}
double ChuVi(ToaDoDiem a, ToaDoDiem b, ToaDoDiem c)
{
    return a.Range(b) + b.Range(c) + c.Range(a);
}
bool thangHang(ToaDoDiem a, ToaDoDiem b, ToaDoDiem c)
{
    return DienTich(a,b,c) <= 0.0001;
}
void outRes(ToaDoDiem a, ToaDoDiem b, ToaDoDiem c)
{
    cout << DienTich(a,b,c) << " " << ChuVi(a,b,c);
}
void outRange(ToaDoDiem a, ToaDoDiem b, ToaDoDiem c)
{
    cout << setprecision(3) << fixed 
    << a.Range(b) << "\n" << c.Range(a) << "\n" << b.Range(c) << "\n";
}

int main()
{
    ToaDoDiem a,b,c;
    cin >> a >> b >> c;
    
    cout << a << b << c << "\n";
    
    outRange(a,b,c);
    
    if(thangHang(a,b,c))
        cout << -1;
    else
        outRes(a,b,c);
        
    return 0;
}
