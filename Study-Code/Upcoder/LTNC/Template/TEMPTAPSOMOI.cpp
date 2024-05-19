#include <iostream>
using namespace std;

class TapSoMoi
{
    private: 
        int x, y, z, t;
    public:
        TapSoMoi ()
        {
            x=0;
            y=0;
            z=0;
            t=0;
        }
        TapSoMoi(int a,int b,int c,int d)
        {
            x = a;
            y = b;
            z = c;
            t = d;
        }
        friend istream& operator >> (istream& is, TapSoMoi& p)
        {
            is >> p.x >> p.y >> p.z >> p.t;
            return is;
        }
        friend ostream& operator << (ostream& os, TapSoMoi p)
        {
            os << "[TapSoMoi] " << p.x << ";" << p.y << ";" << p.z << ";" << p.t << "\n";
            return os;
        }
        
        void operator = (TapSoMoi other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            t = other.t;
        }

        TapSoMoi operator + (TapSoMoi other)
        {
            TapSoMoi kq;
            kq.x = this->x + other.x;
            kq.y = this->y + other.y;
            kq.z = this->z + other.z;
            kq.t = this->t + other.t;
            return kq;
        }
        
        int TongTV()
        {
            int sum = x + y + z + t;
            return sum;
        }
        bool operator < (TapSoMoi other)
        {
            return (this->TongTV() < other.TongTV());
        }
        
        ~TapSoMoi() {}
};

template<typename T>
class Mang
{
    private:
        int size;
        T values[100];
    public:

        Mang(T _values[] = new T {}, int _size = 0)
        {
            size = _size;
            for(int i=0;i<size;i++)
            {
                values[i] = _values[i];
            }
            return;
        }
        Mang(const Mang& p)
        {
            size = p.size;
            for(int i=0;i<size;i++)
            {
                values[i] = p.values[i];
            }
            return;
        }

        T& operator [](int index)
        {
            return values[index];
        }
        void operator = (Mang p)
        {
            size = p.size;
            for(int i=0;i<p.size;i++)
            {
                values[i] = p.values[i];
            }
        }

        friend istream& operator >> (istream& is, Mang& p)
        {
            p.size=0;
            while(is>>p.values[p.size])
            {
                p.size++;
            }
            return is;
        }
        T Max()
        {
            T max = values[0];
            for(int i=1;i<size;i++)
            {
                if(max < values[i])
                    max = values[i];
            }
            return max;
        }
        T Sum()
        {
            T sum = T();
            for(int i=0;i<size;i++)
            {
                sum = values[i] + sum;
            }
            return sum;
        }
    
        friend ostream& operator << (ostream& os, Mang p)
        {
            for(int i=0;i<p.size;i++)
            {
                os << p.values[i] << "\n";
            }
            return os;
        }
};  
int main()
{
    Mang<int> a;
    Mang<TapSoMoi> b;

    char type;
    cin>>type;
    
    switch(type)
    {
        case 'A':
        {
            cin >> a;
            cout << a.Max();
            cout << a.Sum();
            break;
        }
        case 'B':
        {
            cin >> b;
            cout << b.Max();
            cout << b.Sum();
            break;
        }
    }
    return 0;
}
