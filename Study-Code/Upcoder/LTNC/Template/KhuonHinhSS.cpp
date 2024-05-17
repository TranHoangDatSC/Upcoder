#include <iostream>
using namespace std;

struct PhanSo
{
    int tu,mau;
    
    friend istream& operator >> (istream& is, PhanSo& ps)
    {
        is >> ps.tu >> ps.mau;
        return is;
    }
    friend ostream& operator << (ostream& os, PhanSo ps)
    {
        os << ps.tu << "\n" << ps.mau;
        return os;
    }
    bool operator == (PhanSo other)
    {
        return this->tu * other.mau == this->mau * other.tu;
    }
};

template<typename T>
void solve(T a, T b)
{
    if(a == b) cout << "true";
    else cout << "false";
}

int main()
{
    char type;
    cin >> type;
    
    switch(type)
    {
        case 'a':
        {
            int a,b;
            cin >> a >> b;
            solve(a,b);
            break;
        }
        case 'b': 
        {
            float a,b;
            cin >> a >> b;
            solve(a,b);
            break;
        }
        case 'c':
        {
            PhanSo a,b;
            cin >> a >> b;
            solve(a,b);
            break;
        }
        default: "khong co";
    }
    return 0;
}
