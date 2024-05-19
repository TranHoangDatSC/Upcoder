#include <iostream>
using namespace std;

struct SoDao
{
    int dao;
    
    friend istream& operator >> (istream& is, SoDao& d)
    {
        is >> d.dao;
        return is;
    }
    friend ostream& operator << (ostream& os, SoDao d)
    {
        os << "[SoDao] " << d.dao << "\n";
        return os;
    }
    
    int DaoSo()
    {
        int sum=0;
        int tmp = this->dao;
        while(tmp>0)
        {
            sum = sum*10 + tmp%10;
            tmp/=10;
        }
        return sum;
    }
    bool operator > (SoDao other)
    {
        return this->DaoSo() > other.DaoSo();
    }
    
    int operator + (int b)
    {
        return this->DaoSo() + b;
    }
};

int main()
{
    SoDao a,b;
    cin >> a >> b;
    cout << a << b;
    cout << (a>b ? "YES" : "NO") << "\n";
    int kq = a + 0;
    cout << b + kq;
    return 0;
}
