#include <iostream>
using namespace std;

struct SoDao
{
    int Dao;
};

istream& operator >> (istream& is, SoDao& d)
{
    is >> d.Dao;
    return is;
}
ostream& operator << (ostream& os, SoDao d)
{
    os << "[SoDao]" << " " << d.Dao;
    return os;
}

int DaoNguoc(SoDao a, int kq = 0)
{
    if(a.Dao == 0) return kq;
    
    kq = kq * 10 + a.Dao % 10;
    a.Dao /= 10;
    return DaoNguoc(a,kq);
}

bool operator > (SoDao a,SoDao b)
{
    return DaoNguoc(a) > DaoNguoc(b); 
}

int operator + (SoDao a, int b)
{
    return DaoNguoc(a) + b;
}

template <class T>
struct Mang
{
    int size;
    T array[100];
    
    T& operator[](int index)
    {
        return array[index];
    }
};

template<class T>
T Max(Mang<T> m)
{
    T max = m[0];
    for(int i=1;i<m.size;i++)
    {
        if(m[i]>max)
            max = m[i];
    }
    return max;
}

template<class T>
int Sum(Mang<T> m)
{
    int s=0;
    for(int i=0;i<m.size;i++)
    {
        s = m[i]+s;
    }
    return s;
}
int main()
{
    Mang<int> a;
    Mang<SoDao> b;
    a.size=0;
    b.size=0;
    
    char type;
    
    while(cin >> type)
    {
        if(type=='T')
        {
            int n;
            cin >> n;
            a[a.size++]=n;
            
        }
        if(type=='D')
        {
            SoDao d;
            cin >> d;
            b[b.size++]=d;
        }
    }
    
    if(a.size==0)
    {
        cout << "khong co" << "\n";
        cout << "khong co" << "\n";
    }
    else 
    {
        cout << Sum(a) << "\n";
        cout << Max(a) << "\n";
    }
    if(b.size==0) 
    {
        cout << "khong co" << "\n";
        cout << "khong co" << "\n";
    }
    else 
    {
        cout << Sum(b) << "\n";
        cout << Max(b) << "\n";
    }
    
    return 0;
}
