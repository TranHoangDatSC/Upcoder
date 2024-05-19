#include <iostream>
using namespace std;

struct HCN
{
    int length, width;
    
    friend istream& operator >> (istream& is, HCN& h)
    {
        is >> h.length >> h.width;
        return is;
    }
    friend ostream& operator << (ostream& os, HCN h)
    {
        os << "[HCN] " << h.length << "," << h.width << "\n";
        return os;
    }
    double ChuVi()
    {
        return 2 * (this->width + this->length);
    }
    bool operator < (HCN h)
    {
        return this->ChuVi() < h.ChuVi();
    }
    double operator + (double other)
    {
        return this->ChuVi() + other;
    }
};

int main()
{
    HCN a,b;
    cin >> a >> b;
    cout << a << b;
    cout << (a<b ? "true" : "false");
    return 0;   
}
