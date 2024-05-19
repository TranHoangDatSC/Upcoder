#include <iostream>
using namespace std;

struct Mang 
{
    int size;
    int values[100];
    
    void operator = (Mang m)
    {
        size = m.size;
        for(int i=0;i<size;i++)
        {
            values[i] = m.values[i];
        }
    }
    int& operator [](int index)
    {
        return values[index];
    }
    friend istream& operator >> (istream& is, Mang& m)
    {
        is >> m.size;
        for(int i=0;i<m.size;i++)
        {
            is >> m.values[i];
        }
        return is;
    }
    friend ostream& operator << (ostream& os, Mang m)
    {
        for(int i=0;i<m.size;i++)
        {
            os << m.values[i] << " "; 
        }
        return os;
    }
    
    bool operator == (Mang other)
    {
        if(this->size!=other.size)
            return false;
        for(int i=0;i<this->size;i++)
        {
            if(this->values[i]!=other.values[i])
                return false;
        }
        return true;
    }
    bool operator != (Mang other)
    {
        return !(*this == other);
    }
    
    Mang operator + (Mang m)
    {
        Mang kq;
        kq.size = (this->size < m.size ? m.size : this->size);
        for(int i=0;i<kq.size;i++)
        {
            int sum1 = (i<this->size ? this->values[i] : 0);
            int sum2 = (i<m.size ? m.values[i] : 0); 
            kq.values[i] = sum1 + sum2;
        }
        return kq;
    }
};

int main()
{
    Mang a,b;
    cin >> a >> b;
    
    cout << (a==b ? "yes" : "no");
    
    return 0;
}
