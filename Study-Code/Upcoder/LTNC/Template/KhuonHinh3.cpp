#include <iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
    
    friend istream& operator >> (istream& is, PhanSo& p)
    {
        is >> p.tu >> p.mau;
        return is;
    }
    friend ostream& operator << (ostream& os, PhanSo p)
    {
        os << p.tu << "/" << p.mau;
        return os;
    }
    
    bool operator < (PhanSo other)
    {
        return ((double)this->tu/this->mau<(double)other.tu/other.mau);
    }
        
};

template<typename T>
struct Mang
{
    int size;
    Mang() 
    {
        size = 0;
    }
    
    T values[100];
    
    T& operator[](int i)
    {
        return values[i];
    }
    
    void operator = (Mang m)
    {
        size = m.size;
        for(int i=0;i<size;i++)
        {
            values[i] = m.values[i];
        }
    }
};

int main() 
{
    Mang <int>a;
    Mang <double>b;
    Mang <PhanSo>c;
    
    char type;
    while(cin>>type)
    {
        switch(type)
        {
            case 'a':
            {
                cin >> a[a.size];
                a.size++;
                break;
            }
            case 'b':
            {
                cin >> b[b.size];
                b.size++;
                break;
            }
            case 'c':
            {
                cin >> c[c.size];
                c.size++;
                break;
            }
        }
    }
    
    int m1=a[0];
    double m2=b[0];
    PhanSo m3=c[0];
    
    if(a.size==0)
    {
        cout << "khong co" << "\n";
    }
    else 
    {
        for(int i=1;i<a.size;i++)
        {
            if(a[i]<m1)
                m1 = a[i];
        }
        cout << m1 << "\n";
    }

    
    if(b.size==0)
    {
        cout << "khong co" << "\n";
    }
    else 
    {
        for(int i=1;i<b.size;i++)
        {
            if(b[i]<m2)
                m2 = b[i];
        }
        cout << m2 << "\n";
    }


    if(c.size==0)
    {
        cout << "khong co" << "\n";
    }
    else 
    {
        for(int i=1;i<c.size;i++)
        {
            if(c[i]<m3)
                m3 = c[i];
        }
        cout << m3 << "\n";
    }
    return 0;
}
