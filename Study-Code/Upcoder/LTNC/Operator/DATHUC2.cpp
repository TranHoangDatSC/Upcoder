#include <iostream>
using namespace std;

struct BACNHAT
{
    int a,b;
    
    friend istream& operator >> (istream& is, BACNHAT& p)
    {
        is >> p.a >> p.b;
        return is;
    }
    friend ostream& operator << (ostream& os, BACNHAT p)
    {
        os << p.a << "x+" << p.b;
        return os;
    }
    
    BACNHAT operator + (BACNHAT other)
    {
        BACNHAT kq;
        kq.a = this->a + other.a;
        kq.b = this->b + other.b;
        return kq;
    }
    
    int SumDaThuc (int x)
    {
        return a * x + b;
    }
    
    bool operator == (BACNHAT other)
    {
        return ((this->a + this->b) == (other.a + other.b));
    }
};

int main()
{
    BACNHAT f1,f2;
    cin >> f1 >> f2;
    int x;
    cin >> x;
    
    cout << f1 << "\n";
    cout << f2 << "\n";
    
    BACNHAT sum = f1 + f2;
    
    cout << f1 << "+" << f2 << "=" << sum << "\n";
    /*
    cout << sum.a << "\n" << sum.b << "\n"; // Tinh ax hoac b
    */
    
    cout << f1.SumDaThuc(x) << "\n";
    cout << f2.SumDaThuc(x) << "\n";
    
    cout << ((f1 == f2) ? "TRUE" : "FALSE");
    return 0;
}
