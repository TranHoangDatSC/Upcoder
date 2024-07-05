#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
struct PhanSo
{
    int tu, mau;
    
    bool nhap()
    {
        if(!(cin >> tu >> mau))
            return false;
        
        if(tu < 0)
        {
            tu = -tu;
            mau = -mau;
        }
        return true;
    }
    void rutgon()
    {
        int d = gcd(tu,mau);
        tu /= d;
        mau /= d;
    }
    PhanSo operator + (PhanSo other)
    {
        PhanSo kq;
        kq.tu = this->tu*other.mau + this->mau*other.tu;
        kq.mau = this->mau * other.mau;
        kq.rutgon();
        return kq;
    }
};

void xuat(PhanSo ps[],int n)
{
    PhanSo res = ps[0];
    
    for(int i = 1; i < n; i++)
    {
        res = res + ps[i];
    }
    res.rutgon();
    cout << res.tu << "/" << res.mau;
}

int main()
{
    PhanSo ps[100];
    int n = 0;
    
    while(ps[n].nhap())
        n++;
        
    xuat(ps,n);
    
    return 0;
}
