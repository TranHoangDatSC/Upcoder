#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b%a,b);
}
struct PhanSo
{
    int tu, mau;
    
    void nhap()
    {
        cin >> tu >> mau;
    }
    bool operator < (PhanSo other)
    {
        return ((this->tu / this->mau) < (other.tu / other.mau));
    }
};

void xuat(PhanSo ps[], int n)
{
    PhanSo kq = ps[0];
    for(int i = 0; i < n; i++)
    {
        if(ps[i] < kq)
            kq = ps[i];
    }
    cout << kq.tu << "/" << kq.mau;
}

int main()
{
    int n;
    cin >> n;
    PhanSo ps[n];
    
    for(PhanSo &x : ps)
        x.nhap();
        
    xuat(ps,n);
    
    return 0;
}
