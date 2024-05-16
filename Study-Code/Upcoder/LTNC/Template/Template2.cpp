#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b,a%b);
}

struct PhanSo
{
    int tu, mau;
    
    void operator = (int t)
    {
        tu = t;
        mau = 1;
    }
    
    friend istream& operator >> (istream& is, PhanSo& ps)
    {
        is >> ps.tu >> ps.mau;
        return is;
    }
    friend ostream& operator << (ostream& os, PhanSo ps)
    {
        os << ps.tu << "/" << ps.mau << "\n";
        return os;
    }
    
    bool operator < (PhanSo other)
    {
        return this->tu * other.mau < this->mau * other.tu;
    }
    
    void rutGon()
    {
        int d = gcd(this->tu,this->mau);
        this->tu /= d;
        this->mau /= d;
    }
    
    PhanSo operator + (PhanSo other)
    {
        PhanSo kq;
        kq.tu = this->tu * other.mau + this->mau * other.tu;
        kq.mau = this->mau * other.mau;
        kq.rutGon();
        return kq;
    }
};

template<typename T>
struct Mang
{
    int size;
    T values[100];
    
    void operator = (Mang arr)
    {
        size = arr.size;
        for(int i = 0; i < size; i++)
        {
            values[i] = arr.values[i];
        }
    }
    T& operator [](int index)
    {
        return values[index];
    }
    
    friend istream& operator >> (istream& is, Mang& arr)
    {
        arr.size = 0; 
        T x;
        while(is >> x)
        {
            arr.values[arr.size++] = x;
        }
        return is;
    }
    friend ostream& operator << (ostream& os, Mang arr)
    {
        os << arr.Sum();
        return os;
    }
    T Sum()
    {
        T res;
        res = 0;
        for(int i = 0; i < this->size; i++)
        {
            res = res + this->values[i];
        }
        return res;
    }
};


int main()
{
    char type;
    cin >> type;
    
    switch(type)
    {
        case 'a':
        {
            Mang<int> a;
            cin >> a;
            cout << a;
            break;
        }
        case 'b':
        {
            Mang<PhanSo> b;
            cin >> b;
            cout << b;
            break;
        }
        case 'c':
        {
            Mang<float> c;
            cin >> c;
            cout << c;
            break;
        }
    }
    return 0;
}
