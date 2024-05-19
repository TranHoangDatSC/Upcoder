#include <iostream> 
#include <iomanip>
#include <typeinfo>
using namespace std;

struct HCN
{
    double length, width;
    
    void operator = (double l)
    {
        length = l;
        width = l;
    }
    
    friend istream& operator >> (istream& is, HCN& h)
    {
        is >> h.length >> h.width;
        return is;
    }
    
    friend ostream& operator << (ostream& os, HCN h)
    {
        os << "[HCN] " << h.length << "," << h.width;
        return os;
    }
    
    double ChuVi()
    {
        return (double)(2 * (this->length + this->width));
    }
    
    bool operator < (HCN other)
    {
        return (this->ChuVi() < other.ChuVi());
    }
    
    double operator + (double h)
    {
        return (this->ChuVi() + h);
    }
};

bool operator == (HCN h, int n)
{
    return true;
}

template<typename T>
struct Mang
{
    int size;
    T values[100];
    
    T& operator [](int index)
    {
        return values[index];
    }
    void operator = (Mang a)
    {
        size = a.size;
        for(int i=0;i<size;i++)
        {
            values[i] = a.values[i];
        }
    }
    
    friend istream& operator >> (istream& is, Mang& a)
    {
        a.size = 0;
        T x;
        while(cin>>x)
        {
            a.values[a.size++] = x;
        }
        return is;
    }
    
    T Min()
    {
        T min = this->values[0];
        for(int i = 1;i<this->size;i++)
        {
            if(this->values[i]<min)
                min = values[i];
        }
        return min;
    }
    void Sum()
    {
        double sum = 0;
        for(int i = 0;i<this->size;i++)
        {
            sum = this->values[i] + sum;
        }
        
        if(typeid(T)==typeid(HCN))
        {
            cout << setprecision(1) << fixed << sum;
        }
        else cout << sum;
        return;
    }
    
    friend ostream& operator << (ostream& os, Mang p)
    {
        os << p.Min() << "\n";
        p.Sum();
        return os;
    }
};

int main()
{
    char type;
    cin >> type;
    
    switch(type)
    {
        case 'N':
        {
            Mang<int> a;
            cin >> a;
            cout << a;
            break;
        }
        case 'H':
        {
            Mang<HCN> a;
            cin >> a;
            cout << a;
            break;
        }
    }
    return 0;
}
