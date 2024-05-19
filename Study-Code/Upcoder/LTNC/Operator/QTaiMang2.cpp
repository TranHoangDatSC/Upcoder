#include <iostream>
using namespace std;

struct Mang
{
    int size;
    int values[100];
    
    int& operator [](int index)
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
            os << m.values[i];
        }
        return os;
    }
    
    Mang operator + (Mang other)
    {
        Mang result;
        result.size = (this->size < other.size ? other.size : this->size);
        
        for(int i=0;i<result.size;i++)
        {
            int sum1 = (i<this->size ? this->values[i] : 0);
            int sum2 = (i<other.size ? other.values[i] : 0);
            result.values[i] = sum1 + sum2;
        }
        return result;
    }
};

int main()
{
    Mang a,b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}
