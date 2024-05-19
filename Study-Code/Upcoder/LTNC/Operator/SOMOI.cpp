#include <iostream>
using namespace std;

struct SoMoi
{
    int New;
    
    friend istream& operator >> (istream& is, SoMoi& p)
    {
        is >> p.New;
        return is;
    }
    friend ostream& operator << (ostream& os, SoMoi p)
    {
        os << "[SoMoi] " << p.New;
        return os;
    }
    
    int TongChuSo(int n)
    {
        int kq;
        int sum = 0;
        while(n!=0)
        {
            kq = n % 10;
            sum = sum + kq;
            n /= 10;
        }
        return sum;
    }
    
    SoMoi operator + (SoMoi other)
    {
        SoMoi kq;
        kq.New = TongChuSo(this->New) + TongChuSo(other.New);
        return kq;
    }
    bool operator < (SoMoi other)
    {
        return (TongChuSo(this->New) < (TongChuSo(other.New)));
    }
};

int main()
{
    SoMoi a,b;
    cin >> a >> b;
    cout << a << "\n" << b << "\n";
    cout << ((a < b) ? "false" : "true") << "\n";
    cout << a + b;
    return 0;
}
