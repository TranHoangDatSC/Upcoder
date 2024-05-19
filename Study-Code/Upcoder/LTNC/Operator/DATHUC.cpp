#include <iostream>
using namespace std;

struct BacNhat
{
    int a,b;
};

istream& operator >> (istream& is, BacNhat& f);
ostream& operator << (ostream& os, BacNhat f);
bool operator == (BacNhat f, BacNhat other);
BacNhat operator + (BacNhat f, BacNhat other);

int Count(BacNhat& f, int x);

int main()
{
    BacNhat f1,f2;
    int x0;
    cin >> f1 >> f2 >> x0;
    cout << f1 << "\n";
    cout << f2 << "\n";
    cout << f1 << "+" << f2 << "=" << f1+f2 << "\n";
    cout << Count(f1,x0) << "\n" << Count(f2,x0) << "\n";
    if(f1==f2) cout << "TRUE";
    else cout << "FALSE";
    return 0;
}

istream& operator >> (istream& is, BacNhat& f)
{
    is >> f.a >> f.b;
    return is;
}
ostream& operator << (ostream& os, BacNhat f)
{
    os << f.a << "x+" << f.b;
    return os;
}

bool operator == (BacNhat f, BacNhat other)
{
    return (f.a + f.b == other.a + other.b);
}
BacNhat operator + (BacNhat f, BacNhat other)
{
    BacNhat kq;
    kq.a = f.a + other.a;
    kq.b = f.b + other.b;
    return kq;
}
int Count(BacNhat& f, int x)
{
    return f.a * x + f.b;
}
